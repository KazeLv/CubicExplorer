#include<iostream>
#include<core/core.hpp>
#include<highgui/highgui.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int Color(Mat imgHSV, String C);
void ColorTest(Mat imgHSV, String c);
void FillBlocks(Mat& A,string color, int num);
void getHSV(Mat hsv, int x, int y);
void JudgeColor(Mat image,Mat& Blank, String c,string color[10]);	//将image读入，识别相应的色块并写入Blank，把颜色信息作为字符串回传

const Scalar Red(0, 0, 255);
const Scalar White(255, 255, 255);
const Scalar Yellow(0, 255, 255);
const Scalar Blue(255, 0, 0);
const Scalar Green(0, 255, 0);
const Scalar Orange(0, 165, 255);

int main()
{
	vector <Point> center;								//存放9个色块的中心位置,x和y，未来采样用
	//初始化9个白色魔方
	Mat B(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	Mat D(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	Mat F(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	Mat L(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	Mat R(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	Mat U(360, 360, CV_8UC3, Scalar(255, 255, 255));		//
	int i;
	Mat image;
	string Bcolor[10];
	string Dcolor[10];
	string Fcolor[10];
	string Lcolor[10];
	string Rcolor[10];
	string Ucolor[10];

	image = imread("B.png");
	JudgeColor(image, B, "B_decode",Bcolor);
	image = imread("D.png");
	JudgeColor(image, D, "D_decode",Dcolor);
	image = imread("F.png");
	JudgeColor(image, F, "F_decode",Fcolor);
	image = imread("L.png");
	JudgeColor(image, L, "L_decode",Lcolor);
	image = imread("R.png");
	JudgeColor(image, R, "R_decode",Rcolor);
	image = imread("U.png");
	JudgeColor(image, U, "U_decode",Ucolor);

	for (i = 1; i <= 9; i++)
		cout << Ucolor[i][0];
	for (i = 1; i <= 9; i++)
		cout << Rcolor[i][0];
	for (i = 1; i <= 9; i++)
		cout << Fcolor[i][0];
	for (i = 1; i <= 9; i++)
		cout << Dcolor[i][0];
	for (i = 1; i <= 9; i++)
		cout << Lcolor[i][0];
	for (i = 1; i <= 9; i++)
		cout << Bcolor[i][0];
	cout << endl;

	system("pause");
	waitKey(0);


	return 0;
}

void ColorTest(Mat imgHSV, String c)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	Mat imgThresholded;
	Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;

	if (c == "White") {
		iLowH = 10;
		iHighH = 50;

		iLowS = 0;
		iHighS = 20;

		iLowV = 220;
		iHighV = 255;
	}
	else if (c == "Red") {
		iLowH = 156;
		iHighH = 180;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Yellow") {
		iLowH = 26;
		iHighH = 34;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Blue") {
		iLowH = 100;
		iHighH = 115;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Green") {
		iLowH = 50;
		iHighH = 70;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Orange") {
		iLowH = 0;
		iHighH = 10;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}

	cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the imageq
	imwrite("threstest.png", imgThresholded);
	int count = 0;
	int i, j;

	for (i = 0; i < imgThresholded.rows; i++) {
		Vec3b *p = imgThresholded.ptr<Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++)
			if (p[j] == pixel)
				count++;
	}
	
	cout << count << endl;

}


int Color(Mat imgHSV, String c)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	Mat imgThresholded;
	Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;
	iLowH = 0;
	iHighH = 180;

	iLowS = 0;
	iHighS = 30;

	iLowV = 220;
	iHighV = 255;

	if (c == "White") {
		iLowH = 0;
		iHighH = 180;

		iLowS = 0;
		iHighS = 60;

		iLowV = 150;
		iHighV = 255;
	}
	else if (c == "Red") {
		iLowH = 0;
		iHighH = 3;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Yellow") {
		iLowH = 26;
		iHighH = 40;

		iLowS = 150;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Blue") {
		iLowH = 90;
		iHighH = 124;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Green") {
		iLowH = 40;
		iHighH = 70;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Orange") {
		iLowH = 3;
		iHighH = 10;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	
	
	cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

	int count = 0;
	int i, j;

	for (i = 0; i < imgThresholded.rows; i++) {
		Vec3b *p = imgThresholded.ptr<Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++)
			if (p[j] == pixel)
				count++;
	}
	if(c=="Red"){
		iLowH = 170;
		iHighH = 185;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
		cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
		int count2 = 0;
		for (i = 0; i < imgThresholded.rows; i++) {
			Vec3b *p = imgThresholded.ptr<Vec3b>(i);
			for (j = 0; j < imgThresholded.cols; j++)
				if (p[j] == pixel)
					count2++;
		}
		count += count2;
	}

	if (count > 1500)
		return 1;
	return 0;
}

void FillBlocks(Mat& A,string color,int num)			//num表示第几个色块
{
	switch (num) {
	case(1):					//第一个色块
		if (color == "White")
			rectangle(A, Rect(0, 0, 120, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 0, 120, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 0, 120, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 0, 120, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 0, 120, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 0, 120, 120), Orange, -1, 1, 0);
	case(2):
		if (color == "White")
			rectangle(A, Rect(120, 0, 240, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 0, 240, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 0, 240, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 0, 240, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 0, 240, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 0, 240, 120), Orange, -1, 1, 0);
	case(3):
		if (color == "White")
			rectangle(A, Rect(240, 0, 360, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 0, 360, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 0, 360, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 0, 360, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 0, 360, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 0, 360, 120), Orange, -1, 1, 0);
	case(4):
		if (color == "White")
			rectangle(A, Rect(0, 120, 120, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 120, 120, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 120, 120, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 120, 120, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 120, 120, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 120, 120, 240), Orange, -1, 1, 0);
	case(5):
		if (color == "White")
			rectangle(A, Rect(120, 120, 240, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 120, 240, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 120, 240, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 120, 240, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 120, 240, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 120, 240, 240), Orange, -1, 1, 0);
	case(6):
		if (color == "White")
			rectangle(A, Rect(240, 120, 360, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 120, 360, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 120, 360, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 120, 360, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 120, 360, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 120, 360, 240), Orange, -1, 1, 0);
	case(7):
		if (color == "White")
			rectangle(A, Rect(0, 240, 120, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 240, 120, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 240, 120, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 240, 120, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 240, 120, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 240, 120, 360), Orange, -1, 1, 0);
	case(8):
		if (color == "White")
			rectangle(A, Rect(120, 240, 240, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 240, 240, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 240, 240, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 240, 240, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 240, 240, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 240, 240, 360), Orange, -1, 1, 0);
	case(9):
		if (color == "White")
			rectangle(A, Rect(240, 240, 360, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 240, 360, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 240, 360, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 240, 360, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 240, 360, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 240, 360, 360), Orange, -1, 1, 0);
	default:
		;
	}
}

void getHSV(Mat hsv, int x, int y) {
	Point p(x, y);
	printf("H=%d\t", hsv.at<Vec3b>(p)[0]);
	printf("S=%d\t", hsv.at<Vec3b>(p)[1]);
	printf("V=%d\n", hsv.at<Vec3b>(p)[2]);
	return;
}

void JudgeColor(Mat image, Mat& Blank, String c,string color[10]){
	resize(image, image, Size(900, 900), 0, 0, 3);			//调整图片大小
	int i, j;

	//采色块
	Mat P1 = image(Range(150, 200), Range(230, 280));		//第一行第一列
	Mat P2 = image(Range(150, 200), Range(430, 480));		//第一行第二列
	Mat P3 = image(Range(150, 200), Range(630, 680));		//第一行第三列
	Mat P4 = image(Range(400, 450), Range(230, 280));		//第二行第一列的
	Mat P5 = image(Range(400, 450), Range(430, 480));		//第二行第二列的
	Mat P6 = image(Range(400, 450), Range(630, 680));		//第二行第三列的
	Mat P7 = image(Range(700, 750), Range(230, 280));		//第二行第三列的
	Mat P8 = image(Range(700, 750), Range(430, 480));		//第二行第三列的
	Mat P9 = image(Range(700, 750), Range(630, 680));		//第二行第三列的

	Rect ColorBlocks[10];
	ColorBlocks[1] = Rect(0, 0, 120, 120);					//到时候根据图片修改参数,画出一个360*360的魔方识别图
	ColorBlocks[2] = Rect(120, 0, 240, 120);
	ColorBlocks[3] = Rect(240, 0, 360, 120);
	ColorBlocks[4] = Rect(0, 120, 120, 240);
	ColorBlocks[5] = Rect(120, 120, 240, 240);
	ColorBlocks[6] = Rect(240, 120, 360, 240);
	ColorBlocks[7] = Rect(0, 240, 120, 360);
	ColorBlocks[8] = Rect(120, 240, 240, 360);
	ColorBlocks[9] = Rect(240, 240, 360, 360);
	imwrite("P1.png", P1);
	imwrite("P2.png", P2);
	imwrite("P3.png", P3);
	imwrite("P4.png", P4);
	imwrite("P5.png", P5);
	imwrite("P6.png", P6);
	imwrite("P7.png", P7);
	imwrite("P8.png", P8);
	imwrite("P9.png", P9);
	Mat imgHSV[10];
	Mat imgThresholded(200, 200, CV_8UC3);
	//string color[10];									//存放9个色块的颜色
	cvtColor(P1, imgHSV[1], COLOR_BGR2HSV);
	cvtColor(P2, imgHSV[2], COLOR_BGR2HSV);
	cvtColor(P3, imgHSV[3], COLOR_BGR2HSV);
	cvtColor(P4, imgHSV[4], COLOR_BGR2HSV);
	cvtColor(P5, imgHSV[5], COLOR_BGR2HSV);
	cvtColor(P6, imgHSV[6], COLOR_BGR2HSV);
	cvtColor(P7, imgHSV[7], COLOR_BGR2HSV);
	cvtColor(P8, imgHSV[8], COLOR_BGR2HSV);
	cvtColor(P9, imgHSV[9], COLOR_BGR2HSV);

	/*
	Mat test;
	test = imgHSV[1];
	for (i = 0; i < test.rows; i++) {			//print HSV
	for (j = 0; j < test.cols; j++)
	getHSV(test, i, j);
	printf("\n");
	}
	*/

	for (i = 1; i <= 9; i++) {				//对每个颜色做threshold,得到色块的颜色矩阵
		if (Color(imgHSV[i], "Red") == 1)
			color[i] = "Red";
		else if (Color(imgHSV[i], "Orange") == 1)
			color[i] = "Orange";
		else if (Color(imgHSV[i], "Yellow") == 1)
			color[i] = "Yellow";
		else if (Color(imgHSV[i], "Blue") == 1)
			color[i] = "Blue";
		else if (Color(imgHSV[i], "Green") == 1)
			color[i] = "Green";
		else if (Color(imgHSV[i], "White") == 1)
			color[i] = "White";
	}

	for (i = 1; i <= 9; i++)				//色块填充
		FillBlocks(Blank, color[i], i);
	line(Blank, Point(0, 120), Point(360, 120), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(0, 240), Point(360, 240), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(120, 0), Point(120, 360), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(240, 0), Point(240, 360), Scalar(0, 0, 0), 1, 8, 0);
	imwrite(c+".png", Blank);			//保存图片

}
