#include "game_scene.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* changer, int stage_num) :
	BaseScene(changer),		//�V�[���`�F���W���[
	kStageNum(stage_num),	//�X�e�[�W�i���o�[
	map_(stage_num),			//�}�b�v�N���X
	enemy_controller_(stage_num, kWindowWidth, kWindowHeight),		//�G�N���X
	col_road_(stage_num, kWindowWidth, kWindowHeight)	//���̓����蔻��
{
}

//�X�^�[�g�ʒu,���a
const int GameScene::kStartX[] = { 32,25,5,620,147 };
const int GameScene::kStartY[] = { 455,454,436,426,397 };
const int GameScene::kStartRadius[] = { 30,30,30,10,30 };
//�S�[���ʒu,���a
const int GameScene::kGoalX[] = { 633,32,637,7,640 };
const int GameScene::kGoalY[] = { 324,13,37,440,0 };
const int GameScene::kGoalRadius[] = { 30,30,30,30,30 };

//�f�X�g���N�^
GameScene::~GameScene() {
}

//������
void GameScene::Initialize() {
	//�e�N���X������
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();
	//�X�^�[�g�����ƃS�[�������̉摜�ǂݍ���
	start_img_ = LoadGraph("img/system/start.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�X�^�[�g�摜���ǂݍ��߂܂���");
	goal_img_ = LoadGraph("img/system/goal.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�S�[���摜���ǂݍ��߂܂���");
	//��Ԃ��X�^�[�g�ɐݒ�
	game_state_ = kStart;
}

//���̃X�e�[�W�ɐi�݂܂�
//�ŏI�X�e�[�W�ł̓N���A��ʂɐi�݂܂�
void GameScene::GoNextStage() {
	switch (kStageNum) {
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
	//�}�b�v�͏�ɍX�V
	map_.Update();
	//�Q�[���̏�Ԃɂ���ĕ���
	switch (game_state_) {
	case kStart://�X�^�[�g�O
		//�}�E�X���W�擾
		int mouse_x, mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		//�}�E�X���X�^�[�g�{�^����ɂȂ��Ȃ�switch���I��
		if (util::CirclePointCollision(kStartX[kStageNum - 1], kStartY[kStageNum - 1], kStartRadius[kStageNum - 1], mouse_x, mouse_y) == false)
			break;
		//�z�o�[���}�E�X�̌`��ς���
		SetCursor(LoadCursor(NULL, IDC_HAND));
		//�N���b�N�ňڍs
		if (input::CheckMouseLeftKey() == 1) {
			game_state_ = kPlay;
			while (ShowCursor(false) >= 0);//�J�[�\��������
		}
		break;
	case kPlay://�v���C��
		int px, py;
		//�v���C���[�X�V
		player_.Update(&px, &py);
		//�G�X�V & �G�Ƃ̂����蔻��
		if (enemy_controller_.Update(px, py, player_.kPlayerRadius))
#ifndef _DEBUG
			scene_changer_->ChangeScene(kSceneOver);
#else
			std::cout << "�G�ƐڐG" << std::endl;
#endif
		//���Ƃ̂����蔻��
		if (col_road_.Update(px, py, player_.kPlayerRadius))
			scene_changer_->ChangeScene(kSceneOver);

		//�S�[��������
		if (util::CirclePointCollision(kGoalX[kStageNum - 1], kGoalY[kStageNum - 1], kGoalRadius[kStageNum - 1], px, py))
			GoNextStage();	//���̃X�e�[�W�ɐi��
		break;
	}
#ifdef _DEBUG
	if (input::CheckStateKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		GoNextStage();//���̃X�e�[�W�ɐi��
	}
#endif
}

//�`��
void GameScene::Draw()const {
	//�}�b�v�͏�ɕ`��
	map_.Draw();
	//��Ԃɂ���ĕ���
	switch (game_state_) {
	case kStart://�X�^�[�g�O
		DrawRotaGraph(kStartX[kStageNum - 1], kStartY[kStageNum - 1], 1.0, 0.0, start_img_, TRUE);//�X�^�[�g�{�^��
		break;
	case kPlay://�v���C��
		DrawRotaGraph(kGoalX[kStageNum - 1], kGoalY[kStageNum - 1], 1.0, 0.0, goal_img_, TRUE);//�S�[���{�^��
		enemy_controller_.Draw();//�G
		player_.Draw();//����
		col_road_.Draw();//���̂����蔻��
		break;
	}
}

//�I������
void GameScene::Finalize() {
	//�摜���J��
	DeleteGraph(start_img_);
	DeleteGraph(goal_img_);
	//�e�N���X�̏I������
	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
	//�J�[�\����߂�
	while (ShowCursor(true) < 0);//�J�[�\���J�E���g��0�ȏ�ɂȂ�܂Ń��[�v������

}