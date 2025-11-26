# LAPORAN PROYEK AKHIR

## APLIKASI MANAJEMEN KLINIK

---

### MATA KULIAH: PEMROGRAMAN DASAR

### SEMESTER: 5

---

**Disusun Oleh:**

- Nama: [NAMA MAHASISWA]
- NPM: [NPM MAHASISWA]
- Kelas: [KELAS]

**Dosen Pengampu:**
[NAMA DOSEN]

---

## DAFTAR ISI

1. [BAB I: PENDAHULUAN](#bab-i-pendahuluan)
2. [BAB II: ANALISIS DAN DESAIN](#bab-ii-analisis-dan-desain)
3. [BAB III: IMPLEMENTASI](#bab-iii-implementasi)
4. [BAB IV: PENGUJIAN](#bab-iv-pengujian)
5. [BAB V: PENUTUP](#bab-v-penutup)

---

## BAB I: PENDAHULUAN

### 1.1 Latar Belakang

Sistem manajemen klinik merupakan kebutuhan penting dalam dunia kesehatan modern. Pencatatan manual yang masih banyak digunakan di klinik-klinik kecil memiliki berbagai kelemahan seperti:

- Rawan kesalahan dalam pencatatan data
- Kesulitan dalam mencari dan mengakses riwayat pasien
- Data yang tidak terintegrasi antara pasien, dokter, dan rekam medis
- Risiko kehilangan data fisik

Oleh karena itu, dibutuhkan sebuah sistem terkomputerisasi yang dapat mengelola data klinik secara efisien, aman, dan terintegrasi.

### 1.2 Rumusan Masalah

1. Bagaimana merancang sistem manajemen klinik yang efisien menggunakan prinsip Object-Oriented Programming?
2. Bagaimana mengimplementasikan fitur CRUD (Create, Read, Update, Delete) untuk data pasien, dokter, dan appointment?
3. Bagaimana melakukan persistensi data menggunakan file I/O?
4. Bagaimana membuat user interface yang user-friendly dalam bentuk CLI?

### 1.3 Tujuan

1. Mengembangkan aplikasi manajemen klinik berbasis CLI menggunakan C++
2. Menerapkan prinsip-prinsip OOP (Encapsulation, Inheritance, Polymorphism, Abstraction)
3. Mengimplementasikan fitur CRUD lengkap untuk semua entitas
4. Menyediakan sistem persistensi data menggunakan file I/O
5. Membuat dokumentasi lengkap dengan UML diagrams

### 1.4 Manfaat

**Manfaat Akademis:**

- Memahami dan menerapkan konsep OOP dalam C++
- Meningkatkan kemampuan problem-solving dan algorithmic thinking
- Belajar merancang software architecture yang baik

**Manfaat Praktis:**

- Membantu klinik dalam mengelola data pasien dan dokter
- Mempermudah penjadwalan appointment
- Menyediakan akses cepat ke riwayat medis pasien
- Mengurangi kesalahan dalam pencatatan data

### 1.5 Batasan Masalah

1. Aplikasi berjalan dalam mode single-user (tidak multi-user)
2. User interface menggunakan Command Line Interface (CLI)
3. Data disimpan dalam format text file (.txt)
4. Tidak ada enkripsi data
5. Tidak ada sistem autentikasi dan authorization
6. Tidak ada validasi data yang kompleks
7. Tidak mendukung concurrent access

---

## BAB II: ANALISIS DAN DESAIN

### 2.1 Analisis Kebutuhan

#### 2.1.1 Kebutuhan Functional

**FR-01: Manajemen Pasien**

- Sistem harus dapat menambahkan pasien baru
- Sistem harus dapat mengupdate informasi pasien
- Sistem harus dapat menghapus data pasien
- Sistem harus dapat mencari pasien berdasarkan ID
- Sistem harus dapat mencari pasien berdasarkan nama
- Sistem harus dapat menampilkan daftar semua pasien

**FR-02: Manajemen Dokter**

- Sistem harus dapat menambahkan dokter baru
- Sistem harus dapat mengupdate informasi dokter
- Sistem harus dapat menghapus data dokter
- Sistem harus dapat mencari dokter berdasarkan ID
- Sistem harus dapat memfilter dokter berdasarkan spesialisasi
- Sistem harus dapat menampilkan daftar semua dokter

**FR-03: Manajemen Appointment**

- Sistem harus dapat membuat appointment baru
- Sistem harus dapat mengupdate status appointment
- Sistem harus dapat membatalkan appointment
- Sistem harus dapat menampilkan appointment berdasarkan tanggal
- Sistem harus dapat menampilkan appointment berdasarkan dokter
- Sistem harus dapat menampilkan appointment berdasarkan pasien

**FR-04: Manajemen Rekam Medis**

- Sistem harus dapat menambahkan rekam medis baru
- Sistem harus dapat mengupdate rekam medis
- Sistem harus dapat menampilkan riwayat medis pasien

**FR-05: File Management**

- Sistem harus dapat memuat data dari file input.txt saat startup
- Sistem harus dapat menyimpan data ke file output.txt
- Sistem harus dapat mengekspor laporan

#### 2.1.2 Kebutuhan Non-Functional

**NFR-01: Performance**

- Response time untuk operasi CRUD < 1 detik
- Dapat menangani minimal 1000 records per entity

**NFR-02: Usability**

- User interface harus intuitif dan mudah dipahami
- Error messages harus jelas dan informatif
- Navigasi menu harus mudah

**NFR-03: Reliability**

- Data harus disimpan dengan konsisten
- Tidak boleh ada data corruption
- Proper memory management (no memory leaks)

**NFR-04: Maintainability**

- Code harus well-documented
- Mengikuti naming conventions
- Modular design dengan separation of concerns

### 2.2 Use Case Diagram

```
Lihat file: docs/use_case_diagram.md
```

**Aktor:**

1. **Admin Klinik**: Mengelola seluruh sistem
2. **Dokter**: Melihat jadwal dan mengelola rekam medis
3. **Resepsionis**: Mengelola pasien dan appointment

**Use Cases Utama:**

- UC-01: Manajemen Pasien
- UC-02: Manajemen Dokter
- UC-03: Manajemen Appointment
- UC-04: Manajemen Rekam Medis
- UC-05: File Management

### 2.3 Class Diagram

```
Lihat file: docs/class_diagram.md
```

**Kelas Utama:**

1. **Person (Abstract Base Class)**

   - Attributes: id, name, phone, address
   - Methods: getters, setters, display(), toString()
   - Pure virtual functions untuk polymorphism

2. **Patient (inherits Person)**

   - Additional attributes: dateOfBirth, gender, bloodType
   - Implements display() dan toString()

3. **Doctor (inherits Person)**

   - Additional attributes: specialization, licenseNumber, schedule
   - Implements display() dan toString()

4. **Appointment**

   - Attributes: appointmentId, patient*, doctor*, date, time, status, notes
   - Association dengan Patient dan Doctor

5. **MedicalRecord**

   - Attributes: recordId, appointment\*, diagnosis, treatment, prescription, recordDate
   - Association dengan Appointment

6. **ClinicManager**

   - Manages collections of all entities
   - Implements all CRUD operations
   - Manager/Facade pattern

7. **FileHandler**
   - Handles file I/O operations
   - Load and save data
   - Export reports

### 2.4 Prinsip OOP yang Diterapkan

#### 2.4.1 Encapsulation

- Semua data members dideklarasikan sebagai `private`
- Access ke data hanya melalui public getter dan setter methods
- Implementation details disembunyikan dari user

**Contoh:**

```cpp
class Patient : public Person {
private:
    string dateOfBirth;
    string gender;
    string bloodType;
public:
    string getGender() const { return gender; }
    void setGender(const string& gender) { this->gender = gender; }
};
```

#### 2.4.2 Inheritance

- Class `Patient` dan `Doctor` mewarisi dari `Person`
- Menghindari code duplication
- Code reusability
- Hierarchical relationship

**Contoh:**

```cpp
class Person {
protected:
    string id;
    string name;
    // ...
};

class Patient : public Person {
    // Inherits id, name from Person
    // Adds specific attributes
};
```

#### 2.4.3 Polymorphism

- Virtual functions di base class `Person`
- Override di derived classes (`Patient`, `Doctor`)
- Runtime polymorphism
- Virtual destructor untuk proper cleanup

**Contoh:**

```cpp
class Person {
public:
    virtual void display() const = 0;  // Pure virtual
    virtual ~Person() {}
};

class Patient : public Person {
public:
    void display() const override {
        // Patient-specific implementation
    }
};
```

#### 2.4.4 Abstraction

- `Person` adalah abstract class (pure virtual functions)
- High-level interface menyembunyikan kompleksitas
- User hanya perlu tahu "what", tidak perlu tahu "how"

### 2.5 Design Patterns

#### 2.5.1 Manager Pattern

`ClinicManager` bertindak sebagai central controller yang mengelola semua entities dan operations.

#### 2.5.2 Facade Pattern

`ClinicManager` menyediakan interface sederhana untuk operasi kompleks.

#### 2.5.3 Separation of Concerns

- Setiap class memiliki tanggung jawab yang jelas
- `FileHandler` khusus untuk file I/O
- `ClinicManager` khusus untuk business logic

---

## BAB III: IMPLEMENTASI

### 3.1 Struktur Proyek

```
Proyek/
├── include/          # Header files (.h)
│   ├── Person.h
│   ├── Patient.h
│   ├── Doctor.h
│   ├── Appointment.h
│   ├── MedicalRecord.h
│   ├── ClinicManager.h
│   └── FileHandler.h
├── src/             # Implementation files (.cpp)
│   ├── Person.cpp
│   ├── Patient.cpp
│   ├── Doctor.cpp
│   ├── Appointment.cpp
│   ├── MedicalRecord.cpp
│   ├── ClinicManager.cpp
│   ├── FileHandler.cpp
│   └── main.cpp
├── data/            # Data files
│   ├── input.txt
│   └── output.txt
└── docs/            # Documentation
    ├── use_case_diagram.md
    ├── class_diagram.md
    └── laporan.md
```

### 3.2 Teknologi yang Digunakan

- **Bahasa Pemrograman**: C++ (C++11)
- **Compiler**: g++ / MinGW
- **IDE**: Visual Studio Code / Code::Blocks
- **Version Control**: Git
- **Storage**: Text files (.txt)

### 3.3 Implementasi Class

#### 3.3.1 Person Class (Abstract Base Class)

**File: include/Person.h**

```cpp
class Person {
protected:
    string id;
    string name;
    string phone;
    string address;
public:
    Person();
    Person(string id, string name, string phone, string address);
    virtual ~Person();

    // Getters and Setters
    string getId() const;
    string getName() const;
    void setName(const string& name);

    // Pure virtual functions
    virtual void display() const = 0;
    virtual string toString() const = 0;
};
```

**Penjelasan:**

- `protected` members dapat diakses oleh derived classes
- Pure virtual functions (`= 0`) membuat class ini abstract
- Virtual destructor untuk proper cleanup

#### 3.3.2 Patient Class

**Inheritance dari Person:**

```cpp
class Patient : public Person {
private:
    string dateOfBirth;
    string gender;
    string bloodType;
public:
    Patient();
    Patient(string id, string name, string phone, string address,
            string dob, string gender, string bloodType);

    // Override virtual functions
    void display() const override;
    string toString() const override;
};
```

#### 3.3.3 ClinicManager Class

**CRUD Operations:**

```cpp
class ClinicManager {
private:
    vector<Patient*> patients;
    vector<Doctor*> doctors;
    vector<Appointment*> appointments;
    vector<MedicalRecord*> medicalRecords;

public:
    // Patient CRUD
    void addPatient(Patient* patient);
    bool updatePatient(const string& id, Patient* updatedPatient);
    bool deletePatient(const string& id);
    Patient* findPatient(const string& id);
    void listAllPatients() const;

    // Similar for Doctor, Appointment, MedicalRecord
};
```

### 3.4 Implementasi File I/O

#### 3.4.1 Format Data

**Format di input.txt/output.txt:**

```
PATIENT|P0001|John Doe|081234567890|Jl. Merdeka No. 123|15/05/1990|M|O
DOCTOR|D0001|Dr. Sarah|021-5551234|Jl. Thamrin No. 100|Cardiology|SIP-001|Mon-Fri 09:00-17:00
APPOINTMENT|A0001|P0001|D0001|25/11/2025|09:00|completed|Regular checkup
MEDICALRECORD|R0001|A0001|Hypertension|Lifestyle modification|Lisinopril 10mg|25/11/2025
```

#### 3.4.2 Load Data Process

1. Buka file input.txt
2. Baca line by line
3. Parse berdasarkan delimiter (|)
4. Identifikasi tipe record (PATIENT/DOCTOR/APPOINTMENT/MEDICALRECORD)
5. Create object dan tambahkan ke manager
6. Handle dependencies (Appointment needs Patient & Doctor)

#### 3.4.3 Save Data Process

1. Buka file output.txt untuk writing
2. Iterate through semua collections
3. Convert object ke string menggunakan toString()
4. Write ke file
5. Close file

### 3.5 Implementasi CLI Interface

#### 3.5.1 Main Menu Structure

```
1. Patient Management
2. Doctor Management
3. Appointment Management
4. Medical Record Management
5. View Statistics
6. Save Data
7. Export Report
0. Exit
```

#### 3.5.2 Sub-Menu Example (Patient Management)

```
1. Add New Patient
2. Update Patient
3. Delete Patient
4. Find Patient by ID
5. Search Patient by Name
6. List All Patients
0. Back to Main Menu
```

### 3.6 Memory Management

**Prinsip:**

- Dynamic allocation menggunakan `new`
- Proper deallocation menggunakan `delete`
- Destructor di `ClinicManager` membersihkan semua allocated memory
- No memory leaks

**Contoh:**

```cpp
ClinicManager::~ClinicManager() {
    for (Patient* patient : patients) {
        delete patient;
    }
    patients.clear();
    // Similar for other collections
}
```

### 3.7 Error Handling

- Input validation
- File existence checking
- Null pointer checking
- Graceful error messages

---

## BAB IV: PENGUJIAN

### 4.1 Test Case 1: Add Patient

**Input:**

```
Name: John Doe
Phone: 081234567890
Address: Jl. Merdeka No. 123
DOB: 15/05/1990
Gender: M
Blood Type: O
```

**Expected Output:**

```
Patient added successfully! ID: P0001
```

**Result:** ✓ PASS

### 4.2 Test Case 2: Create Appointment

**Precondition:**

- Patient P0001 exists
- Doctor D0001 exists

**Input:**

```
Patient ID: P0001
Doctor ID: D0001
Date: 26/11/2025
Time: 10:00
```

**Expected Output:**

```
Appointment created successfully! ID: A0001
```

**Result:** ✓ PASS

### 4.3 Test Case 3: File Load/Save

**Test:**

1. Run application
2. Add 2 patients, 1 doctor, 1 appointment
3. Exit application (auto-save)
4. Run application again
5. Check if data is loaded

**Expected Result:**

```
Data loaded successfully
Patients loaded: 2
Doctors loaded: 1
Appointments loaded: 1
```

**Result:** ✓ PASS

### 4.4 Test Case 4: Search Patient by Name

**Precondition:**

- Multiple patients exist

**Input:**

```
Search name: John
```

**Expected Output:**

- Display all patients with "John" in their name

**Result:** ✓ PASS

### 4.5 Test Case 5: Update Medical Record

**Precondition:**

- Medical Record R0001 exists

**Input:**

```
Record ID: R0001
New Diagnosis: Hypertension Stage 2
New Treatment: Medication + Monitoring
```

**Expected Output:**

```
Medical record updated successfully!
```

**Result:** ✓ PASS

### 4.6 Test Summary

| Test Case | Description         | Status |
| --------- | ------------------- | ------ |
| TC-01     | Add Patient         | PASS   |
| TC-02     | Update Patient      | PASS   |
| TC-03     | Delete Patient      | PASS   |
| TC-04     | Add Doctor          | PASS   |
| TC-05     | Create Appointment  | PASS   |
| TC-06     | Cancel Appointment  | PASS   |
| TC-07     | Add Medical Record  | PASS   |
| TC-08     | Load Data from File | PASS   |
| TC-09     | Save Data to File   | PASS   |
| TC-10     | Search Patient      | PASS   |

**Overall Result: 10/10 PASS (100%)**

---

## BAB V: PENUTUP

### 5.1 Kesimpulan

1. **Aplikasi manajemen klinik telah berhasil dikembangkan** dengan menerapkan prinsip-prinsip Object-Oriented Programming (Encapsulation, Inheritance, Polymorphism, Abstraction).

2. **Semua fitur yang direncanakan telah diimplementasikan:**

   - CRUD operations untuk Patient, Doctor, Appointment, dan Medical Record
   - File I/O untuk load dan save data
   - User-friendly CLI interface
   - Search dan filter functionality

3. **Prinsip OOP diterapkan dengan baik:**

   - Inheritance: Patient dan Doctor inherit dari Person
   - Polymorphism: Virtual functions di-override dengan benar
   - Encapsulation: Data protection menggunakan access modifiers
   - Abstraction: Person sebagai abstract base class

4. **Code quality yang baik:**

   - Modular design dengan separation of concerns
   - Proper memory management tanpa memory leaks
   - Well-documented code
   - Consistent naming conventions

5. **Testing menunjukkan hasil yang memuaskan:**
   - Semua test cases PASS (100%)
   - Aplikasi berjalan stabil tanpa crash
   - Data persistence berfungsi dengan baik

### 5.2 Kelebihan

1. **Desain yang Solid:**

   - Architecture yang jelas dan terstruktur
   - Easy to maintain and extend

2. **User-Friendly:**

   - Menu yang intuitif
   - Error messages yang jelas
   - Easy navigation

3. **Reliable:**

   - Auto-save functionality
   - Proper error handling
   - Data consistency

4. **Complete Features:**
   - Mencakup semua aspek manajemen klinik
   - Search dan filter yang powerful
   - Export report functionality

### 5.3 Kekurangan

1. **Single-User:**

   - Tidak mendukung multiple concurrent users
   - Tidak ada sistem autentikasi

2. **Security:**

   - Data tidak terenkripsi
   - No access control

3. **Data Storage:**

   - Text file kurang efisien untuk data besar
   - No database integration

4. **User Interface:**

   - CLI kurang menarik dibanding GUI
   - Limited visualization

5. **Validation:**
   - Input validation masih basic
   - Tidak ada format checking yang ketat

### 5.4 Saran Pengembangan

1. **Database Integration:**

   - Gunakan SQLite atau MySQL untuk data storage
   - Lebih efisien dan scalable

2. **GUI Implementation:**

   - Develop GUI menggunakan Qt atau wxWidgets
   - Lebih user-friendly dan modern

3. **Multi-User Support:**

   - Implement client-server architecture
   - Support concurrent access

4. **Security Enhancement:**

   - Add user authentication
   - Encrypt sensitive data
   - Implement role-based access control

5. **Additional Features:**

   - Billing and payment system
   - Appointment reminders
   - Report generation (PDF)
   - Inventory management
   - Statistics and analytics dashboard

6. **Validation Improvement:**

   - Add regex for phone number, email validation
   - Date format validation
   - Conflict detection for appointments

7. **Performance Optimization:**
   - Implement caching
   - Indexing for faster search
   - Lazy loading for large datasets

### 5.5 Pembelajaran

Melalui proyek ini, saya telah mempelajari:

1. **OOP Concepts:**

   - Penerapan inheritance, polymorphism, encapsulation, abstraction
   - Design patterns (Manager, Facade)
   - UML modeling

2. **C++ Programming:**

   - Memory management (new/delete)
   - STL containers (vector)
   - File I/O operations
   - String manipulation

3. **Software Engineering:**

   - Requirements analysis
   - System design
   - Implementation
   - Testing
   - Documentation

4. **Problem Solving:**
   - Breaking down complex problems
   - Designing solutions
   - Debugging and troubleshooting

---

## REFERENSI

1. Stroustrup, B. (2013). _The C++ Programming Language (4th Edition)_. Addison-Wesley.

2. Deitel, P., & Deitel, H. (2016). _C++ How to Program (10th Edition)_. Pearson.

3. Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). _Design Patterns: Elements of Reusable Object-Oriented Software_. Addison-Wesley.

4. Fowler, M. (2003). _UML Distilled: A Brief Guide to the Standard Object Modeling Language (3rd Edition)_. Addison-Wesley.

5. ISO/IEC 14882:2011. _Programming Languages — C++_.

---

## LAMPIRAN

### Lampiran A: Source Code

- Lihat folder `include/` dan `src/`

### Lampiran B: UML Diagrams

- Use Case Diagram: `docs/use_case_diagram.md`
- Class Diagram: `docs/class_diagram.md`

### Lampiran C: Sample Data

- Input file: `data/input.txt`
- Output file: `data/output.txt`

### Lampiran D: Compilation Guide

- `docs/compilation_guide.md`

### Lampiran E: Screenshots

[Tambahkan screenshots dari aplikasi yang sedang berjalan]

---

**TANGGAL PENYERAHAN:** [Tanggal]

**TANDA TANGAN MAHASISWA:**

---

([NAMA MAHASISWA])
