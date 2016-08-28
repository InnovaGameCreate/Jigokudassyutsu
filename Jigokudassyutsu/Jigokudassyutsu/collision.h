#ifndef JIGOKUDASSYUTSU_COLLISION_COLLISION_H_
#define JIGOKUDASSYUTSU_COLLISION_COLLISION_H_

#include "DxLib.h"
#include "task.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

class CollisionRoad {
private:
	const int kStageNum;	//ステージナンバー
	const int kMapWidth;	//マップの横ピクセル数
	const int kMapHeight;	//マップの縦ピクセル数
	cv::Mat col_map_;		//当たり判定用の画像のデータ

	inline bool IsColMapAlpha(int x, int y);//x,yの位置が当たり判定画像で透過部分ならtrueを返す

public:
	CollisionRoad(int stage_num, int map_width, int map_height);
	~CollisionRoad();
	void Initialize();
	void Finalize();
	//道からはみ出している時trueを返す
	//引数はプレイヤー座標と半径
	bool Update(float x, float y, float radius);
	void Draw()const;
};

#endif