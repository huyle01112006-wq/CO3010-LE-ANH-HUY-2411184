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

# 1. Tim thu muc Exercise (chap nhan 'Excercise X' va 'Exercise X')
$labDir = "lab_$Lab"
$exDir = Get-ChildItem -Path . -Filter $labDir -Directory | ForEach-Object { 
    Get-ChildItem -Path $_.FullName -Directory | Where-Object { $_.Name -match "Ex.*cise\s*$Ex$" } 
} | Select-Object -First 1

if (-not $exDir) {
    Write-Host "[!] Khong tim thay thu muc Exercise $Ex trong $labDir" -ForegroundColor Red
    exit
}

# 2. Tim main.c va chep de vao Project STM32 chinh
$srcMain = Get-ChildItem -Path $exDir.FullName -Filter "main.c" -Recurse | Select-Object -First 1
$targetMain = Get-ChildItem -Path $labDir -Filter "main.c" -Recurse | Where-Object { $_.FullName -like "*\Core\Src\*" } | Select-Object -First 1

if ($srcMain -and $targetMain) {
    Copy-Item -Path $srcMain.FullName -Destination $targetMain.FullName -Force
    Write-Host "[*] Da cap nhat code main.c cua Exercise $Ex vao Project STM32!" -ForegroundColor Green
} else {
    Write-Host "[!] Khong tim thay main.c nguon hoac dich de chep de." -ForegroundColor Yellow
}

# 3. Mo Proteus Schematic (.pdsprj)
$protFile = Get-ChildItem -Path $exDir.FullName -Filter "*.pdsprj" -Recurse | Select-Object -First 1
if (-not $protFile) {
    $protFile = Get-ChildItem -Path $labDir -Filter "*.pdsprj" | Select-Object -First 1
}

if ($protFile) {
    Invoke-Item $protFile.FullName
    Write-Host "[*] Da mo Proteus: $($protFile.Name)" -ForegroundColor Cyan
} else {
    Write-Host "[!] Khong tim thay file Proteus .pdsprj" -ForegroundColor Yellow
}

# 4. Mo STM32CubeIDE Project (.project)
$projFile = Get-ChildItem -Path $labDir -Filter "*.project" -Recurse | Select-Object -First 1
if ($projFile) {
    Invoke-Item $projFile.FullName
    Write-Host "[*] Da mo STM32CubeIDE Project!" -ForegroundColor Cyan
}