// Detector.h
// detector object
// wpf 20181006 20h

#ifndef SCREEN_H
#define SCREEN_H

#include "globals.h"
#include "Cluster.h"

class Detector
{public:
  Detector()=default;
  Detector(int size, double sizecm)
    // size = number of points; sizecm = size/cm
  : size_(size),
    sizecm_(sizecm),
    detector_(std::vector<std::vector<double>>(size,std::vector<double>(size,0)))
  { }
 ~Detector()=default;
  const size_t size() const;
  const double sizecm() const;
  void detect(const Cluster& cluster,
              vector_t k, vector_t kp, // kp = k prime
              double d); // d = distance
 private:
  int size_;        // one side of a square, in number of points
  double sizecm_;   // one side of a square, in cm
  std::vector<std::vector<double>> detector_;
};
#endif
// eof Detector.h
