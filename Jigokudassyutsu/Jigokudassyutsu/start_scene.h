#ifndef JIGOKUDASSYUTSU_SCENESUB_STARTSCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_STARTSCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"

#include "input.h"

//�Q�[����ʃN���X
class StartScene : public BaseScene {
private:
	int handle01_;
	int font_handle1_;
public:
	StartScene(ISceneChanger* changer);
	~StartScene();
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;        //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw()const override;            //�`�揈�����I�[�o�[���C�h�B
};

#endif