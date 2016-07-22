#include "game_scene.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//�V�[���`�F���W���[
	stage_num_(stage_num),	//�X�e�[�W�i���o�[
	map(stage_num),			//�}�b�v�N���X
	enemy_controller(stage_num)		//�G�N���X
{
}

//�f�X�g���N�^
GameScene::~GameScene() {
}

//������
void GameScene::Initialize() {
	map.Initialize();
	player.Initialize();
	enemy_controller.Initialize();
}

void GameScene::GoNextStage() {
	switch (stage_num_) {
	case 1:
		scene_changer_->ChangeScene(kSceneGame2);
		break;
	case 2:
		scene_changer_->ChangeScene(kSceneGame3);
		break;
	case 3:
		scene_changer_->ChangeScene(kSceneGame4);
		break;
	case 4:
		scene_changer_->ChangeScene(kSceneGame5);
		break;
	case 5:
		scene_changer_->ChangeScene(kSceneClear);
		break;
	default:
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "���ݒ��stage_num_�ł�,�X�^�[�g��ʂɈڍs���܂�");
		scene_changer_->ChangeScene(kSceneStart);
		break;
	}
}

//�X�V
void GameScene::Update() {
	map.Update();
	player.Update();
	enemy_controller.Update();
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		GoNextStage();//���̃X�e�[�W�ɐi��
	}
}

//�`��
void GameScene::Draw()const {
	map.Draw();
	player.Draw();
	enemy_controller.Draw();
	char string[256];
	sprintf_s(string, "�Q�[�����(�X�e�[�W%d)�ł��B", stage_num_);
	DrawString(0, 0, string, GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃX�^�[�g��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}

//�I������
void GameScene::Finalize() {
	player.Finalize();
	map.Finalize();
	enemy_controller.Finalize();
}