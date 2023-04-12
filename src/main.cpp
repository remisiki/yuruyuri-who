#include <cmath>
#include <cstring>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "Chara.hpp"

float calDistance(const cv::Vec3b &a, const cv::Vec3b &b) {
	float dl = (float)(a[0]-b[0])/2.55;
	int da = a[1]-b[1];
	int db = a[2]-b[2];
	return sqrt(dl*dl+da*da+db*db);
}

int main(int argc, const char* argv[]) {
	if (argc != 2) {
		std::cout << "Bad arguments\n";
		return 1;
	}
	cv::Mat img;
	try {
		img = cv::imread(argv[1]);
		cv::resize(img, img, cv::Size(128, 128), cv::INTER_LINEAR);
		cv::cvtColor(img, img, cv::COLOR_BGR2Lab);
	} catch(...) {
		std::cout << "Bad file\n";
		return 1;
	}
	std::vector<Chara> charas {
		Chara("akari", cv::Vec3b(145, 142, 228)),
		Chara("kyouko", cv::Vec3b(166, 208, 243)),
		Chara("chinatsu", cv::Vec3b(219, 219, 255)),
		Chara("yui", cv::Vec3b(98, 92, 127)),
		Chara("chitose", cv::Vec3b(231, 212, 229)),
		Chara("ayano", cv::Vec3b(161, 132, 201)),
		Chara("himawari", cv::Vec3b(184, 148, 140)),
		Chara("sakurako", cv::Vec3b(137, 177, 226))
	};
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			cv::Vec3b p0 = img.at<cv::Vec3b>(i, j);
			for (auto &chara: charas) {
				if (!chara.found) {
					float distance = calDistance(p0, chara.lab);
					if (distance < 1) {
						chara.found = true;
					}
				}
			}
		}
	}
	std::string output = "";
	for (auto &chara: charas) {
		if (chara.found) {
			if (output == "") {
				output = chara.name;
			} else {
				output = output + ' ' + chara.name;
			}
		}
	}
	if (output != "") {
		std::cout << output << '\n';
	}
	return 0;
}
