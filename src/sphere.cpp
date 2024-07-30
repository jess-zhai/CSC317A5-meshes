#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////
  const double num_faces = num_faces_u * num_faces_v;
  const double num_vertices = (num_faces_u + 1) * (num_faces_v + 1);

  V.resize(num_vertices, 3);
  UV.resize(num_vertices, 2);
  NV.resize(num_vertices, 3);

  int row = 0;

  for (int u = 0; u < num_faces_u+ 1; u++) {
    for (int v = 0; v < num_faces_v + 1; v++) {
      double theta = 2 * (double)u * M_PI / num_faces_u;
      double phi = (double)v * M_PI / num_faces_v;
      
      double x = cos(theta) * sin(phi);
      double y = sin(theta) * sin(phi);
      double z = -cos(phi);

      V.row(row) = Eigen::RowVector3d(x, z, y);
      UV.row(row) = Eigen::RowVector2d(1 - (double)u / num_faces_u, (double)v / num_faces_v);
      NV.row(row) = Eigen::RowVector3d(x, z, y);
      row ++;
    }
  }

  row = 0;
  F.resize(num_faces, 4);
  UF.resize(num_faces, 4);
  NF.resize(num_faces, 4);

  for (int u = 0; u < num_faces_u; u++) {
    for (int v = 0; v < num_faces_v; v++) {
      int v1 = u * (num_faces_v + 1) + v; // bottom left
      int v2 = u * (num_faces_v + 1) + v + 1; // right
      int v3 = (u + 1) * (num_faces_v + 1) + v; // top left
      int v4 = (u + 1) * (num_faces_v + 1) + v + 1; // right

      F.row(row) = Eigen::RowVector4i(v1, v3, v4, v2);
      UF.row(row) = Eigen::RowVector4i(v1, v3, v4, v2);
      NF.row(row) = Eigen::RowVector4i(v1, v3, v4, v2);
      row ++;
    }
  }
}
