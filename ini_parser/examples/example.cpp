#include <iostream>

#include "..\include\Exceptions.hpp"
#include "..\include\IniParser.hpp"
#include "..\include\StdFileReader.hpp"

const std::string PATH{
    "C:\\Users\\OBI_1_KENOBI\\source\\repos\\advanced_cpp\\ini_"
    "parser\\examples\\example.ini"};

int main() {
    try {
        IniParser parser(std::make_unique<StdFileReader>());
        parser.load(PATH);

        auto var2 = parser.get_value<std::string>("Section1.var2");
        std::cout << var2 << std::endl;

        auto var1 = parser.get_value<double>("Section1.var1");
        std::cout << var1 << std::endl;
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