# Shim Method

Run `install.bat` as Administrator to install the shim.
Run `uninstall.bat` as Administrator to remove the shim.

## Verify Installation
To confirm the shim is installed:

```
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\InstalledSDB" /s | findstr /i Titanfall2OpenSSLFix.sdb
```

To confirm the per-exe entry exists:

```
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Custom" /s | findstr /i Titanfall2.exe
```
