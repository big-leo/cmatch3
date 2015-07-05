//Випадкове заповнення знаками: '*' '/' '+'

#include "zapovn.h"

#include <time.h>
#include <stdlib.h>

char zapovn()
{
    time_t lt;
    lt=time(NULL);
    lt=lt%10;
    int k;

    k=rand()+lt;
            if (!(k%3||k%5))
            {
                return '*';
            }
            if (k%3)
            {
                return '/';
            }
            if (k%5)
            {
                return '+';
            }
            /*if (k%7)
            {
                return '-';
            }
            if (k%11)
            {
                return '<';
            }*/
    return ' ';
}

