@echo off
setlocal

set "SDB=%~dp0Titanfall2OpenSSLFix.sdb"

if not exist "%SDB%" (
  echo ERROR: %SDB% not found.
  echo Place Titanfall2OpenSSLFix.sdb in the same folder as this script.
  exit /b 1
)

sdbinst.exe -q "%SDB%"
if errorlevel 1 (
  echo ERROR: Failed to install shim. Try running as Administrator.
  exit /b 1
)

echo Installed shim successfully.
