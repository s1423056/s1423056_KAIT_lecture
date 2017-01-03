
/*
	Game.cs
	フォーム外のアプリケーション全体を制御するクラス
	Created at 2016/10/18
	Created by Shou Watanabe
*/

using System;
using System.Drawing;
using System.Collections.Generic;

namespace ClickerApp2
{
	public class Data
	{
		public ulong counter {get; set;}	// クリック回数カウンター
		public ulong score {get; set;}		// 得点
		
		// ================================================
		// コンストラクタ
		// ================================================
		public Data() { counter = 0; score = 0; }
	}

	public class Game
	{
		Image backGround;		// 背景画像
		Image coalImage;		// 石炭画像
		Image stoneImage;		// 石画像
		List<Ore> oreList = new List<Ore>( 50 );  // 鉱石リスト 要素50個分確保しておく

		Random random = new Random();		// ランダム数値生成オブジェクト
		private Data data;				// セーブデータ

		public string filename = "data.xml";		// セーブデータファイル名

		// ================================================
		// コンストラクタ
		// ================================================
		public Game()
		{
			backGround = Image.FromFile( "石壁.png" );	// 背景画像読み込み
			coalImage = Image.FromFile( "石炭.png" );	// 石炭画像読み込み
			stoneImage = Image.FromFile( "石.png" );	// 石画像読み込み

			data = new Data();	// セーブデータインスタンス生成
			data.counter = 0;	// カウンター初期化
			data.score = 0;		// スコア初期化
		}

		// ================================================
		// デストラクタ
		// ================================================
		~Game()
		{
			// リソースを解放する
			stoneImage.Dispose();
			coalImage.Dispose();
			backGround.Dispose();
		}

		// ================================================
		// クリック時の処理
		// ================================================
		public void OnClick( Point p )
		{
			data.counter++;	// カウント増加
			int i = random.Next( 10 );	// 種類をランダムで決定
			float vX = (float)( random.NextDouble() * 6.0f - 3.0f );	// X軸速度をランダムで決定
			float vY = (float)( random.NextDouble() * 6.0f - 3.0f );	// Y軸速度をランダムで決定
			Ore ore;	// 鉱石オブジェクト

			// 引数pの位置（クライアント領域中のマウス位置）から鉱石を出す
			switch( i ) {
				case 0 :	// 石炭を生成
					ore = new Coal( coalImage, p.X, p.Y, vX, vY, 1.0f );
					break;

				default:	// 石を生成
					ore = new Stone( stoneImage, p.X, p.Y, vX, vY, 1.0f );
					break;
			}
			data.score += ore.GetScore();	// 得点加算
			oreList.Add( ore );	// 生成した鉱石をリストに追加
		}

		// ================================================
		// 更新
		// ================================================
		public void Update()
		{
			// 鉱石リスト内の全鉱石を更新
			foreach( Ore ore in oreList )
			{
				ore.Update();	// 更新
			}
			
			// 無効な鉱石をリストから削除する
			oreList.RemoveAll( Ore => !Ore.GetActive() );
		}

		// ================================================
		// 描画
		// ================================================
		public void Draw( Graphics g, int clientWidth, int clientHeight )
		{
			// 背景を描画
			g.DrawImage( backGround, 0, 0, clientWidth, clientHeight );

			// 鉱石リスト内の全鉱石を描画
			foreach( Ore ore in oreList )
				ore.Draw( g );
		}

		// ================================================
		// セーブデータ取得
		// ================================================
		public Data GetData() { return data; }

		// ================================================
		// セーブデータ読み込み
		// ================================================
		public void SetData( Data d ) { data = d; }

		// ================================================
		// スコア取得
		// ================================================
		public ulong GetScore() { return data.score; }

		// ================================================
		// セーブデータファイル名取得
		// ================================================
		public string GetFilename() { return filename; }
	}
}
