// accessories.h
// functions of general use
//

#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include <array>
#include "globals.h"
#include "Cluster.h"

int msgToUserHeader();
bool wrongNumberOfArgs(int argc);
int msgToUserUsage(int argc);
int parseArguments(const int argc, char ** argv,
      vector_t & a, vector_t & b, vector_t & c,
      int & Na, int & Nb, int & Nc,
      double & r, double & L, int & n);

int msgdbg1(int Na, int Nb, int Nc, const Cluster & cluster);

#endif
// eof accessories.h
