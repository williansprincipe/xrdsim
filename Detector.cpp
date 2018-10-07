// Screen.cpp
// screen of the detector
// wpf 20181006 20h

#include "Screen.h"
#include <iostream>

  void Screen::detect(const Cluster& cluster,
                      vector_t k, vector_t kp, // kp = k prime
                      double d)  // d = distance
  { std::cout << " distance d = " << d << "\n";
    std::cout << "todo: normalize k?\n";
    std::cout << "Size of screen: " << screen_.size() << "\n";
    if (!screen_.empty())
    { std::cout << "Size of screen[0]: " << screen_[0].size() << "\n";
    }
    return;
  }

//eof Screen.cpp
