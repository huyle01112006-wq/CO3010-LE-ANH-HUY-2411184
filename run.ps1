param(
    [int]$Lab,
    [int]$Ex
)

if (-not $Lab -or -not $Ex) {
    Write-Host "[!] Cách dùng: .\run.ps1 <Số_Lab> <Số_Bài>" -ForegroundColor Yellow
    Write-Host "[!] Ví dụ: .\run.ps1 1 3" -ForegroundColor Yellow
    exit
}

Write-Host "[*] Đang kích hoạt Lab $Lab - Exercise $Ex..." -ForegroundColor Cyan

# 1. Tìm thư mục Exercise (chấp nhận cả 'Excercise X' lẫn 'Exercise X')
$labDir = "lab_$Lab"
$exDir = Get-ChildItem -Path . -Filter $labDir -Directory | ForEach-Object { 
    Get-ChildItem -Path $_.FullName -Directory | Where-Object { $_.Name -match "Ex.*cise\s*$Ex$" } 
} | Select-Object -First 1

if (-not $exDir) {
    Write-Host "[!] Không tìm thấy thư mục Exercise $Ex trong $labDir" -ForegroundColor Red
    exit
}

# 2. Tìm file main.c nguồn và chép đè vào Project STM32 chính
$srcMain = Get-ChildItem -Path $exDir.FullName -Filter "main.c" -Recurse | Select-Object -First 1
$targetMain = Get-ChildItem -Path $labDir -Filter "main.c" -Recurse | Where-Object { $_.FullName -like "*\Core\Src\*" } | Select-Object -First 1

if ($srcMain -and $targetMain) {
    Copy-Item -Path $srcMain.FullName -Destination $targetMain.FullName -Force
    Write-Host "[*] Đã cập nhật code main.c của Exercise $Ex vào Project STM32!" -ForegroundColor Green
} else {
    Write-Host "[!] Không tìm thấy main.c nguồn hoặc đích để chép đè." -ForegroundColor Yellow
}

# 3. Mở Proteus Schematic (.pdsprj)
$protFile = Get-ChildItem -Path $exDir.FullName -Filter "*.pdsprj" -Recurse | Select-Object -First 1
if (-not $protFile) {
    $protFile = Get-ChildItem -Path $labDir -Filter "*.pdsprj" | Select-Object -First 1
}

if ($protFile) {
    Invoke-Item $protFile.FullName
    Write-Host "[*] Đã mở Proteus: $($protFile.Name)" -ForegroundColor Cyan
} else {
    Write-Host "[!] Không tìm thấy file Proteus .pdsprj" -ForegroundColor Yellow
}

# 4. Mở STM32CubeIDE Project (.project)
$projFile = Get-ChildItem -Path $labDir -Filter "*.project" -Recurse | Select-Object -First 1
if ($projFile) {
    Invoke-Item $projFile.FullName
    Write-Host "[*] Đã mở STM32CubeIDE Project!" -ForegroundColor Cyan
}