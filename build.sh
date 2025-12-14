#!/bin/bash
# Build script for Clinic Management CLI App (Linux/Mac)
# Compiles all C++ source files and creates Klinik executable

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${CYAN}========================================"
echo -e " Clinic Management CLI App - Builder"
echo -e "========================================${NC}"
echo ""

# Configuration
COMPILER="g++"
OUTPUT="Klinik"
INCLUDE_DIR="include"
SRC_DIR="src"
SOURCES=$(find "$SRC_DIR" -name "*.cpp" 2>/dev/null)
CXXFLAGS="-std=c++11 -Wall -I $INCLUDE_DIR"

# Check if g++ is installed
echo -e "${YELLOW}[1/4] Checking compiler...${NC}"
if ! command -v $COMPILER &> /dev/null; then
    echo -e "${RED}✗ Error: g++ compiler not found!${NC}"
    echo -e "${RED}Please install g++ using:${NC}"
    echo -e "${RED}  Ubuntu/Debian: sudo apt install g++ make${NC}"
    echo -e "${RED}  macOS: xcode-select --install${NC}"
    exit 1
fi
echo -e "${GREEN}✓ g++ compiler found${NC}"

# Check source files
echo ""
echo -e "${YELLOW}[2/4] Checking source files...${NC}"
if [ -z "$SOURCES" ]; then
    echo -e "${RED}✗ Error: No .cpp files found in $SRC_DIR/${NC}"
    exit 1
fi
SOURCE_COUNT=$(echo "$SOURCES" | wc -l | tr -d ' ')
echo -e "${GREEN}✓ Found $SOURCE_COUNT source file(s)${NC}"

# Compile
echo ""
echo -e "${YELLOW}[3/4] Compiling...${NC}"
echo -e "\033[0;37mCommand: $COMPILER $CXXFLAGS -o $OUTPUT $SOURCES${NC}"

if $COMPILER $CXXFLAGS -o $OUTPUT $SOURCES; then
    echo -e "${GREEN}✓ Compilation successful${NC}"
else
    echo -e "${RED}✗ Compilation failed!${NC}"
    exit 1
fi

# Verify output
echo ""
echo -e "${YELLOW}[4/4] Verifying output...${NC}"
if [ -f "$OUTPUT" ]; then
    FILE_SIZE=$(ls -lh "$OUTPUT" | awk '{print $5}')
    echo -e "${GREEN}✓ Executable created: $OUTPUT ($FILE_SIZE)${NC}"
    chmod +x "$OUTPUT"
    echo -e "${GREEN}✓ Execute permission granted${NC}"
else
    echo -e "${RED}✗ Error: Output file not created!${NC}"
    exit 1
fi

# Success
echo ""
echo -e "${GREEN}========================================"
echo -e " Build Completed Successfully! "
echo -e "========================================${NC}"
echo ""
echo -e "${CYAN}To run the application, execute:${NC}"
echo -e "  ./$OUTPUT"
echo ""
