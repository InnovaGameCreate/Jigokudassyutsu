#ifndef JIGOKUDASSYUTSU_SCENESUB_CLEARSCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_CLEARSCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"
#include "util.h"

#include "input.h"

//ゲーム画面クラス
class ClearScene : public BaseScene {
private:
	int clear_image_;
	int font_handle_01_, font_handle_02_;
public:
	ClearScene(ISceneChanger* changer);
	~ClearScene();
	void Initialize() override;    //初期化処理をオーバーライド。
	void Finalize() override;        //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw()const override;            //描画処理をオーバーライド。
};

#endif