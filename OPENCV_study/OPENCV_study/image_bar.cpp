#if 0
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1(50, 512, CV_8UC1, Scalar(0));
	Mat image2(50, 512, CV_8UC1, Scalar(0));

	for (int i = 0; i < image1.rows; i++)
	{
		for (int j = 0; j < image1.cols; j++)
		{
			image1.at<uchar>(i, j) = j / 2;  // int 형이기에 이미지1은 부드럽고 이미지2에는 소수점으로 돌리기에 구간이 길다
			image2.at<uchar>(i, j) = (j / 20) * 10; //나눗셈에 대한 소수점 손실 
		}
	}
	imshow("image1", image1);
	imshow( "image2", image2);
	waitKey();

}
#endif