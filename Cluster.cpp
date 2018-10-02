// accessories.cpp
// functions of general use
//

#include "Cluster.h"
  
Cluster::Cluster(fsVec_t a, fsVec_t b, fsVec_t c, int Na, int Nb, int Nc)
{ for (int k = 0; k < Nc; ++k)
  { plane_t auxPlane;
    for (int j = 0; j < Nb; ++j)
    { row_t auxRow;
      for (int i = 0; i < Na; ++i)
      { auxRow.push_back({0.0,0.1,0.2,0.3});
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
