#include "ClinicManager.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

// Function prototypes
void displayMainMenu();
void patientMenu(ClinicManager &manager);
void doctorMenu(ClinicManager &manager);
void appointmentMenu(ClinicManager &manager);
void medicalRecordMenu(ClinicManager &manager);
void clearScreen();
void pause();
string getCurrentDate();
string generateId(const string &prefix, int count);

int main()
{
    ClinicManager manager;
    FileHandler fileHandler;

    cout << "========================================" << endl;
    cout << "   CLINIC MANAGEMENT SYSTEM v1.0        " << endl;
    cout << "========================================" << endl;
    cout << "\nInitializing system...\n"
         << endl;

    // Load data from input file
    fileHandler.loadData(&manager);

    int choice;
    bool running = true;

    while (running)
    {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            clearScreen();
            patientMenu(manager);
            break;
        case 2:
            clearScreen();
            doctorMenu(manager);
            break;
        case 3:
            clearScreen();
            appointmentMenu(manager);
            break;
        case 4:
            clearScreen();
            medicalRecordMenu(manager);
            break;
        case 5:
            clearScreen();
            cout << "\n========================================" << endl;
            cout << "         SYSTEM STATISTICS              " << endl;
            cout << "========================================" << endl;
            cout << "Total Patients        : " << manager.getPatientsCount() << endl;
            cout << "Total Doctors         : " << manager.getDoctorsCount() << endl;
            cout << "Total Appointments    : " << manager.getAppointmentsCount() << endl;
            cout << "Total Medical Records : " << manager.getMedicalRecordsCount() << endl;
            cout << "========================================" << endl;
            pause();
            break;
        case 6:
            clearScreen();
            fileHandler.saveData(&manager);
            pause();
            break;
        case 7:
            clearScreen();
            {
                string reportFile = "data/report.txt";
                fileHandler.exportReport(&manager, reportFile);
            }
            pause();
            break;
        case 0:
            clearScreen();
            cout << "\nSaving data before exit..." << endl;
            fileHandler.saveData(&manager);
            cout << "\nThank you for using Clinic Management System!" << endl;
            cout << "Goodbye!\n"
                 << endl;
            running = false;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
            pause();
        }
    }

    return 0;
}

void displayMainMenu()
{
    clearScreen();
    cout << "\n========================================" << endl;
    cout << "      CLINIC MANAGEMENT SYSTEM          " << endl;
    cout << "========================================" << endl;
    cout << "1. Patient Management" << endl;
    cout << "2. Doctor Management" << endl;
    cout << "3. Appointment Management" << endl;
    cout << "4. Medical Record Management" << endl;
    cout << "5. View Statistics" << endl;
    cout << "6. Save Data" << endl;
    cout << "7. Export Report" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
}

void patientMenu(ClinicManager &manager)
{
    int choice;
    bool back = false;

    while (!back)
    {
        clearScreen();
        cout << "\n========================================" << endl;
        cout << "       PATIENT MANAGEMENT MENU          " << endl;
        cout << "========================================" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Update Patient" << endl;
        cout << "3. Delete Patient" << endl;
        cout << "4. Find Patient by ID" << endl;
        cout << "5. Search Patient by Name" << endl;
        cout << "6. List All Patients" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            clearScreen();
            cout << "\n=== ADD NEW PATIENT ===" << endl;
            string id = generateId("P", manager.getPatientsCount() + 1);
            string name, phone, address, dob, gender, bloodType;

            cout << "Patient ID (auto): " << id << endl;
            cout << "Name: ";
            getline(cin, name);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Address: ";
            getline(cin, address);
            cout << "Date of Birth (DD/MM/YYYY): ";
            getline(cin, dob);
            cout << "Gender (M/F): ";
            getline(cin, gender);
            cout << "Blood Type (A/B/AB/O): ";
            getline(cin, bloodType);

            Patient *newPatient = new Patient(id, name, phone, address, dob, gender, bloodType);
            manager.addPatient(newPatient);
            pause();
            break;
        }
        case 2:
        {
            clearScreen();
            cout << "\n=== UPDATE PATIENT ===" << endl;
            string id;
            cout << "Enter Patient ID to update: ";
            getline(cin, id);

            Patient *patient = manager.findPatient(id);
            if (patient)
            {
                patient->display();
                cout << "\nEnter new information (press Enter to keep current):" << endl;

                string name, phone, address, dob, gender, bloodType;
                cout << "Name [" << patient->getName() << "]: ";
                getline(cin, name);
                if (name.empty())
                    name = patient->getName();

                cout << "Phone [" << patient->getPhone() << "]: ";
                getline(cin, phone);
                if (phone.empty())
                    phone = patient->getPhone();

                cout << "Address [" << patient->getAddress() << "]: ";
                getline(cin, address);
                if (address.empty())
                    address = patient->getAddress();

                cout << "Date of Birth [" << patient->getDateOfBirth() << "]: ";
                getline(cin, dob);
                if (dob.empty())
                    dob = patient->getDateOfBirth();

                cout << "Gender [" << patient->getGender() << "]: ";
                getline(cin, gender);
                if (gender.empty())
                    gender = patient->getGender();

                cout << "Blood Type [" << patient->getBloodType() << "]: ";
                getline(cin, bloodType);
                if (bloodType.empty())
                    bloodType = patient->getBloodType();

                Patient *updatedPatient = new Patient(id, name, phone, address, dob, gender, bloodType);
                manager.updatePatient(id, updatedPatient);
                delete updatedPatient;
            }
            else
            {
                cout << "Patient not found!" << endl;
            }
            pause();
            break;
        }
        case 3:
        {
            clearScreen();
            cout << "\n=== DELETE PATIENT ===" << endl;
            string id;
            cout << "Enter Patient ID to delete: ";
            getline(cin, id);

            Patient *patient = manager.findPatient(id);
            if (patient)
            {
                patient->display();
                cout << "\nAre you sure you want to delete this patient? (y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (confirm == 'y' || confirm == 'Y')
                {
                    manager.deletePatient(id);
                }
                else
                {
                    cout << "Deletion cancelled." << endl;
                }
            }
            else
            {
                cout << "Patient not found!" << endl;
            }
            pause();
            break;
        }
        case 4:
        {
            clearScreen();
            cout << "\n=== FIND PATIENT ===" << endl;
            string id;
            cout << "Enter Patient ID: ";
            getline(cin, id);

            Patient *patient = manager.findPatient(id);
            if (patient)
            {
                patient->display();
            }
            else
            {
                cout << "Patient not found!" << endl;
            }
            pause();
            break;
        }
        case 5:
        {
            clearScreen();
            cout << "\n=== SEARCH PATIENT BY NAME ===" << endl;
            string name;
            cout << "Enter patient name (partial match allowed): ";
            getline(cin, name);

            vector<Patient *> results = manager.searchPatientByName(name);
            if (results.empty())
            {
                cout << "No patients found with name containing: " << name << endl;
            }
            else
            {
                cout << "\nFound " << results.size() << " patient(s):" << endl;
                for (Patient *p : results)
                {
                    cout << "\n";
                    p->display();
                }
            }
            pause();
            break;
        }
        case 6:
        {
            clearScreen();
            manager.listAllPatients();
            pause();
            break;
        }
        case 0:
            back = true;
            break;
        default:
            cout << "\nInvalid choice!" << endl;
            pause();
        }
    }
}

void doctorMenu(ClinicManager &manager)
{
    int choice;
    bool back = false;

    while (!back)
    {
        clearScreen();
        cout << "\n========================================" << endl;
        cout << "        DOCTOR MANAGEMENT MENU          " << endl;
        cout << "========================================" << endl;
        cout << "1. Add New Doctor" << endl;
        cout << "2. Update Doctor" << endl;
        cout << "3. Delete Doctor" << endl;
        cout << "4. Find Doctor by ID" << endl;
        cout << "5. List Doctors by Specialization" << endl;
        cout << "6. List All Doctors" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            clearScreen();
            cout << "\n=== ADD NEW DOCTOR ===" << endl;
            string id = generateId("D", manager.getDoctorsCount() + 1);
            string name, phone, address, specialization, license, schedule;

            cout << "Doctor ID (auto): " << id << endl;
            cout << "Name: ";
            getline(cin, name);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Address: ";
            getline(cin, address);
            cout << "Specialization: ";
            getline(cin, specialization);
            cout << "License Number: ";
            getline(cin, license);
            cout << "Schedule (e.g., Mon-Fri 09:00-17:00): ";
            getline(cin, schedule);

            Doctor *newDoctor = new Doctor(id, name, phone, address, specialization, license, schedule);
            manager.addDoctor(newDoctor);
            pause();
            break;
        }
        case 2:
        {
            clearScreen();
            cout << "\n=== UPDATE DOCTOR ===" << endl;
            string id;
            cout << "Enter Doctor ID to update: ";
            getline(cin, id);

            Doctor *doctor = manager.findDoctor(id);
            if (doctor)
            {
                doctor->display();
                cout << "\nEnter new information (press Enter to keep current):" << endl;

                string name, phone, address, specialization, license, schedule;
                cout << "Name [" << doctor->getName() << "]: ";
                getline(cin, name);
                if (name.empty())
                    name = doctor->getName();

                cout << "Phone [" << doctor->getPhone() << "]: ";
                getline(cin, phone);
                if (phone.empty())
                    phone = doctor->getPhone();

                cout << "Address [" << doctor->getAddress() << "]: ";
                getline(cin, address);
                if (address.empty())
                    address = doctor->getAddress();

                cout << "Specialization [" << doctor->getSpecialization() << "]: ";
                getline(cin, specialization);
                if (specialization.empty())
                    specialization = doctor->getSpecialization();

                cout << "License Number [" << doctor->getLicenseNumber() << "]: ";
                getline(cin, license);
                if (license.empty())
                    license = doctor->getLicenseNumber();

                cout << "Schedule [" << doctor->getSchedule() << "]: ";
                getline(cin, schedule);
                if (schedule.empty())
                    schedule = doctor->getSchedule();

                Doctor *updatedDoctor = new Doctor(id, name, phone, address, specialization, license, schedule);
                manager.updateDoctor(id, updatedDoctor);
                delete updatedDoctor;
            }
            else
            {
                cout << "Doctor not found!" << endl;
            }
            pause();
            break;
        }
        case 3:
        {
            clearScreen();
            cout << "\n=== DELETE DOCTOR ===" << endl;
            string id;
            cout << "Enter Doctor ID to delete: ";
            getline(cin, id);

            Doctor *doctor = manager.findDoctor(id);
            if (doctor)
            {
                doctor->display();
                cout << "\nAre you sure you want to delete this doctor? (y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (confirm == 'y' || confirm == 'Y')
                {
                    manager.deleteDoctor(id);
                }
                else
                {
                    cout << "Deletion cancelled." << endl;
                }
            }
            else
            {
                cout << "Doctor not found!" << endl;
            }
            pause();
            break;
        }
        case 4:
        {
            clearScreen();
            cout << "\n=== FIND DOCTOR ===" << endl;
            string id;
            cout << "Enter Doctor ID: ";
            getline(cin, id);

            Doctor *doctor = manager.findDoctor(id);
            if (doctor)
            {
                doctor->display();
            }
            else
            {
                cout << "Doctor not found!" << endl;
            }
            pause();
            break;
        }
        case 5:
        {
            clearScreen();
            cout << "\n=== DOCTORS BY SPECIALIZATION ===" << endl;
            string spec;
            cout << "Enter specialization: ";
            getline(cin, spec);

            manager.listDoctorsBySpecialization(spec);
            pause();
            break;
        }
        case 6:
        {
            clearScreen();
            manager.listAllDoctors();
            pause();
            break;
        }
        case 0:
            back = true;
            break;
        default:
            cout << "\nInvalid choice!" << endl;
            pause();
        }
    }
}

void appointmentMenu(ClinicManager &manager)
{
    int choice;
    bool back = false;

    while (!back)
    {
        clearScreen();
        cout << "\n========================================" << endl;
        cout << "     APPOINTMENT MANAGEMENT MENU        " << endl;
        cout << "========================================" << endl;
        cout << "1. Create New Appointment" << endl;
        cout << "2. Update Appointment Status" << endl;
        cout << "3. Cancel Appointment" << endl;
        cout << "4. View Appointments by Date" << endl;
        cout << "5. View Appointments by Doctor" << endl;
        cout << "6. View Appointments by Patient" << endl;
        cout << "7. List All Appointments" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            clearScreen();
            cout << "\n=== CREATE NEW APPOINTMENT ===" << endl;

            // First show available patients
            cout << "\n--- Available Patients ---" << endl;
            manager.listAllPatients();

            string patientId;
            cout << "\nEnter Patient ID: ";
            getline(cin, patientId);

            Patient *patient = manager.findPatient(patientId);
            if (!patient)
            {
                cout << "Patient not found!" << endl;
                pause();
                break;
            }

            // Show available doctors
            cout << "\n--- Available Doctors ---" << endl;
            manager.listAllDoctors();

            string doctorId;
            cout << "\nEnter Doctor ID: ";
            getline(cin, doctorId);

            Doctor *doctor = manager.findDoctor(doctorId);
            if (!doctor)
            {
                cout << "Doctor not found!" << endl;
                pause();
                break;
            }

            string id = generateId("A", manager.getAppointmentsCount() + 1);
            string date, time;

            cout << "\nAppointment ID (auto): " << id << endl;
            cout << "Date (DD/MM/YYYY): ";
            getline(cin, date);
            cout << "Time (HH:MM): ";
            getline(cin, time);

            Appointment *newAppointment = new Appointment(id, patient, doctor, date, time);
            manager.createAppointment(newAppointment);
            pause();
            break;
        }
        case 2:
        {
            clearScreen();
            cout << "\n=== UPDATE APPOINTMENT STATUS ===" << endl;
            string id;
            cout << "Enter Appointment ID: ";
            getline(cin, id);

            Appointment *apt = manager.findAppointment(id);
            if (apt)
            {
                apt->display();
                cout << "\nSelect new status:" << endl;
                cout << "1. Scheduled" << endl;
                cout << "2. Completed" << endl;
                cout << "3. Cancelled" << endl;
                cout << "Choice: ";

                int statusChoice;
                cin >> statusChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string newStatus;
                switch (statusChoice)
                {
                case 1:
                    newStatus = "scheduled";
                    break;
                case 2:
                    newStatus = "completed";
                    break;
                case 3:
                    newStatus = "cancelled";
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    pause();
                    continue;
                }

                apt->setStatus(newStatus);
                cout << "Appointment status updated to: " << newStatus << endl;
            }
            else
            {
                cout << "Appointment not found!" << endl;
            }
            pause();
            break;
        }
        case 3:
        {
            clearScreen();
            cout << "\n=== CANCEL APPOINTMENT ===" << endl;
            string id;
            cout << "Enter Appointment ID to cancel: ";
            getline(cin, id);

            manager.cancelAppointment(id);
            pause();
            break;
        }
        case 4:
        {
            clearScreen();
            cout << "\n=== APPOINTMENTS BY DATE ===" << endl;
            string date;
            cout << "Enter date (DD/MM/YYYY): ";
            getline(cin, date);

            manager.listAppointmentsByDate(date);
            pause();
            break;
        }
        case 5:
        {
            clearScreen();
            cout << "\n=== APPOINTMENTS BY DOCTOR ===" << endl;
            string doctorId;
            cout << "Enter Doctor ID: ";
            getline(cin, doctorId);

            manager.listAppointmentsByDoctor(doctorId);
            pause();
            break;
        }
        case 6:
        {
            clearScreen();
            cout << "\n=== APPOINTMENTS BY PATIENT ===" << endl;
            string patientId;
            cout << "Enter Patient ID: ";
            getline(cin, patientId);

            manager.listAppointmentsByPatient(patientId);
            pause();
            break;
        }
        case 7:
        {
            clearScreen();
            manager.listAllAppointments();
            pause();
            break;
        }
        case 0:
            back = true;
            break;
        default:
            cout << "\nInvalid choice!" << endl;
            pause();
        }
    }
}

void medicalRecordMenu(ClinicManager &manager)
{
    int choice;
    bool back = false;

    while (!back)
    {
        clearScreen();
        cout << "\n========================================" << endl;
        cout << "    MEDICAL RECORD MANAGEMENT MENU      " << endl;
        cout << "========================================" << endl;
        cout << "1. Add New Medical Record" << endl;
        cout << "2. Update Medical Record" << endl;
        cout << "3. View Patient Medical History" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            clearScreen();
            cout << "\n=== ADD NEW MEDICAL RECORD ===" << endl;

            // Show completed appointments
            cout << "\n--- Completed Appointments ---" << endl;
            bool hasCompleted = false;
            for (Appointment *apt : manager.getAppointments())
            {
                if (apt->getStatus() == "completed")
                {
                    apt->display();
                    hasCompleted = true;
                }
            }

            if (!hasCompleted)
            {
                cout << "No completed appointments found!" << endl;
                pause();
                break;
            }

            string appointmentId;
            cout << "\nEnter Appointment ID: ";
            getline(cin, appointmentId);

            Appointment *apt = manager.findAppointment(appointmentId);
            if (!apt)
            {
                cout << "Appointment not found!" << endl;
                pause();
                break;
            }

            if (apt->getStatus() != "completed")
            {
                cout << "Can only create medical record for completed appointments!" << endl;
                pause();
                break;
            }

            string id = generateId("R", manager.getMedicalRecordsCount() + 1);
            string diagnosis, treatment, prescription;

            cout << "\nMedical Record ID (auto): " << id << endl;
            cout << "Diagnosis: ";
            getline(cin, diagnosis);
            cout << "Treatment: ";
            getline(cin, treatment);
            cout << "Prescription: ";
            getline(cin, prescription);

            string recordDate = getCurrentDate();

            MedicalRecord *newRecord = new MedicalRecord(id, apt, diagnosis, treatment, prescription, recordDate);
            manager.addMedicalRecord(newRecord);
            pause();
            break;
        }
        case 2:
        {
            clearScreen();
            cout << "\n=== UPDATE MEDICAL RECORD ===" << endl;
            string id;
            cout << "Enter Medical Record ID: ";
            getline(cin, id);

            MedicalRecord *record = manager.findMedicalRecord(id);
            if (record)
            {
                record->display();
                cout << "\nEnter new information (press Enter to keep current):" << endl;

                string diagnosis, treatment, prescription;
                cout << "Diagnosis [" << record->getDiagnosis() << "]: ";
                getline(cin, diagnosis);
                if (diagnosis.empty())
                    diagnosis = record->getDiagnosis();

                cout << "Treatment [" << record->getTreatment() << "]: ";
                getline(cin, treatment);
                if (treatment.empty())
                    treatment = record->getTreatment();

                cout << "Prescription [" << record->getPrescription() << "]: ";
                getline(cin, prescription);
                if (prescription.empty())
                    prescription = record->getPrescription();

                record->setDiagnosis(diagnosis);
                record->setTreatment(treatment);
                record->setPrescription(prescription);

                cout << "Medical record updated successfully!" << endl;
            }
            else
            {
                cout << "Medical record not found!" << endl;
            }
            pause();
            break;
        }
        case 3:
        {
            clearScreen();
            cout << "\n=== PATIENT MEDICAL HISTORY ===" << endl;
            string patientId;
            cout << "Enter Patient ID: ";
            getline(cin, patientId);

            Patient *patient = manager.findPatient(patientId);
            if (!patient)
            {
                cout << "Patient not found!" << endl;
                pause();
                break;
            }

            cout << "\nMedical History for: " << patient->getName() << endl;
            cout << "========================================" << endl;

            vector<MedicalRecord *> history = manager.getPatientHistory(patientId);
            if (history.empty())
            {
                cout << "No medical records found for this patient." << endl;
            }
            else
            {
                for (MedicalRecord *record : history)
                {
                    record->display();
                    cout << endl;
                }
                cout << "Total Records: " << history.size() << endl;
            }
            pause();
            break;
        }
        case 0:
            back = true;
            break;
        default:
            cout << "\nInvalid choice!" << endl;
            pause();
        }
    }
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
    cout << "\nPress Enter to continue...";
    cin.get();
}

string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
       << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "/"
       << (1900 + ltm->tm_year);

    return ss.str();
}

string generateId(const string &prefix, int count)
{
    stringstream ss;
    ss << prefix << setfill('0') << setw(4) << count;
    return ss.str();
}
