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
	if (next_scene_ != kSceneNone) {    //���̃V�[�����Z�b�g����Ă�����
		scene_->Finalize();//���݂̃V�[���̏I�����������s
		delete scene_;
		switch (next_scene_) {       //�V�[���ɂ���ď����𕪊�
		case kSceneStart:        //���̉�ʂ����j���[�Ȃ�
			scene_ = (BaseScene*) new StartScene(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break;//�ȉ���
		case kSceneGame:
			scene_ = (BaseScene*) new GameScene(this);
			break;
		}
		next_scene_ = kSceneNone;    //���̃V�[�������N���A
		scene_->Initialize();    //�V�[����������
	}

	scene_->Update(); //�V�[���̍X�V
}

//�`��
void SceneMgr::Draw() {
	scene_->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene NextScene) {
	next_scene_ = NextScene;    //���̃V�[�����Z�b�g����
}
