#include "zmina.h"
#include <iostream>

using namespace std;

int i=0, x_y[4];
char temp;

void xy(int koord)
{
    if (koord>=0&&koord<=9)
    {
        x_y[i]=koord;
        i++;
    }

    if (koord<0||koord>9)
    {
        std::cout << "Please return enter: " << std::endl;
        cin >> temp;
        xy((int)temp-48);
    }
}


int zmina()
{
    i=0;

    unsigned int suma=0;
    std::cout << "Please enter x1: " << std::endl;
    cin >> temp;
    xy((int)temp-48);

    std::cout << "Please enter y1: " << std::endl;
    cin >> temp;
    xy((int)temp-48);

    std::cout << "Please enter x2: " << std::endl;
    cin >> temp;
    xy((int)temp-48);

    std::cout << "Please enter y2: " << std::endl;
    cin >> temp;
    xy((int)temp-48);

    if    (!((((x_y[0]-x_y[2])==0)&&((x_y[1]-x_y[3])==1))
           ||(((x_y[2]-x_y[0])==1)&&((x_y[1]-x_y[3])==0))
           ||(((x_y[0]-x_y[2])==1)&&((x_y[1]-x_y[3])==0))
           ||(((x_y[0]-x_y[2])==0)&&((x_y[3]-x_y[1])==1))))
    {
       std::cout << "Please repeat enter only related field!" << std::endl;
       zmina ();
    }

    suma=(x_y[0]*1000+x_y[1]*100+x_y[2]*10+x_y[3]);
    return suma;
}
