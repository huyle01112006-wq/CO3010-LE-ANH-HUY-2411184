@echo off
chcp 65001 > nul
set LAB=%1
set EX=%2

if "%LAB%"=="" (
    echo [!] Cách dùng: .\run ^<Số_Lab^> ^<Số_Bài^>
    echo [!] Ví dụ: .\run 1 3
    exit /b
)

echo [*] Đang mở Lab %LAB% - Exercise %EX%...

:: Xác định đường dẫn thư mục Exercise chuẩn
set "EX_PATH=lab_%LAB%\Excercise %EX%"
if not exist "%EX_PATH%" set "EX_PATH=lab_%LAB%\Exercise %EX%"

:: 1. TÌM VÀ MỞ PROTEUS (.pdsprj) CHÍNH XÁC CHO EXERCISE ĐÓ
set "SCHEMATIC_FOUND="

:: Ưu tiên 1: Tìm file .pdsprj nằm bên trong thư mục Excercise %EX%
if exist "%EX_PATH%" (
    for /f "delims=" %%s in ('dir /b /s "%EX_PATH%\*.pdsprj" 2^>nul') do (
        start "" "%%s"
        echo [*] Đã mở Proteus Schematic riêng của Exercise %EX%
        set "SCHEMATIC_FOUND=1"
        goto :MO_STM32
    )
)

:: Ưu tiên 2: Nếu bài đó không có file riêng, tìm file .pdsprj chung ở ngoài thư mục lab_%LAB%
if not defined SCHEMATIC_FOUND (
    for /f "delims=" %%s in ('dir /b "lab_%LAB%\*.pdsprj" 2^>nul') do (
        start "" "lab_%LAB%\%%s"
        echo [*] Đã mở Proteus Schematic chung của Lab %LAB%
        goto :MO_STM32
    )
)

:MO_STM32
:: 2. TÌM VÀ MỞ CODE / PROJECT STM32 CỦA EXERCISE ĐÓ
if exist "%EX_PATH%" (
    :: Tìm và mở Project STM32CubeIDE (.project) trong folder bài đó
    for /f "delims=" %%p in ('dir /b /s "%EX_PATH%\.project" 2^>nul') do (
        start "" "%%p"
        echo [*] Đã mở STM32CubeIDE Project cho Exercise %EX%!
        goto :END
    )
    
    :: Nếu không có file .project thì mở file main.c
    for /f "delims=" %%c in ('dir /b /s "%EX_PATH%\main.c" 2^>nul') do (
        start "" "%%c"
        echo [*] Đã mở file main.c cho Exercise %EX%!
        goto :END
    )

    :: Nếu không có cả hai thì mở thư mục Explorer
    explorer "%EX_PATH%"
) else (
    echo [!] Không tìm thấy thư mục bài tập: lab_%LAB%\Excercise %EX%
)

:END