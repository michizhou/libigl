// COMPLETE BINDINGS ========================
#include <tuple>
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <npe.h>
#include <typedefs.h>






// INCOMPLETE BINDINGS ========================
#include <igl/render_to_tga.h>

const char* ds_render_to_tga = R"igl_Qu8mg5v7(

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

 Render current open GL image to .tga file
     Inputs:
       tga_file  path to output .tga file
       width  width of scene and resulting image
       height height of scene and resulting image
    /  alpha  whether to include alpha channel
     Returns true only if no errors occurred
    
     See also: png/render_to_png which is slower but writes .png files
)igl_Qu8mg5v7";

npe_function(render_to_tga)
npe_doc(ds_render_to_tga)

npe_arg(tga_file, std::string)
npe_arg(width, int)
npe_arg(height, int)
npe_arg(alpha, bool)



npe_begin_code()
using namespace std;



igl::opengl::render_to_tga(tga_file, width, height, alpha);

return

npe_end_code()


