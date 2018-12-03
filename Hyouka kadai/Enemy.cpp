/*******************************************************************************
* タイトル:		評価課題 RPGゲーム
* プログラム名:	Enemy.cpp
* 作成者:		GP11B-341 29 益子　聖渚
* 作成日:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "Enemy.h"
#include "BG.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/

ENEMY enemy[ENEMY_MAX];          //プレイヤー

int flag1 = 0;											//エネミーの生死判定
int flag2 = 0;											//エネミーの生死判定
int flag3 = 0;											//エネミーの生死判定
int flag4 = 0;											//エネミーの生死判定
int flag5 = 0;											//エネミーの生死判定


/*******************************************************************************
関数名:	( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/

/*******************************************************************************
関数名:	void InitEnemy( void )
引数:	void
戻り値:	void
説明:	エネミーの初期化処理
*******************************************************************************/
void InitEnemy(void)
{
	ENEMY *enemy  = GetEnemyAdr(0);			//エネミー(0) のアドレスを取得する
	ENEMY *enemy1 = GetEnemyAdr(1);			//エネミー(1) のアドレスを取得する
	ENEMY *enemy2 = GetEnemyAdr(2);			//エネミー(2) のアドレスを取得する
	ENEMY *enemy3 = GetEnemyAdr(3);			//エネミー(3) のアドレスを取得する
	ENEMY *enemy4 = GetEnemyAdr(4);			//エネミー(4) のアドレスを取得する

	char *map;


	/* 敵の初期位置設定 */
	enemy->fx = 40;
	enemy->fy = 10;

	enemy1->fx = 20;
	enemy1->fy = 8;

	enemy2->fx = 30;
	enemy2->fy = 5;

	enemy3->fx = 50;
	enemy3->fy = 3;

	enemy4->fx = 77;
	enemy4->fy = 7;


	map = GetMapAdr(enemy->fy, enemy->fx);	    // フィールドのアドレスを取得
	*map = 'K';
	map = GetMapAdr(enemy1->fy, enemy1->fx);	// フィールドのアドレスを取得
	*map = 'S';
	map = GetMapAdr(enemy2->fy, enemy2->fx);	// フィールドのアドレスを取得
	*map = 'W';
	map = GetMapAdr(enemy3->fy, enemy3->fx);	// フィールドのアドレスを取得
	*map = 'D';
	map = GetMapAdr(enemy4->fy, enemy4->fx);	// フィールドのアドレスを取得
	*map = 'A';


	//エネミーのパラメーター設定
	//エネミー(0)番
	strcpy(&enemy->name[0], "ナイト");
	enemy->HP  = 1000;
	enemy->ATK =  100;
	enemy->EXP = 1000;

	//エネミー(1)番
	strcpy(&enemy1->name[1], "スライム");
	enemy1->HP =  25;
	enemy1->ATK = 10;
	enemy1->EXP = 10;

	//エネミー(2)番
	strcpy(&enemy2->name[2], "ウルフ");
	enemy2->HP  = 300;
	enemy2->ATK =  45;
	enemy2->EXP = 100;

	//エネミー(3)番
	strcpy(&enemy3->name[3], "ドラゴン");
	enemy3->HP  =  3000;
	enemy3->ATK =   300;
	enemy3->EXP = 10000;

	//エネミー(4)番
	strcpy(&enemy4->name[4], "S  A  N  S");
	enemy4->HP =   10000;
	enemy4->ATK =    999;
	enemy4->EXP =  99999;



	
}


/*******************************************************************************
関数名:	void UpdateEnemy( void )
引数:	void
戻り値:	void
説明:	エネミーの更新処理
*******************************************************************************/
void UpdateEnemy(void)
{
	int key;
	int key1;
	int key2;
	int key3;
	int key4;
	int old_x, old_y;
	int old1_x, old1_y;
	int old2_x, old2_y;
	int old3_x, old3_y;
	int old4_x, old4_y;

	ENEMY *enemy = GetEnemyAdr(0);
	ENEMY *enemy1 = GetEnemyAdr(1);
	ENEMY *enemy2 = GetEnemyAdr(2);
	ENEMY *enemy3 = GetEnemyAdr(3);
	ENEMY *enemy4 = GetEnemyAdr(4);

	char *map;
	char *map1;
	char *map2;
	char *map3;
	char *map4;


	/* 前回の表示位置の消去*/
	map = GetMapAdr(enemy->fy, enemy->fx);	// フィールドのアドレスを取得
	*map = ' ';
	map1 = GetMapAdr(enemy1->fy, enemy1->fx);	// フィールドのアドレスを取得
	*map1 = ' ';
	map2 = GetMapAdr(enemy2->fy, enemy2->fx);	// フィールドのアドレスを取得
	*map2 = ' ';
	map3 = GetMapAdr(enemy3->fy, enemy3->fx);	// フィールドのアドレスを取得
	*map3 = ' ';
	map4 = GetMapAdr(enemy4->fy, enemy4->fx);	// フィールドのアドレスを取得
	*map4 = ' ';


	/* エネミーの位置判定 */
	old_x = enemy->fx;
	old_y = enemy->fy;

	old1_x = enemy1->fx;
	old1_y = enemy1->fy;

	old2_x = enemy2->fx;
	old2_y = enemy2->fy;

	old3_x = enemy3->fx;
	old3_y = enemy3->fy;

	old4_x = enemy4->fx;
	old4_y = enemy4->fy;

	if (enemy->HP < 0)
	{
		flag1 += 1;
	}

	if (enemy1->HP < 0)
	{
		flag2 += 1;
	}

	if (enemy2->HP < 0)
	{
		flag3 += 1;
	}

	if (enemy3->HP < 0)
	{
		flag4 += 1;
	}

	if (enemy4->HP < 0)
	{
		flag5 += 1;
	}


	// エネミーの移動処理


	/*  エネミー(0)の移動先をランダムで決定する。  */
	if (flag1 == 0) 
	{
		key = rand() % (9 + 1);

		switch (key)
		{
		case 1:
		case 5:
			enemy->fx--;     //左に移動する。
			break;

		case 2:
		case 6:
			enemy->fx++;     //右に移動する。
			break;

		case 3:
		case 7:
			enemy->fy--;     //上に移動する。
			break;

		case 4:
		case 8:
			enemy->fy++;     //下に移動する。
			break;

		case 9:
		default:           //移動しない。
			break;
		}
	}
	/*  エネミー(1)の移動先をランダムで決定する。  */
	if (flag2 == 0)
	{
		key1 = rand() % (9 + 1);

		switch (key1)
		{
		case 1:
		case 5:
			enemy1->fx--;     //左に移動する。
			break;

		case 2:
		case 6:
			enemy1->fx++;     //右に移動する。
			break;

		case 3:
		case 7:
			enemy1->fy--;     //上に移動する。
			break;

		case 4:
		case 8:
			enemy1->fy++;     //下に移動する。
			break;

		case 9:
		default:           //移動しない。
			break;
		}
	}

	/*  エネミー(2)の移動先をランダムで決定する。  */
	if (flag3 == 0)
	{

		key2 = rand() % (9 + 1);

		switch (key2)
		{
		case 1:
		case 5:
			enemy2->fx--;     //左に移動する。
			break;

		case 2:
		case 6:
			enemy2->fx++;     //右に移動する。
			break;

		case 3:
		case 7:
			enemy2->fy--;     //上に移動する。
			break;

		case 4:
		case 8:
			enemy2->fy++;     //下に移動する。
			break;

		case 9:
		default:           //移動しない。
			break;
		}
	}
	/*  エネミー(3)の移動先をランダムで決定する。  */
	if (flag4 == 0)
	{

		key3 = rand() % (9 + 1);

		switch (key3)
		{
		case 1:
		case 5:
			enemy3->fx--;     //左に移動する。
			break;

		case 2:
		case 6:
			enemy3->fx++;     //右に移動する。
			break;

		case 3:
		case 7:
			enemy3->fy--;     //上に移動する。
			break;

		case 4:
		case 8:
			enemy3->fy++;     //下に移動する。
			break;

		case 9:
		default:           //移動しない。
			break;
		}
	}

	/*  エネミー(4)の移動先をランダムで決定する。  */
	if (flag5 == 0)
	{
		key4 = rand() % (9 + 1);

		switch (key4)
		{
		case 1:
		case 5:
			//enemy4->fx--;     //左に移動する。
			break;

		case 2:
		case 6:
			//enemy4->fx++;     //右に移動する。
			break;

		case 3:
		case 7:
			//enemy4->fy--;     //上に移動する。
			break;

		case 4:
		case 8:
			//enemy4->fy++;     //下に移動する。
			break;

		case 9:
		default:           //移動しない。
			break;
		}
	}
	else if (flag5 == 1)
	{
		map = GetMapAdr(enemy4->fy, enemy4->fx);	    // フィールドのアドレスを取得
		*map4 = ' ';									//エネミーを消す
	}


	// 移動した先はNGな所？
	map = GetMapAdr(enemy->fy, enemy->fx);				    //エネミーのフィールドのアドレスを取得
	if (*map == '*')
	{	// NGなら移動前の場所に戻す
		enemy->fx = old_x;
		enemy->fy = old_y;
	}

	map1 = GetMapAdr(enemy1->fy, enemy1->fx);				//エネミー 1 のフィールドのアドレスを取得
	if (*map1 == '*')
	{	// NGなら移動前の場所に戻す
		enemy1->fx = old1_x;
		enemy1->fy = old1_y;
	}

	map2 = GetMapAdr(enemy2->fy, enemy2->fx);				//エネミー 2 のフィールドのアドレスを取得
	if (*map2 == '*')
	{	// NGなら移動前の場所に戻す
		enemy2->fx = old2_x;
		enemy2->fy = old2_y;
	}

	map3 = GetMapAdr(enemy3->fy, enemy3->fx);				//エネミー 3 のフィールドのアドレスを取得
	if (*map3 == '*')
	{	// NGなら移動前の場所に戻す
		enemy3->fx = old3_x;
		enemy3->fy = old3_y;
	}

	map4 = GetMapAdr(enemy4->fy, enemy4->fx);				//エネミー 4 のフィールドのアドレスを取得
	if (*map4 == '*')
	{	// NGなら移動前の場所に戻す
		enemy4->fx = old4_x;
		enemy4->fy = old4_y;
	}

	//エネミーもDirect Xではここでアニメーションの更新処理を行う。

}


/*******************************************************************************
関数名:	void DrawEnemy( void )
引数:	void
戻り値:	void
説明:	エネミーの描画処理
*******************************************************************************/
void DrawEnemy(void)
{
	ENEMY *enemy = GetEnemyAdr(0);
	ENEMY *enemy1 = GetEnemyAdr(1);
	ENEMY *enemy2 = GetEnemyAdr(2);
	ENEMY *enemy3 = GetEnemyAdr(3);
	ENEMY *enemy4 = GetEnemyAdr(4);

	char *map = GetMapAdr(enemy->fy, enemy->fx);
	char *map1 = GetMapAdr(enemy1->fy, enemy1->fx);
	char *map2 = GetMapAdr(enemy2->fy, enemy2->fx);
	char *map3 = GetMapAdr(enemy3->fy, enemy3->fx);
	char *map4 = GetMapAdr(enemy4->fy, enemy4->fx);


	/* エネミーの位置更新 */
	if (flag1 == 0)
	{
		*map = 'K';
	}
	else if (flag1 == 1)
	{
		*map = ' ';
	}
	if (flag2 == 0)
	{
		*map1 = 'S';
	}
	else if (flag2 == 1)
	{
		*map1 = ' ';
	}
	if (flag3 == 0)
	{
		*map2 = 'W';
	}
	else if (flag3 == 1)
	{
		*map2 = ' ';
	}
	if (flag4 == 0)
	{
		*map3 = 'D';
	}
	else if (flag4 == 1)
	{
		*map3 = ' ';
	}
	if (flag5 == 0)
	{
		*map4 = 'B';
	}
	else if (flag5 == 1)
	{
		*map4 = ' ';
	}




}


/*******************************************************************************
関数名:	void UninitEnemy( void )
引数:	void
戻り値:	void
説明:	エネミーの終了処理
*******************************************************************************/
void UninitEnemy(void)
{
	//いまのところなし
}


//*************************************************************
//
//*************************************************************
ENEMY *GetEnemyAdr(int pno)
{
	return &enemy[pno];
}

