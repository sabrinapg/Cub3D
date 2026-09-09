#!/usr/bin/env bash

set -u

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
MAP_DIR="$ROOT_DIR/maps"
BIN="$ROOT_DIR/cub3D"
LOG_FILE="/tmp/cub3d_valgrind.out"

passed=0
failed=0

run_check()
{
	local map_file="$1"
	local name

	name="$(basename "$map_file")"
	valgrind --leak-check=full --track-fds=yes \
		"$BIN" "$map_file" >"$LOG_FILE" 2>&1
	if grep -q "All heap blocks were freed" "$LOG_FILE" \
		&& grep -q "ERROR SUMMARY: 0 errors" "$LOG_FILE" \
		&& grep -q "FILE DESCRIPTORS: 3 open (3 std)" "$LOG_FILE"; then
		printf "[PASS] %s\n" "$name"
		passed=$((passed + 1))
	else
		printf "[FAIL] %s\n" "$name"
		grep -E "definitely lost|indirectly lost|possibly lost|ERROR SUMMARY|FILE DESCRIPTORS" \
			"$LOG_FILE"
		failed=$((failed + 1))
	fi
}

cd "$ROOT_DIR" || exit 1
if ! make; then
	printf "[FAIL] build failed\n"
	exit 1
fi

run_check "$MAP_DIR/tester.cub"
for map_file in "$MAP_DIR"/invalid_*; do
	if [ -f "$map_file" ]; then
		run_check "$map_file"
	fi
done

printf "\nSummary: %d passed, %d failed\n" "$passed" "$failed"
if [ "$failed" -ne 0 ]; then
	exit 1
fi
exit 0
