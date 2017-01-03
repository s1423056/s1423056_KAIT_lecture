
/*
	Coal.cs
	石炭クラス　鉱石クラスを継承する
	Created at 2016/10/17
	Created by Shou Watanabe
*/

using System;
using System.Drawing;

namespace ClickerApp2
{
	class Coal : Ore
	{
		// ================================================
		// コンストラクタ
		// ================================================
		public Coal( Image img, float x, float y, float vX, float vY, float g ) : base( img, x, y ) {
			// 速度、重力加速度を引数の値で初期化
			base.vX = vX;
			base.vY = vY;
			base.g = g;
			base.score = 10;	// 得点
		}
	}
}
