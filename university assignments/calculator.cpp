#include <cctype>
#include <iostream>
#include <limits>
#include <string>

int main(){

    int flag = 1;
    while(flag != 0){

        int num_1, num_2;
        char command[3];
        
        int flag_2 = 1;
        while(flag_2 != 0){

            std::cout << "Enter first number: ";
            std::cin >> num_1;

            if (std::cin.fail()){

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid." << std::endl;

                continue;
            }
            flag_2 = 0;
        }
        flag_2 = 1;
        while (flag_2 != 0){

            std::cout << "Enter second number: ";
            std::cin >> num_2;

            if (std::cin.fail()){

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid." << std::endl;

                continue;
            }
            flag_2 = 0;
        }
        flag_2 = 1;
        while(flag_2 != 0){

            std::cout << std::endl
                    << "Choose one of the operations:\n"
                    << "Addition(A)\n"
                    << "Subtraction(S)\n"
                    << "Multiplication(M)\n"
                    << "Division(D)\n"
                    << "Quit(Q)\n"
                    << std::endl
                    << "Enter: ";
                    
            std::cin >> command;

            if (command[1] != '\0'){

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid." << std::endl;
                
                continue;
            }
            flag_2 = 0;
        }
        command[0] = std::tolower(command[0]);

        switch (command[0]){

            case 'a':

                std::cout << num_1 + num_2 << std::endl;

                break;
            
            case 's':

                std::cout << num_1 - num_2 << std::endl;

                break;
            
            case 'm':

                std::cout << num_1 * num_2 << std::endl;

                break;
            
            case 'd':

                std::cout << float(num_1) / num_2 << std::endl;

                break;

            case 'q':

                flag = 0;

                break;
            
            default:

                std::cout << "Invalid." << std::endl;

                break;
        }
    }
}