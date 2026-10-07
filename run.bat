@echo off
chcp 65001 > nul
set LAB=%1
set EX=%2

if "%LAB%"=="" (
    echo [!] Cach dung: .\run ^<So_Lab^> ^<So_Bai^>
    echo [!] Vi du: .\run 1 3
    exit /b
)

echo [*] Dang kich hoat Lab %LAB% - Exercise %EX%...

:: 1. XAC DINH THU MUC EXERCISE NGUON
set "EX_DIR=lab_%LAB%\Excercise %EX%"
if not exist "%EX_DIR%" set "EX_DIR=lab_%LAB%\Exercise %EX%"

if not exist "%EX_DIR%" (
    echo [!] KHONG TIM THAY THU MUC: %EX_DIR%
    goto :END
)

:: 2. DONG BO MAIN.C TANG CUONG (CHEP DE FILE MAIN.C CUA EXERCISE VAO PROJECT MAIN)
set "MAIN_UPDATED="
for /f "delims=" %%m in ('dir /b /s "%EX_DIR%\main.c" 2^>nul') do (
    :: Tim file main.c goc trong Project STM32 o thu muc lab_%LAB%
    for /f "delims=" %%target in ('dir /b /s "lab_%LAB%\Core\Src\main.c" 2^>nul') do (
        copy /y "%%m" "%%target" >nul
        echo [*] Da cap nhat code Exercise %EX% vao Project STM32 thanh cong!
        set "MAIN_UPDATED=1"
        goto :MO_SCHEMATIC
    )
)

if not defined MAIN_UPDATED (
    echo [!] Warning: Khong tim thay file main.c trong %EX_DIR% de chep de.
)

:MO_SCHEMATIC
:: 3. MO FILE PROTEUS (.pdsprj)
set "SCHEMATIC_FOUND="

:: Uu tien 1: File Proteus nam trong thu muc Exercise
for /f "delims=" %%s in ('dir /b /s "%EX_DIR%\*.pdsprj" 2^>nul') do (
    start "" "%%s"
    echo [*] Da mo Proteus Schematic cua Exercise %EX%
    set "SCHEMATIC_FOUND=1"
    goto :MO_IDE
)

:: Uu tien 2: File Proteus chung cua Lab
if not defined SCHEMATIC_FOUND (
    for /f "delims=" %%s in ('dir /b "lab_%LAB%\*.pdsprj" 2^>nul') do (
        start "" "lab_%LAB%\%%s"
        echo [*] Da mo Proteus Schematic chung cua Lab %LAB%
        goto :MO_IDE
    )
)

:MO_IDE
:: 4. MO PROJECT STM32CUBEIDE
for /f "delims=" %%p in ('dir /b /s "lab_%LAB%\*.project" 2^>nul') do (
    start "" "%%p"
    echo [*] Da mo STM32CubeIDE Project!
    goto :END
)

:END