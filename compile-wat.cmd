@echo off
rem compile-wat.cmd - Build EQUATOR console tools for OS/2 using Open Watcom
rem Output goes to bin\, log to compile-wat.log
rem OS/2 CMD.EXE only: no NT-style IF blocks, no SETLOCAL.

set LOGFILE=compile-wat.log
echo Build started: > %LOGFILE%

rem Auto-detect Open Watcom installation
if exist C:\WATCOM\bin\wcc386.exe set WATCOM=C:\WATCOM
if exist D:\WATCOM\bin\wcc386.exe set WATCOM=D:\WATCOM
if "%WATCOM%"=="" goto nowatcom

set INCLUDE=%WATCOM%\h;%WATCOM%\h\os2
set PATH=%WATCOM%\bin;%PATH%

echo Using WATCOM=%WATCOM% >> %LOGFILE%

wmake -f makefile.wat clean >> %LOGFILE% 2>&1
wmake -f makefile.wat all  >> %LOGFILE% 2>&1
if errorlevel 1 goto failed

echo Build OK >> %LOGFILE%
echo Build OK
exit 0

:nowatcom
echo ERROR: Open Watcom not found. Set WATCOM environment variable. >> %LOGFILE%
echo ERROR: Open Watcom not found. Set WATCOM environment variable.
exit 1

:failed
echo BUILD FAILED - see %LOGFILE%
type %LOGFILE%
exit 1