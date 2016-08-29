#ifndef JIGOKUDASSYUTSU_MAP_MAP_H_
#define JIGOKUDASSYUTSU_MAP_MAP_H_

#include "task.h"
#include "DxLib.h"
#include "util.h"
#include <string.h>

class Map :public Task {
private:
	const int kStageNum;
	int map_image_;
public:
	Map(int stage_num);
	~Map();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw()const override;
};

#endif