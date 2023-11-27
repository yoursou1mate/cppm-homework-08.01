//
//  main.cpp
//  cppm-homework-08.01
//
//  Created by a1ex on 11/25/23.
//

#include <iostream>
#include <exception>


 class Check_length : public std::exception
{
public:
    const  char* what() const noexcept override
    {
        return "You entered a word with forbidden length. Good bye!";
    }
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) throw Check_length();
    return str.length();
}

int main(int argc, const char * argv[]) {
  
    int forbidden_length;
    std::string str;
    std::cout << "Please enter forbidden length: ";
    std::cin >> forbidden_length;
//    std::cout << '\n' << "Enter a word: ";
//    std::cin >> str;
    
    try
    {
        for (;;)
        {
            function(str, forbidden_length);
            std::cout << '\n' << "Enter a word: ";
            std::cin >> str;
            if (str.length() != forbidden_length)
            {
                std::cout << '\n';
                std::cout << "The word " << '"' << str << '"' << " length is: " << str.length() << std::endl;
            }
        }
    }
    catch (const Check_length& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}
