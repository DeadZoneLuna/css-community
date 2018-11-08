@echo off
setlocal ENABLEDELAYEDEXPANSION

rem Getting Steam path from registry
rem for /F "usebackq tokens=2*" %%I in (`reg query "HKCU\Software\Valve\Steam"^|find /I "SteamPath"`) do set steampath=%%J
for /f "usebackq tokens=1,2,*" %%i in (`reg query "HKCU\Software\Valve\Steam" /v "SteamPath"`) do set "steampath=%%~k"
rem Since this is loop, we cannot use ERRORLEVEL here
rem if not ERRORLEVEL 0 goto error

rem Replacing "/"'s with "\" in some cases
set steampath=%steampath:/=\%

rem Testing common paths
if not exist "%steampath%\steam.exe" (
	if not exist "%ProgramFiles(x86)%\steam.exe" (
		if not exist "%ProgramFiles%\steam.exe" (
			goto error
		) else (
			set steampath=%ProgramFiles%
		)
	) else set steampath=%ProgramFiles(x86)%
)

echo Running Engine Tool...

@start /D "%steampath%\steamapps\common\Source SDK Base 2013 Multiplayer" hl2.exe -sw -dev +sv_cheats 1 -console -novid -noborder -game "%CD%" -nop4 -tools

if %ERRORLEVEL% NEQ 0 goto error
goto success

:success
exit

:error
echo Error during launching game!
pause
exit
