#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

// to calculate the centre of a black circle on an image with white background
int main(int argc, char* argv[])
{
    int x, y;
    int BlackPoints;
    x=0;
    y=0;
    BlackPoints=0;
    
    if (argc < 1)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }
    
    Mat image;
    image = imread( argv[1], 0 );
    
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    
    for(int j=0; j<image.rows; j++)
        for(int i=0; i<image.cols; i++)
        {
            Scalar intensity = image.at<uchar>(j,i);
            //cout << "Pixel value " << intensity.val[0] << " for " << j << "," << i << endl;
            
            // the center of the black circle is the average of the coordinates of all the points inside.
            if(!intensity.val[0])
            {
                // cout << intensity.val[0] << "\t" << j << "," << i << endl;
                x+=i;
                y+=j;
                BlackPoints++;
            }
        }
    
    x=x/BlackPoints;
    y=y/BlackPoints;
    
    cout << "The size of the image (pixel): " << endl << image.cols << "," << image.rows << endl;
    cout << "The center of the black circle (pixel): " << endl << x << "," << y << endl;
    
    return 0;
}

/*
 Output
 The size of the image:
 269,193
 Pixel coordinates of the center of the black circle:
 89,99
*/
