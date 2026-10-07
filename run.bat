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

:: 1. Tự động tìm và mở file Proteus (.pdsprj) trong thư mục lab_%LAB%
for /f "delims=" %%i in ('dir /b /s "lab_%LAB%\*.pdsprj" 2^>nul') do (
    start "" "%%i"
    goto :MO_CODE
)

:MO_CODE
:: 2. Mở thư mục bài tập chuẩn theo tên "Excercise X"
if exist "lab_%LAB%\Excercise %EX%" (
    explorer "lab_%LAB%\Excercise %EX%"
) else if exist "lab_%LAB%\Exercise %EX%" (
    explorer "lab_%LAB%\Exercise %EX%"
) else (
    echo [!] Không tìm thấy thư mục bài tập: lab_%LAB%\Excercise %EX%
)