@echo off
cd %~dp0
:start
echo SC-CL fuieventmonitor.c
echo Press ENTER to launch
pause > nul
cls
"../bin/SC-CL.exe" -platform=SWITCH -target=RDR_#SC -name="fuieventmonitor" -out-dir="RDR_SC/SWITCH/bin/" -vcx="fuieventmonitor.vcxproj" -- -I "../include/"
goto start
