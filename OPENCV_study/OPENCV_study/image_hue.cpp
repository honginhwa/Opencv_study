
#if 1 // hue 이미지에 표시 

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void calc_Histo(const Mat& img, Mat& hist, Vec3i bins, Vec3f range, int _dims)
{
	int dims = (_dims <= 0) ? img.channels() : _dims;// 히스토그램 차원수
	int channels[] = { 0, 1, 2 };
	int histSize[] = { bins[0], bins[1], bins[2] }; // 간격 

	float  range1[] = { 0, range[0] };
	float  range2[] = { 0, range[1] };
	float  range3[] = { 0, range[2] };
	const float* ranges[] = { range1, range2, range3 };

	calcHist(&img, 1, channels, Mat(), hist, dims, histSize, ranges);
	normalize(hist, hist, 0, 1, NORM_MINMAX);			// 정규화 0,1 
}

Mat draw_histo(Mat hist)
{
	
	if (hist.dims != 2)
	{
		cout << "히스토그램이 2차원 데이터가 아닙니다 " << endl;
		exit(1);
	}
	float ratio_value = 256; // weight factor
	float ratio_hue = 180.f / hist.rows; // 색상 스케일 비율 
	float ratio_sat = 256.f / hist.cols; // 채도 스케일 비율 
	Mat graph(hist.size(), CV_32FC3);
	for (int i = 0; i < hist.rows; i++)
	{
		for (int j = 0; j < hist.cols; j++)
		{
			float value = hist.at<float>(i, j)* ratio_value;
			float hue = i * ratio_hue;
			float sat = j* ratio_sat;
			graph.at<Vec3f>(i, j) = Vec3f(hue, sat, value);
		}
	}
	graph.convertTo(graph, CV_8UC3);
	cvtColor(graph, graph, CV_HSV2BGR);
	resize(graph, graph, Size(0, 0), 10, 10, INTER_NEAREST);

	return graph;
}

int main()
{
	Vec3i bins(30, 42, 0); // H 30 칸 S 42칸  << hist의 rows= 30 , cols = 42 
	Vec3f ranges(180, 256, 0); // H S 

	Mat image = imread("../image/color_space.jpg", 1);// 컬러 영상 로드
	CV_Assert(image.data);

	Mat hsv, hist;
	cvtColor(image, hsv, CV_BGR2HSV);			// HSV 컬러 변환
	calc_Histo(hsv, hist, bins, ranges, 2);			// 2차원 히스토그램 계산 ( 
	Mat hist_img = draw_histo(hist); 				// 2차원 그래프 생성


	imshow("image", image);
	imshow("hist_img", hist_img);
	waitKey();
	return 0;
}


#endif