#include "Patient.h"
#include <iostream>
#include <sstream>

// Default constructor
Patient::Patient() : Person(), dateOfBirth(""), gender(""), bloodType("") {}

// Parameterized constructor
Patient::Patient(string id, string name, string phone, string address,
                 string dob, string gender, string bloodType)
    : Person(id, name, phone, address),
      dateOfBirth(dob), gender(gender), bloodType(bloodType) {}

// Destructor
Patient::~Patient() {}

// Getters
string Patient::getDateOfBirth() const
{
    return dateOfBirth;
}

string Patient::getGender() const
{
    return gender;
}

string Patient::getBloodType() const
{
    return bloodType;
}

// Setters
void Patient::setDateOfBirth(const string &dob)
{
    this->dateOfBirth = dob;
}

void Patient::setGender(const string &gender)
{
    this->gender = gender;
}

void Patient::setBloodType(const string &bloodType)
{
    this->bloodType = bloodType;
}

// Display patient information
void Patient::display() const
{
    cout << "======================================" << endl;
    cout << "           PATIENT DETAILS            " << endl;
    cout << "======================================" << endl;
    cout << "ID            : " << id << endl;
    cout << "Name          : " << name << endl;
    cout << "Date of Birth : " << dateOfBirth << endl;
    cout << "Gender        : " << gender << endl;
    cout << "Blood Type    : " << bloodType << endl;
    cout << "Phone         : " << phone << endl;
    cout << "Address       : " << address << endl;
    cout << "======================================" << endl;
}

// Convert patient to string format for file storage
string Patient::toString() const
{
    stringstream ss;
    ss << "PATIENT|" << id << "|" << name << "|" << phone << "|"
       << address << "|" << dateOfBirth << "|" << gender << "|" << bloodType;
    return ss.str();
}
