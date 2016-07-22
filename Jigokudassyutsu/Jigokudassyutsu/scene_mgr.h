#ifndef JIGOKUDASSYUTSU_SCENE_SCENEMGR_H_
#define JIGOKUDASSYUTSU_SCENE_SCENEMGR_H_

#include "DxLib.h"
#include "i_scene_changer.h"
#include "base_scene.h"

#include "start_scene.h"
#include "game_scene.h"
#include "clear_scene.h"
#include "over_scene.h"


class SceneMgr : public ISceneChanger, Task {
private:
	BaseScene* scene_;    //�V�[���Ǘ��ϐ�
	Scene next_scene_;    //���̃V�[���Ǘ��ϐ�

public:
	SceneMgr();
	void Initialize() override;//������
	void Finalize() override;//�I������
	void Update() override;//�X�V
	void Draw()const override;//�`��

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(Scene NextScene) override;
};

#endif