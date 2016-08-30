#ifndef JIGOKUDASSYUTSU_SCENESUB_CLEARSCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_CLEARSCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"
#include "util.h"

#include "input.h"

//�Q�[����ʃN���X
class ClearScene : public BaseScene {
private:
	int clear_image_;
	int font_handle_01_, font_handle_02_;
public:
	ClearScene(ISceneChanger* changer);
	~ClearScene();
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;        //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw()const override;            //�`�揈�����I�[�o�[���C�h�B
};

#endif