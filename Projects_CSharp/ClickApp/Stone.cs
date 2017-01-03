
/*
	Stone.cs
	石クラス 鉱石クラスを継承
	Created at 2016/10/18
	Created by Shou Watanabe
*/

using System;
using System.Drawing;

namespace ClickerApp2
{
	class Stone : Ore
	{
		// ================================================
		// コンストラクタ
		// ================================================
		public Stone( Image img, float x, float y, float vX, float vY, float g ) : base( img, x, y )
		{
			// 速度と重力加速度を引数の値で初期化
			base.vX = vX;
			base.vY = vY;
			base.g = g;
			base.score = 1;	// 得点
		}
	}
}
