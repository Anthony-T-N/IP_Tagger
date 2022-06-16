#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string input_file_line;
    std::ifstream input_file;
    input_file.open("sample3.txt");
    while (std::getline(input_file, input_file_line))
    {
        //std::cout << input_file_line << "\n";
        if (input_file_line.find("1") != std::string::npos)
        {
            std::cout << input_file_line << " END " << "\n";
        }
    }
    input_file.close();
}
