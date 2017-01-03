using System;
using System.Windows.Forms;
using System.Drawing;
using WiimoteLib;	// WiimoteLibの使用を宣言

namespace WiiRemoteMouseTest1
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();		// Wiimoteクラスのインスタンスを作成
		System.Drawing.Point ScreenSize;	// 画面サイズを格納
		bool isConnected = false;				// WiiRemoteが接続されているか
		int cursorX, cursorY;						// カーソル座標
		float cursorSpdX, cursorSpdY;			// カーソル移動速度
		const float threshold = 0.05f;			// 閾値

		#region コンストラクタ
		public Form1() {
			InitializeComponent();
			// 他スレッドからのコントロール呼び出し許可
			Control.CheckForIllegalCrossThreadCalls = false;
			// カーソルに関わる変数を初期化
			cursorX = pictureBox1.Width / 2;
			cursorY = pictureBox1.Height / 2;
			cursorSpdX = cursorSpdY = 0;
		}
		#endregion

		#region WiiRemoteの状態が変化したとき呼ばれる関数
		void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
			if (isConnected){
				WiimoteState ws = args.WiimoteState;
				DrawForms(ws);		// フォーム描画関数
				CursorMove(ws);		// カーソル移動
				ButtonEvents(ws);	// ボタンイベント
				EffectsOut(ws);		// LED・装飾
			} else {
				// 切断
				this.wm.SetLEDs(0);			// LED消灯
				this.wm.SetRumble(false);	// バイブレータ停止
				this.wm.Disconnect();			// WiiRemoteの切断
				this.wm.Dispose();				//  オブジェクトの破棄
			}
		}
		#endregion

		#region ボタンイベント
		public void ButtonEvents(WiimoteState ws) {
		}
		#endregion

		#region フォーム描画関数
		public void DrawForms(WiimoteState ws) {
			// グラフィックスを取得
			Graphics g = this.pictureBox1.CreateGraphics();
			g.Clear(Color.Black);

			// マーカーを描画
			//g.FillEllipse(Brushes.Red, cursorX, cursorY, 5, 5);

			// ラベルを描画
			label1.Text = "accX：" + ws.AccelState.Values.X;
			label2.Text = "accY：" + ws.AccelState.Values.Y;
			label3.Text = "accZ：" + ws.AccelState.Values.Z;
			g.Dispose();
		}
		#endregion

		#region フォームのボタン処理(接続・切断)
		// 接続ボタンが押されたら
		private void button1_Click(object sender, EventArgs e)
		{
			if (isConnected) return;	// 既に接続されている場合、この関数を抜ける
			this.wm = new Wiimote();	// WiiRemoteの初期化
			wm.Connect();					// WiiRemoteの接続
			wm.WiimoteChanged += wm_WiimoteChanged;	// イベント関数の登録
			wm.SetReportType(InputReport.ButtonsAccel, true);// レポートタイプの設定

			this.wm.SetLEDs(0);				// LEDを消す
			this.wm.SetRumble(false);		// バイブレータを停止

			this.button1.Enabled = false;	// 接続ボタンを無効化
			this.button2.Enabled = true;	// 切断ボタンを有効化
			isConnected = true;				// 接続状態をtrue
		}

		// 切断ボタンが押されたら
		private void button2_Click(object sender, EventArgs e)
		{
			if (!isConnected) return;	// 既に切断されている場合、この関数を抜ける
			wm.SetLEDs(0);				// LEDを消す(念のため)
			wm.SetRumble(false);	// バイブレータを停止(念のため)
			wm.WiimoteChanged -= wm_WiimoteChanged;	// イベント関数の登録解除
			wm.Disconnect();	// WiiRemoteの切断
			wm.Dispose();			// wmオブジェクトの破棄

			// カーソル位置初期化
			cursorX = pictureBox1.Width / 2;
			cursorY = pictureBox1.Height / 2;

			this.button1.Enabled = true;	// 接続ボタンを有効化
			this.button2.Enabled = false;	// 切断ボタンを無効化
			isConnected = false;		// 接続状態をfalse
		}

		#endregion

		#region マウスカーソル移動
		public void CursorMove(WiimoteState ws) {
			float ax = ws.AccelState.Values.X;
			float ay = ws.AccelState.Values.Y;
			if (-threshold < ax && ax < threshold) ax = 0;
			if (-threshold < ay && ay < threshold) ay = 0;
			cursorSpdX += ax;
			cursorSpdY += ay;	
		}
		#endregion

		#region LED・装飾
		public void EffectsOut(WiimoteState ws) {

		}
		#endregion

		#region タイマー
		private void timer1_Tick(object sender, EventArgs e)
		{
			//cursorX += (int)cursorSpdX;
			//cursorY -= (int)cursorSpdY;
		}
		#endregion
	}
}
