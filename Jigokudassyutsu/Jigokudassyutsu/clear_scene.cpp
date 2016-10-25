#include "clear_scene.h"

//�R���X�g���N�^
ClearScene::ClearScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
ClearScene::~ClearScene() {
}

//������
void ClearScene::Initialize() {
	clear_image_ = LoadGraph("img/back/clear.jpg");   //�摜�̓ǂݍ���
	if (clear_image_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�ǂݍ��߂܂���ł����B");   //�G���[����

	font_handle_01_ = CreateFontToHandle("AR�ۃS�V�b�N��M", 30, 3);
}

//�X�V
void ClearScene::Update() {
	if (input::CheckPushAnyButton()) { //�����{�^����������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void ClearScene::Draw()const {
	DrawRotaGraph(320, 240, 1.0, 0, clear_image_, TRUE);   //�摜�̕`��
	DrawStringToHandle(200, 300, "�����L�[�������Ă�������", GetColor(255, 255, 255), font_handle_01_);   //�X�^�[�g��ʈē�
}

//�I������
void ClearScene::Finalize() {
	DeleteGraph(clear_image_);
	DeleteFontToHandle(font_handle_01_);
}