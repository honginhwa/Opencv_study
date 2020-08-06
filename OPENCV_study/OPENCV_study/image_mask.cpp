#if 1
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("../image/sum_test.jpg", 1);
	CV_Assert(image.data);

	Mat mask(image.size(), CV_8UC1, Scalar(0));
	mask(Rect(20, 40, 70, 70)).setTo(255);

	Scalar sum_value = sum(image);
	Scalar mean_value1 = mean(image);
	Scalar mean_value2 = mean(image, mask); // ����ũ 1 ������  ��� ��� 

	cout << "sum_value = " << sum_value << endl;
	cout << " mean_value1 =" << mean_value1 << endl;
	cout << " mean_value2 =" << mean_value2 << endl;

	Mat mean, stddev;
	meanStdDev(image, mean, stddev);
	cout << " mean =" << mean << endl;
	cout << "stddev = " << stddev << endl << endl;
	1
	meanStdDev(image, mean, stddev, mask); //�̹����� ��հ� ǥ�������� ���Ѵ� 
	cout << "mean = " << mean << endl;
	cout << "stddev = " << stddev << endl;

	imshow(" image", image);
	imshow("stddev", stddev);
	waitKey(0);
	return 0;

	

}
#endif