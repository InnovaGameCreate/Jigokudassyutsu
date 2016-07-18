#ifndef JIGOKUDASSYUTSU_SCENESUB_STAGESELECTSCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_STAGESELECTSCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"

#include "input.h"

//ゲーム画面クラス
class StageSelectScene : public BaseScene {
public:
	StageSelectScene(ISceneChanger* changer);
	~StageSelectScene();
	void Initialize() override;    //初期化処理をオーバーライド。
	void Finalize() override;        //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw()const override;            //描画処理をオーバーライド。
};

#endif