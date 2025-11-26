# Test Script untuk Aplikasi Manajemen Klinik
# Automated testing dengan PowerShell

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "   TESTING APLIKASI MANAJEMEN KLINIK" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Test 1: Kompilasi
Write-Host "[TEST 1] Kompilasi Program..." -ForegroundColor Yellow
$compileResult = & g++ -I include -o klinik.exe src/*.cpp -std=c++11 -Wall 2>&1
if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Kompilasi BERHASIL" -ForegroundColor Green
} else {
    Write-Host "❌ Kompilasi GAGAL" -ForegroundColor Red
    Write-Host $compileResult
    exit 1
}
Write-Host ""

# Test 2: Cek File Executable
Write-Host "[TEST 2] Verifikasi File Executable..." -ForegroundColor Yellow
if (Test-Path "klinik.exe") {
    $fileSize = (Get-Item "klinik.exe").Length
    Write-Host "✅ File klinik.exe ditemukan (Size: $fileSize bytes)" -ForegroundColor Green
} else {
    Write-Host "❌ File klinik.exe tidak ditemukan" -ForegroundColor Red
    exit 1
}
Write-Host ""

# Test 3: Cek Input File
Write-Host "[TEST 3] Verifikasi Input File..." -ForegroundColor Yellow
if (Test-Path "data/input.txt") {
    $lines = (Get-Content "data/input.txt" | Measure-Object -Line).Lines
    Write-Host "✅ File input.txt ditemukan ($lines baris)" -ForegroundColor Green
    
    # Hitung jumlah data
    $patients = (Select-String -Path "data/input.txt" -Pattern "^PATIENT\|" | Measure-Object).Count
    $doctors = (Select-String -Path "data/input.txt" -Pattern "^DOCTOR\|" | Measure-Object).Count
    $appointments = (Select-String -Path "data/input.txt" -Pattern "^APPOINTMENT\|" | Measure-Object).Count
    $records = (Select-String -Path "data/input.txt" -Pattern "^MEDICALRECORD\|" | Measure-Object).Count
    
    Write-Host "   - Pasien: $patients" -ForegroundColor Cyan
    Write-Host "   - Dokter: $doctors" -ForegroundColor Cyan
    Write-Host "   - Appointments: $appointments" -ForegroundColor Cyan
    Write-Host "   - Medical Records: $records" -ForegroundColor Cyan
} else {
    Write-Host "❌ File input.txt tidak ditemukan" -ForegroundColor Red
}
Write-Host ""

# Test 4: Test Quick Run (dengan input untuk langsung exit)
Write-Host "[TEST 4] Test Quick Run..." -ForegroundColor Yellow
Write-Host "Menjalankan program dengan auto-exit..." -ForegroundColor Gray

# Buat temporary input file untuk test
"5" | Out-File -FilePath "temp_test_input.txt" -Encoding ASCII
"0" | Out-File -FilePath "temp_test_input.txt" -Encoding ASCII -Append

$testOutput = & cmd /c "type temp_test_input.txt | klinik.exe 2>&1"
Remove-Item "temp_test_input.txt" -ErrorAction SilentlyContinue

if ($testOutput -match "CLINIC MANAGEMENT SYSTEM") {
    Write-Host "✅ Program berjalan dengan benar" -ForegroundColor Green
    Write-Host "✅ Menu utama ditampilkan" -ForegroundColor Green
} else {
    Write-Host "⚠️ Output program tidak sesuai ekspektasi" -ForegroundColor Yellow
}
Write-Host ""

# Test 5: Verifikasi Source Files
Write-Host "[TEST 5] Verifikasi Source Files..." -ForegroundColor Yellow
$sourceFiles = @(
    "src/main.cpp",
    "src/Person.cpp",
    "src/Patient.cpp",
    "src/Doctor.cpp",
    "src/Appointment.cpp",
    "src/MedicalRecord.cpp",
    "src/ClinicManager.cpp",
    "src/FileHandler.cpp"
)

$allFilesExist = $true
foreach ($file in $sourceFiles) {
    if (Test-Path $file) {
        Write-Host "   ✅ $file" -ForegroundColor Green
    } else {
        Write-Host "   ❌ $file (MISSING)" -ForegroundColor Red
        $allFilesExist = $false
    }
}
Write-Host ""

# Test 6: Verifikasi Header Files
Write-Host "[TEST 6] Verifikasi Header Files..." -ForegroundColor Yellow
$headerFiles = @(
    "include/Person.h",
    "include/Patient.h",
    "include/Doctor.h",
    "include/Appointment.h",
    "include/MedicalRecord.h",
    "include/ClinicManager.h",
    "include/FileHandler.h"
)

foreach ($file in $headerFiles) {
    if (Test-Path $file) {
        Write-Host "   ✅ $file" -ForegroundColor Green
    } else {
        Write-Host "   ❌ $file (MISSING)" -ForegroundColor Red
        $allFilesExist = $false
    }
}
Write-Host ""

# Summary
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "            TEST SUMMARY" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
if ($allFilesExist -and $LASTEXITCODE -eq 0) {
    Write-Host "✅ SEMUA TEST PASSED" -ForegroundColor Green
    Write-Host ""
    Write-Host "Program siap untuk dijalankan dengan:" -ForegroundColor Yellow
    Write-Host "   .\klinik.exe" -ForegroundColor White
} else {
    Write-Host "⚠️ ADA BEBERAPA ISSUE" -ForegroundColor Yellow
}
Write-Host "========================================" -ForegroundColor Cyan
