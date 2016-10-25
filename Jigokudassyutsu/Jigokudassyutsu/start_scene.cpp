#include "start_scene.h"

//�R���X�g���N�^
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
StartScene::~StartScene() {
}

//������
void StartScene::Initialize() {
	font_handle1_ = CreateFontToHandle(NULL, 20, 6);
	handle01_ = LoadGraph("img/back/start.jpg"); //�摜�̓ǂݍ���
	if (handle01_ == -1) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�摜��ǂݍ��߂܂���ł���"); //�G���[����
	}
}

//�X�V
void StartScene::Update() {
	if (input::CheckPushAnyButton()) { //�����{�^����������Ă�����
		scene_changer_->ChangeScene(kSceneGame1);//�V�[�������j���[�ɕύX
	}
}

//�`��
void StartScene::Draw()const {
	DrawGraph(0, 0, handle01_, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
	DrawStringToHandle(230, 220, "�����L�[�������Ă�������", GetColor(255, 255, 255), font_handle1_);
}

//�I������
void StartScene::Finalize() {
	DeleteGraph(handle01_);
	DeleteFontToHandle(font_handle1_);
}