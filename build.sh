#!/bin/bash

# Build script for Linux/Mac

echo "========================================"
echo "  Clinic Management System - Build     "
echo "========================================"
echo ""

# Check if g++ is available
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found!"
    echo "Please install g++ compiler."
    exit 1
fi

echo "Compiler found: $(which g++)"
echo ""

# Create obj directory if it doesn't exist
if [ ! -d "obj" ]; then
    mkdir obj
    echo "Created obj directory"
fi

# Compile
echo "Compiling source files..."

OBJ_FILES=""

for file in src/*.cpp; do
    filename=$(basename "$file" .cpp)
    echo "  Compiling $filename.cpp..."
    
    g++ -I include -c "$file" -o "obj/$filename.o" -std=c++11
    
    if [ $? -ne 0 ]; then
        echo "Compilation failed for $filename.cpp!"
        exit 1
    fi
    
    OBJ_FILES="$OBJ_FILES obj/$filename.o"
done

echo ""
echo "Linking object files..."

g++ -o klinik $OBJ_FILES

if [ $? -ne 0 ]; then
    echo "Linking failed!"
    exit 1
fi

# Make executable
chmod +x klinik

echo ""
echo "========================================"
echo "  Build Successful!                    "
echo "========================================"
echo ""
echo "Run the application with: ./klinik"
echo ""
