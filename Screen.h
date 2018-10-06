// Screen.h
// screen of the detector
// wpf 20181006 20h

#ifndef SCREEN_H
#define SCREEN_H

#include "globals.h"
#include "Cluster.h"

class Screen
{public:
  Screen()=default;
  Screen(int size, double sizecm)
    // size = number of points; sizecm = size/cm
    : size_(size), sizecm_(sizecm) { }
 ~Screen()=default;
  const size_t size() const;
  const double sizecm() const;
  void detect(const Cluster& cluster,
              vector_t k, vector_t kp, // kp = k prime
              double d); // d = distance
 private:
  int size_;        // one side of a square, in number of points
  double sizecm_;   // one side of a square, in cm
};
#endif
// eof Screen.h
