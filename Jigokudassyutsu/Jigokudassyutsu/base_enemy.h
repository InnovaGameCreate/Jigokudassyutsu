#ifndef JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_
#define JIGOKUDASSYUTSU_ENEMY_BASEENEMY_H_

#include <string>
#include "DxLib.h"
#include "task.h"
#include "util.h"

class BaseEnemy {
private:
	int img_handle_;//敵画像ハンドル
	int cnt_;		//出現してからのフレーム数
protected:
	float x_, y_;
	float speed_;
	float radius_;

	void Initialize();//コンストラクタから呼び出すのでprotectedに置く
public:
	//コンストラクタ、デストラクタ
	BaseEnemy(std::string img_pass);
	BaseEnemy(int img_handle);
	virtual ~BaseEnemy();
	void Finalize();
	//task
	void Count() { cnt_++; }//毎回呼び出す
	virtual void Update(int player_x, int player_y, int cnt) = 0;//移動計算は派生クラスで定義
	void Draw()const;
	//その他
	int get_cnt_() { return cnt_; }//現在のフレーム数取得
	bool IsCollision(float px, float py, float pr);//プレイヤーと接触しているとtrueを返す
};

#endif