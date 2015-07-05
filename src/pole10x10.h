#ifndef POLE10X10_H
#define POLE10X10_H

class cPole
 {
 public:
 cPole();
 ~cPole();
 
 void set_pole (int, int, char);
 char get_pole (int, int);
 
 private:
 char pole[11][11];
 };

#endif