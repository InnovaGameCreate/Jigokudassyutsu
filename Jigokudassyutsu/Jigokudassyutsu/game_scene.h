#ifndef JIGOKUDASSYUTSU_SCENESUB_SCENEGAME_H_
#define JIGOKUDASSYUTSU_SCENESUB_SCENEGAME_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"

//�Q�[����ʃN���X
class GameScene : public BaseScene {
public:
	GameScene::GameScene(ISceneChanger* changer);
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;        //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
};

#endif