# Aplikasi Manajemen Klinik

## Deskripsi Proyek

Aplikasi Manajemen Klinik adalah sistem berbasis CLI (Command Line Interface) untuk mengelola data pasien, dokter, jadwal appointment, dan rekam medis di klinik kesehatan.

## Permasalahan dan Kebutuhan

### Permasalahan

1. **Pengelolaan Data Manual**: Klinik masih menggunakan pencatatan manual yang rawan kesalahan
2. **Kesulitan Pencarian**: Sulit mencari riwayat pasien atau jadwal dokter dengan cepat
3. **Tidak Terintegrasi**: Data pasien, dokter, dan appointment terpisah-pisah
4. **Risiko Kehilangan Data**: Data dalam bentuk kertas mudah hilang atau rusak

### Kebutuhan Aplikasi

1. **Manajemen Pasien**: Menambah, edit, hapus, dan menampilkan data pasien
2. **Manajemen Dokter**: Mengelola informasi dokter dan spesialisasi
3. **Manajemen Appointment**: Penjadwalan kunjungan pasien dengan dokter
4. **Rekam Medis**: Mencatat diagnosis dan treatment pasien
5. **Persistensi Data**: Load dan save data dari/ke file
6. **Navigasi Mudah**: Interface yang user-friendly

## Fitur Utama

### 1. Manajemen Pasien

- Registrasi pasien baru
- Update informasi pasien
- Hapus data pasien
- Tampilkan daftar pasien
- Cari pasien berdasarkan ID atau nama

### 2. Manajemen Dokter

- Tambah dokter baru
- Update informasi dokter
- Hapus data dokter
- Tampilkan daftar dokter berdasarkan spesialisasi
- Cari dokter berdasarkan ID

### 3. Manajemen Appointment

- Buat appointment baru
- Update status appointment (scheduled, completed, cancelled)
- Hapus appointment
- Tampilkan jadwal appointment
- Filter appointment berdasarkan tanggal/dokter/pasien

### 4. Rekam Medis

- Catat diagnosis dan treatment
- Tampilkan riwayat medis pasien
- Update rekam medis

### 5. File Management

- Load data dari input.txt saat aplikasi dimulai
- Auto-save perubahan ke output.txt
- Export laporan

## Teknologi

- **Bahasa**: C++ (C++11 atau lebih tinggi)
- **Paradigma**: Object-Oriented Programming (OOP)
- **Interface**: Command Line Interface (CLI)
- **Storage**: Text file (input.txt, output.txt)

## Struktur Proyek

```
Proyek/
├── include/
│   ├── Person.h
│   ├── Patient.h
│   ├── Doctor.h
│   ├── Appointment.h
│   ├── MedicalRecord.h
│   ├── ClinicManager.h
│   └── FileHandler.h
├── src/
│   ├── Person.cpp
│   ├── Patient.cpp
│   ├── Doctor.cpp
│   ├── Appointment.cpp
│   ├── MedicalRecord.cpp
│   ├── ClinicManager.cpp
│   ├── FileHandler.cpp
│   └── main.cpp
├── data/
│   ├── input.txt
│   └── output.txt
├── docs/
│   ├── use_case_diagram.md
│   ├── class_diagram.md
│   └── laporan.md
└── README.md
```

## Cara Kompilasi dan Menjalankan

### Windows (MinGW/g++)

```bash
g++ -I include -o Klinik.exe src/*.cpp -std=c++11
Klinik.exe
```

### Linux/Mac

```bash
g++ -I include -o Klinik src/*.cpp -std=c++11
./Klinik
```

## Prinsip OOP yang Diterapkan

1. **Encapsulation**: Data dan method dijadikan satu dalam class dengan access modifier (private, public, protected)
2. **Inheritance**: Class Patient dan Doctor mewarisi dari class Person
3. **Polymorphism**: Virtual function untuk behavior yang berbeda pada derived class
4. **Abstraction**: Interface yang sederhana menyembunyikan kompleksitas implementasi

## License

Academic Project - For Educational Purpose Only
