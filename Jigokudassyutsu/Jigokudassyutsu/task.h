#ifndef JIGOKUDASSYUTSU_SCENE_TASK_H_
#define JIGOKUDASSYUTSU_SCENE_TASK_H_

//�^�X�N�N���X�B�����̃��W���[���͂��ׂĂ���Task�N���X���p������B
class Task {
public:
	virtual ~Task() {}
	virtual void Initialize() {}     //�����������͎������Ă����Ȃ��Ă�����
	virtual void Finalize() {}     //�I�������͎������Ă����Ȃ��Ă�����
	virtual void Update() = 0;   //�X�V�����͕K���p����Ŏ�������
	virtual void Draw() = 0;   //�`�揈���͕K���p����Ŏ�������
};

#endif