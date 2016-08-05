#include "game_scene.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//�V�[���`�F���W���[
	stage_num_(stage_num),	//�X�e�[�W�i���o�[
	map_(stage_num),			//�}�b�v�N���X
	enemy_controller_(stage_num),		//�G�N���X
	col_road_(stage_num)	//���̓����蔻��
{
}

//�f�X�g���N�^
GameScene::~GameScene() {
}

//������
void GameScene::Initialize() {
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();
}

//���̃X�e�[�W�ɐi�݂܂�
//�ŏI�X�e�[�W�ł̓N���A��ʂɐi�݂܂�
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
	map_.Update();
	player_.Update();

	int px, py;
	float rad = 10;//�v���C���[�̑傫�����擾(��)
	GetMousePoint(&px, &py);//�v���C���[���W���擾(��)

	enemy_controller_.Update(px, py, rad);
	col_road_.Update(px, py, rad);

	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		GoNextStage();//���̃X�e�[�W�ɐi��
	}
}

//�`��
void GameScene::Draw()const {
	map_.Draw();
	player_.Draw();
	enemy_controller_.Draw();
	col_road_.Draw();
	std::string str = "�Q�[�����(�X�e�[�W" + std::to_string(stage_num_) + ")�ł��B";
	DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������Ǝ��̃X�e�[�W�ɐi�݂܂��B", GetColor(255, 255, 255));
}

//�I������
void GameScene::Finalize() {
	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
}