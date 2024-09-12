#include <iostream>

using namespace std;

int main(){

    int total_units;
    int bill(0);

    cout << "Total units consumed: ";
    cin >> total_units;

    while(total_units > 0){

        if (total_units > 500){

            bill += 22 * 500;
            total_units -= 500;
        }
        else if (total_units > 400){

            bill += 18 * 400;
            total_units -= 400;
        }
        else if (total_units > 300){

            bill += 15 * 300;
            total_units -= 300;
        }
        else if (total_units > 200){

            bill += 13 * 200;
            total_units -= 200;
        }
        else if (total_units > 100){

            bill += 11 * 100;
            total_units -= 100;
        }
        else{

            bill += 5 * total_units;
            total_units -= total_units;
        }
    }
    cout << bill;
}