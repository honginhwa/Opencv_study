#if 0

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
 
string title = "밝기 변경", bar_name = "밝기값";
Mat image;

bool LD = false;
int MP;

void onChange(int value, void *userdata)
{
	int add_value = value - 130;
	cout << "추가 화소값" << endl;
	Mat tmp = image + add_value;
	imshow(title, image);

}


void onMouse(int event, int x, int y, int flags, void *param) 
{
	if (event == EVENT_LBUTTONDOWN)
	{
		LD = true;
		MP = x;
	}
		if (event == EVENT_MOUSEMOVE)
		{
			if (LD == true)
			{
				if (LD = true)
				{

				
					if (x > MP)
					{
						add(image, 1, image);
						setTrackbarPos(bar_name, title, image.at<uchar>(0));
						MP = x;
					}
					else if (x < MP)
					{
						subtract(image, 1, image);
						setTrackbarPos(bar_name, title, image.at<uchar>(0));
						MP = x;
					}
				}
			}
		}
	if (event == 4)
	{
		LD = false;
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