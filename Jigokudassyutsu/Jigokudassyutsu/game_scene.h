#ifndef JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"
#include "define.h"

#include "input.h"
#include "map.h"
#include "player.h"
#include "enemy_controller.h"
#include "collision.h"

//ゲーム画面クラス
class GameScene : public BaseScene {
private:
	enum GameState {
		kStart,
		kPlay,
		kGoal
	};

	const int kStageNum;
	GameState game_state_;
	Map map_;
	Player player_;
	EnemyController enemy_controller_;
	CollisionRoad col_road_;

	void GoNextStage();		//次のステージに進みます
public:
	GameScene(ISceneChanger* changer,int stage_num);
	~GameScene();
	void Initialize() override;    //初期化処理をオーバーライド。
	void Finalize() override;      //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw()const override;     //描画処理をオーバーライド。
};

#endif