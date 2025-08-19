

#!/usr/bin/env python3

import subprocess
import sys

def resolve_symbol(binary_path, symbol_name):
    try:
        result = subprocess.run(["nm", binary_path], capture_output=True, text=True)
        if result.returncode != 0:
            print(f"[SpectreRoot] nm failed: {result.stderr}")
            return None

        for line in result.stdout.splitlines():
            if symbol_name in line:
                address = line.split()[0]
                print(f"[SpectreRoot] {symbol_name} = 0x{address}")
                return int(address, 16)

        print(f"[SpectreRoot] Symbol not found: {symbol_name}")
        return None
    except Exception as e:
        print(f"[SpectreRoot] Exception: {e}")
        return None

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <kernelcache_or_binary> <symbol_name>")
        sys.exit(1)

    binary = sys.argv[1]
    symbol = sys.argv[2]
    resolve_symbol(binary, symbol)