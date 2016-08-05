#ifndef JIGOKUDASSYUTSU_COLLISION_COLLISION_H_
#define JIGOKUDASSYUTSU_COLLISION_COLLISION_H_

#include "DxLib.h"
#include "task.h"
#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>

class CollisionRoad {
private:
	const int stage_num_;
	cv::Mat col_map_;
public:
	CollisionRoad(int stage_num);
	~CollisionRoad();
	void Initialize();
	void Finalize();
	bool Update(float x, float y, float radius);
	void Draw()const;
};

#endif