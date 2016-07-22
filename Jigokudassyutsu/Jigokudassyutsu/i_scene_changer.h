#ifndef JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_
#define JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_

typedef enum {
	//�X�^�[�g���
	kSceneStart,    
	//�Q�[�����
	kSceneGame1,
	kSceneGame2,
	kSceneGame3,
	kSceneGame4,
	kSceneGame5,
	//�Q�[���N���A���
	kSceneClear,
	//�Q�[���I�[�o�[���
	kSceneOver,

	//����
	kSceneNone
} Scene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeScene(Scene NextScene) = 0;//�w��V�[���ɕύX����
};

#endif