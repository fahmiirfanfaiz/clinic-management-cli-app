# Build script for Clinic Management CLI App (Windows PowerShell)
# Compiles all C++ source files and creates Klinik.exe

Write-Host "========================================" -ForegroundColor Cyan
Write-Host " Clinic Management CLI App - Builder" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Configuration
$COMPILER = "g++"
$OUTPUT = "Klinik.exe"
$INCLUDE_DIR = "include"
$SRC_DIR = "src"
$SOURCES = Get-ChildItem -Path "$SRC_DIR\*.cpp" | ForEach-Object { $_.FullName }
$CXXFLAGS = "-std=c++11", "-Wall", "-I", $INCLUDE_DIR

# Check if g++ is installed
Write-Host "[1/4] Checking compiler..." -ForegroundColor Yellow
try {
    $null = & $COMPILER --version 2>&1
    Write-Host "✓ g++ compiler found" -ForegroundColor Green
} catch {
    Write-Host "✗ Error: g++ compiler not found!" -ForegroundColor Red
    Write-Host "Please install MinGW-w64 or MSYS2 with g++ compiler" -ForegroundColor Red
    exit 1
}

# Check source files
Write-Host ""
Write-Host "[2/4] Checking source files..." -ForegroundColor Yellow
if ($SOURCES.Count -eq 0) {
    Write-Host "✗ Error: No .cpp files found in $SRC_DIR/" -ForegroundColor Red
    exit 1
}
Write-Host "✓ Found $($SOURCES.Count) source file(s)" -ForegroundColor Green

# Compile
Write-Host ""
Write-Host "[3/4] Compiling..." -ForegroundColor Yellow
Write-Host "Command: $COMPILER $CXXFLAGS -o $OUTPUT $(($SOURCES | ForEach-Object { Split-Path $_ -Leaf }) -join ' ')" -ForegroundColor Gray

try {
    & $COMPILER $CXXFLAGS -o $OUTPUT $SOURCES
    
    if ($LASTEXITCODE -ne 0) {
        Write-Host "✗ Compilation failed!" -ForegroundColor Red
        exit 1
    }
    
    Write-Host "✓ Compilation successful" -ForegroundColor Green
} catch {
    Write-Host "✗ Compilation error: $_" -ForegroundColor Red
    exit 1
}

# Verify output
Write-Host ""
Write-Host "[4/4] Verifying output..." -ForegroundColor Yellow
if (Test-Path $OUTPUT) {
    $fileSize = (Get-Item $OUTPUT).Length
    $fileSizeKB = [math]::Round($fileSize / 1KB, 2)
    Write-Host "✓ Executable created: $OUTPUT ($fileSizeKB KB)" -ForegroundColor Green
} else {
    Write-Host "✗ Error: Output file not created!" -ForegroundColor Red
    exit 1
}

# Success
Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host " Build Completed Successfully! " -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""
Write-Host "To run the application, execute:" -ForegroundColor Cyan
Write-Host "  .\$OUTPUT" -ForegroundColor White
Write-Host ""
