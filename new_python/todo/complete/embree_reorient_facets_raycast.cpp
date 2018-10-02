#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/reorient_facets_raycast.h>

const char* ds_reorient_facets_raycast = R"igl_Qu8mg5v7(

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

 Orient each component (identified by C) of a mesh (V,F) using ambient
     occlusion such that the front side is less occluded than back side, as
     described in "A Simple Method for Correcting Facet Orientations in
     Polygon Meshes Based on Ray Casting" [Takayama et al. 2014].
    
     Inputs:
       V  #V by 3 list of vertex positions
       F  #F by 3 list of triangle indices
       rays_total  Total number of rays that will be shot
       rays_minimum  Minimum number of rays that each patch should receive
       facet_wise  Decision made for each face independently, no use of patches
         (i.e., each face is treated as a patch)
       use_parity  Use parity mode
       is_verbose  Verbose output to cout
     Outputs:
       I  #F list of whether face has been flipped
       C  #F list of patch ID (output of bfs_orient > manifold patches)
)igl_Qu8mg5v7";

npe_function(reorient_facets_raycast)
npe_doc(ds_reorient_facets_raycast)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int rays_total;
    int rays_minimum;
    bool facet_wise;
    bool use_parity;
    bool is_verbose;
    dense_f32 i;
    dense_f32 c;
    igl::    embree::reorient_facets_raycast(v, f, rays_total, rays_minimum, facet_wise, use_parity, is_verbose, i, c);
    return std::make_tuple(    npe::move(rays_total),
    npe::move(rays_minimum),
    npe::move(facet_wise),
    npe::move(use_parity),
    npe::move(is_verbose),
    npe::move(i),
    npe::move(c));
} else if (dtype.type() == npe::type_f64) {
    int rays_total;
    int rays_minimum;
    bool facet_wise;
    bool use_parity;
    bool is_verbose;
    dense_f64 i;
    dense_f64 c;
    igl::    embree::reorient_facets_raycast(v, f, rays_total, rays_minimum, facet_wise, use_parity, is_verbose, i, c);
    return std::make_tuple(    npe::move(rays_total),     npe::move(rays_minimum),     npe::move(facet_wise),     npe::move(use_parity),     npe::move(is_verbose),     npe::move(i),     npe::move(c));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/reorient_facets_raycast.h>

const char* ds_reorient_facets_raycast = R"igl_Qu8mg5v7(

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

 Outputs:
       FF  #F by 3 list of reoriented faces
     Defaults:
       rays_total = F.rows()*100;
       rays_minimum = 10;
       facet_wise = false;
       use_parity = false;
       is_verbose = false;
)igl_Qu8mg5v7";

npe_function(reorient_facets_raycast)
npe_doc(ds_reorient_facets_raycast)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 ff;
    dense_f32 i;
    igl::    embree::reorient_facets_raycast(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),
    npe::move(i));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 ff;
    dense_f64 i;
    igl::    embree::reorient_facets_raycast(v, f, ff, i);
    return std::make_tuple(    npe::move(ff),     npe::move(i));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


