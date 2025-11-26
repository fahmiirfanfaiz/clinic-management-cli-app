# Build script for Windows (PowerShell)

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Clinic Management System - Build     " -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Check if g++ is available
$gppPath = Get-Command g++ -ErrorAction SilentlyContinue
if (-not $gppPath) {
    Write-Host "Error: g++ compiler not found!" -ForegroundColor Red
    Write-Host "Please install MinGW or similar C++ compiler." -ForegroundColor Yellow
    exit 1
}

Write-Host "Compiler found: $($gppPath.Source)" -ForegroundColor Green
Write-Host ""

# Create obj directory if it doesn't exist
if (-not (Test-Path "obj")) {
    New-Item -ItemType Directory -Path "obj" | Out-Null
    Write-Host "Created obj directory" -ForegroundColor Green
}

# Compile
Write-Host "Compiling source files..." -ForegroundColor Yellow

$sourceFiles = Get-ChildItem -Path "src" -Filter "*.cpp"
$objectFiles = @()

foreach ($file in $sourceFiles) {
    $objFile = "obj\$($file.BaseName).o"
    Write-Host "  Compiling $($file.Name)..." -ForegroundColor Gray
    
    & g++ -I include -c "src\$($file.Name)" -o $objFile -std=c++11
    
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Compilation failed for $($file.Name)!" -ForegroundColor Red
        exit 1
    }
    
    $objectFiles += $objFile
}

Write-Host ""
Write-Host "Linking object files..." -ForegroundColor Yellow

& g++ -o klinik.exe $objectFiles

if ($LASTEXITCODE -ne 0) {
    Write-Host "Linking failed!" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "  Build Successful!                    " -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""
Write-Host "Run the application with: .\klinik.exe" -ForegroundColor Cyan
Write-Host ""
