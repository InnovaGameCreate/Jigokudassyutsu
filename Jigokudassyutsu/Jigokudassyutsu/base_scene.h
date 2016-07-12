#ifndef JIGOKUDASSYUTSU_SCENE_BASESCENE_H_
#define JIGOKUDASSYUTSU_SCENE_BASESCENE_H_

#include "DxLib.h"
#include "task.h"
#include "i_scene_changer.h"

//シーンの基底クラス。
//新しいシーンを作るときはこのクラスを継承してください
class BaseScene : public Task {

protected:
	ISceneChanger* scene_changer_;    //クラス所有元にシーン切り替えを伝えるインターフェイス

public:
	BaseScene(ISceneChanger* changer) {
		scene_changer_ = changer;
	}
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //初期化処理をオーバーライド。
	virtual void Finalize() override {}      //終了処理をオーバーライド。
	virtual void Update() override {}        //更新処理をオーバーライド。
	virtual void Draw() override {}          //描画処理をオーバーライド。

};

#endif