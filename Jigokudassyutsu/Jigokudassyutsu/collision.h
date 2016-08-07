#ifndef JIGOKUDASSYUTSU_COLLISION_COLLISION_H_
#define JIGOKUDASSYUTSU_COLLISION_COLLISION_H_

#include "DxLib.h"
#include "task.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>

class CollisionRoad {
private:
	const int kStageNum;	//ステージナンバー
	const int kMapWidth;	//マップの横ピクセル数
	const int kMapHeight;	//マップの縦ピクセル数
	cv::Mat col_map_;		//当たり判定用の画像のデータ
	int col_map_width_;		//当たり判定用の画像の横ピクセル数
	int col_map_height_;	//当たり判定用の画像の縦ピクセル数
	double width_ratio_;	//当たり判定用の画像とマップの横ピクセル比
	double height_ratio_;	//当たり判定用の画像とマップの縦ピクセル比
	int test_handle_;

	inline bool IsColMapAlpha(int x, int y);//x,yの位置が当たり判定画像で透過部分ならtrueを返す

public:
	CollisionRoad(int stage_num, int map_width, int map_height);
	~CollisionRoad();
	void Initialize();
	void Finalize();
	bool Update(float x, float y, float radius);
	void Draw()const;
};

#endif