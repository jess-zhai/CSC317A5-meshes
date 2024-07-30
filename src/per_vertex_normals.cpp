#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  for (int i = 0; i < V.rows(); i++) {
    Eigen::RowVector3d n(0, 0, 0);
    for (int j = 0; j < F.rows(); j++) {
      Eigen::RowVector3d a = V.row(F(j, 0));
      Eigen::RowVector3d b = V.row(F(j, 1));
      Eigen::RowVector3d c = V.row(F(j, 2));
      n += triangle_area_normal(a, b, c);
    }
    N.row(i) = n.normalized();
  }
  ////////////////////////////////////////////////////////////////////////////
}
