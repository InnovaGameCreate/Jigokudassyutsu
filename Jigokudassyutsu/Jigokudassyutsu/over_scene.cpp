#include "over_scene.h"

//�R���X�g���N�^
OverScene::OverScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
OverScene::~OverScene() {
}

//������
void OverScene::Initialize() {
	font_handle1_ = CreateFontToHandle(NULL, 20, 6);
	handle01_ = LoadGraph("img/back/over.jpg"); //�摜�̓ǂݍ���
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜��ǂݍ��߂܂���ł���"); //�G���[����
	}
}

//�X�V
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //ESC�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�����X�^�[�g��ʂɕύX
		return;
	}
	if (input::CheckPushAnyButton() == 1) { //�����L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneGame1);//�V�[�����X�e�[�W1�ɕύX
		return;
	}
}

//�`��
void OverScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
	DrawStringToHandle(220, 370, "�����L�[�������ă��g���C���Ă�������", GetColor(0, 0, 0), font_handle1_);
	DrawStringToHandle(220, 410, "ESC�L�[�ŃX�^�[�g��ʂɖ߂�", GetColor(0, 0, 0), font_handle1_);
}

//�I������
void OverScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}