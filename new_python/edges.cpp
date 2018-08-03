#include <Eigen/Core>
#include <numpyeigen_utils.h>
#include <numpyeigen_typedefs.h>
#include <igl/edges.h>
#include <pybind11/pybind11.h>
#include <exception>

npe_function("edges")
npe_arg("f", "type_i32", "type_i64")
npe_default_arg("dtype", "pybind11::object", "pybind11::dtype(\"int32\")")
npe_begin_code()

npe::Map_f F((npe::Scalar_f*)f.data(), f.shape()[0], f.shape()[1]);

switch(pybind11::dtype::from_args(dtype).type()) {
  case numpyeigen::detail::NumpyTypeChar::char_i32:
  {
    Eigen::Matrix<std::int32_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::edges(F, E);
    return NPE_MOVE_DENSE(E);
  }
  case numpyeigen::detail::NumpyTypeChar::char_i64:
  {
    Eigen::Matrix<std::int64_t, Eigen::Dynamic, Eigen::Dynamic> E;
    igl::edges(F, E);
    return NPE_MOVE_DENSE(E);
  }
  default:
    throw std::runtime_error("Bad dtype. Only int32 and int64 are supported.");
}

npe_end_code()
