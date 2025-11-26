#include "MedicalRecord.h"
#include <iostream>
#include <sstream>

// Default constructor
MedicalRecord::MedicalRecord()
    : recordId(""), appointment(nullptr), diagnosis(""),
      treatment(""), prescription(""), recordDate("") {}

// Parameterized constructor
MedicalRecord::MedicalRecord(string id, Appointment *appointment,
                             string diagnosis, string treatment,
                             string prescription, string recordDate)
    : recordId(id), appointment(appointment), diagnosis(diagnosis),
      treatment(treatment), prescription(prescription), recordDate(recordDate) {}

// Destructor
MedicalRecord::~MedicalRecord()
{
    // Note: We don't delete appointment here as it is managed by ClinicManager
}

// Getters
string MedicalRecord::getRecordId() const
{
    return recordId;
}

Appointment *MedicalRecord::getAppointment() const
{
    return appointment;
}

string MedicalRecord::getDiagnosis() const
{
    return diagnosis;
}

string MedicalRecord::getTreatment() const
{
    return treatment;
}

string MedicalRecord::getPrescription() const
{
    return prescription;
}

string MedicalRecord::getRecordDate() const
{
    return recordDate;
}

// Setters
void MedicalRecord::setDiagnosis(const string &diagnosis)
{
    this->diagnosis = diagnosis;
}

void MedicalRecord::setTreatment(const string &treatment)
{
    this->treatment = treatment;
}

void MedicalRecord::setPrescription(const string &prescription)
{
    this->prescription = prescription;
}

// Display medical record information
void MedicalRecord::display() const
{
    cout << "======================================" << endl;
    cout << "        MEDICAL RECORD DETAILS        " << endl;
    cout << "======================================" << endl;
    cout << "Record ID      : " << recordId << endl;
    cout << "Record Date    : " << recordDate << endl;

    if (appointment)
    {
        cout << "Appointment ID : " << appointment->getAppointmentId() << endl;
        if (appointment->getPatient())
        {
            cout << "Patient        : " << appointment->getPatient()->getName()
                 << " (ID: " << appointment->getPatient()->getId() << ")" << endl;
        }
        if (appointment->getDoctor())
        {
            cout << "Doctor         : " << appointment->getDoctor()->getName()
                 << " (ID: " << appointment->getDoctor()->getId() << ")" << endl;
        }
    }

    cout << "Diagnosis      : " << diagnosis << endl;
    cout << "Treatment      : " << treatment << endl;
    cout << "Prescription   : " << prescription << endl;
    cout << "======================================" << endl;
}

// Convert medical record to string format for file storage
string MedicalRecord::toString() const
{
    stringstream ss;
    ss << "MEDICALRECORD|" << recordId << "|";

    if (appointment)
    {
        ss << appointment->getAppointmentId();
    }
    ss << "|" << diagnosis << "|" << treatment << "|"
       << prescription << "|" << recordDate;

    return ss.str();
}
