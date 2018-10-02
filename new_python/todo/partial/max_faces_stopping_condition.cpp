// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/max_faces_stopping_condition.h>

const char* ds_max_faces_stopping_condition = R"igl_Qu8mg5v7(

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

 Stopping condition function compatible with igl::decimate. The outpute
   function handle will return true if number of faces is less than max_m
  
   Inputs:
     m  reference to working variable initially should be set to current
      number of faces.
     orig_m  number (size) of original face list _**not**_ including any
       faces added to handle phony boundary faces connecting to point at
       infinity. For closed meshes it's safe to set this to F.rows()
     max_m  maximum number of faces
   Outputs:
     stopping_condition
  
)igl_Qu8mg5v7";

npe_function(max_faces_stopping_condition)
npe_doc(ds_max_faces_stopping_condition)

npe_arg(orig_m, int)
npe_arg(max_m, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & m;
    std::function<bool (const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const std::set<std::pair<double, int> > &, const std::vector<std::set<std::pair<double, int> >::iterator> &, const Eigen::MatrixXd &, const int, const int, const int, const int, const int)> & stopping_condition;
    igl::max_faces_stopping_condition(orig_m, max_m, m, stopping_condition);
    return std::make_tuple(    npe::move(m),
    npe::move(stopping_condition));
} else if (dtype.type() == npe::type_f64) {
    int & m;
    std::function<bool (const Eigen::MatrixXd &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const Eigen::VectorXi &, const Eigen::MatrixXi &, const Eigen::MatrixXi &, const std::set<std::pair<double, int> > &, const std::vector<std::set<std::pair<double, int> >::iterator> &, const Eigen::MatrixXd &, const int, const int, const int, const int, const int)> & stopping_condition;
    igl::max_faces_stopping_condition(orig_m, max_m, m, stopping_condition);
    return std::make_tuple(    npe::move(m),     npe::move(stopping_condition));
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()
#include <igl/max_faces_stopping_condition.h>

const char* ds_max_faces_stopping_condition = R"igl_Qu8mg5v7(
See max_faces_stopping_condition for the documentation.
)igl_Qu8mg5v7";

npe_function(max_faces_stopping_condition)
npe_doc(ds_max_faces_stopping_condition)

npe_arg(, Eigen::MatrixXd &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::VectorXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, Eigen::MatrixXi &)
npe_arg(, std::set<std::pair<double, int> > &)
npe_arg(, std::vector<std::set<std::pair<double, int> >::iterator> &)
npe_arg(, Eigen::MatrixXd &)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(, int)
npe_arg(orign_m, int)
npe_arg(max_m, int)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    int & m;
    igl::max_faces_stopping_condition(, , , , , , , , , , , , , , orign_m, max_m, m);
    return npe::move(m);
} else if (dtype.type() == npe::type_f64) {
    int & m;
    igl::max_faces_stopping_condition(, , , , , , , , , , , , , , orign_m, max_m, m);
    return npe::move(m);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


