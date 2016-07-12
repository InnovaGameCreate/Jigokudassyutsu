#include "fps.h"

Fps::Fps() {
	sampleing_count_ = 60;
	default_fps_ = 60;
	Initialize();
}

Fps::Fps(int fps) {
	if (fps > 0 || fps < 200) {
		util::ErrorOutPut(__FILE__, __func__, __LINE__, "fpsの値が不正です");
		sampleing_count_ = 60;
		default_fps_ = 60;
	}
	else {
		sampleing_count_ = fps;
		default_fps_ = fps;
	}
	Initialize();
}

//Fps初期化
void Fps::Initialize() {
	starttime_ = 0;
	count_ = 0;
	fps_avg_ = 0;
	totai_count_ = 0;
	waittime_sum_ = 0;
	waittime_avg_ = 0;
}

//FPS関連の情報更新(平均フレームレートの計算等)
//この関数を呼ばないとFPS制御は正しく動作しません
void Fps::Update() {
	totai_count_++;
	if (count_ == 0) { //1フレーム目なら時刻を記憶
		starttime_ = GetNowCount();
	}
	if (count_ == sampleing_count_) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		fps_avg_ = 1000. / ((t - starttime_) / (double)sampleing_count_);
		waittime_avg_ = waittime_sum_ / (double)sampleing_count_;
		count_ = 0;
		waittime_sum_ = 0;
		starttime_ = t;
	}
	count_++;
}

//FPS調整のための待機時間
//FPSを制御するために処理にかかった時間から算出した待機時間待機します。
//処理が追いつかず待機時間が要らない場合は待機しません。
void Fps::Wait() {
	if (default_fps_ > 0) {
		int tookTime = GetNowCount() - starttime_;	//かかった時間
		int waitTime = count_ * 1000. / default_fps_ - tookTime;//待つべき時間
		if (waitTime >= 0)	waittime_sum_ += waitTime;
		else				waittime_sum_ = waitTime;
		if (waitTime > 0) {
			WaitTimer(waitTime);	//待機
		}
	}
}

//現在の平均FPSの取得
double Fps::get_fps_avg()  const {
	return fps_avg_;
}

//現在のフレームカウントの取得
int Fps::get_totai_count()  const {
	return totai_count_;
}

//1フレームあたりに使用している時間の平均の取得(実際にかけることが出来る時間に対しての割合)
//ここの値が0に近いほど負荷が少ない
double Fps::ComputeAverageTimepar()  const {
	double f_Time;//1フレームにかける時間
	double par;//割合
	f_Time = 1000. / default_fps_;
	par = (waittime_avg_ * 100) / f_Time - 100;
	if (par < 0)	par = -par;//マイナスなら符号逆転(0.00の時の符号が+-してうざかったから)
	return par;
}

//現在のFPS状況の詳細を画面に描画
//現在のFPS,待機時間の平均,1フレームのうち処理に使用している時間の割合[%]
//文字の大きさのみ20で固定してあります
//
//引数:文字を描画する左上の座標
void Fps::Draw(int X, int Y)  const {
	//FPS描画
	SetFontSize(20);
	DrawFormatString(X, Y, GetColor(255, 255, 255), "FPS(D):%.2f %.2fms(%.2f%%)", fps_avg_, waittime_avg_, ComputeAverageTimepar());
}