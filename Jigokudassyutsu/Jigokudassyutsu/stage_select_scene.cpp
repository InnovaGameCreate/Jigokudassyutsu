#include "stage_select_scene.h"

//�R���X�g���N�^
StageSelectScene::StageSelectScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
StageSelectScene::~StageSelectScene() {
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