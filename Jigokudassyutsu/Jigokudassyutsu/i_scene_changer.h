#ifndef JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_
#define JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_

typedef enum {
	//スタート画面
	kSceneStart,    
	//ゲーム画面
	kSceneGame1,
	kSceneGame2,
	kSceneGame3,
	kSceneGame4,
	kSceneGame5,
	//ゲームクリア画面
	kSceneClear,
	//ゲームオーバー画面
	kSceneOver,

	//無し
	kSceneNone
} Scene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeScene(Scene NextScene) = 0;//指定シーンに変更する
};

#endif