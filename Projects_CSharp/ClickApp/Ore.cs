
/*
	Ore.cs
	鉱石クラス
	Created at 2016/10/17
	Created by Shou Watanabe
*/

using System.Drawing;

namespace ClickerApp2
{
	public class Ore
	{
		protected ImageData image;		// 画像
		protected float vX, vY, g;			// 速度、重力加速度
		protected int score {get; set;}	// 得点
		protected bool active;					// 有効かどうか

		static Size fieldSize;						// 有効な画面範囲

		// ================================================
		// コンストラクタ
		// ================================================
		public Ore( Image img, float x, float y ){
			// パラメータを初期化
			image = new ImageData( img, x, y );
			vX = vY = g = 0;
			score = 0;
			active = true;
		}

		static Ore() {
			fieldSize = new Size( 300, 300 );
		}

		// ================================================
		// 更新
		// ================================================
		virtual public void Update()
		{
			// 位置を速度分だけ移動
			image.posX += vX;
			image.posY += vY;

			vY += g;	// 重力で下方向に加速

			// 有効範囲外に出たら無効化
			if( image.posY > fieldSize.Height + image.image.Height * 0.5f ||
				image.posX > fieldSize.Width + image.image.Width * 0.5f ||
				image.posX < -image.image.Width * 0.5f )
				active = false;
		}

		// ================================================
		// 描画
		// ================================================
		virtual public void Draw( Graphics g )
		{
			image.Draw( g );	// 描画処理
		}

		// ================================================
		// 得点取得
		// ================================================
		public ulong GetScore() { return (uint)score; }

		// ================================================
		// 有効かどうか取得
		// ================================================
		public bool GetActive() { return active; }

		// ================================================
		// 有効範囲設定
		// ================================================
		static public void SetActiveField( Size s ) {
			fieldSize = s;
		}
	}
}
