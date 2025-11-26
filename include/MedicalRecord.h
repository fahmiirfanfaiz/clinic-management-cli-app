#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include "Appointment.h"
#include <string>
using namespace std;

/**
 * MedicalRecord class
 * Represents a medical record associated with an appointment
 */
class MedicalRecord
{
private:
    string recordId;
    Appointment *appointment;
    string diagnosis;
    string treatment;
    string prescription;
    string recordDate;

public:
    // Constructors
    MedicalRecord();
    MedicalRecord(string id, Appointment *appointment,
                  string diagnosis, string treatment,
                  string prescription, string recordDate);

    // Destructor
    ~MedicalRecord();

    // Getters
    string getRecordId() const;
    Appointment *getAppointment() const;
    string getDiagnosis() const;
    string getTreatment() const;
    string getPrescription() const;
    string getRecordDate() const;

    // Setters
    void setDiagnosis(const string &diagnosis);
    void setTreatment(const string &treatment);
    void setPrescription(const string &prescription);

    // Display methods
    void display() const;
    string toString() const;
};

#endif // MEDICALRECORD_H
