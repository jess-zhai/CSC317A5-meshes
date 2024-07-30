#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////
  std::ofstream pfile(filename);
  if (!pfile) {
    return false;
  }

  for (int i = 0; i < V.rows(); i++) {
    pfile << "v " << V.row(i) << "\n";
  }

  for (int i = 0; i < UV.rows(); i++) {
    pfile << "vt " << UV.row(i) << "\n";
  }

  for (int i = 0; i < NV.rows(); i++) {
    pfile << "vn " << NV.row(i) << "\n";
  }

  for (int i = 0; i < F.rows(); i++) { 
    pfile << "f ";
    for (int j = 0; j < F.cols(); j++) {
      pfile << F(i, j) + 1 << "/" << UF(i, j) + 1 << "/" << NF(i, j) + 1 << " ";
    }
    pfile << "\n";
  }

  pfile.close();
  return false;
}
