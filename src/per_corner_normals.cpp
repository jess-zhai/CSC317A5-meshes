#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::vector<std::vector<int>> VF;
  vertex_triangle_adjacency(F, V.rows(), VF);
  Eigen::MatrixXd face_normals = Eigen::MatrixXd::Zero(F.rows(), 3);

  for (int i = 0; i < F.rows(); ++i) {
    const Eigen::RowVector3d &a = V.row(F(i, 0));
    const Eigen::RowVector3d &b = V.row(F(i, 1));
    const Eigen::RowVector3d &c = V.row(F(i, 2));
    face_normals.row(i) = triangle_area_normal(a, b, c).normalized();
  }

  for (int i = 0; i < F.rows(); ++i) {
    for (int j = 0; j < F.cols(); ++j) {
      Eigen::RowVector3d sum = Eigen::RowVector3d::Zero();
      for (int k : VF[F(i, j)]) {
        if (face_normals.row(i).dot(face_normals.row(k)) > cos(corner_threshold * M_PI / 180.0)) {
          sum += face_normals.row(k);
        }
      }
      N.row(i * F.cols() + j) = sum.normalized();
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
