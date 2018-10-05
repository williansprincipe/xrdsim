// globals.h
// global declarations
// wpf 20181002_10h30min

#ifndef GLOBALS_H
#define GLOBALS_H

#include <array>
#include <vector>

typedef std::array<double,4> point_t;
typedef std::array<double,4> fsVec_t; // fs = fixed size

struct vector_t
{ public:
  double t() { return t_; }
  double x() { return x_; }
  double y() { return y_; }
  double z() { return z_; }
 private:
  double t_;
  double x_;
  double y_;
  double z_;
};

typedef std::vector<point_t> row_t;
typedef std::vector<row_t> plane_t;
typedef std::vector<plane_t> space_t;

#endif


