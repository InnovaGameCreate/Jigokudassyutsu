#include "start_scene.h"

static int handle01;

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
	if (input::CheckStateKey(KEY_INPUT_RETURN) == 1) { //Enter�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStageSelect);//�V�[�������j���[�ɕύX
	}

	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		DxLib_End();                                   //�Q�[�����I��
	}
}

//�`��
void StartScene::Draw()const {
	handle01 = LoadGraph("enemy.png"); //�摜�̓ǂݍ���
	DrawGraph(0, 0, handle01, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��

	DrawString(0, 0, "�X�^�[�g��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Enter�L�[�������ƃX�e�[�W�I����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "Esc�L�[�������ƃQ�[�����I�����܂��B", GetColor(255, 255, 255));
}

//�I������
void StartScene::Finalize() {
}