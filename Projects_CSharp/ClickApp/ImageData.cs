
/*
	ImageData.cs
	画像を扱うクラス
	Created at 2016/10/17
	Created by Shou Watanabe
*/

using System.Drawing;

namespace ClickerApp2
{
	public class ImageData
	{
		public Image image;	// 画像データ
		public float posX;			// x座標
		public float posY;			// y座標

		// ================================================
		// コンストラクタ
		// ================================================
		public ImageData( Image img, float x, float y ) {
			image = img; posX = x; posY = y;
		}

		// ================================================
		// 描画
		// ================================================
		virtual public void Draw( Graphics g )
		{
			// 描画処理
			g.DrawImage( image, posX, posY, image.Width, image.Height );	
		}
	}
}
