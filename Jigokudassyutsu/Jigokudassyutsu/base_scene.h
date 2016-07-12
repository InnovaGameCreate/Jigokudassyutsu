#ifndef JIGOKUDASSYUTSU_SCENE_BASESCENE_H_
#define JIGOKUDASSYUTSU_SCENE_BASESCENE_H_

#include "DxLib.h"
#include "task.h"
#include "i_scene_changer.h"

//�V�[���̊��N���X�B
//�V�����V�[�������Ƃ��͂��̃N���X���p�����Ă�������
class BaseScene : public Task {

protected:
	ISceneChanger* scene_changer_;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X

public:
	BaseScene(ISceneChanger* changer) {
		scene_changer_ = changer;
	}
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
	virtual void Finalize() override {}      //�I���������I�[�o�[���C�h�B
	virtual void Update() override {}        //�X�V�������I�[�o�[���C�h�B
	virtual void Draw() override {}          //�`�揈�����I�[�o�[���C�h�B

};

#endif