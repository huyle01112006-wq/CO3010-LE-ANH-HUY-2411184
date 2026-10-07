@echo off
chcp 65001 > nul
set LAB=%1
set EX=%2

if "%LAB%"=="" (
    echo [!] Cách dùng: .\run ^<Số_Lab^> ^<Số_Bài^>
    echo [!] Ví dụ: .\run 1 3
    exit /b
)

echo [*] Đang kích hoạt Lab %LAB% - Exercise %EX%...

:: Chạy script PowerShell ngầm để copy main.c và tìm mở file chính xác
powershell -NoProfile -ExecutionPolicy Bypass -Command "^
    $lab = '%LAB%'; $ex = '%EX%'; ^
    $exDir = Get-ChildItem -Path . -Filter \"lab_$lab\" -Directory | ForEach-Object { Get-ChildItem -Path $_.FullName -Directory | Where-Object { $_.Name -match \"Ex.*cise\s*$ex$\" } } | Select-Object -First 1; ^
    if ($exDir) { ^
        $srcMain = Get-ChildItem -Path $exDir.FullName -Filter \"main.c\" -Recurse | Select-Object -First 1; ^
        $targetMain = Get-ChildItem -Path \"lab_$lab\" -Filter \"main.c\" -Recurse | Where-Object { $_.FullName -like \"*\Core\Src\*\" } | Select-Object -First 1; ^
        if ($srcMain -and $targetMain) { ^
            Copy-Item -Path $srcMain.FullName -Destination $targetMain.FullName -Force; ^
            Write-Host \"[*] Đã cập nhật main.c của Exercise $ex vào Project STM32!\" -ForegroundColor Green; ^
        } else { Write-Host \"[!] Không tìm thấy main.c nguồn hoặc đích để chép đè.\" -ForegroundColor Yellow; } ^
        $protFile = Get-ChildItem -Path $exDir.FullName -Filter \"*.pdsprj\" -Recurse | Select-Object -First 1; ^
        if (-not $protFile) { $protFile = Get-ChildItem -Path \"lab_$lab\" -Filter \"*.pdsprj\" | Select-Object -First 1; } ^
        if ($protFile) { Invoke-Item $protFile.FullName; Write-Host \"[*] Đã mở Proteus: $($protFile.Name)\" -ForegroundColor Cyan; } ^
        $projFile = Get-ChildItem -Path \"lab_$lab\" -Filter \"*.project\" -Recurse | Select-Object -First 1; ^
        if ($projFile) { Invoke-Item $projFile.FullName; Write-Host \"[*] Đã mở STM32 Project!\" -ForegroundColor Cyan; } ^
    } else { Write-Host \"[!] Không tìm thấy thư mục Exercise $ex trong lab_$lab\" -ForegroundColor Red; } ^
"