#include "start_scene.h"

//�R���X�g���N�^
StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//�f�X�g���N�^
StartScene::~StartScene() {
}

//������
void StartScene::Initialize() {
	Cr = GetColor(255, 255, 255);
	FontHandle = CreateFontToHandle(NULL , 40, 3);
	handle01 = LoadGraph("enemy.png"); //�摜�̓ǂݍ���
	if (handle01 == -1) {
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
	DrawGraph(0, 0, handle01, TRUE);  // �ǂ݂��񂾃O���t�B�b�N����ʍ���ɕ`��
	DrawStringToHandle(250, 200, "�n���E�o", Cr, FontHandle);
}

//�I������
void StartScene::Finalize() {
	DeleteGraph(handle01);
}