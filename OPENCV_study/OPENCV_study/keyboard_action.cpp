#if 0


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("Ű�����̺�Ʈ", WINDOW_AUTOSIZE);
	imshow("Ű�����̺�Ʈ", image);

	while (1)
	{
		int key = waitKey(100); // Ű �޾ƿ��°� waitkey
		if (key == 27) break;
		switch (key)
		{
			case 0x250000:
				cout << "���� ȭ��ǥ" << endl;
				break;
			case 0x260000:
				cout << "�� ȭ��ǥ" << endl;
				break;
			case 0x270000:
				cout << "������ ȭ��ǥ" << endl;
				break;
			case 0x280000:
				cout << "�Ʒ� ȭ��ǥ" << endl; 
				break;

		}
	}
}
#endif 