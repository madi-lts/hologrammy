#include <iostream>
#include <vector>
#include <random>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using random_bytes_engine = 
    std::independent_bits_engine<std::default_random_engine, UINT8_WIDTH, unsigned char>;

int main()
{
    int ImgSize = 512 * 512 * 1;
    

    random_bytes_engine rbe;
    std::vector<unsigned char> data(ImgSize);
    std::generate(begin(data), end(data), std::ref(rbe));
    
    Mat image = Mat(512, 512, CV_8UC1, reinterpret_cast<unsigned char*>(data.data()));

    //namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", image); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}