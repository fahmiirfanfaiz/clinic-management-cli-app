#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Default constructor
FileHandler::FileHandler()
    : inputFileName("data/input.txt"), outputFileName("data/output.txt") {}

// Parameterized constructor
FileHandler::FileHandler(const string &inputFile, const string &outputFile)
    : inputFileName(inputFile), outputFileName(outputFile) {}

// Destructor
FileHandler::~FileHandler() {}

// Parse patient data from file line
Patient *FileHandler::parsePatient(const string &line)
{
    stringstream ss(line);
    string type, id, name, phone, address, dob, gender, bloodType;

    getline(ss, type, '|');
    if (type != "PATIENT")
        return nullptr;

    getline(ss, id, '|');
    getline(ss, name, '|');
    getline(ss, phone, '|');
    getline(ss, address, '|');
    getline(ss, dob, '|');
    getline(ss, gender, '|');
    getline(ss, bloodType, '|');

    return new Patient(id, name, phone, address, dob, gender, bloodType);
}

// Parse doctor data from file line
Doctor *FileHandler::parseDoctor(const string &line)
{
    stringstream ss(line);
    string type, id, name, phone, address, specialization, licenseNumber, schedule;

    getline(ss, type, '|');
    if (type != "DOCTOR")
        return nullptr;

    getline(ss, id, '|');
    getline(ss, name, '|');
    getline(ss, phone, '|');
    getline(ss, address, '|');
    getline(ss, specialization, '|');
    getline(ss, licenseNumber, '|');
    getline(ss, schedule, '|');

    return new Doctor(id, name, phone, address, specialization, licenseNumber, schedule);
}

// Parse appointment data from file line
Appointment *FileHandler::parseAppointment(const string &line, ClinicManager *manager)
{
    stringstream ss(line);
    string type, id, patientId, doctorId, date, time, status, notes;

    getline(ss, type, '|');
    if (type != "APPOINTMENT")
        return nullptr;

    getline(ss, id, '|');
    getline(ss, patientId, '|');
    getline(ss, doctorId, '|');
    getline(ss, date, '|');
    getline(ss, time, '|');
    getline(ss, status, '|');
    getline(ss, notes, '|');

    Patient *patient = manager->findPatient(patientId);
    Doctor *doctor = manager->findDoctor(doctorId);

    if (!patient || !doctor)
        return nullptr;

    Appointment *apt = new Appointment(id, patient, doctor, date, time);
    apt->setStatus(status);
    apt->setNotes(notes);

    return apt;
}

// Parse medical record data from file line
MedicalRecord *FileHandler::parseMedicalRecord(const string &line, ClinicManager *manager)
{
    stringstream ss(line);
    string type, id, appointmentId, diagnosis, treatment, prescription, recordDate;

    getline(ss, type, '|');
    if (type != "MEDICALRECORD")
        return nullptr;

    getline(ss, id, '|');
    getline(ss, appointmentId, '|');
    getline(ss, diagnosis, '|');
    getline(ss, treatment, '|');
    getline(ss, prescription, '|');
    getline(ss, recordDate, '|');

    Appointment *appointment = manager->findAppointment(appointmentId);

    if (!appointment)
        return nullptr;

    return new MedicalRecord(id, appointment, diagnosis, treatment, prescription, recordDate);
}

// Load data from input file
bool FileHandler::loadData(ClinicManager *manager)
{
    ifstream inFile(inputFileName);

    if (!inFile.is_open())
    {
        cout << "Warning: Could not open input file: " << inputFileName << endl;
        cout << "Starting with empty database." << endl;
        return false;
    }

    string line;
    int patientCount = 0, doctorCount = 0, appointmentCount = 0, recordCount = 0;

    // First pass: Load patients and doctors
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;

        if (line.find("PATIENT|") == 0)
        {
            Patient *patient = parsePatient(line);
            if (patient)
            {
                manager->addPatient(patient);
                patientCount++;
            }
        }
        else if (line.find("DOCTOR|") == 0)
        {
            Doctor *doctor = parseDoctor(line);
            if (doctor)
            {
                manager->addDoctor(doctor);
                doctorCount++;
            }
        }
    }

    // Reset file stream for second pass
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Second pass: Load appointments
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;

        if (line.find("APPOINTMENT|") == 0)
        {
            Appointment *appointment = parseAppointment(line, manager);
            if (appointment)
            {
                manager->createAppointment(appointment);
                appointmentCount++;
            }
        }
    }

    // Reset file stream for third pass
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Third pass: Load medical records
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;

        if (line.find("MEDICALRECORD|") == 0)
        {
            MedicalRecord *record = parseMedicalRecord(line, manager);
            if (record)
            {
                manager->addMedicalRecord(record);
                recordCount++;
            }
        }
    }

    inFile.close();

    cout << "\n========================================" << endl;
    cout << "      DATA LOADED SUCCESSFULLY          " << endl;
    cout << "========================================" << endl;
    cout << "Patients loaded      : " << patientCount << endl;
    cout << "Doctors loaded       : " << doctorCount << endl;
    cout << "Appointments loaded  : " << appointmentCount << endl;
    cout << "Medical records loaded: " << recordCount << endl;
    cout << "========================================\n"
         << endl;

    return true;
}

// Save data to output file
bool FileHandler::saveData(ClinicManager *manager)
{
    ofstream outFile(outputFileName);

    if (!outFile.is_open())
    {
        cout << "Error: Could not open output file: " << outputFileName << endl;
        return false;
    }

    // Save patients
    for (Patient *patient : manager->getPatients())
    {
        outFile << patient->toString() << endl;
    }

    // Save doctors
    for (Doctor *doctor : manager->getDoctors())
    {
        outFile << doctor->toString() << endl;
    }

    // Save appointments
    for (Appointment *apt : manager->getAppointments())
    {
        outFile << apt->toString() << endl;
    }

    // Save medical records
    for (MedicalRecord *record : manager->getMedicalRecords())
    {
        outFile << record->toString() << endl;
    }

    outFile.close();

    cout << "\nData saved successfully to " << outputFileName << endl;
    return true;
}

// Export report to file
bool FileHandler::exportReport(ClinicManager *manager, const string &reportFile)
{
    ofstream report(reportFile);

    if (!report.is_open())
    {
        cout << "Error: Could not create report file: " << reportFile << endl;
        return false;
    }

    report << "========================================" << endl;
    report << "     CLINIC MANAGEMENT SYSTEM REPORT    " << endl;
    report << "========================================" << endl;
    report << "\nSUMMARY:" << endl;
    report << "Total Patients        : " << manager->getPatientsCount() << endl;
    report << "Total Doctors         : " << manager->getDoctorsCount() << endl;
    report << "Total Appointments    : " << manager->getAppointmentsCount() << endl;
    report << "Total Medical Records : " << manager->getMedicalRecordsCount() << endl;

    report << "\n\n========================================" << endl;
    report << "           PATIENT LIST                 " << endl;
    report << "========================================" << endl;

    for (Patient *patient : manager->getPatients())
    {
        report << "\nID: " << patient->getId() << endl;
        report << "Name: " << patient->getName() << endl;
        report << "Gender: " << patient->getGender() << endl;
        report << "Blood Type: " << patient->getBloodType() << endl;
        report << "Phone: " << patient->getPhone() << endl;
        report << "----------------------------------------" << endl;
    }

    report << "\n\n========================================" << endl;
    report << "           DOCTOR LIST                  " << endl;
    report << "========================================" << endl;

    for (Doctor *doctor : manager->getDoctors())
    {
        report << "\nID: " << doctor->getId() << endl;
        report << "Name: " << doctor->getName() << endl;
        report << "Specialization: " << doctor->getSpecialization() << endl;
        report << "License: " << doctor->getLicenseNumber() << endl;
        report << "Phone: " << doctor->getPhone() << endl;
        report << "----------------------------------------" << endl;
    }

    report.close();

    cout << "\nReport exported successfully to " << reportFile << endl;
    return true;
}

// Setters
void FileHandler::setInputFile(const string &filename)
{
    inputFileName = filename;
}

void FileHandler::setOutputFile(const string &filename)
{
    outputFileName = filename;
}
