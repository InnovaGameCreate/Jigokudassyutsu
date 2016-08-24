#ifndef JIGOKUDASSYUTSU_ENEMY_ENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_ENEMY_H_

#include <string>
#include <math.h>
#include "DxLib.h"
#include "base_enemy.h"

//—H—ì
class EnemyYurei :public BaseEnemy {
public:
	EnemyYurei(float x,float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‰ì‹S
class EnemyGaki :public BaseEnemy {
public:
	EnemyGaki(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‚ª‚µ‚á‚Ç‚­‚ë
class EnemyDokuro :public BaseEnemy {
public:
	EnemyDokuro(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‘Â“VŽg
class EnemyDatenshi :public BaseEnemy {
public:
	EnemyDatenshi(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//è…–‚‘å‰¤
class EnemyEnma :public BaseEnemy {
public:
	EnemyEnma(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};

//‹S
class EnemyOni :public BaseEnemy {
public:
	EnemyOni(float x, float y);
	void Update(int player_x, int player_y, int cnt) override;
};


#endif