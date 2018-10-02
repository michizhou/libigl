// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/row_to_point.h>

const char* ds_row_to_point = R"igl_Qu8mg5v7(

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

 Extract a row from V and treat as a 2D cgal point (only first two
       columns of V are used).
       
       Inputs:
         V  #V by 2 list of vertex positions
         i  row index
       Returns 2D cgal point
)igl_Qu8mg5v7";

npe_function(row_to_point)
npe_doc(ds_row_to_point)

npe_arg(v, dense_f64)
npe_arg(i, typename DerivedV::Index &)



npe_begin_code()
using namespace std;



igl::copyleft::cgal::row_to_point(v, i);

return

npe_end_code()


