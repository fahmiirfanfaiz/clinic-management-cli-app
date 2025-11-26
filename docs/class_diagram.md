# Class Diagram - Aplikasi Manajemen Klinik

## Class Diagram (UML)

```
┌─────────────────────────────────────┐
│            <<abstract>>             │
│              Person                 │
├─────────────────────────────────────┤
│ - id: string                        │
│ - name: string                      │
│ - phone: string                     │
│ - address: string                   │
├─────────────────────────────────────┤
│ + Person()                          │
│ + Person(id, name, phone, address)  │
│ + virtual ~Person()                 │
│ + getId(): string                   │
│ + getName(): string                 │
│ + getPhone(): string                │
│ + getAddress(): string              │
│ + setName(name): void               │
│ + setPhone(phone): void             │
│ + setAddress(address): void         │
│ + virtual display(): void = 0       │
│ + virtual toString(): string = 0    │
└─────────────────────────────────────┘
            △                 △
            │                 │
            │                 │
   ┌────────┘                 └────────┐
   │                                   │
┌──────────────────────────┐  ┌───────────────────────────┐
│       Patient            │  │         Doctor            │
├──────────────────────────┤  ├───────────────────────────┤
│ - dateOfBirth: string    │  │ - specialization: string  │
│ - gender: string         │  │ - licenseNumber: string   │
│ - bloodType: string      │  │ - schedule: string        │
├──────────────────────────┤  ├───────────────────────────┤
│ + Patient()              │  │ + Doctor()                │
│ + Patient(...)           │  │ + Doctor(...)             │
│ + ~Patient()             │  │ + ~Doctor()               │
│ + getDateOfBirth(): str  │  │ + getSpecialization(): str│
│ + getGender(): string    │  │ + getLicenseNumber(): str │
│ + getBloodType(): string │  │ + getSchedule(): string   │
│ + setDateOfBirth(): void │  │ + setSpecialization(): void│
│ + setGender(): void      │  │ + setSchedule(): void     │
│ + setBloodType(): void   │  │ + display(): void         │
│ + display(): void        │  │ + toString(): string      │
│ + toString(): string     │  └───────────────────────────┘
└──────────────────────────┘              │
            │                             │
            │ 1                        1  │
            │                             │
            │ *                        *  │
┌───────────────────────────────────────────────┐
│            Appointment                        │
├───────────────────────────────────────────────┤
│ - appointmentId: string                       │
│ - patient: Patient*                           │
│ - doctor: Doctor*                             │
│ - date: string                                │
│ - time: string                                │
│ - status: string (scheduled/completed/cancel) │
│ - notes: string                               │
├───────────────────────────────────────────────┤
│ + Appointment()                               │
│ + Appointment(id, patient, doctor, date, time)│
│ + ~Appointment()                              │
│ + getAppointmentId(): string                  │
│ + getPatient(): Patient*                      │
│ + getDoctor(): Doctor*                        │
│ + getDate(): string                           │
│ + getTime(): string                           │
│ + getStatus(): string                         │
│ + setDate(date): void                         │
│ + setTime(time): void                         │
│ + setStatus(status): void                     │
│ + setNotes(notes): void                       │
│ + display(): void                             │
│ + toString(): string                          │
└───────────────────────────────────────────────┘
            │ 1
            │
            │ *
┌───────────────────────────────────────────────┐
│            MedicalRecord                      │
├───────────────────────────────────────────────┤
│ - recordId: string                            │
│ - appointment: Appointment*                   │
│ - diagnosis: string                           │
│ - treatment: string                           │
│ - prescription: string                        │
│ - recordDate: string                          │
├───────────────────────────────────────────────┤
│ + MedicalRecord()                             │
│ + MedicalRecord(id, appointment, diag, treat) │
│ + ~MedicalRecord()                            │
│ + getRecordId(): string                       │
│ + getAppointment(): Appointment*              │
│ + getDiagnosis(): string                      │
│ + getTreatment(): string                      │
│ + setDiagnosis(diagnosis): void               │
│ + setTreatment(treatment): void               │
│ + setPrescription(prescription): void         │
│ + display(): void                             │
│ + toString(): string                          │
└───────────────────────────────────────────────┘


┌───────────────────────────────────────────────┐
│            FileHandler                        │
├───────────────────────────────────────────────┤
│ - inputFileName: string                       │
│ - outputFileName: string                      │
├───────────────────────────────────────────────┤
│ + FileHandler()                               │
│ + FileHandler(inputFile, outputFile)          │
│ + ~FileHandler()                              │
│ + loadData(manager): bool                     │
│ + saveData(manager): bool                     │
│ + exportReport(manager): bool                 │
└───────────────────────────────────────────────┘
            │
            │ uses
            ▼
┌───────────────────────────────────────────────┐
│            ClinicManager                      │
├───────────────────────────────────────────────┤
│ - patients: vector<Patient*>                  │
│ - doctors: vector<Doctor*>                    │
│ - appointments: vector<Appointment*>          │
│ - medicalRecords: vector<MedicalRecord*>      │
├───────────────────────────────────────────────┤
│ + ClinicManager()                             │
│ + ~ClinicManager()                            │
│                                               │
│ // Patient Management                         │
│ + addPatient(patient): void                   │
│ + updatePatient(id, patient): bool            │
│ + deletePatient(id): bool                     │
│ + findPatient(id): Patient*                   │
│ + listAllPatients(): void                     │
│ + searchPatientByName(name): vector<Patient*> │
│                                               │
│ // Doctor Management                          │
│ + addDoctor(doctor): void                     │
│ + updateDoctor(id, doctor): bool              │
│ + deleteDoctor(id): bool                      │
│ + findDoctor(id): Doctor*                     │
│ + listAllDoctors(): void                      │
│ + listDoctorsBySpec(spec): void               │
│                                               │
│ // Appointment Management                     │
│ + createAppointment(appointment): void        │
│ + updateAppointment(id, appointment): bool    │
│ + cancelAppointment(id): bool                 │
│ + listAppointments(): void                    │
│ + listAppointmentsByDate(date): void          │
│ + listAppointmentsByDoctor(doctorId): void    │
│                                               │
│ // Medical Record Management                  │
│ + addMedicalRecord(record): void              │
│ + updateMedicalRecord(id, record): bool       │
│ + getPatientHistory(patientId): vector<MR*>   │
│                                               │
│ // Getters                                    │
│ + getPatients(): vector<Patient*>             │
│ + getDoctors(): vector<Doctor*>               │
│ + getAppointments(): vector<Appointment*>     │
│ + getMedicalRecords(): vector<MedicalRecord*> │
└───────────────────────────────────────────────┘
```

## Class Relationships

### Inheritance (IS-A)

- `Patient` **inherits from** `Person`
- `Doctor` **inherits from** `Person`

### Association

- `Appointment` **has-a** `Patient` (many-to-one)
- `Appointment` **has-a** `Doctor` (many-to-one)
- `MedicalRecord` **has-a** `Appointment` (one-to-one)

### Composition/Aggregation

- `ClinicManager` **manages** multiple `Patient` objects
- `ClinicManager` **manages** multiple `Doctor` objects
- `ClinicManager` **manages** multiple `Appointment` objects
- `ClinicManager` **manages** multiple `MedicalRecord` objects

### Dependency

- `FileHandler` **depends on** `ClinicManager` for data operations

## Design Patterns Used

1. **Inheritance**: Person sebagai base class untuk Patient dan Doctor
2. **Polymorphism**: Virtual functions (display(), toString()) di-override di derived classes
3. **Encapsulation**: Private data members dengan public getter/setter
4. **Single Responsibility**: Setiap class memiliki tanggung jawab yang jelas
5. **Manager Pattern**: ClinicManager sebagai facade untuk semua operasi

## OOP Principles Applied

### 1. Encapsulation

- Semua data members adalah private
- Access melalui public getter/setter methods
- Implementation details disembunyikan

### 2. Inheritance

- Patient dan Doctor mewarisi properties dan methods dari Person
- Menghindari code duplication
- Mendukung code reusability

### 3. Polymorphism

- Virtual functions untuk behavior yang berbeda
- display() dan toString() di-override di setiap derived class
- Runtime polymorphism dengan virtual destructor

### 4. Abstraction

- Person adalah abstract class dengan pure virtual functions
- Interface yang simple menyembunyikan kompleksitas
- High-level operations di ClinicManager

## Data Flow

1. User → Main Menu → ClinicManager
2. ClinicManager → CRUD Operations → Objects (Patient/Doctor/Appointment/MR)
3. FileHandler → Load/Save → ClinicManager ↔ Text Files
