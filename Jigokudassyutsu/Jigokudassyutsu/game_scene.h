#ifndef JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_
#define JIGOKUDASSYUTSU_SCENESUB_GAMESCENE_H_

#include "DxLib.h"
#include "base_scene.h"
#include "i_scene_changer.h"

#include "input.h"
#include "map.h"
#include "player.h"
#include "enemy_controller.h"

//�Q�[����ʃN���X
class GameScene : public BaseScene {
private:
	const int stage_num_;

	Map map;
	Player player;
	EnemyController enemy_controller;

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