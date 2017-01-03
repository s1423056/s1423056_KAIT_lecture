
/*
	Form1.cs
	クッキークリッカー風アプリケーション
	Created at 2016/10/17
	Created by Shou Watanabe
*/

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ClickerApp2
{
	public partial class Form1 : Form
	{
		Game app;	// ゲームオブジェクト

		// ================================================
		// フォームの初期化処理(コンストラクタ？)
		// ================================================
		public Form1()
		{
			InitializeComponent();	// デフォルトの初期化処理

			// label1の親コントロールをpictureBox1とする
			pictureBox1.Controls.Add( label1 );

			// label1の位置をpictureBox1内の位置に変更する
			label1.Top = label1.Top - pictureBox1.Top;
			label1.Left = label1.Left - pictureBox1.Left;

			// ボタンの親コントロールをpictureBox1とする
			pictureBox1.Controls.Add( button1 );
			pictureBox1.Controls.Add( button2 );

			// ボタンの位置をpictureBox1内の位置に変更する
			button1.Top = button1.Top - pictureBox1.Top;
			button1.Left = button1.Left - pictureBox1.Left;

			button2.Top = button2.Top - pictureBox1.Top;
			button2.Left = button2.Left - pictureBox1.Left;

			app = new Game();	// ゲームオブジェクト生成
			timer1.Enabled = true;	// タイマー開始
		}

		// ================================================
		// フォームロード時に呼ばれる処理
		// ================================================
		private void Form1_Load( object sender, System.EventArgs e )
		{
			
		}

		// ================================================
		// フォームを閉じるときに呼ばれる処理
		// ================================================
		private void Form1_FormClosing( object sender, FormClosingEventArgs e )
		{

		}

		// ================================================
		// pictureBox1がクリックされたときの処理
		// ================================================
		private void pictureBox1_Click( object sender, System.EventArgs e )
		{
			Point sp = Cursor.Position;	// スクリーン内でのマウス位置を取得
			Point cp = this.PointToClient( sp );	// クライアント領域中のマウス位置を取得
			app.OnClick( cp );	// アプリケーションオブジェクトのクリック時の処理
		}

		// ================================================
		// フォームのサイズが変更されたときの処理
		// ================================================
		private void Form1_Resize( object sender, System.EventArgs e )
		{
			pictureBox1.Size = this.ClientSize; // pictureBoxをリサイズ
			Ore.SetActiveField( this.ClientSize );	// 鉱石のアクティブ領域をリサイズ
		}

		// ================================================
		// 最大化ボタンが押されたときの処理
		// ================================================
		private void Form1_MaximumSizeChanged( object sender, System.EventArgs e )
		{
			pictureBox1.Size = this.ClientSize; // pictureBoxをリサイズ
			Ore.SetActiveField( this.ClientSize );	// 鉱石のアクティブ領域をリサイズ
		}

		// ================================================
		// 定期的に呼ばれる処理
		// ================================================
		private void timer1_Tick( object sender, System.EventArgs e )
		{
			pictureBox1.Invalidate();   // pictureBox1を描画する

			// アプリケーション更新
			app.Update();
		}

		// ================================================
		// 描画時に呼ばれる処理
		// ================================================
		private void pictureBox1_Paint( object sender, PaintEventArgs e )
		{
			// アプリケーションの描画処理
			app.Draw( e.Graphics, this.ClientSize.Width, this.ClientSize.Height );

			// ラベル更新
			label1.Text = app.GetScore().ToString();
		}

		// ================================================
		// セーブボタンが押されたときの処理
		// ================================================
		private void button1_Click( object sender, EventArgs e )
		{
			// XmlSerializerオブジェクトを作成
			System.Xml.Serialization.XmlSerializer serializer = 
				new System.Xml.Serialization.XmlSerializer( typeof( Data ) );

			// 書き込むファイルを開く
			System.IO.FileStream fs = new System.IO.FileStream(
				app.GetFilename(), System.IO.FileMode.Create );

			// シリアライズして、XMLファイルに保存する
			serializer.Serialize( fs, app.GetData() );

			// ファイルを閉じる
			fs.Close();
		}

		// ================================================
		// ロードボタンが押されたときの処理
		// ================================================
		private void button2_Click( object sender, EventArgs e )
		{
			// XmlSerializerオブジェクトを作成
			System.Xml.Serialization.XmlSerializer serializer = 
				new System.Xml.Serialization.XmlSerializer( typeof( Data ) );

			// 読み込むファイルを開く
			System.IO.FileStream fs = new System.IO.FileStream(
				app.GetFilename(), System.IO.FileMode.Open );

			// XMLファイルから読み込み、デシリアライズする
			app.SetData( ( Data )serializer.Deserialize( fs ) );

			// ファイルを閉じる
			fs.Close();
		}

		// ================================================
		// セーブボタンにマウスカーソルが入ってきたら
		// ================================================
		private void button1_MouseEnter( object sender, EventArgs e )
		{
			// 手の形にする
			this.Cursor = Cursors.Hand;
		}

		// ================================================
		// ロードボタンにマウスカーソルが入ってきたら
		// ================================================
		private void button2_MouseEnter( object sender, EventArgs e )
		{
			// 手の形にする
			this.Cursor = Cursors.Hand;
		}

		// ================================================
		// 領域内にマウスカーソルが入ってきたら
		// ================================================
		private void pictureBox1_MouseEnter( object sender, EventArgs e )
		{
			// マウスカーソル用画像を生成
			Image img = Image.FromFile( "つるはし.png" );
			Bitmap bitmap = new Bitmap( img );
			IntPtr handle = bitmap.GetHicon();
			
			var icon = Icon.FromHandle(handle);
			this.Cursor = new Cursor( icon.Handle );
			
		}
	}
}
