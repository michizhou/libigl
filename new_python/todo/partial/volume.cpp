// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/volume.h>

const char* ds_volume = R"igl_Qu8mg5v7(

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

 VOLUME Compute volume for all tets of a given tet mesh
   (V,T)
  
   vol = volume(V,T)
  
   Inputs:
     V  #V by dim list of vertex positions
     T  #V by 4 list of tet indices
   Outputs:
     vol  #T list of dihedral angles (in radians)
  
)igl_Qu8mg5v7";

npe_function(volume)
npe_doc(ds_volume)

npe_arg(v, dense_f64)
npe_arg(t, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vol;
    igl::volume(v, t, vol);
    return npe::move(vol);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vol;
    igl::volume(v, t, vol);
    return npe::move(vol);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/volume.h>

const char* ds_volume = R"igl_Qu8mg5v7(
See volume for the documentation.
)igl_Qu8mg5v7";

npe_function(volume)
npe_doc(ds_volume)

npe_arg(a, dense_f64)
npe_arg(b, dense_f64)
npe_arg(c, dense_f64)
npe_arg(d, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vol;
    igl::volume(a, b, c, d, vol);
    return npe::move(vol);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vol;
    igl::volume(a, b, c, d, vol);
    return npe::move(vol);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/volume.h>

const char* ds_volume = R"igl_Qu8mg5v7(

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

 Intrinsic version:
  
   Inputs:
     L  #V by 6 list of edge lengths (see edge_lengths)
)igl_Qu8mg5v7";

npe_function(volume)
npe_doc(ds_volume)

npe_arg(l, dense_f64)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    dense_f32 vol;
    igl::volume(l, vol);
    return npe::move(vol);
} else if (dtype.type() == npe::type_f64) {
    dense_f64 vol;
    igl::volume(l, vol);
    return npe::move(vol);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()






// INCOMPLETE BINDINGS ========================
#include <igl/volume_single.h>

const char* ds_volume_single = R"igl_Qu8mg5v7(

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

 Single tet
)igl_Qu8mg5v7";

npe_function(volume_single)
npe_doc(ds_volume_single)

npe_arg(a, VecA &)
npe_arg(b, VecB &)
npe_arg(c, VecC &)
npe_arg(d, VecD &)



npe_begin_code()
using namespace std;



igl::volume_single(a, b, c, d);

return

npe_end_code()


