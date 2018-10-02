// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/signed_distance_isosurface.h>

const char* ds_signed_distance_isosurface = R"igl_Qu8mg5v7(

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

 SIGNED_DISTANCE_ISOSURFACE Compute the contour of an iso-level of the
       signed distance field to a given mesh.
      
       Inputs:
         IV  #IV by 3 list of input mesh vertex positions
         IF  #IF by 3 list of input triangle indices
         level  iso-level to contour in world coords, negative is inside.
         angle_bound  lower bound on triangle angles (mesh quality) (e.g. 28)
         radius_bound  upper bound on triangle size (mesh density?) (e.g. 0.02)
         distance_bound  cgal mysterious parameter (mesh density?) (e.g. 0.01)
         sign_type  method for computing distance _sign_ (see
           ../signed_distance.h)
       Outputs:
         V  #V by 3 list of input mesh vertex positions
         F  #F by 3 list of input triangle indices
        
)igl_Qu8mg5v7";

npe_function(signed_distance_isosurface)
npe_doc(ds_signed_distance_isosurface)

npe_arg(iv, Eigen::MatrixXd &)
npe_arg(if, Eigen::MatrixXi &)
npe_arg(level, double)
npe_arg(angle_bound, double)
npe_arg(radius_bound, double)
npe_arg(distance_bound, double)
npe_arg(sign_type, igl::SignedDistanceType)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXd & v;
    Eigen::MatrixXi & f;
    igl::    copyleft::    cgal::signed_distance_isosurface(iv, if, level, angle_bound, radius_bound, distance_bound, sign_type, v, f);
    return std::make_tuple(    npe::move(v),
    npe::move(f));
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXd & v;
    Eigen::MatrixXi & f;
    igl::    copyleft::    cgal::signed_distance_isosurface(iv, if, level, angle_bound, radius_bound, distance_bound, sign_type, v, f);
    return std::make_tuple(    npe::move(v),     npe::move(f));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


