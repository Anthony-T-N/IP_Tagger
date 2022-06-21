#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <regex>

std::vector<std::string> extension_blacklist = { ".gif", ".jpeg", ".png", ".jpg", ".exe", ".tif", ".7z", ".py" };

int scan_dir(std::vector<std::string> &dir_vector)
{
    std::string input_file_line;
    std::ifstream input_file;
    std::string user_input;
    std::regex rgx(R"(\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b)");
    for (int i = 0; i <= dir_vector.size() - 1; i++)
    {   
        std::smatch match;
        std::cout << "\n";
        std::cout << "[+] Opening file: " << dir_vector[i] << "\n\n";
        input_file.open(dir_vector[i]);
        while (std::getline(input_file, input_file_line))
        {
            if (std::regex_match(input_file_line, match, rgx))
            {
                std::cout << "NNN: " << input_file_line << "\n";
                std::cout << "Match: " << match[0] << '\n';
            }
            /*
            //std::cout << input_file_line << "\n";
            if (input_file_line.find("1") != std::string::npos)
            {
                std::cout << input_file_line << " END " << "\n\n";
            }
            */
        }
        input_file.close();
    }
    return 1;
}

int main()
{
    std::cout << "=======================================" << "\n";
    std::cout << "- IP_Tagger console application" << "\n";
    std::cout << "- Console Application Version: 1.0" << "\n";
    std::cout << "- Created By: Anthony-T-N." << "\n";
    std::cout << "- Current location of executable: " << std::filesystem::current_path() << "\n";
    std::cout << "=======================================" << "\n\n";
    std::vector<std::string> dir_vector;
    std::ifstream input_file;
    std::string user_input;
    std::cout << "Show current directoy files" << "\n";
    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        if (entry.is_directory())
        {
            std::cout << entry.path() << "\n";
        }
        else if (entry.path().has_extension())
        {
            for (int i = 0; i <= extension_blacklist.size() - 1; i++)
            {
                if (entry.path().extension() == (extension_blacklist[i]))
                {
                    std::cout << "Skipping.. | Path contains: " << extension_blacklist[i] << "\n";
                    continue;
                }
            }
            std::cout << entry.path() << "\n";
            dir_vector.push_back(entry.path().string());
        }
    }
    while (true)
    {
        /*
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
            {
                std::cout << entry.path() << "\n";
            }
        }
        */
        scan_dir(dir_vector);
        std::cout << "\n";
        std::cout << "[!] END" << "\n";
        std::cout << "[!] Exiting..." << "\n\n";
        std::cin.get();
    }
    return 0;
}
