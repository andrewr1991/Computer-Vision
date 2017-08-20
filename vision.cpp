#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void processImage(Mat image) {
	int channels = image.channels();
	int numRows = image.rows;
	int numCols = image.cols * channels;
	
	for (int i = 0; i < numRows; i++) {
		uchar* image_row = image.ptr<uchar>(i);
		for (int j = 0; j < numCols; ++j) {
			image_row[j] = 0;
		}
	}
} 

int main() {
	Mat image = imread("test.jpg");
	processImage(image);
	
	imshow("Output", image);
	waitKey(0);
	
	return 0;
}
