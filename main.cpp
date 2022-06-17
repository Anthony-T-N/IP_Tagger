#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
    std::cout << "=======================================" << "\n";
    std::cout << "- IP_Tagger console application" << "\n";
    std::cout << "- Console Application Version: 1.0" << "\n";
    std::cout << "- Created By: Anthony-T-N." << "\n";
    std::cout << "- Current location of executable: " << std::filesystem::current_path() << "\n";
    std::cout << "=======================================" << "\n\n";
    std::vector<std::string> dir_vector;
    std::string input_file_line;
    std::ifstream input_file;
    std::string user_input;
    std::cout << "[>] Select directory to check:" << "\n";
    std::getline(std::cin, user_input);
    std::cout << "\n";
    if (std::filesystem::is_directory(user_input) == 0)
    {
        std::cout << "[!] Entered user input does not exist." << "\n";
    }
    else
    {
        // List all files within selected directory
        for (const auto& entry : std::filesystem::directory_iterator(user_input))
        std::cout << entry.path() << std::endl;
    }
    input_file.open(user_input);
    while (std::getline(input_file, input_file_line))
    {
        //std::cout << input_file_line << "\n";
        if (input_file_line.find("1") != std::string::npos)
        {
            std::cout << input_file_line << " END " << "\n\n";
        }
    }
    input_file.close();
    std::cout << "[!] END" << "\n";
    std::cout << "[!] Exiting..." << "\n\n";
    std::cin.get();
    return 0;
}
