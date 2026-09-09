#!/usr/bin/env bash

set -u

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
MAP_DIR="$ROOT_DIR/maps"
VALID_MAP="$MAP_DIR/tester.cub"
BIN="$ROOT_DIR/cub3D"

pass_count=0
fail_count=0

run_valid_test()
{
	local map_file="$1"
	local name

	name="$(basename "$map_file")"
	if "$BIN" "$map_file" > /tmp/cub3d_test.out 2>&1; then
		printf "[PASS] valid   %s\n" "$name"
		pass_count=$((pass_count + 1))
	else
		printf "[FAIL] valid   %s -> " "$name"
		tr '\n' ' ' < /tmp/cub3d_test.out
		printf "\n"
		fail_count=$((fail_count + 1))
	fi
}

run_invalid_test()
{
	local map_file="$1"
	local name

	name="$(basename "$map_file")"
	if "$BIN" "$map_file" > /tmp/cub3d_test.out 2>&1; then
		printf "[FAIL] invalid %s unexpectedly passed\n" "$name"
		fail_count=$((fail_count + 1))
	else
		printf "[PASS] invalid %s -> " "$name"
		tr '\n' ' ' < /tmp/cub3d_test.out
		printf "\n"
		pass_count=$((pass_count + 1))
	fi
}

cd "$ROOT_DIR" || exit 1
if ! make; then
	printf "[FAIL] build failed\n"
	exit 1
fi

if [ -f "$VALID_MAP" ]; then
	run_valid_test "$VALID_MAP"
	for map_file in "$MAP_DIR"/valid_*.cub; do
		if [ -f "$map_file" ]; then
			run_valid_test "$map_file"
		fi
	done
else
	printf "[FAIL] missing valid map: %s\n" "$VALID_MAP"
	fail_count=$((fail_count + 1))
fi

for map_file in "$MAP_DIR"/invalid_*; do
	if [ -f "$map_file" ]; then
		run_invalid_test "$map_file"
	fi
done

printf "\nSummary: %d passed, %d failed\n" "$pass_count" "$fail_count"

if [ "$fail_count" -ne 0 ]; then
	exit 1
fi
exit 0
