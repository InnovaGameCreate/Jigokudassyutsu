#include "start_scene.h"

StartScene::StartScene(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void StartScene::Initialize() {

}

//�X�V
void StartScene::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneGame);//�V�[�������j���[�ɕύX
	}
}

//�`��
void StartScene::Draw() {
	BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void StartScene::Finalize() {

}