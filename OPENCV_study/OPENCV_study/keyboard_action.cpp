#if 0


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("키보드이벤트", WINDOW_AUTOSIZE);
	imshow("키보드이벤트", image);

	while (1)
	{
		int key = waitKey(100); // 키 받아오는것 waitkey
		if (key == 27) break;
		switch (key)
		{
			case 0x250000:
				cout << "왼쪽 화살표" << endl;
				break;
			case 0x260000:
				cout << "위 화살표" << endl;
				break;
			case 0x270000:
				cout << "오른쪽 화살표" << endl;
				break;
			case 0x280000:
				cout << "아래 화살표" << endl; 
				break;

		}
	}
}
#endif 