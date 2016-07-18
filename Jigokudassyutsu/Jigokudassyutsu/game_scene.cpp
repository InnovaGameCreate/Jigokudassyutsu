#include "game_scene.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//�V�[���`�F���W���[
	stage_num_(stage_num),	//�X�e�[�W�i���o�[
	map(stage_num)			//�}�b�v�N���X
{
}

//�f�X�g���N�^
GameScene::~GameScene() {
}

//������
void GameScene::Initialize() {
	map.Initialize();
}

//�X�V
void GameScene::Update() {
	map.Update();
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		scene_changer_->ChangeScene(kSceneStart);//�V�[�������j���[�ɕύX
	}
}

//�`��
void GameScene::Draw() {
	map.Draw();
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

//�I������
void GameScene::Finalize() {
	map.Finalize();
}