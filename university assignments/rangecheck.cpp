#include <iostream>

int main(){

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num >= 1 && num <= 100){

        std::cout << "Within range.";
    }
    else{

        std::cout << "Out of range.";
    }
}