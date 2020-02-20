#include <cairo.h>
#include <rsvg.h>
#include <iostream>

using namespace std;

int Width = 800;
int Height = 800;
string path = "";

int main(int argc, char *argv[])
{
    if(argc!=4) {
        cout << "Введите Width"<<"\n";
        cin >> Width;
        cout << "Введите Height"<<"\n";
        cin >> Height;
        cout << "Введите путь файла и имя"<<"\n";
        cin >> path;
    }else
    {
        Width =  atoi(argv[1]);
        Height =  atoi(argv[2]);
        path = argv[3];
    }

    //Display buffer and Canvas
    cairo_surface_t *surface;

    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,Width, Height);
    cairo_t *cr = cairo_create (surface);

    cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);

    //Flame Surface and SVG Handle
    RsvgHandle* flame_handle;
    flame_handle = rsvg_handle_new_from_file((path+".svg").c_str(),0);

    RsvgDimensionData dimensions;
    double x_factor, y_factor;
    double scale_factor;
    rsvg_handle_get_dimensions (flame_handle, &dimensions);
    x_factor = (double) Width / dimensions.width;
    y_factor = (double) Height / dimensions.height;
    scale_factor = MIN (x_factor, y_factor);
    cairo_scale (cr, scale_factor, scale_factor);


    rsvg_handle_render_cairo (flame_handle,cr);

    // Clean up
    cairo_surface_write_to_png (surface, (path+".png").c_str());
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    return 0;
}
