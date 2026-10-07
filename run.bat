@echo off
set LAB=%1
set EX=%2

if "%LAB%"=="" (
    echo [!] Cach dung: run ^<Lab_Number^> ^<Ex_Number^>
    echo [!] Vi du: run 1 3
    exit /b
)

echo [*] Dang mo Lab %LAB% - Exercise %EX%...

:: 1. Mo file Proteus tuong ung (Neu schematic xài chung Lab1.pdsprj)
if exist "Lab%LAB%\Schematic\Lab%LAB%.pdsprj" (
    start "" "Lab%LAB%\Schematic\Lab%LAB%.pdsprj"
)

:: 2. Mo thu muc Code hoac Project STM32CubeIDE/Keil C tuong ung
if exist "Lab%LAB%\Ex%EX%" (
    explorer "Lab%LAB%\Ex%EX%"
) else (
    echo [!] Khong tim thấy Lab%LAB%\Ex%EX%
)