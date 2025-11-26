#include "Person.h"

// Default constructor
Person::Person() : id(""), name(""), phone(""), address("") {}

// Parameterized constructor
Person::Person(string id, string name, string phone, string address)
    : id(id), name(name), phone(phone), address(address) {}

// Virtual destructor
Person::~Person() {}

// Getters
string Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

string Person::getPhone() const
{
    return phone;
}

string Person::getAddress() const
{
    return address;
}

// Setters
void Person::setName(const string &name)
{
    this->name = name;
}

void Person::setPhone(const string &phone)
{
    this->phone = phone;
}

void Person::setAddress(const string &address)
{
    this->address = address;
}
