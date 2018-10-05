// accessories.h
// functions of general use
//

#ifndef CLUSTER_H
#define CLUSTER_H

#include "globals.h"

class Cluster
{public:
  Cluster()=default;
 ~Cluster()=default;
  Cluster(vector_t a, vector_t b, vector_t c, int Na, int Nb, int Nc);
  size_t size() const;
  space_t lattice() const;
 private:
 space_t cluster_;
};
#endif
// eof accessories.h
