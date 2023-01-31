#include "ZoomWindow.h"

ZoomWindow::ZoomWindow(Point xy, int w, int h, const string& title)
    :Simple_window(xy,w,h,title),
    plane(PLANE_Y_OFFSET, 0, 1.0, w, (h-PLANE_Y_OFFSET)), 
    next_i(Point(x_max()-120,0),50,20,"Center i:"),
    next_r(Point(x_max()-240,0),50,20,"Center r:"),
    next_zoom(Point(x_max()-360,0),50,20,"Zoom Level:")
{
    attach(plane);
    attach(next_i);
    attach(next_r);
    attach(next_zoom);
    plane.createBuffer();
}

bool ZoomWindow::wait_for_button() {
    Simple_window::wait_for_button();
    double i = 0;
    double r = 0;
    double z = 0;

    istringstream is;

    is.str(next_i.get_string());
    is >> i;
    cout << "next i: " << i << endl;
    is.clear();

    is.str(next_r.get_string());
    is >> r;
    cout << "next r: " << r << endl;
    is.clear();

    is.str(next_zoom.get_string());
    is >> z;
    cout << "next z: " << z << endl;
    is.clear();

    complex<double> c (r,i);

    plane.setCenter(c);
    plane.setZoomLevel(z);
    plane.createBuffer();

}

double ZoomWindow::getCenter_r() const {
    return plane.getCenter().real();
}

double ZoomWindow::getCenter_i() const {
    return plane.getCenter().imag();
}

double ZoomWindow::getZoom() const {
    return plane.getZoomLevel();
}