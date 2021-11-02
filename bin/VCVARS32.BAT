@echo off
rem
rem Root of Visual C++ installed files.
rem     Note: This batch file will not work on Windows NT if MSDevDir contains spaces.
rem
rem set MSDevDir=C:\MSDEV
set MSDevDir=%~dp0\..

rem
rem Root of Visual C++ files on cd-rom.
rem Remove "set vcsource=" if you don't want include cdrom in Visual C++ environment.
rem
set vcsource=D:\MSDEV

rem
rem VcOsDir is used to help create either a Windows 95 or Windows NT specific path.
rem
set VcOsDir=WIN95
if "%OS%" == "Windows_NT" set VcOsDir=WINNT

if "%1" == "x86" goto x86
if "%1" == "m68k" goto m68k
if "%1" == "mppc" goto mppc

echo Usage: vcvars32 [target]
echo     Where target is one of the following: x86, m68k, mppc.
if "%1" == "" goto default
goto done

:default
echo No target specified.  Selecting x86 as default target. 

:x86
rem
echo Setting environment for building x86 target
rem
if "%vcsource%" == "" goto x86main
rem
rem Include cdrom files in environment.
rem
if "%OS%" == "Windows_NT" set PATH=%vcsource%\BIN;%vcsource%\BIN\%VcOsDir%;%PATH%
if "%OS%" == "" set PATH="%vcsource%\BIN";"%vcsource%\BIN\%VcOsDir%";"%PATH%"
set INCLUDE=%vcsource%\INCLUDE;%vcsource%\MFC\INCLUDE;%INCLUDE%
set LIB=%vcsource%\LIB;%vcsource%\MFC\LIB;%LIB%
set vcsource=

:x86main
if "%OS%" == "Windows_NT" set PATH=%MSDevDir%\BIN;%MSDevDir%\BIN\%VcOsDir%;%PATH%
if "%OS%" == "" set PATH="%MSDevDir%\BIN";"%MSDevDir%\BIN\%VcOsDir%";"%PATH%"
set INCLUDE=%MSDevDir%\INCLUDE;%MSDevDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSDevDir%\LIB;%MSDevDir%\MFC\LIB;%LIB%
goto done

:m68k
rem
echo Setting environment for building m68k target
rem
if "%OS%" == "Windows_NT" set PATH=%MSDevDir%\mac\m68k\bin;%MSDevDir%\mac\bin;%MSDevDir%\BIN;%MSDevDir%\BIN\%VcOsDir%;%PATH%
if "%OS%" == "" set PATH="%MSDevDir%\mac\m68k\bin";"%MSDevDir%\mac\bin";"%MSDevDir%\BIN";"%MSDevDir%\BIN\%VcOsDir%";"%PATH%"
set INCLUDE=%MSDevDir%\mac\include;%MSDevDir%\mac\include\macos;%MSDevDir%\mac\include\mrc;%MSDevDir%\INCLUDE;%MSDevDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSDevDir%\mac\m68k\lib;%MSDevDir%\LIB;%MSDevDir%\MFC\LIB;%LIB%
goto done

:mppc
rem
echo Setting environment for building mppc target
rem
if "%OS%" == "Windows_NT" set PATH=%MSDevDir%\mac\mppc\bin;%MSDevDir%\mac\bin;%MSDevDir%\BIN;%MSDevDir%\BIN\%VcOsDir%;%PATH%
if "%OS%" == "" set PATH="%MSDevDir%\mac\mppc\bin";"%MSDevDir%\mac\bin";"%MSDevDir%\BIN";"%MSDevDir%\BIN\%VcOsDir%";"%PATH%"
set INCLUDE=%MSDevDir%\mac\include;%MSDevDir%\mac\include\macos;%MSDevDir%\mac\include\sys;%MSDevDir%\mac\include\mrc;%MSDevDir%\INCLUDE;%MSDevDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSDevDir%\mac\mppc\lib;%MSDevDir%\LIB;%MSDevDir%\MFC\LIB;%LIB%

:done
set VcOsDir=
