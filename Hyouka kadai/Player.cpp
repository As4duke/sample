/*******************************************************************************
* タイトル:		評価課題 RPGゲーム
* プログラム名:	Player.cpp
* 作成者:		GP11B-341 29 益子　聖渚
* 作成日:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "Player.h"
#include "BG.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/

#define PLAYER_MAX   (1)				//プレイヤーの人数

/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/

PLAYER player[PLAYER_MAX];          //プレイヤー

/*******************************************************************************
関数名:	InitPlayer( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/

void InitPlayer(void)
{

	PLAYER *player = GetPlayerAdr(0);			//プレイヤー( ) のアドレスを取得する
	char *map;

	/* プレイヤーの初期位置設定 */
	player->fx = 1;
	player->fy = 1;

	map = GetMapAdr(player->fy, player->fx);	// フィールドのアドレスを取得
	*map = 'P';								// プレイヤー記号を書き込む

	//本当はここのところでパラメーターの設定も行う

	player->status.HP = 100;					//現在のHP
	player->status.HP_MAX = 100;				//現在の最大HP
	player->status.MP = 20;						//現在のMP			(未実装）
	player->status.MP_MAX = 20;					//現在の最大MP		(未実装）
	player->status.name[32];					//主人公の名前
	player->status.ATK = 15;					//現在の攻撃力
	player->status.DEF = 10;					//現在の守備力		(未実装）
	player->status.SPD = 10;					//現在の行動優先値	(未実装）
	player->status.EXP =  0;					//現在の経験値
	player->status.LV  =  1;					//現在のレベル
	player->status.GOLD = 0;					//現在の所持金		(未実装）

}

/*******************************************************************************
関数名:	void UpdatePlayer( void )
引数:	void
戻り値:	void
説明:	プレイヤーの更新処理
*******************************************************************************/
void UpdatePlayer(void)
{
	int key;
	int old_x, old_y;
	PLAYER *player = GetPlayerAdr(0);
	char *map;

	/* キーが入力されたら */
	key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}

	/* 前回の表示位置の消去*/
	map = GetMapAdr(player->fy, player->fx);	// フィールドのアドレスを取得
	*map = ' ';

	/* プレイヤーの位置判定 */
	old_x = player->fx;
	old_y = player->fy;
	switch (key)
	{
	case 'a':
	case 0x4b:	// 左へ移動する
		player->fx--;
		break;

	case 'd':
	case 0x4d:	// 右へ移動する
		player->fx++;
		break;

	case 'w':
	case 0x48:	// 上へ移動する
		player->fy--;
		break;

	case 's':
	case 0x50:	// 下へ移動する
		player->fy++;
		break;

	default:	// 移動しない
		break;
	}

	// 移動した先はNGな所？
	map = GetMapAdr(player->fy, player->fx);				//フィールドのアドレスを取得
	if (*map == '*')
	{	// NGなら移動前の場所に戻す
		player->fx = old_x;
		player->fy = old_y;
	}
	//DirectXでは、アニメーションの更新処理も行う

	if ((player->status.EXP >= 10) && (player->status.LV == 1))
	{
		int old_HP  = 0;					//現在の最大HPを入れておく変数
		int old_ATK = 0;					//現在の最大攻撃力を入れておく変数
		int old_LV = 0;						//現在のレベルを入れておく変数

		old_HP = player->status.HP_MAX;		//現在の最大HPを入れておく
		old_ATK = player->status.ATK;		//現在の最大攻撃力を入れておく
		old_LV = player->status.LV;			//現在のレベルを入れておく


		player->status.HP_MAX += 400;					//ステータスアップ
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HPを回復

		player->status.ATK +=     50;					//ステータスアップ
		player->status.LV  +=      1;					//ステータスアップ
		

		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("レベルアップ!!");
		// キー入力待ち
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%sの LV が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_LV, player->status.LV);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの HP が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ",old_HP,player->status.HP);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの ATK が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_ATK, player->status.ATK);		//ステータスアップ

		// キー入力待ち
		rewind(stdin);
		_getch();

		system("cls");


	}
	if ((player->status.EXP >= 100) && (player->status.LV == 2))
	{
		int old_HP = 0;						//現在の最大HPを入れておく変数
		int old_ATK = 0;					//現在の最大攻撃力を入れておく変数
		int old_LV = 0;						//現在のレベルを入れておく変数

		old_HP = player->status.HP_MAX;		//現在の最大HPを入れておく
		old_ATK = player->status.ATK;		//現在の最大攻撃力を入れておく
		old_LV = player->status.LV;			//現在のレベルを入れておく


		player->status.HP_MAX += 1000;					//ステータスアップ
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HPを回復

		player->status.ATK += 135;					//ステータスアップ
		player->status.LV += 1;						//ステータスアップ


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("レベルアップ!!");
		// キー入力待ち
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%sの LV が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_LV, player->status.LV);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの HP が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_HP, player->status.HP);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの ATK が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_ATK, player->status.ATK);		//ステータスアップ

		// キー入力待ち
		rewind(stdin);
		_getch();


		system("cls");

	}
	if ((player->status.EXP >= 1000) && (player->status.LV == 3))
	{
		int old_HP = 0;					//現在の最大HPを入れておく変数
		int old_ATK = 0;					//現在の最大攻撃力を入れておく変数
		int old_LV = 0;						//現在のレベルを入れておく変数

		old_HP = player->status.HP_MAX;		//現在の最大HPを入れておく
		old_ATK = player->status.ATK;		//現在の最大攻撃力を入れておく
		old_LV = player->status.LV;			//現在のレベルを入れておく


		player->status.HP_MAX += 3000;					//ステータスアップ
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HPを回復

		player->status.ATK += 300;					//ステータスアップ
		player->status.LV +=    1;					//ステータスアップ


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("レベルアップ!!");
		// キー入力待ち
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%sの LV が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_LV, player->status.LV);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの HP が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_HP, player->status.HP);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの ATK が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_ATK, player->status.ATK);		//ステータスアップ

																// キー入力待ち
		rewind(stdin);
		_getch();

		system("cls");


	}
	if ((player->status.EXP >= 10000) && (player->status.LV == 4))
	{
		int old_HP = 0;					//現在の最大HPを入れておく変数
		int old_ATK = 0;					//現在の最大攻撃力を入れておく変数
		int old_LV = 0;						//現在のレベルを入れておく変数

		old_HP = player->status.HP_MAX;		//現在の最大HPを入れておく
		old_ATK = player->status.ATK;		//現在の最大攻撃力を入れておく
		old_LV = player->status.LV;			//現在のレベルを入れておく


		player->status.HP_MAX += 4500;					//ステータスアップ
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HPを回復

		player->status.ATK += 500;					//ステータスアップ
		player->status.LV += 1;					//ステータスアップ


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("レベルアップ!!");
		// キー入力待ち
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%sの LV が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_LV, player->status.LV);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの HP が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_HP, player->status.HP);			//ステータスアップ

		printf("\n\n                             ");
		printf("%sの ATK が上がった!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d → %d ", old_ATK, player->status.ATK);		//ステータスアップ

																// キー入力待ち
		rewind(stdin);
		_getch();

		system("cls");
	}


}
/*******************************************************************************
関数名:	void DrawPlayer( void )
引数:	void
戻り値:	void
説明:	プレイヤーの描画処理
*******************************************************************************/
void DrawPlayer(void)
{

	PLAYER *player = GetPlayerAdr(0);
	char *map = GetMapAdr(player->fy, player->fx);

	/* プレイヤーの位置更新 */
	*map = 'P';

}
/*******************************************************************************
関数名:	void UninitPlayer( void )
引数:	void
戻り値:	void
説明:	プレイヤーの終了処理
*******************************************************************************/
void UninitPlayer(void)
{
//いまのとこなし
}

//******************************************************
//
//******************************************************
PLAYER *GetPlayerAdr(int pno)
{
	return &player[pno];
}
