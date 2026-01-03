# Titanfall 2 Multiplayer Fix

Fixes the "Contacting Respawn Servers" connection issue on modern Intel CPUs (10th gen+).

## Problem
Titanfall 2 fails to connect to multiplayer servers on modern Intel CPUs due to an OpenSSL bug with AVX-512/VAES instructions.

## Solutions
This repo offers two options:
- **Shim method (recommended):** Uses a Windows Application Compatibility shim to set `OPENSSL_ia32cap` only for `Titanfall2.exe`.
- **Launcher method:** A small launcher that sets `OPENSSL_ia32cap` and starts the game.

### Alternative: System-Wide Fix
You can also set the environment variable globally (affects all applications):
1. Press Windows key and type "edit the system environment variables"
2. Click "Environment Variables"
3. Under "System Variables", create new variable:
   - Name: `OPENSSL_ia32cap`
   - Value: `~0x200000200000000`
4. Restart your computer

⚠️ **This affects all OpenSSL applications system-wide.** The shim method is recommended.

## Usage
Choose a method:
- Shim method: see `shim-method/README.md`
- Launcher method: see `launcher-method/README.md`

## Building from Source (Launcher Method)

### Prerequisites
- CMake
- MinGW-w64
  - Download (e.g., `x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev0.7z`) from the MinGW-w64 releases
  - Extract to `C:\mingw64`
  - Add `C:\mingw64\bin` to your user PATH environment variable

### Build
```bash
git clone https://github.com/dkschruteBeets/titanfall2-multiplayer-fix.git
cd titanfall2-multiplayer-fix/launcher-method/source
cmake -B build -G "MinGW Makefiles"
cmake --build build --config Release
```

The executable will be in `build/TF2Fix.exe`
