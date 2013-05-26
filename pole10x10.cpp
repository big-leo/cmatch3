#include "pole10x10.h"
#include "zapovn.h"

cPole::cPole (){}
cPole::~cPole (){}
void cPole::set_pole (int k, int l, char m)
    {
        pole[k][l]=m;
    }
char cPole::get_pole (int f, int p)
    {
        if (pole[f][p]=='*'||'/'||'+')
        {
            return pole[f][p];
        }
        else
        {
            return zapovn();
        }
    }

