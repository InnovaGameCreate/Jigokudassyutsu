#ifndef JIGOKUDASSYUTSU_MAP_MAP_H_
#define JIGOKUDASSYUTSU_MAP_MAP_H_

#include "task.h"
#include "DxLib.h"

class Map :public Task {
private:
	const int stage_num_;
public:
	Map(int stage_num);
	~Map();
	void Initialize();
	void Finalize();
	void Update();
	void Draw();
};

#endif