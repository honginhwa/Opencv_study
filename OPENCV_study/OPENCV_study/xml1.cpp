//매핑 노드 저장시에는 "{}"가 들어가고 <<매핑노드 : 이름으로 데이터 접근
//시퀀스 노드 저장시에는 "[]"가 들어간다  << 시퀀스 노드  : 인덱스로 접근 
#if 0  //xml 만들기

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	FileStorage fs("test.xml", FileStorage::WRITE);
	string name = "이정진";
	fs << "name" << name;
	fs << "age" << 20;
	fs << "university" << "숭실대학교";
	fs << "picture" << "[" << "mine1.jpg" << "mine2.jpg" << "mine3.jpg" << "]";

	fs << "hardware" << "{";
	fs << "cpu" << 25;
	fs << "mainboard" << 10;
	fs << "ram" << 6 << "}";

	int  data[] = { 1, 2, 3, 4, 5 , 6 };
	vector <int> vec(data, data + sizeof(data) / sizeof(float));
	fs << "vector" << vec;
	Mat m(2, 3, CV_32S, data);
	fs << "Mat" << m;

	Point2d  pt(10.5, 200);
	Rect     rect(pt, Size(100, 200));
	fs << "Point" << pt;
	fs << "Rect" << rect;

	fs.release();
	return 0;
}
#endif