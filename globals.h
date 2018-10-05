// globals.h
// global declarations
// wpf 20181002_10h30min

#ifndef GLOBALS_H
#define GLOBALS_H

#include <array>
#include <vector>

// typedef std::array<double,4> point_t;
// typedef std::array<double,4> fsVec_t; // fs = fixed size

class vector_t
{public:
  vector_t() = default;
  vector_t(const double x, const double y, const double z) : x_(x), y_(y), z_(z) {}
 ~vector_t() = default;

  const double x() const { return x_; }
  void x(const double x) { x_ = x; }

  const double y() const { return y_; }
  void y(const double y) { y_ = y; }

  const double z() const { return z_; }
  void z(const double z) { z_ = z; }

 private:
  double x_;
  double y_;
  double z_;
};

typedef vector_t point_t;

typedef std::vector<point_t> row_t;
typedef std::vector<row_t> plane_t;
typedef std::vector<plane_t> space_t;

#endif

