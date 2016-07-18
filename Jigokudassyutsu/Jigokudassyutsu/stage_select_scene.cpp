#include "stage_select_scene.h"

StageSelectScene::StageSelectScene(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void StageSelectScene::Initialize() {
}

//�X�V
void StageSelectScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneGame1);//�V�[�������j���[�ɕύX
	}
}

//�`��
void StageSelectScene::Draw() {
	DrawString(0, 0, "�X�e�[�W�I����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void StageSelectScene::Finalize() {
}