// Cluster.cpp
// cluster of atoms
// wpf 20180928 11h

#include "Cluster.h"
#include<iostream>
  
Cluster::Cluster(vector_t a, vector_t b, vector_t c, int Na, int Nb, int Nc)
{ const point_t cOr(0.0, 0.0,0.0); // clusterOrigin
        vector_t cOf;              // clusterOffset
  cOf.x(-((Na-1) * a.x() + (Nb-1) * b.x() + (Nc-1) * c.x())/2);
  cOf.y(-((Na-1) * a.y() + (Nb-1) * b.y() + (Nc-1) * c.y())/2);
  cOf.z(-((Na-1) * a.z() + (Nb-1) * b.z() + (Nc-1) * c.z())/2);
  std::cout << "ClusterOffset: " << "x=" << cOf.x() << ", " << "y=" << cOf.y() << ", " << "z=" << cOf.z() << "\n";
  for (int iz = 0 ; iz < Nc; ++iz)
  { plane_t auxPlane;
    for (int iy = 0; iy < Nb; ++iy)
    { row_t auxRow;
      for (int ix = 0; ix < Na; ++ix)
      { point_t pt;
        pt.x(cOr.x() + cOf.x() + ix * a.x() + iy * b.x() + iz * c.x());
        pt.y(cOr.y() + cOf.y() + ix * a.y() + iy * b.y() + iz * c.y());
        pt.z(cOr.z() + cOf.z() + ix * a.z() + iy * b.z() + iz * c.z());
        auxRow.push_back(pt);
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

//eof Cluster.cpp
