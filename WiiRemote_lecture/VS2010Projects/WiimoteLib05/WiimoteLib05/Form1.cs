using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WiimoteLib;		// WiimoteLibの使用を宣言

namespace WiimoteLib05
{
	public partial class Form1 : Form {
		Wiimote wm = new Wiimote();	// Wiimoteクラスのインスタンスを作成
		public Form1() {
			InitializeComponent();
			// 他スレッドからのコントロール呼び出し許可
			Control.CheckForIllegalCrossThreadCalls = false;
		}	
		// 接続ボタンが押されたら
		private void button1_Click(object sender, EventArgs e) {
			wm.Connect();	// Wiimoteの接続
			wm.WiimoteChanged += wm_WiimoteChanged;	// イベント関数の登録
			wm.SetReportType(InputReport.IRExtensionAccel, true);	// レポートタイプの設定
		}
		// 切断ボタンが押されたら
		private void button2_Click(object sender, EventArgs e) {
			wm.WiimoteChanged -= wm_WiimoteChanged;	// イベント関数の登録解除
			wm.Disconnect();	// Wiimote切断
			wm.Dispose();			// オブジェクトの配置
		}
		// Wiiリモコンの値が変化するたびに呼ばれる
		void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
			WiimoteState ws = args.WiimoteState;		// WiimoteStateの値を取得
			// もし赤外線を１つ発見したら
			if (ws.IRState.IRSensors[0].Found){
				wm.SetRumble(true);		// バイブレーターON
			}else{
				wm.SetRumble(false);	// バイブレーターOFF
			}
		}
	}
}
