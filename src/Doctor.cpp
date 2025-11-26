#include "Doctor.h"
#include <iostream>
#include <sstream>

// Default constructor
Doctor::Doctor() : Person(), specialization(""), licenseNumber(""), schedule("") {}

// Parameterized constructor
Doctor::Doctor(string id, string name, string phone, string address,
               string specialization, string licenseNumber, string schedule)
    : Person(id, name, phone, address),
      specialization(specialization), licenseNumber(licenseNumber), schedule(schedule) {}

// Destructor
Doctor::~Doctor() {}

// Getters
string Doctor::getSpecialization() const
{
    return specialization;
}

string Doctor::getLicenseNumber() const
{
    return licenseNumber;
}

string Doctor::getSchedule() const
{
    return schedule;
}

// Setters
void Doctor::setSpecialization(const string &specialization)
{
    this->specialization = specialization;
}

void Doctor::setLicenseNumber(const string &licenseNumber)
{
    this->licenseNumber = licenseNumber;
}

void Doctor::setSchedule(const string &schedule)
{
    this->schedule = schedule;
}

// Display doctor information
void Doctor::display() const
{
    cout << "======================================" << endl;
    cout << "           DOCTOR DETAILS             " << endl;
    cout << "======================================" << endl;
    cout << "ID              : " << id << endl;
    cout << "Name            : " << name << endl;
    cout << "Specialization  : " << specialization << endl;
    cout << "License Number  : " << licenseNumber << endl;
    cout << "Schedule        : " << schedule << endl;
    cout << "Phone           : " << phone << endl;
    cout << "Address         : " << address << endl;
    cout << "======================================" << endl;
}

// Convert doctor to string format for file storage
string Doctor::toString() const
{
    stringstream ss;
    ss << "DOCTOR|" << id << "|" << name << "|" << phone << "|"
       << address << "|" << specialization << "|" << licenseNumber << "|" << schedule;
    return ss.str();
}
