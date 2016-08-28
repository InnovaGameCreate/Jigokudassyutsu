#ifndef JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"
#include "define.h"

#include "input.h"
#include "map.h"
#include "player.h"
#include "enemy_controller.h"
#include "collision.h"

//�Q�[����ʃN���X
class GameScene : public BaseScene {
private:
	//�Q�[���̏��
	enum GameState {
		kStart,
		kPlay
	};
	//�X�^�[�g�A�S�[�������̒萔
	static const int kStartX[];
	static const int kStartY[];
	static const int kStartRadius = 40;
	static const int kGoalX[];
	static const int kGoalY[];
	static const int kGoalRadius = 40;

	const int kStageNum;//���݂̃X�e�[�W
	int start_img_;		//�X�^�[�g�����̉摜�n���h��
	int goal_img_;		//�S�[�������̉摜�n���h��
	GameState game_state_;//�Q�[���̏��

	//�e�N���X
	Map map_;
	Player player_;
	EnemyController enemy_controller_;
	CollisionRoad col_road_;

	void GoNextStage();		//���̃X�e�[�W�ɐi�݂܂�
public:
	GameScene(ISceneChanger* changer,int stage_num);
	~GameScene();
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;      //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw()const override;     //�`�揈�����I�[�o�[���C�h�B
};

#endif