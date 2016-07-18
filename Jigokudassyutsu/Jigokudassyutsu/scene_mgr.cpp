#include "scene_mgr.h"

SceneMgr::SceneMgr() :
	next_scene_(kSceneNone) //���̃V�[���Ǘ��ϐ�
{
	scene_ = (BaseScene*) new StartScene(this);
}

//������
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//�I������
void SceneMgr::Finalize() {
	scene_->Finalize();
}

//�X�V
void SceneMgr::Update() {
	if (next_scene_ != kSceneNone) {//���̃V�[�����Z�b�g����Ă�����
		scene_->Finalize();			//���݂̃V�[���̏I�����������s
		delete scene_;
		switch (next_scene_) {		//�V�[���ɂ���ď����𕪊�
		case kSceneStart:			//���̉�ʂ����j���[�Ȃ�
			scene_ = (BaseScene*) new StartScene(this);   //�X�^�[�g��ʂ̃C���X�^���X�𐶐�����
			break;//�ȉ���
		case kSceneStageSelect:
			scene_ = (BaseScene*)new StageSelectScene(this);
			break;
		case kSceneGame1:
			scene_ = (BaseScene*) new GameScene(this, 1);
			break;
		case kSceneGame2:
			scene_ = (BaseScene*) new GameScene(this, 2);
			break;
		case kSceneGame3:
			scene_ = (BaseScene*) new GameScene(this, 3);
			break;
		case kSceneGame4:
			scene_ = (BaseScene*) new GameScene(this, 4);
			break;
		case kSceneGame5:
			scene_ = (BaseScene*) new GameScene(this, 5);
			break;
		default:
			util::ErrorOutPut(__FILE__, __func__, __LINE__, "�s���ȃV�[���ł��A�X�^�[�g��ʂɈڍs���܂�");
			scene_ = (BaseScene*) new StartScene(this);   //�X�^�[�g��ʂ̃C���X�^���X�𐶐�����
		}
		next_scene_ = kSceneNone;   //���̃V�[�������N���A
		scene_->Initialize();		//�V�[����������
	}

	scene_->Update();	//�V�[���̍X�V
}

//�`��
void SceneMgr::Draw() {
	scene_->Draw();		//�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene NextScene) {
	next_scene_ = NextScene;    //���̃V�[�����Z�b�g����
}