#ifndef JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_
#define JIGOKUDASSYUTSU_SCENE_ISCENECHANGER_H_

typedef enum {
	kSceneStart,    //���j���[���
	kSceneGame,    //�Q�[�����

	kSceneNone,    //����
} eScene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeScene(eScene NextScene) = 0;//�w��V�[���ɕύX����
};

#endif