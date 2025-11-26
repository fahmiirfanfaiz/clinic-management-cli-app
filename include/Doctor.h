#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include <string>
using namespace std;

/**
 * Doctor class - inherits from Person
 * Represents a doctor in the clinic
 */
class Doctor : public Person
{
private:
    string specialization;
    string licenseNumber;
    string schedule;

public:
    // Constructors
    Doctor();
    Doctor(string id, string name, string phone, string address,
           string specialization, string licenseNumber, string schedule);

    // Destructor
    ~Doctor();

    // Getters
    string getSpecialization() const;
    string getLicenseNumber() const;
    string getSchedule() const;

    // Setters
    void setSpecialization(const string &specialization);
    void setLicenseNumber(const string &licenseNumber);
    void setSchedule(const string &schedule);

    // Override virtual functions from Person
    void display() const override;
    string toString() const override;
};

#endif // DOCTOR_H
