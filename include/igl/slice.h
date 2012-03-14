#ifndef IGL_SLICE_H
#define IGL_SLICE_H
#include "igl_inline.h"

#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#include <Eigen/Sparse>

namespace igl
{
  // Act like the matlab X(row_indices,col_indices) operator
  // 
  // Inputs:
  //   X  m by n matrix
  //   R  list of row indices
  //   C  list of column indices
  // Output:
  //   Y  #R by #C matrix
  template <typename T>
  IGL_INLINE void slice(
    const Eigen::SparseMatrix<T>& X,
    const Eigen::Matrix<int,Eigen::Dynamic,1> & R,
    const Eigen::Matrix<int,Eigen::Dynamic,1> & C,
    Eigen::SparseMatrix<T>& Y);

  template <typename DerivedX>
  IGL_INLINE void slice(
    const Eigen::PlainObjectBase<DerivedX> & X,
    const Eigen::Matrix<int,Eigen::Dynamic,1> & R,
    const Eigen::Matrix<int,Eigen::Dynamic,1> & C,
    Eigen::PlainObjectBase<DerivedX> & Y);

  template <typename DerivedX>
  IGL_INLINE void slice(
    const Eigen::PlainObjectBase<DerivedX> & X,
    const Eigen::Matrix<int,Eigen::Dynamic,1> & R,
    Eigen::PlainObjectBase<DerivedX> & Y);
}

#ifdef IGL_HEADER_ONLY
#  include "slice.cpp"
#endif

#endif