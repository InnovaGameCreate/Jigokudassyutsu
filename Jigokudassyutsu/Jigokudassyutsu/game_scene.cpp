#include "game_scene.h"

GameScene::GameScene(ISceneChanger* changer, int stage_num) : BaseScene(changer) {
	stage_num_ = stage_num;
}

//������
void GameScene::Initialize() {

}

//�X�V
void GameScene::Update() {
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void GameScene::Draw() {
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

//�I������
void GameScene::Finalize() {

}