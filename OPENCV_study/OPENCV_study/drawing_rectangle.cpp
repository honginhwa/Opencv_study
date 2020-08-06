#if 0 // 점두개로 네모 그리기 

#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

string title = "밝기 변경", bar_name = "밝기값";
Mat image;

Point pt_1;
Point pt_2;
Point pt_3;
Point e;

int pt_x1;
int pt_x2;
int pt_y1;
int pt_y2;

bool Click;
Rect rect;
Scalar white(255, 255, 255), yellow(0, 255, 255), blue(255, 0.0);
Scalar red = Scalar(0, 0, 255);
Scalar green = Scalar(0, 255, 0);

void onMouse(int event, int x, int y, int flags, void *param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		if (Click == false)
		{
			Click = true;
			pt_1 = Point(x, y);
		}
		else
		{
			Click = false;
			pt_2 = Point(x, y);
			rect = Rect(pt_1, pt_2);
			rectangle(image, rect, red, 3);
			imshow(title, image);

		}
	}
	if (event == EVENT_RBUTTONDOWN)
	{
		if (Click == false)
		{
			Click = true;
			pt_x1 = x;
			pt_y1 = y;
		}
		else
		{
			Click = false;
			pt_x2 = x;
			pt_y2 = y;
			double a = pt_x1 - pt_x2;
			double b = pt_y1 - pt_y2;
			double c = sqrt(pow(a, 2) + sqrt(pow(b, 2)));
			e = Point(((pt_x1 + pt_x2) / 2), ((pt_y1 + pt_y2) / 2));

			cout << "e: " << endl;
			cout << "c: " << endl;
			circle(image, e, c, Scalar(0), 1);

			imshow(title, image);

		}
	}
}
int main()
{
	int value = 130;
	image = Mat(500, 500, CV_8UC1, Scalar(130));
	imshow(title, image);
	setMouseCallback(title, onMouse, 0);
	waitKey(0);
	return 0;
}



#endif
