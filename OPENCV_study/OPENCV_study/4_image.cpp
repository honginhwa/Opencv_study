
#if 0 // 하나에 4개 이미지 


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("../image/flip_test.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0);
	flip(image, y_axis, 1);
	flip(image, xy_axis, -1);
	repeat(image, 2, 2, rep_img);
	transpose(image, trans_img);

	int i = 0, j = 0;
	for (j = 0; j<image.rows; j++)
		for (i = 0; i < image.cols * 3; i += 3 )
		{
			rep_img.at<uchar>(j, image.cols * 3 + i) = x_axis.at<uchar>(j, i);
			rep_img.at<uchar>(j, image.cols * 3 + 1 + i) = x_axis.at<uchar>(j, i+1);
			rep_img.at<uchar>(j, image.cols * 3 + 2 + i) = x_axis.at<uchar>(j, i+2);
		}

	for (j = 0; j<image.rows; j++)
		for (i = 0; i < image.cols * 3; i += 3)
		{
			rep_img.at<uchar>(j + image.rows, i) = y_axis.at<uchar>(j, i);
			rep_img.at<uchar>(j + image.rows, 1 + i) = y_axis.at<uchar>(j, i + 1);
			rep_img.at<uchar>(j + image.rows, 2 + i) = y_axis.at<uchar>(j, i + 2);
		}

	for (j = 0; j<image.rows; j++)
		for (i = 0; i < image.cols * 3; i += 3)
		{
			rep_img.at<uchar>(j + image.rows, image.cols * 3 + i) = xy_axis.at<uchar>(j, i);
			rep_img.at<uchar>(j + image.rows, image.cols * 3 + 1 + i) = xy_axis.at<uchar>(j, i + 1);
			rep_img.at<uchar>(j + image.rows, image.cols * 3 + 2 + i) = xy_axis.at<uchar>(j, i + 2);
		}
	imshow("rep_img", rep_img);
	imshow("image", image);
	cout << image.size() << endl;
	cout << image.cols << endl;
	waitKey();
	return 0;

}


#endif
