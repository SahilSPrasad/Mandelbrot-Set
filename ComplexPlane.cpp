#include "ComplexPlane.h"

void ComplexPlane::draw_lines() const {
    fl_draw_image(buf, 0, y_pixel_offset,xPixels,yPixels);
}

void writePixel(unsigned char* buf, int xPixels, int row,int col, unsigned char r, unsigned char g, unsigned char b) {
        // Mistake doing buf[i] when the location is given by the formula
        // and making buf[i] = conversion formula
        buf[(row * xPixels + col) * 3] = r;
        //cout << "r: " << buf[i] << endl;
        buf[(row * xPixels + col) * 3 + 1] = g;
        //cout << "g: " << buf[i] << endl;
        buf[(row * xPixels + col) * 3 + 2] = b;
        //cout << "b: " << buf[i] << endl;
 
}

int countIterations(double re, double im, int maxIterations) {
    complex<double> c (re, im);
    complex<double> z (0,0);
    // if abs(z) < 2.0 part of set - color black
    // if abs(z) > 2.0 not part of set - different color color
    //Repeatedly calculate  z = z*z + c, until abs(z) is greater than 2.0 or the iterations have exceeded maxIterations
    // Condition to leave: when abs(z) > 2.0
    // or
    // Condition to leave: i > maxIterations

    int i = 0;
    while (i < maxIterations && abs(z) < 2.0) {
        z = z*z + c;
        i++;
    }


    return i;
}

double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh) {
    return ((n-fromLow)/static_cast<double>(fromHigh-fromLow)) * (toHigh - toLow) + toLow;
}

void ComplexPlane::createBuffer() {
    //double width = reRange * zoomLevel;//x
    //double height = imRange * zoomLevel;//y

    unsigned char r;
    unsigned char g;
    unsigned char b;

    double re = 0;
    double im = 0;

    int iterations = 0;
    

    // //i maps to real, j maps to imaginary
    for (int i = 0; i < yPixels; i++) {

        for (int j = 0; j < xPixels; j++) {

            re = mapRange(j, 0, xPixels,  center.real() - (reRange/2.0 * zoomLevel), center.real() + (reRange/2.0 * zoomLevel));
            im = mapRange(i, yPixels, 0,  center.imag() - (imRange/2.0 * zoomLevel), center.imag() + (imRange/2.0 * zoomLevel));
            //mistake i for re, and j for im

            // re = mapRange(i, 0, width,  -width/2 , width/2);
            // im = mapRange(j, height, 0, -height/2, height/2)


            //cout << "im: " << im << endl;
            // cout << "c.real(): " << c.real() << endl;
            // cout << "c.imag(): " << c.imag() << endl;

            iterations = countIterations(re, im, maxIterations);

            //cout << "Iterations: " << iterations << endl;

            Fl::get_color(maxIterations - iterations, r, g, b);


            writePixel(buf, xPixels, i, j, r, g ,b);


        }
        //cout << "i: " << i << endl;
        //cout << "re: " << re << endl;
        
    }





}
