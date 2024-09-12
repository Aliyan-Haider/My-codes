#include <iostream>
#include <limits>

int main(){

    int day_num;
    int flag = 1;

    while(flag != 0){

        std::cout << "Enter the number of the day of the week: ";
        std::cin >> day_num;

        if (std::cin.fail()){

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid." << std::endl;

            continue;

        }
        switch (day_num)
        {
            case 1:
                
                std::cout << "Monday.";
                flag = 0;
                
                break;
            
            case 2:
                
                std::cout << "Tuesday.";
                flag = 0;

                break;

            case 3:
                
                std::cout << "Wednesday.";
                flag = 0;

                break;

            case 4:
                
                std::cout << "Thursday.";
                flag = 0;

                break;

            case 5:
                
                std::cout << "Friday.";
                flag = 0;

                break;

            case 6:
                
                std::cout << "Saturday.";
                flag = 0;

                break;

            case 7:
                
                std::cout << "sunday.";
                flag = 0;

                break;

            default:

                std::cout << "Invalid." << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}