// accessories.cpp
// functions of general use
//

#include "Cluster.h"
  
Cluster::Cluster(fsVec_t a, fsVec_t b, fsVec_t c, int Na, int Nb, int Nc)
{ const point_t clusterOrigin={0.0, 0.0, 0.0, 0.0};
  for (int k = 0; k < Nc; ++k)
  { plane_t auxPlane;
    for (int j = 0; j < Nb; ++j)
    { row_t auxRow;
      for (int i = 0; i < Na; ++i)
      { double x0 = clusterOrigin[0] + i * a[0] + j * b[0] + k * c[0];
        double x1 = clusterOrigin[1] + i * a[1] + j * b[1] + k * c[1];
        double x2 = clusterOrigin[2] + i * a[2] + j * b[2] + k * c[2];
        double x3 = clusterOrigin[3] + i * a[3] + j * b[3] + k * c[3];
        auxRow.push_back({x0,x1,x2,x3});
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
