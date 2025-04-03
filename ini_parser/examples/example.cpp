#include <iostream>

#include "..\include\Exceptions.hpp"
#include "..\include\IniParser.hpp"
#include "..\include\StdFileReader.hpp"

const std::string PATH{
    "D:\\cpp_projects\\advanced_cpp\\ini_parser\\examples\\example.ini"};

int main() {
    try {
        IniParser parser(std::make_unique<StdFileReader>());
        parser.load(PATH);
    } catch (const FileError& ex) {
        std::cerr << "Configuration error: " << ex.what() << std::endl;
    }

    std::cout << "End of programm" << std::endl;

    return 0;
}