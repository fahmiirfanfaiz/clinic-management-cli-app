# Compilation Guide

## Prerequisites

- C++ Compiler (g++/MinGW for Windows, g++ for Linux/Mac)
- C++11 or higher support

## For Windows (using MinGW)

### Option 1: Compile all files at once

```powershell
g++ -I include -o klinik.exe src/*.cpp -std=c++11
```

### Option 2: Compile individually

```powershell
g++ -I include -c src/Person.cpp -std=c++11
g++ -I include -c src/Patient.cpp -std=c++11
g++ -I include -c src/Doctor.cpp -std=c++11
g++ -I include -c src/Appointment.cpp -std=c++11
g++ -I include -c src/MedicalRecord.cpp -std=c++11
g++ -I include -c src/ClinicManager.cpp -std=c++11
g++ -I include -c src/FileHandler.cpp -std=c++11
g++ -I include -c src/main.cpp -std=c++11
g++ -o klinik.exe *.o
```

## For Linux/Mac

### Option 1: Compile all files at once

```bash
g++ -I include -o klinik src/*.cpp -std=c++11
```

### Option 2: Compile individually

```bash
g++ -I include -c src/Person.cpp -std=c++11
g++ -I include -c src/Patient.cpp -std=c++11
g++ -I include -c src/Doctor.cpp -std=c++11
g++ -I include -c src/Appointment.cpp -std=c++11
g++ -I include -c src/MedicalRecord.cpp -std=c++11
g++ -I include -c src/ClinicManager.cpp -std=c++11
g++ -I include -c src/FileHandler.cpp -std=c++11
g++ -I include -c src/main.cpp -std=c++11
g++ -o klinik *.o
```

## Running the Application

### Windows

```powershell
.\klinik.exe
```

### Linux/Mac

```bash
./klinik
```

## Troubleshooting

### Error: "No such file or directory"

- Make sure you're in the project root directory
- Verify that `include/` and `src/` directories exist

### Error: "undefined reference"

- Make sure all .cpp files are included in compilation
- Check that all header files are in the `include/` directory

### Error: "permission denied"

On Linux/Mac, you may need to make the file executable:

```bash
chmod +x klinik
```

## Using Visual Studio Code

If you're using VS Code, create a `tasks.json` file in `.vscode/` directory:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build Clinic App",
      "type": "shell",
      "command": "g++",
      "args": ["-I", "include", "-o", "klinik", "src/*.cpp", "-std=c++11"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

Then press `Ctrl+Shift+B` to build.

## Notes

- The application will automatically create `data/output.txt` if it doesn't exist
- Make sure `data/input.txt` exists before running for the first time
- All changes are auto-saved to `output.txt` when you exit the application
