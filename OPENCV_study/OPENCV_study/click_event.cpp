#if 0

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

string title = "��� ����", bar_name = "��Ⱚ";
Mat image;

bool LD = false;
int MP;

void onChange(int value, void *userdata)
{
	int add_value = value - 130;
	cout << "�߰� ȭ�Ұ�" << endl;
	Mat tmp = image + add_value;
	imshow(title, image);

}


void onMouse(int event, int x, int y, int flags, void *param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		
	}
	
	if (event == EVENT_RBUTTONDOWN)
	{
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		
	}
}

int main()
{
	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(130));
	namedWindow(title, WINDOW_AUTOSIZE);

	createTrackbar(bar_name, title, &value, 255, onChange);

	setMouseCallback(title, onMouse, 0);
	imshow(title, image);
	waitKey(0);
	return 0;

}
#endif 