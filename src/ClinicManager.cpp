#include "ClinicManager.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

// Constructor
ClinicManager::ClinicManager() {}

// Destructor - clean up all allocated memory
ClinicManager::~ClinicManager()
{
    clearAllData();
}

// Helper function to generate unique patient ID
string ClinicManager::generatePatientId()
{
    stringstream ss;
    ss << "P" << setfill('0') << setw(4) << (patients.size() + 1);
    return ss.str();
}

// Helper function to generate unique doctor ID
string ClinicManager::generateDoctorId()
{
    stringstream ss;
    ss << "D" << setfill('0') << setw(4) << (doctors.size() + 1);
    return ss.str();
}

// Helper function to generate unique appointment ID
string ClinicManager::generateAppointmentId()
{
    stringstream ss;
    ss << "A" << setfill('0') << setw(4) << (appointments.size() + 1);
    return ss.str();
}

// Helper function to generate unique medical record ID
string ClinicManager::generateRecordId()
{
    stringstream ss;
    ss << "R" << setfill('0') << setw(4) << (medicalRecords.size() + 1);
    return ss.str();
}

// ========== PATIENT MANAGEMENT ==========

void ClinicManager::addPatient(Patient *patient)
{
    if (patient != nullptr)
    {
        patients.push_back(patient);
        cout << "Patient added successfully! ID: " << patient->getId() << endl;
    }
}

bool ClinicManager::updatePatient(const string &id, Patient *updatedPatient)
{
    for (size_t i = 0; i < patients.size(); i++)
    {
        if (patients[i]->getId() == id)
        {
            // Keep the same ID but update other information
            patients[i]->setName(updatedPatient->getName());
            patients[i]->setPhone(updatedPatient->getPhone());
            patients[i]->setAddress(updatedPatient->getAddress());
            patients[i]->setDateOfBirth(updatedPatient->getDateOfBirth());
            patients[i]->setGender(updatedPatient->getGender());
            patients[i]->setBloodType(updatedPatient->getBloodType());
            cout << "Patient updated successfully!" << endl;
            return true;
        }
    }
    cout << "Patient with ID " << id << " not found!" << endl;
    return false;
}

bool ClinicManager::deletePatient(const string &id)
{
    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            delete *it;
            patients.erase(it);
            cout << "Patient deleted successfully!" << endl;
            return true;
        }
    }
    cout << "Patient with ID " << id << " not found!" << endl;
    return false;
}

Patient *ClinicManager::findPatient(const string &id)
{
    for (Patient *patient : patients)
    {
        if (patient->getId() == id)
        {
            return patient;
        }
    }
    return nullptr;
}

void ClinicManager::listAllPatients() const
{
    if (patients.empty())
    {
        cout << "\nNo patients found in the system." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "         LIST OF ALL PATIENTS           " << endl;
    cout << "========================================" << endl;
    cout << left << setw(8) << "ID"
         << setw(25) << "Name"
         << setw(12) << "Gender"
         << setw(15) << "Phone" << endl;
    cout << "----------------------------------------" << endl;

    for (const Patient *patient : patients)
    {
        cout << left << setw(8) << patient->getId()
             << setw(25) << patient->getName()
             << setw(12) << patient->getGender()
             << setw(15) << patient->getPhone() << endl;
    }
    cout << "========================================" << endl;
    cout << "Total Patients: " << patients.size() << endl;
}

vector<Patient *> ClinicManager::searchPatientByName(const string &name)
{
    vector<Patient *> results;
    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    for (Patient *patient : patients)
    {
        string patientName = patient->getName();
        transform(patientName.begin(), patientName.end(), patientName.begin(), ::tolower);

        if (patientName.find(lowerName) != string::npos)
        {
            results.push_back(patient);
        }
    }

    return results;
}

// ========== DOCTOR MANAGEMENT ==========

void ClinicManager::addDoctor(Doctor *doctor)
{
    if (doctor != nullptr)
    {
        doctors.push_back(doctor);
        cout << "Doctor added successfully! ID: " << doctor->getId() << endl;
    }
}

bool ClinicManager::updateDoctor(const string &id, Doctor *updatedDoctor)
{
    for (size_t i = 0; i < doctors.size(); i++)
    {
        if (doctors[i]->getId() == id)
        {
            doctors[i]->setName(updatedDoctor->getName());
            doctors[i]->setPhone(updatedDoctor->getPhone());
            doctors[i]->setAddress(updatedDoctor->getAddress());
            doctors[i]->setSpecialization(updatedDoctor->getSpecialization());
            doctors[i]->setLicenseNumber(updatedDoctor->getLicenseNumber());
            doctors[i]->setSchedule(updatedDoctor->getSchedule());
            cout << "Doctor updated successfully!" << endl;
            return true;
        }
    }
    cout << "Doctor with ID " << id << " not found!" << endl;
    return false;
}

bool ClinicManager::deleteDoctor(const string &id)
{
    for (auto it = doctors.begin(); it != doctors.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            delete *it;
            doctors.erase(it);
            cout << "Doctor deleted successfully!" << endl;
            return true;
        }
    }
    cout << "Doctor with ID " << id << " not found!" << endl;
    return false;
}

Doctor *ClinicManager::findDoctor(const string &id)
{
    for (Doctor *doctor : doctors)
    {
        if (doctor->getId() == id)
        {
            return doctor;
        }
    }
    return nullptr;
}

void ClinicManager::listAllDoctors() const
{
    if (doctors.empty())
    {
        cout << "\nNo doctors found in the system." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "         LIST OF ALL DOCTORS            " << endl;
    cout << "========================================" << endl;
    cout << left << setw(8) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Specialization"
         << setw(15) << "Phone" << endl;
    cout << "----------------------------------------" << endl;

    for (const Doctor *doctor : doctors)
    {
        cout << left << setw(8) << doctor->getId()
             << setw(25) << doctor->getName()
             << setw(20) << doctor->getSpecialization()
             << setw(15) << doctor->getPhone() << endl;
    }
    cout << "========================================" << endl;
    cout << "Total Doctors: " << doctors.size() << endl;
}

void ClinicManager::listDoctorsBySpecialization(const string &specialization) const
{
    cout << "\n========================================" << endl;
    cout << "  Doctors - Specialization: " << specialization << endl;
    cout << "========================================" << endl;

    bool found = false;
    for (const Doctor *doctor : doctors)
    {
        if (doctor->getSpecialization() == specialization)
        {
            cout << "ID: " << doctor->getId()
                 << " | Name: " << doctor->getName()
                 << " | Phone: " << doctor->getPhone() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No doctors found with specialization: " << specialization << endl;
    }
}

// ========== APPOINTMENT MANAGEMENT ==========

void ClinicManager::createAppointment(Appointment *appointment)
{
    if (appointment != nullptr)
    {
        appointments.push_back(appointment);
        cout << "Appointment created successfully! ID: " << appointment->getAppointmentId() << endl;
    }
}

bool ClinicManager::updateAppointment(const string &id, Appointment *updatedAppointment)
{
    for (size_t i = 0; i < appointments.size(); i++)
    {
        if (appointments[i]->getAppointmentId() == id)
        {
            appointments[i]->setDate(updatedAppointment->getDate());
            appointments[i]->setTime(updatedAppointment->getTime());
            appointments[i]->setStatus(updatedAppointment->getStatus());
            appointments[i]->setNotes(updatedAppointment->getNotes());
            cout << "Appointment updated successfully!" << endl;
            return true;
        }
    }
    cout << "Appointment with ID " << id << " not found!" << endl;
    return false;
}

bool ClinicManager::cancelAppointment(const string &id)
{
    for (Appointment *appointment : appointments)
    {
        if (appointment->getAppointmentId() == id)
        {
            appointment->setStatus("cancelled");
            cout << "Appointment cancelled successfully!" << endl;
            return true;
        }
    }
    cout << "Appointment with ID " << id << " not found!" << endl;
    return false;
}

void ClinicManager::listAllAppointments() const
{
    if (appointments.empty())
    {
        cout << "\nNo appointments found in the system." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       LIST OF ALL APPOINTMENTS         " << endl;
    cout << "========================================" << endl;
    cout << left << setw(8) << "ID"
         << setw(12) << "Date"
         << setw(8) << "Time"
         << setw(20) << "Patient"
         << setw(20) << "Doctor"
         << setw(12) << "Status" << endl;
    cout << "----------------------------------------" << endl;

    for (const Appointment *apt : appointments)
    {
        cout << left << setw(8) << apt->getAppointmentId()
             << setw(12) << apt->getDate()
             << setw(8) << apt->getTime();

        if (apt->getPatient())
        {
            cout << setw(20) << apt->getPatient()->getName();
        }
        else
        {
            cout << setw(20) << "N/A";
        }

        if (apt->getDoctor())
        {
            cout << setw(20) << apt->getDoctor()->getName();
        }
        else
        {
            cout << setw(20) << "N/A";
        }

        cout << setw(12) << apt->getStatus() << endl;
    }
    cout << "========================================" << endl;
    cout << "Total Appointments: " << appointments.size() << endl;
}

void ClinicManager::listAppointmentsByDate(const string &date) const
{
    cout << "\nAppointments on " << date << ":" << endl;
    bool found = false;

    for (const Appointment *apt : appointments)
    {
        if (apt->getDate() == date)
        {
            apt->display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No appointments found on " << date << endl;
    }
}

void ClinicManager::listAppointmentsByDoctor(const string &doctorId) const
{
    Doctor *doctor = nullptr;
    for (Doctor *d : doctors)
    {
        if (d->getId() == doctorId)
        {
            doctor = d;
            break;
        }
    }

    if (!doctor)
    {
        cout << "Doctor not found!" << endl;
        return;
    }

    cout << "\nAppointments for Dr. " << doctor->getName() << ":" << endl;
    bool found = false;

    for (const Appointment *apt : appointments)
    {
        if (apt->getDoctor() && apt->getDoctor()->getId() == doctorId)
        {
            apt->display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No appointments found for this doctor." << endl;
    }
}

void ClinicManager::listAppointmentsByPatient(const string &patientId) const
{
    Patient *patient = nullptr;
    for (Patient *p : patients)
    {
        if (p->getId() == patientId)
        {
            patient = p;
            break;
        }
    }

    if (!patient)
    {
        cout << "Patient not found!" << endl;
        return;
    }

    cout << "\nAppointments for " << patient->getName() << ":" << endl;
    bool found = false;

    for (const Appointment *apt : appointments)
    {
        if (apt->getPatient() && apt->getPatient()->getId() == patientId)
        {
            apt->display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No appointments found for this patient." << endl;
    }
}

Appointment *ClinicManager::findAppointment(const string &id)
{
    for (Appointment *apt : appointments)
    {
        if (apt->getAppointmentId() == id)
        {
            return apt;
        }
    }
    return nullptr;
}

// ========== MEDICAL RECORD MANAGEMENT ==========

void ClinicManager::addMedicalRecord(MedicalRecord *record)
{
    if (record != nullptr)
    {
        medicalRecords.push_back(record);
        cout << "Medical record added successfully! ID: " << record->getRecordId() << endl;
    }
}

bool ClinicManager::updateMedicalRecord(const string &id, MedicalRecord *updatedRecord)
{
    for (size_t i = 0; i < medicalRecords.size(); i++)
    {
        if (medicalRecords[i]->getRecordId() == id)
        {
            medicalRecords[i]->setDiagnosis(updatedRecord->getDiagnosis());
            medicalRecords[i]->setTreatment(updatedRecord->getTreatment());
            medicalRecords[i]->setPrescription(updatedRecord->getPrescription());
            cout << "Medical record updated successfully!" << endl;
            return true;
        }
    }
    cout << "Medical record with ID " << id << " not found!" << endl;
    return false;
}

vector<MedicalRecord *> ClinicManager::getPatientHistory(const string &patientId)
{
    vector<MedicalRecord *> history;

    for (MedicalRecord *record : medicalRecords)
    {
        if (record->getAppointment() &&
            record->getAppointment()->getPatient() &&
            record->getAppointment()->getPatient()->getId() == patientId)
        {
            history.push_back(record);
        }
    }

    return history;
}

MedicalRecord *ClinicManager::findMedicalRecord(const string &id)
{
    for (MedicalRecord *record : medicalRecords)
    {
        if (record->getRecordId() == id)
        {
            return record;
        }
    }
    return nullptr;
}

// ========== GETTERS ==========

vector<Patient *> ClinicManager::getPatients() const
{
    return patients;
}

vector<Doctor *> ClinicManager::getDoctors() const
{
    return doctors;
}

vector<Appointment *> ClinicManager::getAppointments() const
{
    return appointments;
}

vector<MedicalRecord *> ClinicManager::getMedicalRecords() const
{
    return medicalRecords;
}

// ========== UTILITY FUNCTIONS ==========

void ClinicManager::clearAllData()
{
    // Delete all patients
    for (Patient *patient : patients)
    {
        delete patient;
    }
    patients.clear();

    // Delete all doctors
    for (Doctor *doctor : doctors)
    {
        delete doctor;
    }
    doctors.clear();

    // Delete all appointments
    for (Appointment *apt : appointments)
    {
        delete apt;
    }
    appointments.clear();

    // Delete all medical records
    for (MedicalRecord *record : medicalRecords)
    {
        delete record;
    }
    medicalRecords.clear();
}

int ClinicManager::getPatientsCount() const
{
    return patients.size();
}

int ClinicManager::getDoctorsCount() const
{
    return doctors.size();
}

int ClinicManager::getAppointmentsCount() const
{
    return appointments.size();
}

int ClinicManager::getMedicalRecordsCount() const
{
    return medicalRecords.size();
}
