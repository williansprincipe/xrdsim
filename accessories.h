// accessories.h
// functions of general use
//
#ifndef ACCESSORIES_H
#define ACCESSORIES_H
#include<array>
int msgToUserHeader();
bool wrongNumberOfArgs(int argc);
int msgToUserUsage();
int parseArguments(int argc, char ** argv, std::array<double,4> a, std::array<double,4> b, std::array<double,4> c, int Na, int Nb, int Nc, double r, double L, int n);
//int msgdbg1(int argc, char ** argv, std::array<4,double> a, std::array<4,double> b, std::array<4,double> c, int Na, int Nb, int Nc, double r, double L, int n);
#endif
// eof accessories.h
