// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/fit_rotations.h>

const char* ds_fit_rotations = R"igl_Qu8mg5v7(

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

 Known issues: This seems to be implemented in Eigen/Geometry:
   Eigen::umeyama
  
   FIT_ROTATIONS Given an input mesh and new positions find rotations for
   every covariance matrix in a stack of covariance matrices
   
   Inputs:
     S  nr*dim by dim stack of covariance matrices
     single_precision  whether to use single precision (faster)
   Outputs:
     R  dim by dim * nr list of rotations
  
)igl_Qu8mg5v7";

npe_function(fit_rotations)
npe_doc(ds_fit_rotations)

npe_arg(s, dense_f64)
npe_arg(single_precision, bool)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::fit_rotations(s, single_precision, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::fit_rotations(s, single_precision, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/fit_rotations_planar.h>

const char* ds_fit_rotations_planar = R"igl_Qu8mg5v7(

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

 FIT_ROTATIONS Given an input mesh and new positions find 2D rotations for
   every vertex that best maps its one ring to the new one ring
   
   Inputs:
     S  nr*dim by dim stack of covariance matrices, third column and every
     third row will be ignored
   Outputs:
     R  dim by dim * nr list of rotations, third row and third column of each
     rotation will just be identity
  
)igl_Qu8mg5v7";

npe_function(fit_rotations_planar)
npe_doc(ds_fit_rotations_planar)

npe_arg(s, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 r;
    igl::fit_rotations_planar(s, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 r;
    igl::fit_rotations_planar(s, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/fit_rotations_SSE.h>

const char* ds_fit_rotations_sse = R"igl_Qu8mg5v7(
See fit_rotations_SSE for the documentation.
)igl_Qu8mg5v7";

npe_function(fit_rotations_sse)
npe_doc(ds_fit_rotations_sse)

npe_arg(s, Eigen::MatrixXf &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXf & r;
    igl::fit_rotations_SSE(s, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXf & r;
    igl::fit_rotations_SSE(s, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/fit_rotations_SSE.h>

const char* ds_fit_rotations_sse = R"igl_Qu8mg5v7(
See fit_rotations_SSE for the documentation.
)igl_Qu8mg5v7";

npe_function(fit_rotations_sse)
npe_doc(ds_fit_rotations_sse)

npe_arg(s, Eigen::MatrixXd &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & r;
    igl::fit_rotations_SSE(s, r);
    return npe::move(r);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & r;
    igl::fit_rotations_SSE(s, r);
    return npe::move(r);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


