#pragma once

#include <cstring>
#include <opencv2/opencv.hpp>

class Chara {
	public:
		std::string name;
		cv::Vec3b bgr;
		cv::Vec3b lab;
		bool found;
		Chara(std::string name, cv::Vec3b bgr);
		~Chara();
};
