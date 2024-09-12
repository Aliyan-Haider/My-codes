#include <iostream>

int main(){

    int percentage;

    std::cout << "Enter your percentage: ";
    std::cin >> percentage;

    if (percentage <= 100){

        if (percentage >= 90){

            std::cout << "Your grade is A.";
        }
        else if (percentage >= 80){

            std::cout << "Your grade is B.";
        }
        else if (percentage >= 70){

            std::cout << "Your grade is C.";
        }
        else if (percentage >= 60){

            std::cout << "Your grade is D.";
        }
        else{

            std::cout << "Your grade is F.";
        }
    }
    else{
        
        std::cout << "Invalid.";
    }
}