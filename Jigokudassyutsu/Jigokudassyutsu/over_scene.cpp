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
	handle01_ = LoadGraph("img/over.jpg"); //�摜�̓ǂݍ���
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜��ǂݍ��߂܂���ł���"); //�G���[����
	}
}

//�X�V
void OverScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void OverScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
	DrawStringToHandle(230, 220, "ESc�L�[�Ń��g���C", GetColor(0, 255, 255), font_handle1_);
}

//�I������
void OverScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}