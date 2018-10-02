// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/triangle_fan.h>

const char* ds_triangle_fan = R"igl_Qu8mg5v7(

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

 Given a list of faces tessellate all of the "exterior" edges forming another
   list of 
  
   Inputs:
     E  #E by simplex_size-1  list of exterior edges (see exterior_edges.h)
   Outputs:
     cap  #cap by simplex_size  list of "faces" tessellating the boundary edges
)igl_Qu8mg5v7";

npe_function(triangle_fan)
npe_doc(ds_triangle_fan)

npe_arg(e, Eigen::MatrixXi &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Eigen::MatrixXi & cap;
    igl::triangle_fan(e, cap);
    return npe::move(cap);
} else if (dtype.type() == npe::type_f64) {
    Eigen::MatrixXi & cap;
    igl::triangle_fan(e, cap);
    return npe::move(cap);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/triangle_fan.h>

const char* ds_triangle_fan = R"igl_Qu8mg5v7(

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

 In-line version
)igl_Qu8mg5v7";

npe_function(triangle_fan)
npe_doc(ds_triangle_fan)

npe_arg(e, Eigen::MatrixXi &)



npe_begin_code()
using namespace std;



igl::triangle_fan(e);

return

npe_end_code()


