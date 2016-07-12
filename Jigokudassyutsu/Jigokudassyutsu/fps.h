#ifndef JIGOKUDASSYUTSU_UTIL_FPS_H_
#define JIGOKUDASSYUTSU_UTIL_FPS_H_

#include "DxLib.h"
#include "util.h"

class Fps {
private:
	int default_fps;			//�ݒ肵��FPS

	unsigned int starttime;		//����J�n����
	unsigned int count;			//�J�E���^
	int sampleing_count;		//���ς����T���v����
	int waittime_sum;			//�ҋ@���Ԃ̃T���v�����O�t���[���Ԃł̍��v

	double waittime_avg;		//�ҋ@���Ԃ̕���
	double fps_avg;				//����fps
	unsigned int totai_count;	//�o�߃t���[���̃J�E���g

	void Initialize();
	double ComputeAverageTimepar() const;
public:
	Fps();
	Fps(int fps);
	void Update();				//FPS�֘A�̏��X�V(���σt���[�����[�g�̌v�Z��)
	void Wait();				//FPS����̂��߂̑ҋ@�֐�
	double get_fps_avg() const;		//���݂̕���FPS�̎擾
	int get_totai_count() const;		//�N�����Ă��猻�݂܂ł̃t���[���J�E���g���̎擾
	void Draw(int x0, int y0) const;	//���݂�FPS�󋵂̏ڍׂ���ʂɕ`��
};

#endif