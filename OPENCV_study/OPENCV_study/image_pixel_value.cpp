#if 0

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("../image/pixel_test.jpg", IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << " 영상을 읽지 못했습니다" << endl;
		exit(1);
	}
	Rect roi(135, 90, 20, 15);
	Mat roi_img = image(roi);
	cout << "roi_img : " << endl;

	for (int i = 0; i < roi_img.rows; i++) // roi_img안에 돌아다니면서 화소값을 프린트해준다 

	{
		for (int j = 0; j < roi_img.cols; j++)
		{
			cout.width(5);
			cout << (int)roi_img.at<uchar>(i, j);
		}
		cout << endl;
	}

	rectangle(image, roi, Scalar(255),1);
	imshow("image", image);
	waitKey(0);
	return 0;

}


#endif
