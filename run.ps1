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

# 1. Tim thu muc lab
$labDir = "lab_$Lab"
if (-not (Test-Path $labDir)) {
    Write-Host "[!] Khong tim thay thu muc $labDir" -ForegroundColor Red
    exit
}

# 2. Tim thu muc Exercise nguon
$exDir = Get-ChildItem -Path $labDir -Directory | Where-Object { $_.Name -match "Ex.*cise\s*$Ex$" } | Select-Object -First 1

if (-not $exDir) {
    Write-Host "[!] Khong tim thay thu muc Exercise $Ex trong $labDir" -ForegroundColor Red
    exit
}

# 3. Tim file main.c nguon va main.c dich cua Project STM32
$srcMain = Get-ChildItem -Path $exDir.FullName -Filter "main.c" -Recurse | Select-Object -First 1
$targetMain = Get-ChildItem -Path $labDir -Filter "main.c" -Recurse | Where-Object { $_.FullName -like "*\Core\Src\*" } | Select-Object -First 1

if ($srcMain -and $targetMain) {
    # Kiểm tra nếu 2 đường dẫn khác nhau hoàn toàn mới thực hiện copy
    if ($srcMain.FullName -ne $targetMain.FullName) {
        Copy-Item -Path $srcMain.FullName -Destination $targetMain.FullName -Force
        Write-Host "[*] Da cap nhat code main.c cua Exercise $Ex vao Project STM32!" -ForegroundColor Green
    } else {
        Write-Host "[*] Dang chay Exercise $Ex (File main.c goc da trung voi Project STM32)." -ForegroundColor Green
    }
} else {
    Write-Host "[!] Khong tim thay main.c nguon hoac dich de chep de." -ForegroundColor Yellow
}

# 4. Mo Proteus Schematic (.pdsprj)
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

# 5. Mo STM32CubeIDE Project (.project)
$projFile = Get-ChildItem -Path $labDir -Filter "*.project" -Recurse | Select-Object -First 1
if ($projFile) {
    Invoke-Item $projFile.FullName
    Write-Host "[*] Da mo STM32CubeIDE Project!" -ForegroundColor Cyan
}