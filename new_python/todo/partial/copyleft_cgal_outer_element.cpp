// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/outer_vertex.h>

const char* ds_outer_vertex = R"igl_Qu8mg5v7(

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

 Find a vertex that is reachable from infinite without crossing any faces.
       Such vertex is called "outer vertex."
      
       Precondition: The input mesh must have all self-intersection resolved and
       no duplicated vertices.  See cgal::remesh_self_intersections.h for how to
       obtain such input.
      
       Inputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices into V
         I  #I list of facets to consider
       Outputs:
         v_index  index of outer vertex
         A  #A list of facets incident to the outer vertex
)igl_Qu8mg5v7";

npe_function(outer_vertex)
npe_doc(ds_outer_vertex)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    IndexType & v_index;
    dense_f32 a;
    igl::    copyleft::    cgal::outer_vertex(v, f, i, v_index, a);
    return std::make_tuple(    npe::move(v_index),
    npe::move(a));
} else if (dtype.type() == npe::type_f64) {
    IndexType & v_index;
    dense_f64 a;
    igl::    copyleft::    cgal::outer_vertex(v, f, i, v_index, a);
    return std::make_tuple(    npe::move(v_index),     npe::move(a));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/outer_edge.h>

const char* ds_outer_edge = R"igl_Qu8mg5v7(

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

 Find an edge that is reachable from infinity without crossing any faces.
       Such edge is called "outer edge."
      
       Precondition: The input mesh must have all self-intersection resolved
       and no duplicated vertices.  The correctness of the output depends on
       the fact that there is no edge overlap.  See
       cgal::remesh_self_intersections.h for how to obtain such input.
      
       Inputs:
         V  #V by 3 list of vertex positions
         F  #F by 3 list of triangle indices into V
         I  #I list of facets to consider
       Outputs:
         v1 index of the first end point of outer edge
         v2 index of the second end point of outer edge
         A  #A list of facets incident to the outer edge
)igl_Qu8mg5v7";

npe_function(outer_edge)
npe_doc(ds_outer_edge)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)
npe_arg(i, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    IndexType & v1;
    IndexType & v2;
    dense_f32 a;
    igl::    copyleft::    cgal::outer_edge(v, f, i, v1, v2, a);
    return std::make_tuple(    npe::move(v1),
    npe::move(v2),
    npe::move(a));
} else if (dtype.type() == npe::type_f64) {
    IndexType & v1;
    IndexType & v2;
    dense_f64 a;
    igl::    copyleft::    cgal::outer_edge(v, f, i, v1, v2, a);
    return std::make_tuple(    npe::move(v1),     npe::move(v2),     npe::move(a));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


