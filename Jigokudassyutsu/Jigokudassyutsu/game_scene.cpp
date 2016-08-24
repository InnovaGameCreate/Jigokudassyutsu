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

//�����X�^�[�g�ʒu
const int GameScene::kStartX[] = { 80,80,80,80,80 };
const int GameScene::kStartY[] = { 400,400,400,400,400 };

//�f�X�g���N�^
GameScene::~GameScene() {
}

//������
void GameScene::Initialize() {
	map_.Initialize();
	player_.Initialize();
	enemy_controller_.Initialize();
	col_road_.Initialize();

	start_img_ = LoadGraph("img/system/start.png");
	if (start_img_ == -1)
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "�X�^�[�g�摜���ǂݍ��߂܂���");

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
	map_.Update();

	switch (game_state_) {
	case kStart://�X�^�[�g�O
		int mouse_x, mouse_y;
		GetMousePoint(&mouse_x, &mouse_y);
		if (util::CirclePointCollision(kStartX[kStageNum - 1], kStartY[kStageNum - 1], kStartRadius, mouse_x, mouse_y)) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
			if (input::CheckMouseLeftKey() == 1)
				game_state_ = kPlay;
		}
		break;
	case kPlay://�v���C��
		int px, py;
		player_.Update(&px, &py);
		if (enemy_controller_.Update(px, py, player_.kPlayerRadius))
			std::cout << "�G�ƐڐG" << std::endl;
		if (col_road_.Update(px, py, player_.kPlayerRadius))
			std::cout << "�͈͊O" << std::endl;
		else
			std::cout << "�͈͓�" << std::endl;
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
	map_.Draw();

	switch (game_state_) {
	case kStart://�X�^�[�g�O
		DrawRotaGraph(kStartX[kStageNum - 1], kStartY[kStageNum - 1], 1.0, 0.0, start_img_, TRUE);
		break;
	case kPlay://�v���C��
		player_.Draw();
		enemy_controller_.Draw();
		col_road_.Draw();
		break;
	}

#ifdef _DEBUG
	std::string str = "�Q�[�����(�X�e�[�W" + std::to_string(kStageNum) + ")�ł��B";
	DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������Ǝ��̃X�e�[�W�ɐi�݂܂��B", GetColor(255, 255, 255));
#endif
}

//�I������
void GameScene::Finalize() {
	DeleteGraph(start_img_);

	player_.Finalize();
	map_.Finalize();
	enemy_controller_.Finalize();
	col_road_.Finalize();
}