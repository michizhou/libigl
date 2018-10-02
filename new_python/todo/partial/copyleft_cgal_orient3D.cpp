// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/orient3D.h>

const char* ds_orient3_d = R"igl_Qu8mg5v7(

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
         pa,pb,pc,pd  3D points.
       Output:
         1 if pa,pb,pc,pd forms a tet of positive volume.
         0 if pa,pb,pc,pd are coplanar.
        -1 if pa,pb,pc,pd forms a tet of negative volume.
)igl_Qu8mg5v7";

npe_function(orient3_d)
npe_doc(ds_orient3_d)

npe_arg(pa, Scalar [3])
npe_arg(pb, Scalar [3])
npe_arg(pc, Scalar [3])
npe_arg(pd, Scalar [3])



npe_begin_code()
using namespace std;



igl::copyleft::cgal::orient3D(pa, pb, pc, pd);

return

npe_end_code()


