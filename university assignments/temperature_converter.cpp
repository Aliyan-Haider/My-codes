#include <cctype>
#include <iostream>
#include <limits>

int main(){

    float temp, converted;
    char temp_type;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    int flag = 1;
    while(flag != 0){
        
        std::cout << "Is the temperature in Celsius (C) or Fahrenheit (F)? ";
        std::cin >> temp_type;
        temp_type = std::tolower(temp_type);

        switch (temp_type){

            case 'c':
                std::cout << "Converted to Fahrenheit: " << temp * 1.8 + 32;
                flag = 0;

                break;
            
            case 'f':
                std::cout << "Converted to Celsius: " << temp / 1.8 - 17.77778;
                flag = 0;

                break;
            
            default:
                std::cout << "Invalid." << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}