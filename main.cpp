#include <iostream>
#include <fstream>

int main() {

    //Image
    const int image_width = 256;
    const int image_height = 256;

    std::ofstream out("image.ppm");

    //Render
    // PPM header: "P3" = text colors, then width/height, then max color value
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Rows go top to bottom, pixels left to right
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            // Colors are floats in [0, 1]
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0.0;

            // Scale to [0, 255]
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}