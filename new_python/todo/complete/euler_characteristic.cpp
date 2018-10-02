#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/euler_characteristic.h>

const char* ds_euler_characteristic = R"igl_Qu8mg5v7(

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

 Computes the Euler characteristic of a given mesh (V,F)
  
   Inputs:
     F #F by dim list of mesh faces (must be triangles)
   Returns An int containing the Euler characteristic
)igl_Qu8mg5v7";

npe_function(euler_characteristic)
npe_doc(ds_euler_characteristic)

npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::euler_characteristic(f);

return

npe_end_code()
#include <igl/euler_characteristic.h>

const char* ds_euler_characteristic = R"igl_Qu8mg5v7(

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

 Computes the Euler characteristic of a given mesh (V,F)
   Templates:
     Scalar  should be a floating point number type
     Index   should be an integer type
   Inputs:
     V       #V by dim list of mesh vertex positions
     F       #F by dim list of mesh faces (must be triangles)
   Returns An int containing the Euler characteristic
)igl_Qu8mg5v7";

npe_function(euler_characteristic)
npe_doc(ds_euler_characteristic)

npe_arg(v, dense_f64)
npe_arg(f, dense_i32)



npe_begin_code()
using namespace std;



igl::euler_characteristic(v, f);

return

npe_end_code()


