#ifndef JIGOKUDASSYUTSU_COLLISION_COLLISION_H_
#define JIGOKUDASSYUTSU_COLLISION_COLLISION_H_

#include "DxLib.h"
#include "task.h"
#include <opencv2\core\core.hpp>

class CollisionRoad {
private:
	const int stage_num_;
public:
	CollisionRoad(int stage_num);
	~CollisionRoad();
	void Initialize();
	void Finalize();
	bool Update(float x, float y, float radius);
	void Draw()const;
};

#endif