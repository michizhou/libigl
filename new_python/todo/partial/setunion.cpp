// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/setunion.h>

const char* ds_setunion = R"igl_Qu8mg5v7(

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

 Union of elements of matrices (like matlab's `union`)
  
   Inputs:
     A  m-long vector of indices
     B  n-long vector of indices
   Outputs:
     C  (k>=m)-long vector of unique elements appearing in A and/or B
     IA  (<k>=m)-long list of indices into A so that C = sort([A(IA);B(IB)])
     IB  (<k>=m)-long list of indices into B so that C = sort([A(IA);B(IB)])
  
)igl_Qu8mg5v7";

npe_function(setunion)
npe_doc(ds_setunion)

npe_arg(a, Eigen::DenseBase<DerivedA> &)
npe_arg(b, Eigen::DenseBase<DerivedB> &)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 c;
    dense_f32 ia;
    dense_f32 ib;
    igl::setunion(a, b, c, ia, ib);
    return std::make_tuple(    npe::move(c),
    npe::move(ia),
    npe::move(ib));
} else if (dtype.type() == npe::type_f64) {
    dense_f64 c;
    dense_f64 ia;
    dense_f64 ib;
    igl::setunion(a, b, c, ia, ib);
    return std::make_tuple(    npe::move(c),     npe::move(ia),     npe::move(ib));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


