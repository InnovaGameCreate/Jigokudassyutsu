#ifndef JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_
#define JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_

typedef enum {
	kSceneStart,    //メニュー画面
	kSceneGame,    //ゲーム画面

	kSceneNone,    //無し
} eScene;

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeScene(eScene NextScene) = 0;//指定シーンに変更する
};

#endif