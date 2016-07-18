#include "start_scene.h"

//�R���X�g���N�^
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
StartScene::~StartScene() {
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
void StartScene::Draw()const {
	DrawString(0, 0, "�X�^�[�g��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�e�[�W�I����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void StartScene::Finalize() {
}