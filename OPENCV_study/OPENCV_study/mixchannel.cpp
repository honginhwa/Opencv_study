
#if 0  // 믹스채널 

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
	merge(vec_012, ch_012); // 행렬백터를 다중채널 행렬 합성

	Mat ch_13(ch_012.size(), CV_8UC2);
	Mat  ch_2(ch_012.size(), CV_8UC1);


	Mat out[] = { ch_13, ch_2 };
	int from_to[] = { 2, 0, 0, 1, 1, 2 };
	mixChannels(&ch_012, 1, out, 2, from_to, 3); // 믹스채널로 3개 채널을 2, 1개로 쪼갠다 //만들어질 갯수 2개 , 

												 //  *@param src       입력영상의 배열
												 //	* @param src_n     입력의 수
												 //	* @param dest      출력영상의 배열
												 //	* @param dest_n    출력의 수
												 //	* @param pairs     혼합순서쌍의 배열
												 //	* @param pairs_n   혼합순서쌍의 개수


	cout << "[ch_123] = " << endl << ch_012 << endl << endl;
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;
	return 0;
}


#endif
