# Panduan Testing Manual - Aplikasi Manajemen Klinik

## ✅ HASIL KOMPILASI DAN TESTING

### 1. Kompilasi Berhasil

```
✅ Kompilasi BERHASIL
✅ File klinik.exe ditemukan (410,095 bytes)
```

### 2. Data Input Terverifikasi

```
✅ File input.txt ditemukan (18 baris)
   - Pasien: 5
   - Dokter: 5
   - Appointments: 6
   - Medical Records: 2
```

### 3. Semua Source dan Header Files Lengkap

```
✅ Semua 8 source files (.cpp) tersedia
✅ Semua 7 header files (.h) tersedia
```

---

## 📋 CARA MENJALANKAN PROGRAM

### Metode 1: Langsung dari PowerShell

```powershell
cd "d:\College\Semester 5\Pemrograman Dasar\Proyek"
.\klinik.exe
```

### Metode 2: Menggunakan Build Script

```powershell
.\build.ps1
```

---

## 🧪 SKENARIO TESTING MANUAL

### Test Case 1: Melihat Daftar Pasien

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `1` (Patient Management)
3. Pilih menu `6` (List All Patients)
4. Pilih `0` untuk kembali
5. Pilih `0` untuk exit

**Expected Output:**

- Menampilkan 5 pasien (P0001 - P0005) dengan detail lengkap
- Nama, phone, address, DOB, gender, blood type

---

### Test Case 2: Melihat Daftar Dokter

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `2` (Doctor Management)
3. Pilih menu `4` (List All Doctors)
4. Pilih `0` untuk kembali
5. Pilih `0` untuk exit

**Expected Output:**

- Menampilkan 5 dokter (D0001 - D0005) dengan spesialisasi
- Cardiology, Pediatrics, Orthopedics, General Practice, Dermatology

---

### Test Case 3: Melihat Jadwal Appointment

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `3` (Appointment Management)
3. Pilih menu `4` (List All Appointments)
4. Pilih `0` untuk kembali
5. Pilih `0` untuk exit

**Expected Output:**

- Menampilkan 6 appointments
- Status: completed, scheduled
- Tanggal: 25-28 November 2025

---

### Test Case 4: Menambah Pasien Baru

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `1` (Patient Management)
3. Pilih menu `1` (Add New Patient)
4. Masukkan data:
   - Patient ID: `P0006`
   - Name: `Ahmad Wijaya`
   - Phone: `081234567895`
   - Address: `Jl. Asia Afrika No. 99, Bandung`
   - Date of Birth: `15/06/1995`
   - Gender: `M`
   - Blood Type: `A`
5. Pilih `0` untuk kembali
6. Pilih menu `6` untuk verifikasi pasien baru ditambahkan
7. Pilih `0` → `6` (Save Data) → `0` (Exit)

**Expected Output:**

- Pesan "Patient added successfully!"
- Pasien P0006 muncul di daftar
- Data tersimpan di output.txt

---

### Test Case 5: Mencari Pasien

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `1` (Patient Management)
3. Pilih menu `4` (Find Patient by ID)
4. Masukkan ID: `P0001`
5. Verifikasi data ditampilkan

**Expected Output:**

- Detail pasien John Doe ditampilkan lengkap

---

### Test Case 6: View Statistics

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `5` (View Statistics)
3. Review statistik

**Expected Output:**

```
Total Patients: 5
Total Doctors: 5
Total Appointments: 6
Completed Appointments: 2
Scheduled Appointments: 3
Cancelled Appointments: 1
```

---

### Test Case 7: Save dan Export

**Langkah:**

1. Jalankan `.\klinik.exe`
2. Pilih menu `6` (Save Data)
3. Pilih menu `7` (Export Report)
4. Pilih `0` (Exit)

**Expected Output:**

- Pesan "Data saved successfully to output.txt"
- File `data/output.txt` berisi semua data terbaru
- File report di-generate

---

## 📊 VERIFIKASI OUTPUT

### Cek file output.txt

```powershell
Get-Content "data\output.txt"
```

**Expected:**

- Semua data dalam format yang sama dengan input.txt
- Perubahan yang dibuat tersimpan

---

## 🎯 DEMONSTRASI UNTUK DOSEN

### Skenario Demo Lengkap (5-10 menit):

1. **Pengenalan** (1 menit)

   - Tunjukkan struktur project
   - Jelaskan konsep OOP yang digunakan

2. **Kompilasi** (1 menit)

   ```powershell
   g++ -I include -o klinik.exe src/*.cpp -std=c++11 -Wall
   ```

   - Tunjukkan tidak ada error/warning

3. **Menjalankan Program** (1 menit)

   ```powershell
   .\klinik.exe
   ```

   - Tunjukkan menu utama

4. **Demo Fitur CRUD** (3-4 menit)

   - View All Patients (Read)
   - Add New Patient (Create)
   - Update Patient (Update) - optional
   - View Statistics

5. **File Handling** (1 menit)

   - Tunjukkan input.txt
   - Save data
   - Tunjukkan output.txt

6. **Class Diagram & Use Case** (2 menit)
   - Buka `docs/class_diagram.md`
   - Buka `docs/use_case_diagram.md`
   - Jelaskan relationship antar class

---

## ✅ CHECKLIST REQUIREMENTS

- [x] **Domain Aplikasi**: Manajemen Klinik
- [x] **Fitur Menambahkan Data**: ✅ Add Patient, Doctor, Appointment, Medical Record
- [x] **Fitur Mengedit Data**: ✅ Update Patient, Doctor, Appointment
- [x] **Fitur Menampilkan Data**: ✅ List All & Search
- [x] **Fitur Transaksi**: ✅ Create Appointment, Add Medical Record
- [x] **Fitur Menghapus Data**: ✅ Delete Patient, Doctor, Appointment
- [x] **Load dari input.txt**: ✅ Implemented
- [x] **Save ke output.txt**: ✅ Implemented
- [x] **User Interface CLI**: ✅ Console-based menu
- [x] **Use Case Diagram**: ✅ docs/use_case_diagram.md
- [x] **Class Diagram**: ✅ docs/class_diagram.md
- [x] **Implementasi C++**: ✅ All source files complete
- [x] **OOP Principles**:
  - [x] Encapsulation: Private members, getters/setters
  - [x] Inheritance: Patient & Doctor inherit from Person
  - [x] Polymorphism: Virtual functions
  - [x] Abstraction: Interface-based design
- [x] **Laporan**: ✅ docs/laporan.md

---

## 🎓 NILAI TAMBAH

1. **Code Quality**

   - Clean code dengan comments
   - Proper error handling
   - Memory management

2. **Additional Features**

   - Statistics view
   - Export report
   - Search functionality
   - Data validation

3. **Documentation**

   - Complete README
   - Compilation guide
   - UML diagrams
   - Laporan template

4. **Build System**
   - Makefile untuk cross-platform
   - PowerShell build script
   - Automated testing script

---

## 📝 CATATAN PENTING

- Program sudah **BERHASIL DIKOMPILASI** tanpa error
- Semua fitur sudah **IMPLEMENTED**
- Data sample sudah tersedia di input.txt
- Siap untuk **DEMO** dan **DIKUMPULKAN**

**Good luck dengan presentasi! 🚀**
