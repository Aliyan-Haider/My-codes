#include <iostream>

int main(){

    //length is the maximum number up to which the program
    //will print, while height is the total height of the
    //pattern.
    int height, length;
    std::cout << "Enter number: ";
    std::cin >> length;
    height = length + (length - 1);
    
    //The first for-loop will print the height of the
    //pattern.
    for(int i = 0; i < height; i++){
        
        //The if-statement checks whether the descending
        //pattern has been printed. Its parameter makes
        //sure the value of length isn't 0, otherwise a gap
        //will be printed, and the ascending pattern will
        //be unfinished.
        if (i >= height / 2){
            
            for(int limit_1 = 1; limit_1 <= length; limit_1++){
                
                std::cout << limit_1 << " ";
            }
            length++;
        }
        //The else-statement prints the descending pattern.
        else{

            int j = height / 2 + 1;

            for(int limit_2 = length; limit_2 > 0; limit_2--){
                
                std::cout << j << " ";
                j--;
            }
            length--;
        }
        std::cout << std::endl;
    }
}