# Quick Demo Script
# Demonstrasi cepat untuk melihat daftar pasien

Write-Host "=== QUICK DEMO: Clinic Management System ===" -ForegroundColor Cyan
Write-Host ""
Write-Host "Langkah 1: Compile program..." -ForegroundColor Yellow
g++ -I include -o klinik.exe src/*.cpp -std=c++11 -Wall

if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Kompilasi berhasil!" -ForegroundColor Green
    Write-Host ""
    Write-Host "Langkah 2: Verifikasi data input..." -ForegroundColor Yellow
    
    $patients = (Select-String -Path "data/input.txt" -Pattern "^PATIENT\|" | Measure-Object).Count
    $doctors = (Select-String -Path "data/input.txt" -Pattern "^DOCTOR\|" | Measure-Object).Count
    
    Write-Host "✅ Ditemukan $patients pasien dan $doctors dokter" -ForegroundColor Green
    Write-Host ""
    Write-Host "Langkah 3: Program siap dijalankan!" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Untuk menjalankan program, ketik:" -ForegroundColor White
    Write-Host "   .\klinik.exe" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Tips untuk demo:" -ForegroundColor Yellow
    Write-Host "  1. Pilih menu 1 (Patient Management)" -ForegroundColor White
    Write-Host "  2. Pilih menu 6 (List All Patients)" -ForegroundColor White
    Write-Host "  3. Lihat daftar pasien yang sudah dimuat dari input.txt" -ForegroundColor White
    Write-Host "  4. Pilih 0 untuk kembali ke menu utama" -ForegroundColor White
    Write-Host "  5. Pilih 5 untuk melihat statistik" -ForegroundColor White
    Write-Host "  6. Pilih 0 untuk exit" -ForegroundColor White
} else {
    Write-Host "❌ Kompilasi gagal!" -ForegroundColor Red
}
