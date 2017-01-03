using System;
using System.Windows.Forms;
using WiimoteLib;   // ここを1行追加

namespace WiimoteLib01
{
    public partial class Form1 : Form
    {
        Wiimote wm = new Wiimote(); // Wiimoteクラスのインスタンスwmを作成
		public Form1()
        {
            InitializeComponent();  // 初期化処理
            wm.Connect();   // Wiimoteに接続
        }

		// ボタン1をクリックすると呼ばれる関数
		private void button1_Click(object sender, EventArgs e)
		{
			wm.SetRumble(true);	// バイブレーションon
		}

		// ボタン2をクリックすると呼ばれる関数
		private void button2_Click(object sender, EventArgs e)
		{
			wm.SetRumble(false);	// バイブレーションoff
		}
    }
}
