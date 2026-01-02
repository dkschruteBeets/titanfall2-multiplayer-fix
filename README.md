# Titanfall 2 Multiplayer Fix

Fixes the "Contacting Respawn Servers" connection issue on modern Intel CPUs (10th gen+).

## Problem
Titanfall 2 fails to connect to multiplayer servers on modern Intel CPUs due to an OpenSSL bug with AVX-512/VAES instructions.

## Solution
This launcher sets the `OPENSSL_ia32cap` environment variable **only for Titanfall 2**, avoiding system-wide changes that could affect other applications.

### Alternative: System-Wide Fix
You can also set the environment variable globally (affects all applications):
1. Press Windows key and type "edit the system environment variables"
2. Click "Environment Variables"
3. Under "System Variables", create new variable:
   - Name: `OPENSSL_ia32cap`
   - Value: `~0x200000200000000`
4. Restart your computer

⚠️ **This affects all OpenSSL applications system-wide.** The launcher method is recommended.

## Usage
1. Download `TF2Fix.exe` from [Releases](../../releases)
2. Place it in your Titanfall 2 game directory
3. Run `TF2Fix.exe` instead of the normal game launcher

## Building from Source

### Prerequisites
- CMake
- MinGW-w64
  - Download (e.g., `x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev0.7z`) from the MinGW-w64 releases
  - Extract to `C:\mingw64`
  - Add `C:\mingw64\bin` to your user PATH environment variable

### Build
```bash
git clone https://github.com/dkschruteBeets/titanfall2-multiplayer-fix.git
cd titanfall2-multiplayer-fix
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

The executable will be in `build/TF2Fix.exe`
