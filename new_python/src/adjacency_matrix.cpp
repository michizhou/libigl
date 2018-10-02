#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>
#include <igl/adjacency_matrix.h>

const char* ds_adjacency_matrix = R"igl_Qu8mg5v7(
Constructs the graph adjacency matrix of a given mesh (v, f).

Parameters
----------
f : #f by dim list of mesh simplices
dtype : data-type of the returned objects, optional. Default is `float64`.
        (All integer return types are `int32` by default.)

Returns
-------
a : max(f) by max(f) cotangent matrix, each row i corresponding to v(i, :)

See also
--------
edges, cotmatrix, diag

Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>> a = adjacency_matrix(f)

# Sum each row 
>>> a_sum = np.sum(a, axis=1)

# Convert row sums into diagonal of sparse matrix
>>> a_diag = diag(a_sum)

# Build uniform laplacian
>>> u = a - a_diag
)igl_Qu8mg5v7";

npe_function(adjacency_matrix)
npe_doc(ds_adjacency_matrix)

npe_arg(f, dense_i32)
npe_default_arg(dtype, npe::dtype, "float64")


npe_begin_code()
using namespace std;


if (dtype.type() == npe::type_f32) {
    Sparse_f32 a;
    igl::adjacency_matrix(f, a);
    return npe::move(a);
} else if (dtype.type() == npe::type_f64) {
    Sparse_f64 a;
    igl::adjacency_matrix(f, a);
    return npe::move(a);
} else {
    throw pybind11::type_error("Only float32 and float64 dtypes are supported.");
}

npe_end_code()


