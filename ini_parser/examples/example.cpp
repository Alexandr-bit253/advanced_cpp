#include <iostream>
#include <print>

#include "..\include\IniParser.hpp"
#include "..\include\Exceptions.hpp"


int main() {
    try {
        IniParser parser;
    } catch (const FileError& ex) {
        std::cerr << "Configuration error: " << ex.what() << std::endl;
        
    }

    std::cout << "End of programm" << std::endl;
    
    return 0;
}