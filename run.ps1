param(
    [int]$Lab,
    [int]$Ex
)

if (-not $Lab -or -not $Ex) {
    Write-Host "[!] Cach dung: .\run.ps1 <So_Lab> <So_Bai>" -ForegroundColor Yellow
    Write-Host "[!] Vi du: .\run.ps1 1 3" -ForegroundColor Yellow
    exit
}

Write-Host "[*] Dang kich hoat Lab $Lab - Exercise $Ex..." -ForegroundColor Cyan

# 1. Thu muc chua code bai tap (lab_1, lab_2,...)
$labDir = "lab_$Lab"
if (-not (Test-Path $labDir)) {
    Write-Host "[!] Khong tim thay thu muc $labDir" -ForegroundColor Red
    exit
}

# 2. Thu muc chua Project STM32 goc (Laboratory_1, Laboratory_2,...)
$stm32ProjDir = "Laboratory_$Lab"
if (-not (Test-Path $stm32ProjDir)) {
    # Neu khong co "Laboratory_X", dung chinh $labDir
    $stm32ProjDir = $labDir
}

# 3. Tim thu muc Exercise nguon
$exDir = Get-ChildItem -Path $labDir -Directory | Where-Object { $_.Name -match "Ex.*cise\s*$Ex$" -or $_.Name -match "Exercise_$Ex$" -or $_.Name -match "^Ex_$Ex$" } | Select-Object -First 1

if (-not $exDir) {
    Write-Host "[!] Khong tim thay thu muc Exercise $Ex trong $labDir" -ForegroundColor Red
    exit
}

# 4. Tim file main.c nguon va target main.c cua Project STM32 chính
$srcMain = Get-ChildItem -Path $exDir.FullName -Filter "main.c" -Recurse | Select-Object -First 1

# Tìm main.c đích nằm trong thư mục Laboratory_X trước, nếu không có mới tìm trong lab_X (bỏ qua folder của Exercise hiện tại)
$targetMain = Get-ChildItem -Path $stm32ProjDir -Filter "main.c" -Recurse | Where-Object { 
    $_.FullName -like "*\Core\Src\main.c*" -and $_.FullName -ne $srcMain.FullName 
} | Select-Object -First 1

if ($srcMain -and $targetMain) {
    Copy-Item -Path $srcMain.FullName -Destination $targetMain.FullName -Force
    Write-Host "[*] Da chep main.c tu [$($exDir.Name)] sang Project STM32!" -ForegroundColor Green
} elseif ($srcMain) {
    Write-Host "[*] Exercise $Ex da chua san Project STM32/main.c goc. Khong can ghi de!" -ForegroundColor Green
} else {
    Write-Host "[!] Khong tim thay main.c nguon!" -ForegroundColor Red
}

# 5. Mo Proteus Schematic (.pdsprj)
$protFile = Get-ChildItem -Path $exDir.FullName -Filter "*.pdsprj" -Recurse | Select-Object -First 1
if (-not $protFile) {
    $protFile = Get-ChildItem -Path $labDir -Filter "*.pdsprj" -Recurse | Select-Object -First 1
}

if ($protFile) {
    Invoke-Item $protFile.FullName
    Write-Host "[*] Da mo Proteus: $($protFile.Name)" -ForegroundColor Cyan
} else {
    Write-Host "[!] Khong tim thay file Proteus .pdsprj" -ForegroundColor Yellow
}

# 6. Mo Project STM32CubeIDE (.cproject hoac .project)
$projFile = Get-ChildItem -Path $exDir.FullName -Filter "*.cproject" -Recurse | Select-Object -First 1
if (-not $projFile) {
    $projFile = Get-ChildItem -Path $stm32ProjDir -Filter "*.cproject" -Recurse | Select-Object -First 1
}
if (-not $projFile) {
    $projFile = Get-ChildItem -Path $stm32ProjDir -Filter "*.project" -Recurse | Select-Object -First 1
}

if ($projFile) {
    Invoke-Item $projFile.FullName
    Write-Host "[*] Da mo STM32CubeIDE Project!" -ForegroundColor Cyan
} else {
    Write-Host "[!] Khong tim thay file project STM32 (.project / .cproject)" -ForegroundColor Yellow
}