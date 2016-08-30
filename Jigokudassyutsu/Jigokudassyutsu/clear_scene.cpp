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

	font_handle_01_ = CreateFontToHandle("�x�m�|�b�v", 60, 7);
	font_handle_02_ = CreateFontToHandle("AR�ۃS�V�b�N��M", 30, 3);
}

//�X�V
void ClearScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void ClearScene::Draw()const {
	DrawRotaGraph(320, 240, 1.0, 0, clear_image_, TRUE);   //�摜�̕`��

	DrawString(0, 0, "�N���A��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɖ߂�܂��B", GetColor(255, 255, 255));

	DrawStringToHandle(120, 100, "�Q�[���N���A�I", GetColor(0, 0, 0), font_handle_01_);   //�Q�[���N���A
	DrawStringToHandle(200, 300, "Esc�Ń^�C�g����", GetColor(255, 255, 255), font_handle_02_);   //�X�^�[�g��ʈē�
}

//�I������
void ClearScene::Finalize() {
	DeleteGraph(clear_image_);
	DeleteFontToHandle(font_handle_01_);
	DeleteFontToHandle(font_handle_02_);
}