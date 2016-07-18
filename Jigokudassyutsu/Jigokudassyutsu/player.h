#ifndef JIGOKUDASSYUTSU_PLAYER_PLAYER_H_
#define JIGOKUDASSYUTSU_PLAYER_PLAYER_H_

#include "task.h"
#include "DxLib.h"

class Player :public Task {
private:
public:
	Player();
	~Player();
	void Initialize();
	void Finalize();
	void Update();
	void Draw();
};

#endif