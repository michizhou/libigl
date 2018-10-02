// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/polar_svd3x3.h>

const char* ds_polar_svd3x3 = R"igl_Qu8mg5v7(

Parameters
----------

dtype : data-type of the returned objects, optional. Default is `float64`.
(All integer return types are `int32` by default.)

Returns
-------


See also
--------


Notes
-----
None

Examples
--------

 Computes the closest rotation to input matrix A using specialized 3x3 SVD
   singular value decomposition (WunderSVD3x3)
  
   Inputs:
     A  3 by 3 matrix to be decomposed
   Outputs:
     R  3 by 3 closest element in SO(3) (closeness in terms of Frobenius
     metric)
  
    This means that det(R) = 1. Technically it's not polar decomposition
    which guarantees positive semidefinite stretch factor (at the cost of
    having det(R) = -1). "• The orthogonal factors U and V will be true
    rotation matrices..." [McAdams, Selle, Tamstorf, Teran, Sefakis 2011]
  
)igl_Qu8mg5v7";

npe_function(polar_svd3x3)
npe_doc(ds_polar_svd3x3)

npe_arg(a, Mat &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Mat & r;
    igl::polar_svd3x3(a, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    Mat & r;
    igl::polar_svd3x3(a, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/polar_svd3x3_sse.h>

const char* ds_polar_svd3x3_sse = R"igl_Qu8mg5v7(
See polar_svd3x3_sse for the documentation.
)igl_Qu8mg5v7";

npe_function(polar_svd3x3_sse)
npe_doc(ds_polar_svd3x3_sse)

npe_arg(a, Eigen::Matrix<T, 3 * 4, 3> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, 3 * 4, 3> & r;
    igl::polar_svd3x3_sse(a, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, 3 * 4, 3> & r;
    igl::polar_svd3x3_sse(a, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


