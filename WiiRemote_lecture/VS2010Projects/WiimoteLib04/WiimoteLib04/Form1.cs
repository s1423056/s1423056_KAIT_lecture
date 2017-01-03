using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WiimoteLib;		// WiimoteLibの使用を宣言

namespace WiimoteLib04
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();
		public Form1()
		{
			Control.CheckForIllegalCrossThreadCalls = false;	// おまじない
			InitializeComponent();
			wm.WiimoteChanged += wm_WiimoteChanged;	// イベント関数の登録
			wm.Connect();																// Wiimoteと接続
			wm.SetReportType(InputReport.ButtonsAccel, true);	// レポートタイプの設定
		}
		// Wiiリモコンの値が変化したときに呼ばれる関数
		void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args){
			WiimoteState ws = args.WiimoteState;
			this.DrawForms(ws);	// フォーム描画関数
		}
		// フォーム描画関数
		void DrawForms(WiimoteState ws) {
			this.label1.Text = "X軸："+ (ws.AccelState.Values.X);
			this.label2.Text = "Y軸：" + (ws.AccelState.Values.Y);
			this.label3.Text = "Z軸：" + (ws.AccelState.Values.Z);
		}
	}
}
