// accessories.h
// functions of general use
//

#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include <array>
#include "globals.h"

int msgToUserHeader();
bool wrongNumberOfArgs(int argc);
int msgToUserUsage(int argc);
int parseArguments(const int argc, char ** argv,
      fsVec_t & a, fsVec_t & b, fsVec_t & c,
      int & Na, int & Nb, int & Nc,
      double & r, double & L, int & n);

int msgdbg1(int Na, int Nb, int Nc, size_t clusterSize);

#endif
// eof accessories.h
