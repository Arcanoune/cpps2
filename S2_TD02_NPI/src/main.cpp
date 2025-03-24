#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    bool point_found = false;
    if (s.empty() || s.front() == '.' || s.back() == '.') 
        return false;
    

    for (char c : s)
    {
        if (c == '.')
        {
            if (point_found)
                return false;
            point_found = true;
        }
        else if (!std::isdigit(c))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::string npi;

    std::cout << "NPI (operateurs et entre 0 et 9) : \n";
    std::getline(std::cin, npi);

    bool valide = true;
    for (char c : npi)
    {
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == ' '))
        {
            valide = false;
            break;
        }
    }

    if (valide)
    {
        std::vector<std::string> tokens = split_string(npi);
        std::cout << "Tokens : ";
        for (const std::string &token : tokens)
        {
            std::cout << token << ", ";

            // for (char c : token)
            if (is_floating(token))
                std::cout << "lfksjd" << token;
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "operateur et entre 0 et 9\n";
    }

    return 0;
}