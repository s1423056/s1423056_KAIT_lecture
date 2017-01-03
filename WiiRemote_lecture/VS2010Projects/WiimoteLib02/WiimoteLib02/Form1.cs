using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WiimoteLib;	// WiimoteLibの使用を宣言

namespace WiimoteLib02
{
	public partial class Form1 : Form
	{
		Wiimote wm = new Wiimote();	// Wiimoteのインスタンスを作成
		int count = 0;								// int型のカウンタを宣言

		public Form1()
		{
			InitializeComponent();
			wm.Connect();
		}
		// ボタンが押されたときの処理
		private void button1_Click(object sender, EventArgs e)
		{
			this.button1.Text = "wm.SetLEDs(" + count + ") を表示中 ";
			this.wm.SetLEDs(count);	// LEDを点灯
			count++;
		}
	}
}