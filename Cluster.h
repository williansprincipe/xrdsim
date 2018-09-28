// accessories.h
// functions of general use
//
#ifndef CLUSTER_H
#define CLUSTER_H
class Cluster
{public:
  Cluster(size_t)
  site_t size();
 private:
  std::vector<std::array<4,double>> cluster_;
};
#endif // eof accessories.h
