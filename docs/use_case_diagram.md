# Use Case Diagram - Aplikasi Manajemen Klinik

## Actors

1. **Admin Klinik**: Staff yang mengelola seluruh sistem
2. **Dokter**: Dapat melihat jadwal dan mengelola rekam medis
3. **Resepsionis**: Mengelola pendaftaran pasien dan appointment

## Use Cases

### UC-01: Manajemen Pasien

**Actor**: Admin, Resepsionis
**Description**: Mengelola data pasien klinik
**Flow**:

1. Pilih menu Manajemen Pasien
2. Pilih aksi: Tambah/Edit/Hapus/Lihat/Cari
3. Input data yang diperlukan
4. Sistem menyimpan perubahan

**Sub Use Cases**:

- UC-01.1: Registrasi Pasien Baru
- UC-01.2: Update Data Pasien
- UC-01.3: Hapus Data Pasien
- UC-01.4: Tampilkan Daftar Pasien
- UC-01.5: Cari Pasien

### UC-02: Manajemen Dokter

**Actor**: Admin
**Description**: Mengelola informasi dokter
**Flow**:

1. Pilih menu Manajemen Dokter
2. Pilih aksi: Tambah/Edit/Hapus/Lihat/Cari
3. Input data dokter (nama, spesialisasi, jadwal)
4. Sistem menyimpan data

**Sub Use Cases**:

- UC-02.1: Tambah Dokter Baru
- UC-02.2: Update Informasi Dokter
- UC-02.3: Hapus Data Dokter
- UC-02.4: Lihat Daftar Dokter
- UC-02.5: Filter Dokter by Spesialisasi

### UC-03: Manajemen Appointment

**Actor**: Admin, Resepsionis
**Description**: Mengelola jadwal kunjungan pasien
**Flow**:

1. Pilih menu Appointment
2. Pilih aksi: Buat/Edit/Hapus/Lihat
3. Pilih pasien dan dokter
4. Tentukan tanggal dan waktu
5. Sistem validasi dan simpan appointment

**Sub Use Cases**:

- UC-03.1: Buat Appointment Baru
- UC-03.2: Update Status Appointment
- UC-03.3: Cancel Appointment
- UC-03.4: Lihat Jadwal Appointment
- UC-03.5: Filter Appointment by Tanggal/Dokter

### UC-04: Manajemen Rekam Medis

**Actor**: Dokter, Admin
**Description**: Mencatat dan melihat riwayat medis pasien
**Flow**:

1. Pilih pasien
2. Tambah/Lihat rekam medis
3. Input diagnosis dan treatment
4. Sistem menyimpan rekam medis

**Sub Use Cases**:

- UC-04.1: Tambah Rekam Medis Baru
- UC-04.2: Update Rekam Medis
- UC-04.3: Lihat Riwayat Medis Pasien

### UC-05: File Management

**Actor**: System
**Description**: Load dan save data
**Flow**:

1. Saat aplikasi start, load data dari input.txt
2. Setiap perubahan data, auto-save ke output.txt
3. Export laporan jika diperlukan

**Sub Use Cases**:

- UC-05.1: Load Data dari File
- UC-05.2: Save Data ke File
- UC-05.3: Export Laporan

## Use Case Diagram (Text Representation)

```
                    +-------------------+
                    |   Admin Klinik    |
                    +-------------------+
                            |
        +-------------------+-------------------+
        |                   |                   |
        v                   v                   v
[Manajemen Pasien]  [Manajemen Dokter]  [File Management]
        |                   |
        |                   +-------------------+
        |                                       |
        +-------------------+                   |
                            |                   |
                    +-------------------+       |
                    |   Resepsionis     |       |
                    +-------------------+       |
                            |                   |
        +-------------------+                   |
        |                   |                   |
        v                   v                   v
[Manajemen Pasien]  [Manajemen Appointment] [File Management]


                    +-------------------+
                    |      Dokter       |
                    +-------------------+
                            |
        +-------------------+-------------------+
        |                                       |
        v                                       v
[Lihat Jadwal Appointment]          [Manajemen Rekam Medis]
```

## Relationships

- **Include**: UC-03 (Appointment) includes UC-01 (Cari Pasien) dan UC-02 (Cari Dokter)
- **Extend**: UC-04 (Rekam Medis) extends UC-03 (Appointment) - setelah appointment selesai
- **Generalization**: Sub use cases adalah spesialisasi dari use case utama

## Business Rules

1. Satu pasien bisa memiliki multiple appointments
2. Satu dokter bisa menangani multiple appointments
3. Appointment harus memiliki pasien dan dokter yang valid
4. Rekam medis harus terkait dengan appointment yang completed
5. Tidak boleh ada double booking untuk dokter di waktu yang sama
