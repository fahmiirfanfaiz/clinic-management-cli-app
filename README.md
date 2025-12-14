# Clinic Management CLI App

## 📌 Deskripsi Aplikasi

Clinic Management CLI App adalah sebuah aplikasi berbasis Command Line Interface (CLI) yang dirancang untuk mendukung manajemen operasional klinik kesehatan. Aplikasi ini dikembangkan untuk mengintegrasikan seluruh proses pengelolaan data klinik, mulai dari registrasi pasien, penjadwalan appointment, manajemen dokter, hingga pencatatan rekam medis.

Aplikasi ini hadir sebagai solusi atas permasalahan umum dalam pengelolaan klinik, seperti:

- **Pengelolaan Data Manual** yang rawan kesalahan dan memakan waktu
- **Kesulitan Pencarian** riwayat pasien atau jadwal dokter dengan cepat
- **Data Tidak Terintegrasi** dimana informasi pasien, dokter, dan appointment tersebar
- **Risiko Kehilangan Data** akibat pencatatan dalam bentuk kertas yang mudah hilang atau rusak

Fitur utama meliputi manajemen pasien, manajemen dokter, penjadwalan appointment, pencatatan rekam medis, serta persistensi data otomatis. Melalui fitur-fitur ini, Clinic Management CLI App memungkinkan pencatatan data yang terstruktur, pencarian informasi yang cepat, serta backup data yang aman. Dengan demikian, aplikasi ini tidak hanya mempermudah staf klinik dalam mengelola data harian, tetapi juga membantu dokter dalam mengakses riwayat pasien dan meningkatkan kualitas layanan kesehatan secara keseluruhan.

## ✨ Nama Kelompok dan Daftar Anggota

| No  | Nama                 | NIM                |
| --- | -------------------- | ------------------ |
| 1   | Kistosi Al Ghifari   | 23/515523/TK/56680 |
| 2   | Fahmi Irfan Faiz     | 23/520563/TK/57396 |
| 3   | Kalya Naura Farabias | 24/541690/TK/60097 |

## 📂 Struktur Folder

```
Clinic Management CLI App/
│
├── data/                         # Data storage files
│   ├── input.txt                 # Input data source
│   ├── output.txt                # Auto-generated output
│   └── report.txt                # Generated reports
│
├── docs/                                # Documentation folder
│   ├── use_case_diagram.png             # Use case diagram
│   ├── class_diagram.png                # Class diagram
│   └── 515523-520563-541690_Project.pdf # Project report
│
├── include/                      # Header files (.h)
│   ├── Person.h                  # Base class for person entities
│   ├── Patient.h                 # Patient class (inherits Person)
│   ├── Doctor.h                  # Doctor class (inherits Person)
│   ├── Appointment.h             # Appointment management
│   ├── MedicalRecord.h           # Medical record management
│   ├── ClinicManager.h           # Core clinic operations
│   └── FileHandler.h             # File I/O operations
│
├── src/                          # Source files (.cpp)
│   ├── Person.cpp                # Person implementation
│   ├── Patient.cpp               # Patient implementation
│   ├── Doctor.cpp                # Doctor implementation
│   ├── Appointment.cpp           # Appointment implementation
│   ├── MedicalRecord.cpp         # Medical record implementation
│   ├── ClinicManager.cpp         # Clinic manager implementation
│   ├── FileHandler.cpp           # File handler implementation
│   └── main.cpp                  # Main entry point
│
├── Makefile                      # Build configuration for Unix/Linux
├── build.ps1                     # Build script for Windows PowerShell
├── build.sh                      # Build script for Linux/Mac
└── README.md                     # Project documentation
```

## 💡 Fitur Aplikasi

### 1️⃣ **Manajemen Pasien**

| Fitur                       | Deskripsi                                                                                                            |
| --------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| **Registrasi Pasien**       | Mendaftarkan pasien baru dengan informasi lengkap (ID, nama, telepon, alamat, tanggal lahir, gender, golongan darah) |
| **Update Data Pasien**      | Mengubah informasi pasien yang sudah terdaftar                                                                       |
| **Hapus Pasien**            | Menghapus data pasien dari sistem                                                                                    |
| **Tampilkan Daftar Pasien** | Melihat semua pasien yang terdaftar dalam format tabel                                                               |
| **Cari Pasien**             | Mencari pasien berdasarkan ID atau nama                                                                              |

### 2️⃣ **Manajemen Dokter**

| Fitur                       | Deskripsi                                                               |
| --------------------------- | ----------------------------------------------------------------------- |
| **Tambah Dokter**           | Menambahkan dokter baru dengan informasi spesialisasi dan nomor lisensi |
| **Update Data Dokter**      | Mengubah informasi dokter termasuk jadwal praktik                       |
| **Hapus Dokter**            | Menghapus data dokter dari sistem                                       |
| **Tampilkan Daftar Dokter** | Melihat semua dokter berdasarkan spesialisasi                           |
| **Cari Dokter**             | Mencari dokter berdasarkan ID atau spesialisasi                         |

### 3️⃣ **Manajemen Appointment**

| Fitur                  | Deskripsi                                                     |
| ---------------------- | ------------------------------------------------------------- |
| **Buat Appointment**   | Membuat jadwal kunjungan pasien dengan dokter tertentu        |
| **Update Status**      | Mengubah status appointment (Scheduled, Completed, Cancelled) |
| **Hapus Appointment**  | Membatalkan dan menghapus appointment                         |
| **Tampilkan Jadwal**   | Melihat semua appointment yang terjadwal                      |
| **Filter Appointment** | Filter berdasarkan tanggal, dokter, atau pasien tertentu      |

### 4️⃣ **Rekam Medis**

| Fitur                  | Deskripsi                                     |
| ---------------------- | --------------------------------------------- |
| **Catat Diagnosis**    | Mencatat diagnosis dan treatment untuk pasien |
| **Riwayat Medis**      | Melihat seluruh riwayat medis pasien          |
| **Update Rekam Medis** | Mengubah catatan diagnosis atau treatment     |
| **Export Laporan**     | Generate laporan medis dalam format text      |

### 5️⃣ **File Management**

| Fitur              | Deskripsi                                                               |
| ------------------ | ----------------------------------------------------------------------- |
| **Auto-Load Data** | Otomatis membaca dan memuat data dari `input.txt` saat aplikasi dimulai |
| **Auto-Save Data** | Otomatis menyimpan perubahan ke `output.txt` saat aplikasi ditutup      |
| **Export Report**  | Generate laporan statistik ke file `report.txt`                         |

## ⚙️ Teknologi yang Digunakan

- **Bahasa Pemrograman**: C++ (Standard C++11)
- **Compiler**: g++ 15.1.0 atau lebih tinggi (MinGW/MSYS2 untuk Windows, GCC untuk Linux)
- **Paradigma**: Object-Oriented Programming (OOP)
- **Interface**: Command Line Interface (CLI)
- **Storage**: Text File (pipe-delimited format)
- **Build Tools**:
  - Make (Makefile untuk Unix/Linux)
  - PowerShell Script (build.ps1 untuk Windows)
  - Bash Script (build.sh untuk Linux/Mac)
- **Version Control**: Git
- **Development Environment**: Visual Studio Code / Code::Blocks / CLion

## ⚒️ Instalasi dan Cara Build

### Prasyarat

Pastikan Anda telah menginstall:

- **Windows**: MinGW-w64 atau MSYS2 dengan g++ compiler
- **Linux**: GCC/g++ (install dengan `sudo apt install g++ make`)
- **macOS**: Xcode Command Line Tools (install dengan `xcode-select --install`)

### 1. Clone Repository

```bash
git clone <repository-url>
cd "Clinic Management CLI App"
```

### 2. Build Aplikasi

#### **Opsi A: Menggunakan Makefile (Linux/Mac/Windows dengan Make)**

```bash
make
```

Output akan menghasilkan file executable `Klinik.exe` (Windows) atau `Klinik` (Linux/Mac).

#### **Opsi B: Menggunakan Build Script Windows (PowerShell)**

```powershell
.\build.ps1
```

Atau jika terkena execution policy error:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1
```

#### **Opsi C: Menggunakan Build Script Linux/Mac (Bash)**

```bash
chmod +x build.sh
./build.sh
```

#### **Opsi D: Manual Compilation**

**Windows:**

```bash
g++ -I include -o Klinik.exe src/*.cpp -std=c++11 -Wall
```

**Linux/Mac:**

```bash
g++ -I include -o Klinik src/*.cpp -std=c++11 -Wall
```

### 3. Verifikasi Build

Setelah build sukses, Anda akan melihat:

- File executable `Klinik.exe` (Windows) atau `Klinik` (Linux/Mac)
- Ukuran file sekitar 400-500 KB
- Tidak ada error atau warning saat kompilasi

### 4. Jalankan Aplikasi

**Windows:**

```powershell
.\Klinik.exe
```

**Linux/Mac:**

```bash
./Klinik
```

### 5. Clean Build Files (Opsional)

Untuk menghapus file executable dan object files:

```bash
make clean
```

Atau manual:

- **Windows**: `del Klinik.exe`
- **Linux/Mac**: `rm Klinik`

## 🚀 Cara Menggunakan Aplikasi

1. **Jalankan Aplikasi**: Eksekusi file `Klinik.exe` atau `./Klinik`
2. **Menu Utama**: Anda akan melihat menu dengan 6 pilihan
3. **Pilih Menu**: Masukkan nomor menu (1-6)
4. **Input Data**: Ikuti instruksi untuk input data yang diminta
5. **Lihat Data**: Data akan otomatis dimuat dari `data/input.txt` saat pertama kali aplikasi berjalan
6. **Auto-Save**: Semua perubahan otomatis tersimpan ke `data/output.txt` saat aplikasi ditutup

### Contoh Penggunaan

```
=== CLINIC MANAGEMENT SYSTEM ===
1. Manage Patients
2. Manage Doctors
3. Manage Appointments
4. Manage Medical Records
5. Display Statistics
6. Exit

Enter your choice: 1

=== PATIENT MANAGEMENT ===
1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Back to Main Menu

Enter your choice: 2

[Data pasien akan ditampilkan...]
```

## 🧠 Prinsip OOP yang Diterapkan

| Prinsip           | Implementasi                                                                                   | Contoh                                                                                                                                                             |
| ----------------- | ---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Encapsulation** | Data dan method dijadikan satu dalam class dengan access modifier (private, public, protected) | Class `Patient` memiliki private attributes (`bloodType`, `dateOfBirth`) dan public methods (`getBloodType()`, `setBloodType()`)                                   |
| **Inheritance**   | Class turunan mewarisi properties dan methods dari class induk                                 | `Patient` dan `Doctor` mewarisi dari class `Person` (ID, name, phone, address)                                                                                     |
| **Polymorphism**  | Virtual function untuk behavior yang berbeda pada derived class                                | Virtual function `displayInfo()` di class `Person` yang di-override oleh `Patient` dan `Doctor`                                                                    |
| **Abstraction**   | Interface sederhana yang menyembunyikan kompleksitas implementasi                              | Class `ClinicManager` menyediakan interface sederhana untuk operasi kompleks seperti `addPatient()`, `searchDoctor()` tanpa user perlu tahu detail implementasinya |

## 📄 Format Data File

### Input/Output File Format (Pipe-Delimited)

**PATIENT:**

```
PATIENT|P001|John Doe|081234567890|123 Main St|1990-01-15|Male|O+
```

**DOCTOR:**

```
DOCTOR|D001|Dr. Smith|081298765432|456 Oak Ave|Cardiology|LIC123456|Mon-Fri 09:00-17:00
```

**APPOINTMENT:**

```
APPOINTMENT|A001|P001|D001|2024-12-20|09:00|Scheduled|Regular checkup
```

**MEDICALRECORD:**

```
MEDICALRECORD|MR001|A001|Hypertension|Medication: Amlodipine 5mg|2024-12-20
```

## 🔧 Troubleshooting

### Error: "g++ command not found"

**Solusi**: Install MinGW/MSYS2 (Windows) atau GCC (Linux/Mac)

### Error: "No such file or directory: input.txt"

**Solusi**: Pastikan file `data/input.txt` ada di folder `data/`

### Error: "Permission denied"

**Solusi Linux/Mac**: Jalankan `chmod +x Klinik` untuk memberikan permission execute

### Error: Compilation failed with include errors

**Solusi**: Pastikan flag `-I include` digunakan saat compile

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2025 Kistosi Al Ghifari, Fahmi Irfan Faiz, Kalya Naura Farabias

---

**Dikembangkan sebagai proyek mata kuliah Pemrograman Dasar**  
Departemen Teknik Elektro dan Teknologi Informasi, Universitas Gadjah Mada  
© 2025
