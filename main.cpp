#include "main.h"
#include <iostream>

int main()
{
    cPole pole_10x10;
    std::cout << "Start GAME" << std::endl;
    char temp='0';
    int i, j, x1m, y1m, x2m, y2m, sumam, bonus=0, repeat1=1, repeat2=1;


//Заповнення матриці.
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
        {
            pole_10x10.set_pole(i, j, zapovn());
        }
    }

//Початок.
while (i)
//((x1>9||x1<0)||(y1>9||y1<0)||(x2>9||x2<0)||(y2>9||y2<0))
{
  //Відсів 3 однакових сусідніх полей.
  while ((repeat1==1)||(repeat2==1))
  {
    for (i=9; i>=0; i--)
    {
        for (j=0; j<8; j++)
        {
            repeat1=1;
            while (repeat1==1)
            {
                repeat1=0;
            if   ((pole_10x10.get_pole(i, j)==
                   pole_10x10.get_pole(i, j+1))&&
                  (pole_10x10.get_pole(i, j+1)==
                   pole_10x10.get_pole(i, j+2)))

                {
                repeat1=1;
                repeat2=1;
                bonus=bonus+3;
                std::cout << "i j: " << i << ", "<< j <<" bonus1: " << bonus << std::endl;
                for (int k=i; k>=0; k=k-1)
                    {
                       if (k!=0)
                       {
                           pole_10x10.set_pole(k, j, pole_10x10.get_pole(k-1, j));
                           pole_10x10.set_pole(k, j+1, pole_10x10.get_pole(k-1, j+1));
                           pole_10x10.set_pole(k, j+2, pole_10x10.get_pole(k-1, j+2));
                       }
                       if (k==0)
                       {
                           pole_10x10.set_pole(k, j, zapovn());
                           pole_10x10.set_pole(k, j+1, zapovn());
                           pole_10x10.set_pole(k, j+2, zapovn());
                       }
                       i=9;
                    }
                }
            }
        }
    }
for (i=9; i>=0; i--)
    {
        for (j=0; j<10; j++)
        {
            repeat2=1;
            while (repeat2==1)
            {
               repeat2=0;
               if  ((pole_10x10.get_pole(i, j)==
                    pole_10x10.get_pole(i-1, j))&&
                   (pole_10x10.get_pole(i-1, j)==
                    pole_10x10.get_pole(i-2, j)))

               {
                   repeat2=1;
                   repeat1=1;
                   bonus=bonus+3;
                   std::cout << "i j: " << i << ", "<< j <<" bonus2: " << bonus << std::endl;
                   for (int s=i; s>1; s=s-3)
                       {
                           if (s>4)
                           {
                               pole_10x10.set_pole(s, j, pole_10x10.get_pole(s-3, j));
                               pole_10x10.set_pole(s-1, j, pole_10x10.get_pole(s-4, j));
                               pole_10x10.set_pole(s-2, j, pole_10x10.get_pole(s-5, j));
                           }
                           if (s==4)
                           {
                               pole_10x10.set_pole(s, j, pole_10x10.get_pole(s-3, j));
                               pole_10x10.set_pole(s-1, j, pole_10x10.get_pole(s-4, j));
                               pole_10x10.set_pole(s-2, j, zapovn());
                           }
                           if (s==3)
                           {
                               pole_10x10.set_pole(s, j, pole_10x10.get_pole(s-3, j));
                               pole_10x10.set_pole(s-1, j, zapovn());
                               pole_10x10.set_pole(s-2, j, zapovn());
                           }
                           if (s<3)
                           {
                               pole_10x10.set_pole(s, j, zapovn());
                               pole_10x10.set_pole(s-1, j, zapovn());
                               pole_10x10.set_pole(s-2, j, zapovn());
                           }
                           i=9;
                     }
               }

            }
        }
    }
  }

//Вивід матриці на екран.
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
        {
            std::cout << " " << pole_10x10.get_pole(i, j) << " ";
        }
        std::cout << "\n\n" ;
    }
std::cout << "bonus: " << bonus << std::endl;
//cout << "Vvedit koordynaty for change or <0-9> for exit:" << endl;

//Зміна сусідніх полей.
sumam=zmina();
y2m=sumam%10;
sumam=sumam/10;
x2m=sumam%10;
sumam=sumam/10;
y1m=sumam%10;
sumam=sumam/10;
x1m=sumam%10;

temp=pole_10x10.get_pole(x1m, y1m);
pole_10x10.set_pole(x1m, y1m, pole_10x10.get_pole(x2m, y2m));
pole_10x10.set_pole(x2m, y2m, temp);

repeat1=1;
repeat2=1;
}



    return 0;
}
