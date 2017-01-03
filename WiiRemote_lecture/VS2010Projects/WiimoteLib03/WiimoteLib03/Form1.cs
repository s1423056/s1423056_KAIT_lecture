using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WiimoteLib;	// WiimoteLibの使用を宣言

namespace WiimoteLib03
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();	// Wiimoteクラスのインスタンスを作成
		public Form1()
		{
			Control.CheckForIllegalCrossThreadCalls = false;	// おまじない
			InitializeComponent();
			wm.WiimoteChanged += wm_WiimoteChanged;	// イベント関数の登録
			wm.Connect();
		}
		// Wiiリモコンの値が変化したときに呼ばれる関数
		void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
			WiimoteState ws = args.WiimoteState;
			this.DrawForms(ws);	// フォーム描写関数
		}
		// フォーム描写関数
		public void DrawForms(WiimoteState ws){
			this.label1.Text = "Button A:" + (ws.ButtonState.A);
			this.label2.Text = "Button B" + (ws.ButtonState.B);
			this.label3.Text = "Button 1:" + (ws.ButtonState.One);
			this.label4.Text = "Button 2:" + (ws.ButtonState.Two);
		}
	}
}
