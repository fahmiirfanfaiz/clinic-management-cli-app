#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

/**
 * Abstract base class Person
 * Represents a person with basic information
 * Uses encapsulation and polymorphism principles
 */
class Person
{
protected:
    string id;
    string name;
    string phone;
    string address;

public:
    // Constructors
    Person();
    Person(string id, string name, string phone, string address);

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Person();

    // Getters
    string getId() const;
    string getName() const;
    string getPhone() const;
    string getAddress() const;

    // Setters
    void setName(const string &name);
    void setPhone(const string &phone);
    void setAddress(const string &address);

    // Pure virtual functions - must be implemented by derived classes
    virtual void display() const = 0;
    virtual string toString() const = 0;
};

#endif // PERSON_H
