using System;
using System.Drawing;
using System.Windows.Forms;
using WiimoteLib;		// WiimoteLibの使用を宣言

namespace kadai
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();	// Wiimoteクラスのインスタンスを作成
		
		string gameState = "gameStart";	// ゲームの状態
		Image canvas;					// 描画領域
		Bitmap background;		// 背景の画像
		Bitmap stick;					// 棒の画像

		float time;						// 残り時間
		bool isRight;						// 棒が右に傾いているか(true：右、false：左)
		float angle;						// 棒の傾き
		float velocity;					// 棒の傾く速度
		float rotate;						// 傾く加速度
		float recoil;						// 反動
		float force = 0.0f;			// WiiRemoteによる力

		bool pre_Abutton = false;			// 1フレーム前のAボタンの状態
		bool Abutton = false;					// Aボタンの状態

		// コンストラクタ
		public Form1() {
			Control.CheckForIllegalCrossThreadCalls = false;
			InitializeComponent();
			wm.WiimoteChanged += wm_WiimoteChanged;			// イベント関数の登録
			wm.Connect();																// Wiiリモコンの接続
			wm.SetReportType(InputReport.ButtonsAccel, true);	// レポートタイプの設定

			canvas = new Bitmap(640, 480);	// 描画領域の初期化

			// ダブルバッファリングに設定
			SetStyle(
				ControlStyles.DoubleBuffer |
				ControlStyles.UserPaint |
				ControlStyles.AllPaintingInWmPaint, true
			);
			// 画像ファイルからオブジェクト作成
			background = new Bitmap(@"C:\Users\1423056\Documents\講義関連フォルダ\2015年度\情報メディア基礎ユニットⅡ\E\VS2010Projects\kadai\kadai\background.png");
			stick = new Bitmap(@"C:\Users\1423056\Documents\講義関連フォルダ\2015年度\情報メディア基礎ユニットⅡ\E\VS2010Projects\kadai\kadai\stick1.png");
			// ゲーム初期化
			Initialize();
		}

		// Wiiリモコンの値が変わった時に呼ばれる関数
		void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
			WiimoteState ws = args.WiimoteState;
			force = ws.AccelState.Values.X * (ws.AccelState.Values.Y + 1.0f) * 0.1f;
			Abutton = ws.ButtonState.A;
		}

		// タイマー
		private void timer1_Tick(object sender, EventArgs e) {
			if (gameState == "playing") {	// ゲームプレイ中のときだけ
				time -= 0.01f;						// 残り時間を減らす
			}
			Calc();					// ゲームの更新
			Invalidate();		// 再描画
		}

		// ウインドウが閉じられたとき
		private void Form1_FormClosing(object sender, FormClosingEventArgs e) {
			wm.SetRumble(false);
			wm.SetLEDs(0);
			wm.Dispose();					// WiiRemoteを廃棄
			canvas.Dispose();			// 描画範囲のImageを廃棄
			background.Dispose();	// 背景の画像を廃棄
			stick.Dispose();	// 棒の画像を廃棄
		}

		// ゲームの初期化
		void Initialize() {
			time = 10.0f;		// 時間
			isRight = true;		// 棒が右に傾いているか(true：右、false：左)
			angle = 0.0f;		// 棒の傾き
			velocity = 0.0f;	// 棒の傾く速度
			rotate = 0.0f;		// 傾く加速度
			recoil = 0.0f;		// 反動

			// ラベル表示・非表示
			label1.Visible = true;
			label6.Visible = false;
			
			wm.SetRumble(false);// バイブレータOFF
			wm.SetLEDs(0);			// LEDを消灯
		}

		// 更新
		void Calc() {
			switch (gameState) {
				case "gameStart":
					#region ゲームスタート時
						if (!pre_Abutton && Abutton) {	// Aボタンが押された瞬間ゲームスタート
							gameState = "playing";
							label1.Visible = false;
						}
					#endregion
					break;
				case "playing":
					#region ゲームプレイ時
						Rotate();
						velocity += force;	// WiiRemoteによる力を加える	
						wm.SetLEDs((int)Math.Pow(2.0f , (int)((10.0f - time)/2.5f))-1);
						if (time <= 0.00f) {	// 残り時間0でゲームクリア
							time = 0.00f;	// 値を0.00ぴったりにする
							label6.Text = "げぇむくりあ";
							label6.Visible = true;
							label1.Text = "Aボタンで最初に戻る";
							label1.Visible = true;
							gameState = "gameClear";
						}
					#endregion
					break;
				case "gameClear":
					#region ゲームクリア時

					if (Abutton) {	// Aボタンを押したとき
						Initialize();
						label6.Visible = false;
						label1.Text = "Aボタンでげぇむ開始";
						gameState = "gameStart";
					}
					#endregion
					break;
				case "gameOver":
					#region ゲームオーバー時
						Rotate();
						if (Math.Abs(velocity) < 0.00005f) {	// 値を丸める
							velocity = 0.0f;
							rotate = 0.0f;
						}
						if (Abutton) {	// Aボタンを押したとき
							Initialize();	// ゲームの初期化
							label6.Visible = false;
							label1.Text = "Aボタンでげぇむ開始";
							gameState = "gameStart";
						}
					#endregion
					break;
			}
			if (angle >= 90.0f || angle <= -90.0f) {	// 棒が地面についたとき
				velocity = recoil;					// 反動を与える
				label6.Text = "げぇむおぉばぁ";
				label6.Visible = true;
				label1.Text = "Aボタンで最初に戻る";
				label1.Visible = true;
				gameState = "gameOver";	// ゲームオーバーに
				wm.SetRumble(true);			// バイブレータON
			}
			pre_Abutton = Abutton;
		}

		// 棒の回転
		private void Rotate() {
			isRight = (angle > 0) ? true : false;
			angle += velocity;
			velocity += rotate;
			rotate = isRight ? 0.01f : -0.01f;	// 右に傾いてるときは右に加速
			recoil = -velocity / 2.0f;				// 反動を速度の半分かつ逆向きに
		}

		// 描画
		protected override void OnPaint(PaintEventArgs e) {
			base.OnPaint(e);
			e.Graphics.DrawImage(background, 0, 0);

			label5.Text = time.ToString("F");	// ラベル描画

			// 棒の回転
			double d = angle / (180 / Math.PI);	// 角度をラジアンに変換
			float X = canvas.Width / 2;
			float Y = canvas.Height / 4 * 3;
			float X2 = X + stick.Height * (float)Math.Sin(d);
			float Y2 = Y - stick.Height * (float)Math.Cos(d);

			float x = X2 - stick.Width/2 * (float)Math.Cos(d);
			float y = Y2 - stick.Width/2*(float)Math.Sin(d);
			float x1 = X2 + stick.Width/2*(float)Math.Cos(d);
			float y1 = Y2 + stick.Width/2*(float)Math.Sin(d);
			float x2 = X - stick.Width/2*(float)Math.Cos(d);
			float y2 = Y - stick.Width/2*(float)Math.Sin(d);
			System.Drawing.PointF[] p ={
							new System.Drawing.PointF(x, y),
							new System.Drawing.PointF(x1,y1),
							new System.Drawing.PointF(x2, y2)};
			e.Graphics.DrawImage(stick, p);
		}
	}
}
