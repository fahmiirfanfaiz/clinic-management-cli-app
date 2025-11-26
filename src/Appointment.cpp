#include "Appointment.h"
#include <iostream>
#include <sstream>

// Default constructor
Appointment::Appointment()
    : appointmentId(""), patient(nullptr), doctor(nullptr),
      date(""), time(""), status("scheduled"), notes("") {}

// Parameterized constructor
Appointment::Appointment(string id, Patient *patient, Doctor *doctor,
                         string date, string time)
    : appointmentId(id), patient(patient), doctor(doctor),
      date(date), time(time), status("scheduled"), notes("") {}

// Destructor
Appointment::~Appointment()
{
    // Note: We don't delete patient and doctor here as they are managed by ClinicManager
}

// Getters
string Appointment::getAppointmentId() const
{
    return appointmentId;
}

Patient *Appointment::getPatient() const
{
    return patient;
}

Doctor *Appointment::getDoctor() const
{
    return doctor;
}

string Appointment::getDate() const
{
    return date;
}

string Appointment::getTime() const
{
    return time;
}

string Appointment::getStatus() const
{
    return status;
}

string Appointment::getNotes() const
{
    return notes;
}

// Setters
void Appointment::setDate(const string &date)
{
    this->date = date;
}

void Appointment::setTime(const string &time)
{
    this->time = time;
}

void Appointment::setStatus(const string &status)
{
    this->status = status;
}

void Appointment::setNotes(const string &notes)
{
    this->notes = notes;
}

// Display appointment information
void Appointment::display() const
{
    cout << "======================================" << endl;
    cout << "        APPOINTMENT DETAILS           " << endl;
    cout << "======================================" << endl;
    cout << "Appointment ID : " << appointmentId << endl;
    cout << "Date           : " << date << endl;
    cout << "Time           : " << time << endl;
    cout << "Status         : " << status << endl;

    if (patient)
    {
        cout << "Patient        : " << patient->getName()
             << " (ID: " << patient->getId() << ")" << endl;
    }

    if (doctor)
    {
        cout << "Doctor         : " << doctor->getName()
             << " (ID: " << doctor->getId() << ")" << endl;
        cout << "Specialization : " << doctor->getSpecialization() << endl;
    }

    if (!notes.empty())
    {
        cout << "Notes          : " << notes << endl;
    }
    cout << "======================================" << endl;
}

// Convert appointment to string format for file storage
string Appointment::toString() const
{
    stringstream ss;
    ss << "APPOINTMENT|" << appointmentId << "|";

    if (patient)
    {
        ss << patient->getId();
    }
    ss << "|";

    if (doctor)
    {
        ss << doctor->getId();
    }
    ss << "|" << date << "|" << time << "|" << status << "|" << notes;

    return ss.str();
}
