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

:: 1. Tìm và mở file Proteus (.pdsprj) trong thư mục lab_%LAB%
for /f "delims=" %%i in ('dir /b /s "lab_%LAB%\*.pdsprj" 2^>nul') do (
    start "" "%%i"
    goto :MO_STM32
)

:MO_STM32
:: 2. Tìm file project STM32CubeIDE (.project hoặc .cproject) trong folder Excercise %EX%
set "EX_PATH=lab_%LAB%\Excercise %EX%"
if not exist "%EX_PATH%" set "EX_PATH=lab_%LAB%\Exercise %EX%"

if exist "%EX_PATH%" (
    :: Tìm file .project để kích hoạt STM32CubeIDE mở Project
    for /f "delims=" %%p in ('dir /b /s "%EX_PATH%\.project" 2^>nul') do (
        start "" "%%p"
        echo [*] Đã mở STM32CubeIDE Project!
        goto :END
    )
    
    :: Nếu không có file .project thì tìm và mở thẳng file main.c bằng VS Code / Editor mặc định
    for /f "delims=" %%c in ('dir /b /s "%EX_PATH%\main.c" 2^>nul') do (
        start "" "%%c"
        echo [*] Đã mở file main.c!
        goto :END
    )

    :: Nếu không tìm thấy file code cụ thể thì bật Explorer thư mục đó
    explorer "%EX_PATH%"
) else (
    echo [!] Không tìm thấy thư mục bài tập: lab_%LAB%\Excercise %EX%
)

:END