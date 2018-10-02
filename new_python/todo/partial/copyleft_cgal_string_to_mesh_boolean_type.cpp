// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/string_to_mesh_boolean_type.h>

const char* ds_string_to_mesh_boolean_type = R"igl_Qu8mg5v7(

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

 Convert string to boolean type
      
        Inputs:
          s  string identifying type, one of the following:
            "union","intersect","minus","xor","resolve"
        Outputs:
          type  type of boolean operation
       Returns true only on success
           
)igl_Qu8mg5v7";

npe_function(string_to_mesh_boolean_type)
npe_doc(ds_string_to_mesh_boolean_type)

npe_arg(s, std::string &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    igl::MeshBooleanType & type;
    igl::    copyleft::    cgal::string_to_mesh_boolean_type(s, type);
    return npe::move(type);
} else if (dtype.type() == npe::type_f64) {
    igl::MeshBooleanType & type;
    igl::    copyleft::    cgal::string_to_mesh_boolean_type(s, type);
    return npe::move(type);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/string_to_mesh_boolean_type.h>

const char* ds_string_to_mesh_boolean_type = R"igl_Qu8mg5v7(

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

 Returns type without error handling
)igl_Qu8mg5v7";

npe_function(string_to_mesh_boolean_type)
npe_doc(ds_string_to_mesh_boolean_type)

npe_arg(s, std::string &)



npe_begin_code()
using namespace std;



igl::copyleft::cgal::string_to_mesh_boolean_type(s);

return

npe_end_code()


