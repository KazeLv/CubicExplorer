#ifndef OPENCV_H
#define OPENCV_H
#include<iostream>
#include<core/core.hpp>
#include<highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<fstream>
#include<vector>

using namespace cv;
using namespace std;

int Color(Mat imgHSV, String C);
void ColorTest(Mat imgHSV, String c);
void FillBlocks(Mat& A, string color, int num);
void getHSV(Mat hsv, int x, int y);
void JudgeColor(Mat image, Mat& Blank, String c, string color[10], vector<struct P> Ps);	//将image读入，识别相应的色块并写入Blank，把颜色信息作为字符串回传
string Print_str(string color[10], vector <string> standardcolor);
void Ps_reset(vector<struct P>& Ps);

void recognition();

const Scalar Red(0, 0, 255);
const Scalar White(255, 255, 255);
const Scalar Yellow(0, 255, 255);
const Scalar Blue(255, 0, 0);
const Scalar Green(0, 255, 0);
const Scalar Orange(0, 165, 255);

struct P {
	int x1, x2;
	int y1, y2;
};


#endif