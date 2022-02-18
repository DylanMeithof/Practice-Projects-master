#include <iostream>
#include <string>
#include <time.h>
//diceroll
using namespace std;


int main() {
    int dicetype;
    cout << "Enter A Number of Sides \n";
    cin >> dicetype;
    srand(time(NULL));
    cout << "You Rolled a " << 1 + rand() % dicetype << "\n";
}
