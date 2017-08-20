// Code taken from Learning OpenCV 3 Application Development 
// by Samyak Datta

/*
 * Image traversal methods in OpenCV
 * Code taken from "Learning OpenCV 3 Application Development"
 * by Samyak Datta
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// slower version of scanImage because the matrix is not flattened and traversal is done in O(n^2) time
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

// faster version of processImage because the matrix is flattened and traversal is done in O(n) time
void scanImage(Mat& image) {
	int channels = image.channels();
	int num_rows = image.rows;
	int num_cols = (image.cols * channels);
	
	if (image.isContinuous()) {
		num_cols = (num_rows * num_cols);
		num_rows = 1;
	}
	
	for (int i = 0; i < num_rows; i++) {
		uchar *row_ptr = image.ptr<uchar>(i);
		for (int j = 0; j < num_cols; ++j) {
			row_ptr[j];
			// Computation
		}
	}
}

// traversal using the at() method
void scanImageAt(Mat& image) {
	int channels = image.channels();
	
	if (channels == 1) {
		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; ++j) {
				image.at<uchar>(i, j);
			}
		}
	}
	else if (channels == 3) {
		// can use Mat_ template here
		// Mat_<Vec3b> _image = image;
		// _image(i, j)[0];
		// _image(i, j)[1];
		// _image(i, j)[2];
		
		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; ++j) {
				image.at<Vec3b>(i, j)[0];
				image.at<Vec3b>(i, j)[1];
				image.at<Vec3b>(i, j)[2];
			}
		}
	}
}

int main() {
	Mat image = imread("test.jpg");	
	imshow("Output", image);
	waitKey(0);
	
	return 0;
}
