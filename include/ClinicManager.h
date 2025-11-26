#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "MedicalRecord.h"
#include <vector>
#include <string>
using namespace std;

/**
 * ClinicManager class
 * Main manager class that handles all clinic operations
 * Implements the Manager/Facade pattern
 */
class ClinicManager
{
private:
    vector<Patient *> patients;
    vector<Doctor *> doctors;
    vector<Appointment *> appointments;
    vector<MedicalRecord *> medicalRecords;

    // Helper functions
    string generatePatientId();
    string generateDoctorId();
    string generateAppointmentId();
    string generateRecordId();

public:
    // Constructor & Destructor
    ClinicManager();
    ~ClinicManager();

    // Patient Management
    void addPatient(Patient *patient);
    bool updatePatient(const string &id, Patient *updatedPatient);
    bool deletePatient(const string &id);
    Patient *findPatient(const string &id);
    void listAllPatients() const;
    vector<Patient *> searchPatientByName(const string &name);

    // Doctor Management
    void addDoctor(Doctor *doctor);
    bool updateDoctor(const string &id, Doctor *updatedDoctor);
    bool deleteDoctor(const string &id);
    Doctor *findDoctor(const string &id);
    void listAllDoctors() const;
    void listDoctorsBySpecialization(const string &specialization) const;

    // Appointment Management
    void createAppointment(Appointment *appointment);
    bool updateAppointment(const string &id, Appointment *updatedAppointment);
    bool cancelAppointment(const string &id);
    void listAllAppointments() const;
    void listAppointmentsByDate(const string &date) const;
    void listAppointmentsByDoctor(const string &doctorId) const;
    void listAppointmentsByPatient(const string &patientId) const;
    Appointment *findAppointment(const string &id);

    // Medical Record Management
    void addMedicalRecord(MedicalRecord *record);
    bool updateMedicalRecord(const string &id, MedicalRecord *updatedRecord);
    vector<MedicalRecord *> getPatientHistory(const string &patientId);
    MedicalRecord *findMedicalRecord(const string &id);

    // Getters for collections
    vector<Patient *> getPatients() const;
    vector<Doctor *> getDoctors() const;
    vector<Appointment *> getAppointments() const;
    vector<MedicalRecord *> getMedicalRecords() const;

    // Utility functions
    void clearAllData();
    int getPatientsCount() const;
    int getDoctorsCount() const;
    int getAppointmentsCount() const;
    int getMedicalRecordsCount() const;
};

#endif // CLINICMANAGER_H
