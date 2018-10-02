// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/svd3x3_avx.h>

const char* ds_svd3x3_avx = R"igl_Qu8mg5v7(

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

 Super fast 3x3 SVD according to
   http:pages.cs.wisc.edu/~sifakis/project_pages/svd.html This is AVX
   version of svd3x3 (see svd3x3.h) which works on 8 matrices at a time These
   eight matrices are simply stacked in columns, the rest is the same as for
   svd3x3
  
   Inputs:
     A  12 by 3 stack of 3x3 matrices
   Outputs:
     U  12x3 left singular vectors stacked
     S  12x1 singular values stacked
     V  12x3 right singular vectors stacked
  
   Known bugs: this will not work correctly for double precision.
)igl_Qu8mg5v7";

npe_function(svd3x3_avx)
npe_doc(ds_svd3x3_avx)

npe_arg(a, Eigen::Matrix<T, 3 * 8, 3> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::Matrix<T, 3 * 8, 3> & u;
    Eigen::Matrix<T, 3 * 8, 1> & s;
    Eigen::Matrix<T, 3 * 8, 3> & v;
    igl::svd3x3_avx(a, u, s, v);
    return std::make_tuple(    npe::move(u),
    npe::move(s),
    npe::move(v));
} else if (dtype.type() == npe::type_f64) {
    Eigen::Matrix<T, 3 * 8, 3> & u;
    Eigen::Matrix<T, 3 * 8, 1> & s;
    Eigen::Matrix<T, 3 * 8, 3> & v;
    igl::svd3x3_avx(a, u, s, v);
    return std::make_tuple(    npe::move(u),     npe::move(s),     npe::move(v));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


