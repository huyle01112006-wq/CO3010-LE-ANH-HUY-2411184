@echo off
chcp 65001 > nul
set LAB=%1
set EX=%2

if "%LAB%"=="" (
    echo [!] Cách dùng: .\run ^<Số_Lab^> ^<Số_Bài^>
    echo [!] Ví dụ: .\run 1 3
    exit /b
)

echo [*] Đang xử lý Lab %LAB% - Exercise %EX%...

:: 1. Xác định chính xác thư mục bài tập
set "EX_DIR=lab_%LAB%\Excercise %EX%"
if not exist "%EX_DIR%" set "EX_DIR=lab_%LAB%\Exercise %EX%"

if not exist "%EX_DIR%" (
    echo [!] KHÔNG TÌM THẤY THƯ MỤC: %EX_DIR%
    goto :END
)

:: 2. MỞ SCHEMATIC PROTEUS (.pdsprj) CỦA BÀI ĐÓ
set "SCHEMATIC_FOUND="
:: Tìm file .pdsprj CHÍNH TRONG THƯ MỤC EXERCISE ĐÓ
for /f "delims=" %%s in ('dir /b /s "%EX_DIR%\*.pdsprj" 2^>nul') do (
    start "" "%%s"
    echo [*] Đã mở Proteus Schematic của Exercise %EX%
    set "SCHEMATIC_FOUND=1"
    goto :MO_CODE
)

:: Nếu không có file .pdsprj riêng trong bài đó, mở file chung ở folder lab_%LAB%
if not defined SCHEMATIC_FOUND (
    for /f "delims=" %%s in ('dir /b "lab_%LAB%\*.pdsprj" 2^>nul') do (
        start "" "lab_%LAB%\%%s"
        echo [*] Đã mở Proteus Schematic chung của Lab %LAB%
        goto :MO_CODE
    )
)

:MO_CODE
:: 3. MỞ CHÍNH XÁC PROJECT / CODE CỦA BÀI ĐÓ
set "CODE_FOUND="

:: Tìm file .project CHỈ NẰM TRONG THƯ MỤC EX_DIR
for /f "delims=" %%p in ('dir /b /s "%EX_DIR%\.project" 2^>nul') do (
    start "" "%%p"
    echo [*] Đã mở STM32CubeIDE Project của Exercise %EX%!
    set "CODE_FOUND=1"
    goto :END
)

:: Nếu không thấy .project thì mở file main.c CHỈ NẰM TRONG EX_DIR
if not defined CODE_FOUND (
    for /f "delims=" %%c in ('dir /b /s "%EX_DIR%\main.c" 2^>nul') do (
        start "" "%%c"
        echo [*] Đã mở file main.c của Exercise %EX%!
        set "CODE_FOUND=1"
        goto :END
    )
)

:: Nếu không có cả 2 thì bật Explorer ngay tại thư mục bài đó
if not defined CODE_FOUND (
    explorer "%EX_DIR%"
)

:END