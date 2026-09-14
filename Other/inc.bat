@echo off
rem a global script to manage environment variables in cmd
rem e.g. `inc riscv` adds riscv-gcc to PATH when needed
rem NOTE make sure this file uses CRLF
if %1==mingw64 (
	goto mingw64
) else if %1==riscv (
	goto riscv
) else if %1==qt (
	goto qt
) else
	echo unknown %1
	goto exit
)
:mingw64
C:\msys64\msys2_shell.cmd -defterm -here -no-start -mingw64
goto exit

:riscv
PATH=%PATH%;C:\Program\riscv-toolchain\bin
goto exit

:qt
C:\Program\Qt\6.8.0\msvc2022_64\bin\qtenv2.bat
goto exit

:exit
