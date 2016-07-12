#include "fps.h"

Fps::Fps() {
	sampleing_count_ = 60;
	default_fps_ = 60;
	Initialize();
}

Fps::Fps(int fps) {
	if (fps > 0 || fps < 200) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "fps�̒l���s���ł�");
		sampleing_count_ = 60;
		default_fps_ = 60;
	}
	else {
		sampleing_count_ = fps;
		default_fps_ = fps;
	}
	Initialize();
}

//Fps������
void Fps::Initialize() {
	starttime_ = 0;
	count_ = 0;
	fps_avg_ = 0;
	totai_count_ = 0;
	waittime_sum_ = 0;
	waittime_avg_ = 0;
}

//FPS�֘A�̏��X�V(���σt���[�����[�g�̌v�Z��)
//���̊֐����Ă΂Ȃ���FPS����͐��������삵�܂���
void Fps::Update() {
	totai_count_++;
	if (count_ == 0) { //1�t���[���ڂȂ玞�����L��
		starttime_ = GetNowCount();
	}
	if (count_ == sampleing_count_) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		fps_avg_ = 1000. / ((t - starttime_) / (double)sampleing_count_);
		waittime_avg_ = waittime_sum_ / (double)sampleing_count_;
		count_ = 0;
		waittime_sum_ = 0;
		starttime_ = t;
	}
	count_++;
}

//FPS�����̂��߂̑ҋ@����
//FPS�𐧌䂷�邽�߂ɏ����ɂ����������Ԃ���Z�o�����ҋ@���ԑҋ@���܂��B
//�������ǂ������ҋ@���Ԃ��v��Ȃ��ꍇ�͑ҋ@���܂���B
void Fps::Wait() {
	if (default_fps_ > 0) {
		int tookTime = GetNowCount() - starttime_;	//������������
		int waitTime = count_ * 1000. / default_fps_ - tookTime;//�҂ׂ�����
		if (waitTime >= 0)	waittime_sum_ += waitTime;
		else				waittime_sum_ = waitTime;
		if (waitTime > 0) {
			WaitTimer(waitTime);	//�ҋ@
		}
	}
}

//���݂̕���FPS�̎擾
double Fps::get_fps_avg()  const {
	return fps_avg_;
}

//���݂̃t���[���J�E���g�̎擾
int Fps::get_totai_count()  const {
	return totai_count_;
}

//1�t���[��������Ɏg�p���Ă��鎞�Ԃ̕��ς̎擾(���ۂɂ����邱�Ƃ��o���鎞�Ԃɑ΂��Ă̊���)
//�����̒l��0�ɋ߂��قǕ��ׂ����Ȃ�
double Fps::ComputeAverageTimepar()  const {
	double f_Time;//1�t���[���ɂ����鎞��
	double par;//����
	f_Time = 1000. / default_fps_;
	par = (waittime_avg_ * 100) / f_Time - 100;
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
	DrawFormatString(X, Y, GetColor(255, 255, 255), "FPS(D):%.2f %.2fms(%.2f%%)", fps_avg_, waittime_avg_, ComputeAverageTimepar());
}