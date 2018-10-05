// accessories.cpp
// functions of general use
//

#include "Cluster.h"
#include<iostream>
  
Cluster::Cluster(vector_t a, vector_t b, vector_t c, int Na, int Nb, int Nc)
{ const point_t clusterOrigin(0.0, 0.0,0.0);
  vector_t clusterOffset;
  clusterOffset.x(-((Na-1) * a.x() + (Nb-1) * b.x() + (Nc-1) * c.x())/2);
  clusterOffset.y(-((Na-1) * a.y() + (Nb-1) * b.y() + (Nc-1) * c.y())/2);
  clusterOffset.z(-((Na-1) * a.z() + (Nb-1) * b.z() + (Nc-1) * c.z())/2);
  std::cout << "ClusterOffset: x=" << clusterOffset.x() << ", " << "y=" << clusterOffset.y() << ", " << "z=" << clusterOffset.z() << "\n";
  for (int k = 0 ; k < Nc; ++k)
  { plane_t auxPlane;
    for (int j = 0; j < Nb; ++j)
    { row_t auxRow;
      for (int i = 0; i < Na; ++i)
      { point_t point;
        point.x(clusterOrigin.x() + clusterOffset.x() +
            i * a.x() + j * b.x() + k * c.x());
        point.y(clusterOrigin.y() + clusterOffset.y() +
            i * a.y() + j * b.y() + k * c.y());
        point.z(clusterOrigin.z() + clusterOffset.z() +
            i * a.z() + j * b.z() + k * c.z());
        auxRow.push_back(point);
      }
      auxPlane.push_back(auxRow);
    }
    cluster_.push_back(auxPlane);
  }
}

size_t Cluster::size() const // -----------------------------------------
{
  if (cluster_.empty())
  { return 0;
  }
  else if (cluster_[0].empty())
  { return 0;
  }
  else if (cluster_[0][0].empty())
  { return 0;
  }
  else
  { return cluster_.size() * cluster_[0].size() * cluster_[0][0].size();
  }
}

space_t Cluster::lattice() const

{ return cluster_;
}

//eof accessories.cpp
