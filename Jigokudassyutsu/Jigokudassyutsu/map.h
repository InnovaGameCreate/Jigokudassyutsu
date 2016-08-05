#ifndef JIGOKUDASSYUTSU_MAP_MAP_H_
#define JIGOKUDASSYUTSU_MAP_MAP_H_

#include "task.h"
#include "DxLib.h"

class Map :public Task {
private:
	const int stage_num_;
	int map_image;
public:
	Map(int stage_num);
	~Map();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw()const override;
};

#endif