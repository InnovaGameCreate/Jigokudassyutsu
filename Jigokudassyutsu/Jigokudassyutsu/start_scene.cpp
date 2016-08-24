#include "start_scene.h"

//�R���X�g���N�^
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
StartScene::~StartScene() {
}

//������
void StartScene::Initialize() {
	font_handle1_ = CreateFontToHandle("������ Demibold", 50, 2);
	font_handle2_ = CreateFontToHandle(NULL, 20, 6);
	handle01_ = LoadGraph("img/back/start.png"); //�摜�̓ǂݍ���
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜��ǂݍ��߂܂���ł���"); //�G���[����
	}
}

//�X�V
void StartScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_RETURN) == 1) { //Enter�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneGame1);//�V�[�������j���[�ɕύX
	}
}

//�`��
void StartScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
	DrawStringToHandle(180, 150, "�n���E�o", GetColor(255, 50, 50), font_handle1_);
	DrawStringToHandle(230, 220, "Please push Enter", GetColor(255, 255, 255), font_handle2_);
}

//�I������
void StartScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
	DeleteFontToHandle(font_handle2_);
}