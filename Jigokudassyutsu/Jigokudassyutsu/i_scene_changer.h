#ifndef JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_
#define JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_

typedef enum {
	kSceneStart,    //メニュー画面
	kSceneStageSelect,	//ステージ選択画面
	//ゲーム画面
	kSceneGame1,
	kSceneGame2,
	kSceneGame3,
	kSceneGame4,
	kSceneGame5,

	kSceneNone,    //無し
} Scene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeScene(Scene NextScene) = 0;//指定シーンに変更する
};

#endif