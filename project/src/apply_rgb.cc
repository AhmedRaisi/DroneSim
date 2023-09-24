#include "apply_rgb.h"

int ApplyRGB::ApplyFilter(Image* image){
    int width = image->GetWidth();
    int height = image->GetHeight();

    for(int i=0;i<width;i++){
        for (int j=0; j<height; j++){
            unsigned char* pixel = image->GetPixel(i,j);
            float red = 1.0*pixel[0];
            float green = 1.0*pixel[1];
            float blue = 1.0*pixel[2];
            
            //if orange pixel
            if (red >= 220 && red <=255 && green >= 120 && green <= 165 && blue >= 30 && blue <= 60){
                return 0;
            }

        }
    }

    return -1;
}
