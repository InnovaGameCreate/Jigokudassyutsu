#include "fps.h"

Fps::Fps() {
	sampleing_count = 60;
	default_fps = 60;
	Initialize();
}

Fps::Fps(int fps) {
	if (fps > 0 || fps < 200) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "fps�̒l���s���ł�");
		sampleing_count = 60;
		default_fps = 60;
	}
	else {
		sampleing_count = fps;
		default_fps = fps;
	}
	Initialize();
}

//Fps������
void Fps::Initialize() {
	starttime = 0;
	count = 0;
	fps_avg = 0;
	totai_count = 0;
	waittime_sum = 0;
	waittime_avg = 0;
}

//FPS�֘A�̏��X�V(���σt���[�����[�g�̌v�Z��)
//���̊֐����Ă΂Ȃ���FPS����͐��������삵�܂���
void Fps::Update() {
	totai_count++;
	if (count == 0) { //1�t���[���ڂȂ玞�����L��
		starttime = GetNowCount();
	}
	if (count == sampleing_count) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		fps_avg = 1000. / ((t - starttime) / (double)sampleing_count);
		waittime_avg = waittime_sum / (double)sampleing_count;
		count = 0;
		waittime_sum = 0;
		starttime = t;
	}
	count++;
}

//FPS�����̂��߂̑ҋ@����
//FPS�𐧌䂷�邽�߂ɏ����ɂ����������Ԃ���Z�o�����ҋ@���ԑҋ@���܂��B
//�������ǂ������ҋ@���Ԃ��v��Ȃ��ꍇ�͑ҋ@���܂���B
void Fps::Wait() {
	if (default_fps > 0) {
		int tookTime = GetNowCount() - starttime;	//������������
		int waitTime = count * 1000. / default_fps - tookTime;//�҂ׂ�����
		if (waitTime >= 0)	waittime_sum += waitTime;
		else				waittime_sum = waitTime;
		if (waitTime > 0) {
			WaitTimer(waitTime);	//�ҋ@
		}
	}
}

//���݂̕���FPS�̎擾
double Fps::get_fps_avg()  const {
	return fps_avg;
}

//���݂̃t���[���J�E���g�̎擾
int Fps::get_totai_count()  const {
	return totai_count;
}

//1�t���[��������Ɏg�p���Ă��鎞�Ԃ̕��ς̎擾(���ۂɂ����邱�Ƃ��o���鎞�Ԃɑ΂��Ă̊���)
//�����̒l��0�ɋ߂��قǕ��ׂ����Ȃ�
double Fps::ComputeAverageTimepar()  const {
	double f_Time;//1�t���[���ɂ����鎞��
	double par;//����
	f_Time = 1000. / default_fps;
	par = (waittime_avg * 100) / f_Time - 100;
	if (par < 0)	par = -par;//�}�C�i�X�Ȃ畄���t�](0.00�̎��̕�����+-���Ă�������������)
	return par;
}

//���݂�FPS�󋵂̏ڍׂ���ʂɕ`��
//���݂�FPS,�ҋ@���Ԃ̕���,1�t���[���̂��������Ɏg�p���Ă��鎞�Ԃ̊���[%]
//�����̑傫���̂�20�ŌŒ肵�Ă���܂�
//
//����:������`�悷�鍶��̍��W
void Fps::Draw(int X, int Y)  const {
	//FPS�`��
	SetFontSize(20);
	DrawFormatString(X, Y, GetColor(255, 255, 255), "FPS(D):%.2f %.2fms(%.2f%%)", fps_avg, waittime_avg, ComputeAverageTimepar());
}