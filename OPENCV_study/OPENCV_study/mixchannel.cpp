
#if 0  // �ͽ�ä�� 

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat ch0(3, 4, CV_8U, Scalar(10));
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	vector<Mat> vec_012;
	vec_012.push_back(ch0);
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012); // ��Ĺ��͸� ����ä�� ��� �ռ�

	Mat ch_13(ch_012.size(), CV_8UC2);
	Mat  ch_2(ch_012.size(), CV_8UC1);


	Mat out[] = { ch_13, ch_2 };
	int from_to[] = { 2, 0, 0, 1, 1, 2 };
	mixChannels(&ch_012, 1, out, 2, from_to, 3); // �ͽ�ä�η� 3�� ä���� 2, 1���� �ɰ��� //������� ���� 2�� , 

												 //  *@param src       �Է¿����� �迭
												 //	* @param src_n     �Է��� ��
												 //	* @param dest      ��¿����� �迭
												 //	* @param dest_n    ����� ��
												 //	* @param pairs     ȥ�ռ������� �迭
												 //	* @param pairs_n   ȥ�ռ������� ����


	cout << "[ch_123] = " << endl << ch_012 << endl << endl;
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;
	return 0;
}


#endif
