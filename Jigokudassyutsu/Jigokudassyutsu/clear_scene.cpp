#include "clear_scene.h"

//�R���X�g���N�^
ClearScene::ClearScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
ClearScene::~ClearScene() {
}

//������
void ClearScene::Initialize() {
}

//�X�V
void ClearScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void ClearScene::Draw()const {
	DrawString(0, 0, "�N���A��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void ClearScene::Finalize() {
}