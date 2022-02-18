#include <iostream>
#include <conio.h>
using namespace std;                    
// needs user input
// needs conversions of measurments
int main()                          
{
    int radius; //   <------ input radius here
    cout <<"Please Enter Your Radius :";
    cin >> radius;
    cout << "" <<endl;
    int diameter = radius * 2;
    float Perimeter = 3.14159*diameter;
    
    cout << "Radius = " << radius <<endl;
    cout << "Diameter = " << diameter <<endl;
    cout << "Circumference = " << Perimeter;
    
    getch();
    return 0;
}
    