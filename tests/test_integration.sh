#!/usr/bin/env bash

set -u

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
MAP_DIR="$ROOT_DIR/maps"
BIN="$ROOT_DIR/cub3D"
LOG_FILE="$(mktemp /tmp/cub3d_test.XXXXXX)"
VALID_TIMEOUT="${CUB3D_VALID_TIMEOUT:-3}"

pass_count=0
fail_count=0
skip_count=0
use_xvfb=0
can_run_mlx=1

cleanup()
{
	rm -f "$LOG_FILE"
}

trap cleanup EXIT

setup_display_runner()
{
	if [ -n "${DISPLAY:-}" ]; then
		if ! command -v xdpyinfo >/dev/null 2>&1 \
			|| xdpyinfo >/dev/null 2>&1; then
			return
		fi
	fi
	if command -v xvfb-run >/dev/null 2>&1; then
		use_xvfb=1
		return
	fi
	can_run_mlx=0
}

run_cub3d()
{
	if [ "$use_xvfb" -eq 1 ]; then
		timeout "$VALID_TIMEOUT" xvfb-run -a "$BIN" "$1" >"$LOG_FILE" 2>&1
	else
		timeout "$VALID_TIMEOUT" "$BIN" "$1" >"$LOG_FILE" 2>&1
	fi
}

run_valid_test()
{
	local map_file="$1"
	local name
	local status

	name="$(basename "$map_file")"
	if [ "$can_run_mlx" -eq 0 ]; then
		printf "[SKIP] valid   %s -> needs DISPLAY or xvfb-run for MLX\n" "$name"
		skip_count=$((skip_count + 1))
		return
	fi
	run_cub3d "$map_file"
	status=$?
	if [ "$status" -eq 124 ]; then
		printf "[PASS] valid   %s -> app reached MLX loop\n" "$name"
		pass_count=$((pass_count + 1))
	elif [ "$status" -eq 0 ]; then
		printf "[PASS] valid   %s\n" "$name"
		pass_count=$((pass_count + 1))
	else
		printf "[FAIL] valid   %s -> " "$name"
		tr '\n' ' ' < "$LOG_FILE"
		printf "\n"
		fail_count=$((fail_count + 1))
	fi
}

run_invalid_test()
{
	local map_file="$1"
	local name

	name="$(basename "$map_file")"
	if "$BIN" "$map_file" >"$LOG_FILE" 2>&1; then
		printf "[FAIL] invalid %s unexpectedly passed\n" "$name"
		fail_count=$((fail_count + 1))
	elif grep -q "^Error$" "$LOG_FILE"; then
		printf "[PASS] invalid %s -> " "$name"
		tr '\n' ' ' < "$LOG_FILE"
		printf "\n"
		pass_count=$((pass_count + 1))
	else
		printf "[FAIL] invalid %s rejected without Error prefix -> " "$name"
		tr '\n' ' ' < "$LOG_FILE"
		printf "\n"
		fail_count=$((fail_count + 1))
	fi
}

cd "$ROOT_DIR" || exit 1
if ! make; then
	printf "[FAIL] build failed\n"
	exit 1
fi
setup_display_runner

for map_file in "$MAP_DIR"/tester*.cub "$MAP_DIR"/valid_*.cub; do
	if [ -f "$map_file" ]; then
		run_valid_test "$map_file"
	fi
done

for map_file in "$MAP_DIR"/invalid_* "$MAP_DIR"/bad_*; do
	if [ -f "$map_file" ]; then
		run_invalid_test "$map_file"
	fi
done

printf "\nSummary: %d passed, %d failed, %d skipped\n" \
	"$pass_count" "$fail_count" "$skip_count"

if [ "$fail_count" -ne 0 ] || [ "$skip_count" -ne 0 ]; then
	exit 1
fi
exit 0
