#include "Chara.hpp"

Chara::Chara(std::string _name, cv::Vec3b _bgr): name(_name), bgr(_bgr) {
	cv::Mat mat(1, 1, CV_8UC3, _bgr);
	cv::cvtColor(mat, mat, cv::COLOR_BGR2Lab);
	this->lab = mat.at<cv::Vec3b>(0, 0);
	this->found = false;
}

Chara::~Chara() {}
