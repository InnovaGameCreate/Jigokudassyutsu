#include "game_scene.h"

GameScene::GameScene(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void GameScene::Initialize() {

}

//�X�V
void GameScene::Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void GameScene::Draw() {
	BaseScene::Draw();//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

//�I������
void GameScene::Finalize() {

}