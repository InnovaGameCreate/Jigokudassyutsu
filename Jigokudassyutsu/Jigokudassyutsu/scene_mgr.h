#ifndef JIGOKUDASSYUTSU_SCENE_SCENEMGR_H_
#define JIGOKUDASSYUTSU_SCENE_SCENEMGR_H_

#include "DxLib.h"
#include "i_scene_changer.h"
#include "base_scene.h"

#include "start_scene.h"
#include "game_scene.h"

class SceneMgr : public ISceneChanger, Task {
private:
	BaseScene* scene_;    //シーン管理変数
	eScene next_scene_;    //次のシーン管理変数

public:
	SceneMgr();
	void Initialize() override;//初期化
	void Finalize() override;//終了処理
	void Update() override;//更新
	void Draw() override;//描画

	// 引数 nextScene にシーンを変更する
	void ChangeScene(eScene NextScene) override;
};

#endif