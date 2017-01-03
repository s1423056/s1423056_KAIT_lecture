/*
	Form1.cs
	初めてのC#プログラム
	ボタンを押すと現在時刻が表示される
	Created at 2016/10/4
	Created by Shou Watanabe
*/

// 必要なライブラリを呼び出す。名前空間をドットで区切る。
using System;
using System.Windows.Forms;

namespace my_CSharp_01
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();	// デフォルトの初期化処理
		}

		// ボタンが押されたときのイベント
		// イベント自体は引数eで渡される
		private void button1_Click( object sender, EventArgs e )
		{
			// ラベル1のテキストに日付時刻型の現在時刻を文字列で渡す
			label1.Text = DateTime.Now.ToString();
		}
	}
}
