#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Patient.h"
#include "Doctor.h"
#include <string>
using namespace std;

/**
 * Appointment class
 * Represents a scheduled visit between a patient and a doctor
 */
class Appointment
{
private:
    string appointmentId;
    Patient *patient;
    Doctor *doctor;
    string date;
    string time;
    string status; // scheduled, completed, cancelled
    string notes;

public:
    // Constructors
    Appointment();
    Appointment(string id, Patient *patient, Doctor *doctor,
                string date, string time);

    // Destructor
    ~Appointment();

    // Getters
    string getAppointmentId() const;
    Patient *getPatient() const;
    Doctor *getDoctor() const;
    string getDate() const;
    string getTime() const;
    string getStatus() const;
    string getNotes() const;

    // Setters
    void setDate(const string &date);
    void setTime(const string &time);
    void setStatus(const string &status);
    void setNotes(const string &notes);

    // Display methods
    void display() const;
    string toString() const;
};

#endif // APPOINTMENT_H
