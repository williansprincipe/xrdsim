// Detector.cpp
// detector object
// wpf 20181006 20h

#include "Detector.h"
#include <iostream>

  void Detector::detect(const Cluster& cluster,
                      vector_t k, vector_t kp, // kp = k prime
                      double d)  // d = distance
  { std::cout << " distance d = " << d << "\n";
    std::cout << "todo: normalize k?\n";
    std::cout << "Size of detector: " << detector_.size() << "\n";
    if (!detector_.empty())
    { std::cout << "Size of detector[0]: " << detector_[0].size() << "\n";
    }
    return;
  }

//eof Detector.cpp
