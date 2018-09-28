// accessories.h
// functions of general use
//
#ifndef ACCESSORIES_H
#define ACCESSORIES_H
int msgToUserHeader();
int msgToUserUsage();
int parseArguments(const int argc, char ** argv, int N, double a,
                   double r, double L, int n);
int msgdbg1(int N, double a, double r, double L, int n);
#endif // eof accessories.h
