#include <iostream>
#include <limits>

int main(){

    int first_num, second_num, third_num, largest_num;
    
    int flag = 1;
    while(flag != 0){
        
        std::cout << "Enter first number: ";
        std::cin >> first_num;
        
        if (std::cin.fail()){
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid." << std::endl;
            
            continue;
        }
        flag = 0;
    }
    flag = 1;
    while(flag != 0){
        
        std::cout << "Enter second number: ";
        std::cin >> second_num;
        
        if (std::cin.fail()){
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid." << std::endl;
            
            continue;
        }
        flag = 0;
    }
    flag = 1;
    while(flag != 0){
        
        std::cout << "Enter third number: ";
        std::cin >> third_num;
        
        if (std::cin.fail()){
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid." << std::endl;
            
            continue;
        }
        flag = 0;
    }
    
    if (first_num >= second_num){

        largest_num = first_num;
    }
    else{

        largest_num = second_num;
    }

    if (largest_num > third_num){

        std::cout << largest_num;
    }
    else{

        std::cout << third_num;
    }

}