#include "over_scene.h"

//�R���X�g���N�^
OverScene::OverScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
OverScene::~OverScene() {
}

//������
void OverScene::Initialize() {
}

//�X�V
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void OverScene::Draw()const {
	DrawString(0, 0, "�Q�[���I�[�o�[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void OverScene::Finalize() {
}