#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <hack_parser.h>
#include <hack_instruction.h>
#include <hack_code.h>
#include <cxxopts.hpp>
#include <hack_symboltable.h>
#include <hack_specification.h>

int main(int argc, char* argv[])
{
    // Process command line arguments
    cxxopts::Options options("HackAssembler", "Converts HackAssembly to hack machine code");
    options.add_options()
        ("o,output","output machine code", cxxopts::value<std::string>()->default_value("out.hack"))
        ("asmfile","Hack assembly file", cxxopts::value<std::string>());

    options.add_options("General")
        ("h,help", "Print help")
        ; 
    options.parse_positional({"asmfile"});
    auto result = options.parse(argc,argv);
    // Check for help option
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }
    std::string outputFileName = result["output"].as<std::string>();
    std::string inputFileName = result["asmfile"].as<std::string>();

    // Process provided aseembly file
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open file " << inputFileName << std::endl;
        return 1;
    }
    std::ofstream outputFile;
    outputFile.open(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not open file " << outputFileName << std::endl;
        return 1;
    }

    std::string line;
    hack::Parser parser;
    hack::SymbolTable symbolTable;

    // initialize symbol table with all known symbols
    symbolTable.insert("R0", hack::Specification::PREDEFINED_SYMBOLS::R0);
    symbolTable.insert("R1", hack::Specification::PREDEFINED_SYMBOLS::R1);
    symbolTable.insert("R2", hack::Specification::PREDEFINED_SYMBOLS::R2);
    symbolTable.insert("R3", hack::Specification::PREDEFINED_SYMBOLS::R3);
    symbolTable.insert("R4", hack::Specification::PREDEFINED_SYMBOLS::R4);
    symbolTable.insert("R5", hack::Specification::PREDEFINED_SYMBOLS::R5);
    symbolTable.insert("R6", hack::Specification::PREDEFINED_SYMBOLS::R6);
    symbolTable.insert("R7", hack::Specification::PREDEFINED_SYMBOLS::R7);
    symbolTable.insert("R8", hack::Specification::PREDEFINED_SYMBOLS::R8);
    symbolTable.insert("R9", hack::Specification::PREDEFINED_SYMBOLS::R9);
    symbolTable.insert("R10", hack::Specification::PREDEFINED_SYMBOLS::R10);
    symbolTable.insert("R11", hack::Specification::PREDEFINED_SYMBOLS::R11);
    symbolTable.insert("R12", hack::Specification::PREDEFINED_SYMBOLS::R12);
    symbolTable.insert("R13", hack::Specification::PREDEFINED_SYMBOLS::R13);
    symbolTable.insert("R14", hack::Specification::PREDEFINED_SYMBOLS::R14);
    symbolTable.insert("R15", hack::Specification::PREDEFINED_SYMBOLS::R15);
    symbolTable.insert("SCREEN", hack::Specification::PREDEFINED_SYMBOLS::SCREEN);
    symbolTable.insert("KBD", hack::Specification::PREDEFINED_SYMBOLS::KBD);

    int instructionAddress = 0;
    while(std::getline(inputFile, line))
    {
        line = parser.removeCommentsAndWhiteSpaces(line);
        // If empty line skip 
        if (line.empty()) { continue; }
        if (line[0]=='(')
        {
            // Reference found
            std::string symbol = line.substr(1);
            symbol.pop_back();
            symbolTable.insert(symbol,instructionAddress);
        }
        else {
            instructionAddress++;
        }
    }
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);


    instructionAddress = 0;
    int unassignedAddress = 16;
    while(std::getline(inputFile, line))
    {
        // Remove comments and white spaces and trim string
        line = parser.removeCommentsAndWhiteSpaces(line);
        // If empty line skip 
        if (line.empty()) { continue; }
        if (line[0]=='(') { continue; }
        if (line[0]=='@') { 
  	    // Extract symbol
	    std::string symbol = line.substr(1);	
	    std::regex pattern("[0-9]+");
	    if (!std::regex_match(symbol, pattern))
	    {
	   	if (!symbolTable.contains(symbol))
		{
		    // Assign memory address to symbol
		    symbolTable.insert(symbol, unassignedAddress);
		    unassignedAddress++;
		}
		line = "@" + std::to_string(symbolTable.lookup(symbol));
	    }
	}
        std::unique_ptr<hack::Instruction> in = parser.convert(line);
        outputFile << in->code() << '\n';
        instructionAddress++;
    }
    inputFile.close();
    outputFile.close();

    return 0;
}
