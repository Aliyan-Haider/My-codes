#include <iostream>
#include <limits>

int main(){

    int year;
    int flag = 1;

    while(flag != 0){

        std::cout << "Enter year: ";
        std::cin >> year;

        if (std::cin.fail()){

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Inavlid." << std::endl;

            continue;
        }
        flag = 0;
    }
    if (year % 4 == 0){

        std::cout << year << " is a leap year.";
    }
    else{

        std::cout << year << " is not a leap year.";
    }
}