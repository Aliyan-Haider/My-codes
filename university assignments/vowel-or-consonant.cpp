#include <cctype>
#include <iostream>
#include <limits>

int main(){
    
    char letter;
    int flag = 1;
    char vowels[] = {'a','e', 'i', 'o', 'u', '\0'};
    
    while(flag != 0){
        
        std::cout << "Enter letter: ";
        std::cin >> letter;
        letter = tolower(letter);

        if (!isalpha(letter)){
            
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid" << std::endl;
        
        continue;
        }
        flag = 0;
    
    }
    
    for(int i = 0; vowels[i] != '\0'; i++){
        
        if (letter == vowels[i]){
            
            std::cout << "Vowel.";
            
            return 0;
        }
    }
    std::cout << "Consonant.";
    
}