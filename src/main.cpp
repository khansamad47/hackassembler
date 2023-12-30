#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <hack_parser.h>
#include <hack_instruction.h>
#include <hack_code.h>
#include <cxxopts.hpp>

int main(int argc, char* argv[])
{
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

    // Access optional positional argument with a default value
    std::string outputFileName = result["output"].as<std::string>();
    std::string inputfile = result["asmfile"].as<std::string>();
    std::ifstream file;
    file.open(inputfile);
    if (!file.is_open())
    {
        std::cerr << "Could not open file " << inputfile << std::endl;
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
    while(std::getline(file, line))
    {
        // Remove comments and white spaces and trim string
        line = parser.removeCommentsAndWhiteSpaces(line);
        // If empty line skip 
        if (line.empty()) { continue; }
        //instructions.emplace_back(hack::Parser::convert(line));
        std::unique_ptr<hack::Instruction> in = parser.convert(line);
        outputFile << in->code() << '\n';
    }
    file.close();
    outputFile.close();

    return 0;
}