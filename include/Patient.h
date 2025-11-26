#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

/**
 * Patient class - inherits from Person
 * Represents a patient in the clinic
 */
class Patient : public Person
{
private:
    string dateOfBirth;
    string gender;
    string bloodType;

public:
    // Constructors
    Patient();
    Patient(string id, string name, string phone, string address,
            string dob, string gender, string bloodType);

    // Destructor
    ~Patient();

    // Getters
    string getDateOfBirth() const;
    string getGender() const;
    string getBloodType() const;

    // Setters
    void setDateOfBirth(const string &dob);
    void setGender(const string &gender);
    void setBloodType(const string &bloodType);

    // Override virtual functions from Person
    void display() const override;
    string toString() const override;
};

#endif // PATIENT_H
