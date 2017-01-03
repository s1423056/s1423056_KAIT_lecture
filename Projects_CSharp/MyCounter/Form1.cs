/*
	Form1.cs
	ボタン1を押すとカウントが増え
	ボタン2を押すとカウントがリセットされるプログラム
	Created at 2016/10/5
	Created by Shou Watanabe
*/

using System;
using System.Windows.Forms;

namespace MyCounter
{
	public partial class Form1 : Form
	{
		//int count = 0;  // カウンター変数

		// プロパティ記法
		int Counter { get; set; }

		public Form1()
		{
			InitializeComponent();	// デフォルトの初期化処理
		}

		// カウントアップボタンが押されたら
		private void button1_Click( object sender, EventArgs e )
		{
			// カウントを1増やし、ラベルを書き換える
			/*
				count++;
				label1.Text = count.ToString();
			*/
			Counter++;
			label1.Text = Counter.ToString();
		}

		// リセットボタンが押されたら
		private void button2_Click( object sender, EventArgs e )
		{
			// カウントを0にして、ラベルを書き換える
			/*
				count = 0;
				label1.Text = count.ToString();
			*/
			Counter = 0;
			label1.Text = Counter.ToString();
		}
	}
}
