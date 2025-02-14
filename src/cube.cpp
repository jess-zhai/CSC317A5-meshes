#include "cube.h"

void cube(
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

  ////Hint:
  V.resize(8,3);
  F.resize(6,4);
  UV.resize(14,2);
  UF.resize(6,4);
  NV.resize(6,3);
  NF.resize(6,4);
  V << 0, 0, 0,
       1, 0, 0,
       1, 1, 0,
       0, 1, 0,
       0, 0, 1,
       1, 0, 1,
       1, 1, 1,
       0, 1, 1;

  F << 0, 1, 5, 4,
       1, 2, 6, 5,
       2, 3, 7, 6,
       3, 0, 4, 7,
       5, 6, 7, 4,
       1, 2, 3, 0;

  UV << 0, 1,
        0, 2,
        1, 0,
        1, 1,
        1, 2,
        1, 3,
        2, 0,
        2, 1,
        2, 2,
        2, 3,
        3, 1,
        3, 2,
        4, 1,
        4, 2;
  UV = (UV.array()/4.0).matrix();

  UF << 0, 3, 4, 1,
        3, 7, 8, 4,
        7, 10, 11, 8,
        10, 12, 13, 11,
        4, 8, 9, 5,
        2, 6, 7, 3;

  NV << 1, 0, 0,
        -1, 0, 0,
        0, 1, 0,
        0, -1, 0,
        0, 0, 1,
        0, 0, -1;

  NF << 3, 3, 3, 3,
        0, 0, 0, 0,
        2, 2, 2, 2,
        1, 1, 1, 1,
        4, 4, 4, 4,
        5, 5, 5, 5;
}
