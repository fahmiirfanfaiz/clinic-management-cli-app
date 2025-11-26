#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "ClinicManager.h"
#include <string>
using namespace std;

/**
 * FileHandler class
 * Handles file I/O operations for loading and saving clinic data
 */
class FileHandler
{
private:
    string inputFileName;
    string outputFileName;

    // Helper functions for parsing
    Patient *parsePatient(const string &line);
    Doctor *parseDoctor(const string &line);
    Appointment *parseAppointment(const string &line, ClinicManager *manager);
    MedicalRecord *parseMedicalRecord(const string &line, ClinicManager *manager);

public:
    // Constructors
    FileHandler();
    FileHandler(const string &inputFile, const string &outputFile);

    // Destructor
    ~FileHandler();

    // File operations
    bool loadData(ClinicManager *manager);
    bool saveData(ClinicManager *manager);
    bool exportReport(ClinicManager *manager, const string &reportFile);

    // Setters
    void setInputFile(const string &filename);
    void setOutputFile(const string &filename);
};

#endif // FILEHANDLER_H
