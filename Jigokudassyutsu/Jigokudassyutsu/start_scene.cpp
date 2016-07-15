#include "start_scene.h"

StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void StartScene::Initialize() {
}

//�X�V
void StartScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStageSelect);//�V�[�������j���[�ɕύX
	}
}

//�`��
void StartScene::Draw() {
	DrawString(0, 0, "�X�^�[�g��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�e�[�W�I����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "�X�^�[�g��ʂł�2�B", GetColor(255, 255, 255));
}

//�I������
void StartScene::Finalize() {
}