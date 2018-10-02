// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/fast_winding_number.h>

const char* ds_fast_winding_number = R"igl_Qu8mg5v7(

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

 Inputs:
       P  #P by 3 list of point locations
       N  #P by 3 list of point normals
       Q  #Q by 3 list of query points for the winding number
     Outputs:
       WN  #Q by 1 list of windinng number values at each query point
    
)igl_Qu8mg5v7";

npe_function(fast_winding_number)
npe_doc(ds_fast_winding_number)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_arg(q, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 wn;
    igl::    copyleft::    cgal::fast_winding_number(p, n, q, wn);
    return npe::move(wn);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 wn;
    igl::    copyleft::    cgal::fast_winding_number(p, n, q, wn);
    return npe::move(wn);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/fast_winding_number.h>

const char* ds_fast_winding_number = R"igl_Qu8mg5v7(

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

 Evaluate the fast winding number for point data, without known areas. The
     areas are calculated using igl::knn and igl::copyleft::cgal::point_areas.
    
     This function performes the precomputation and evaluation all in one.
     If you need to acess the precomuptation for repeated evaluations, use the
     two functions designed for exposed precomputation, which are the first two
     functions see in igl/fast_winding_number.h
    
     Inputs:
       P  #P by 3 list of point locations
       N  #P by 3 list of point normals
       Q  #Q by 3 list of query points for the winding number
       beta  This is a Barnes-Hut style accuracy term that separates near feild
             from far field. The higher the beta, the more accurate and slower
             the evaluation. We reccommend using a beta value of 2.
       expansion_order    the order of the taylor expansion. We support 0,1,2.
     Outputs:
       WN  #Q by 1 list of windinng number values at each query point
    
)igl_Qu8mg5v7";

npe_function(fast_winding_number)
npe_doc(ds_fast_winding_number)

npe_arg(p, dense_f64)
npe_arg(n, dense_f64)
npe_arg(q, dense_f64)
npe_arg(expansion_order, int)
npe_arg(beta, BetaType)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 wn;
    igl::    copyleft::    cgal::fast_winding_number(p, n, q, expansion_order, beta, wn);
    return npe::move(wn);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 wn;
    igl::    copyleft::    cgal::fast_winding_number(p, n, q, expansion_order, beta, wn);
    return npe::move(wn);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


