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

        auto var1 = parser.get_value<std::string>("Section1.var1");
    } catch (const FileError& ex) {
        std::cerr << "Configuration error: " << ex.what() << "\n";
    } catch (const SyntaxError& ex) {
        std::cerr << "Syntax error: " << ex.what() << "\n";
    } catch (const IniException& ex) {
        std::cerr << "INI error: " << ex.what() << "\n";
    }

    std::cout << "End of programm" << std::endl;

    return 0;
}