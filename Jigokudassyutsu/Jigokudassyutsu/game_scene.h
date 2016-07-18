#ifndef JIGOKUDASSYUTSU_SCENESUB_SCENEGAME_H_
#define JIGOKUDASSYUTSU_SCENESUB_SCENEGAME_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"

#include "input.h"

//ゲーム画面クラス
class GameScene : public BaseScene {
private:
	int stage_num_;
public:
	GameScene::GameScene(ISceneChanger* changer,int stage_num);
	void Initialize() override;    //初期化処理をオーバーライド。
	void Finalize() override;        //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw() override;            //描画処理をオーバーライド。
};

#endif