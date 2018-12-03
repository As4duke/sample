/*******************************************************************************
* タイトル:		評価課題 RPGゲーム
* プログラム名:	battle_1.cpp
* 作成者:		GP11B-341 29 益子　聖渚
* 作成日:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "battle_1.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Ending.h"
#include "Gameover.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/

// 戦闘画面時行動選択用
#define TH_MAX      (5)        // 縦幅
#define TW_MAX      (30)        // 横幅

/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/

int a = 0;					  //行動選択の判定値
int o = 0;                    //whileから抜け出すための変数
int p = 0;                    //同上
char choice[TH_MAX][TW_MAX + 1] = {
	"**+**",
	"*   *         Normal_Attack",
	"+   -         Strong_Attack",
	"*   *           R   U   N",
	"**-**",
};
int arrow2_x, arrow2_y, old_arrow2_x, old_arrow2_y;
int flag = 0;											//エネミーのヴィジュアル表示の判定値

/*******************************************************************************
 関数名:	Battle_Wolf( void )
 引数:	void
 戻り値:	正常終了: int型の 0
 説明:	メイン関数
*******************************************************************************/
void Battle_Wolf(void)
{
	int round = 1;				//ターン数をカウントして入れておく変数
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy2 = GetEnemyAdr(2);

	system("cls");


	flag = 2;


	//kokokara
	while (1)
	{
		int damage = 0;								//プレイヤーの攻撃力を入れる
		int damage2 = 0;							//エネミーの攻撃力を入れる

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// 画面クリア
		system("cls");
		switch (a)
		{
		case 1:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK );			// damage = 攻撃力に元ずくダメージ
			damage += (player->status.ATK / 2);
			enemy2->HP -= damage;														// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた!\n", &player->status.name[0], &enemy2->name[2], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy2->HP <= 0)
			{
				player->status.EXP += enemy2->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy2->name[2]);
			damage2 = rand() % (enemy2->ATK + (enemy2->ATK / 2));			// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy2->ATK / 2);
			player->status.HP -= damage2;								// 相手のHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy2->name[2], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;

			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		case 2:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = 攻撃力に元ずくダメージ
			damage += player->status.ATK;
			enemy2->HP -= damage;										// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &player->status.name[0], &enemy2->name[2], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy2->HP <= 0)
			{
				player->status.EXP += enemy2->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy2->name[2]);
			damage2 = rand() % (enemy2->ATK + 1);						// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy2->ATK / 2);
			player->status.HP -= damage2;								// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy2->name[2], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%sは回り込まれてしまった!\n", &player->status.name[0]);
			// 全員分行動したら１ターン終了
			//printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		}
		if (b == 1)
		{
			break;
		}
	}

		
}
/*******************************************************************************
関数名:	Battle_Slime( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/
void Battle_Slime(void)
{
	int round = 1;				//ターン数をカウントして入れておく変数
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy1 = GetEnemyAdr(1);

	system("cls");


	flag = 1;


	//kokokara
	while (1)
	{
		int damage = 0;								//プレイヤーの攻撃力を入れる
		int damage2 = 0;							//エネミーの攻撃力を入れる

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// 画面クリア
		system("cls");
		switch (a)
		{
		case 1:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = 攻撃力に元ずくダメージ
			damage += (player->status.ATK / 2);
			enemy1->HP -= damage;
			printf("%sは%sに%dのダメージを与えた!\n", &player->status.name[0], &enemy1->name[1], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy1->HP <= 0)
			{
				player->status.EXP += enemy1->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy1->name[1]);
			damage2 = rand() % (enemy1->ATK + (enemy1->ATK / 2));			// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy1->ATK / 2);
			player->status.HP -= damage2;								// 相手のHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy1->name[1], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;

			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		case 2:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = 攻撃力に元ずくダメージ
			damage += player->status.ATK;
			enemy1->HP -= damage;										// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &player->status.name[0], &enemy1->name[1], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy1->HP <= 0)
			{
				player->status.EXP += enemy1->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy1->name[1]);
			damage2 = rand() % (enemy1->ATK + 1);						// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy1->ATK / 2);
			player->status.HP -= damage2;								// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy1->name[1], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%sは回り込まれてしまった!\n", &player->status.name[0]);
			// 全員分行動したら１ターン終了
			//printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		}
		if (b == 1)
		{
			break;
		}
	}
	
}
/*******************************************************************************
関数名:	Battle_Dragon( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/
void Battle_Dragon(void)
{
	int round = 1;				//ターン数をカウントして入れておく変数
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy3 = GetEnemyAdr(3);

	system("cls");


	flag = 4;


	//kokokara
	while (1)
	{
		int damage = 0;								//プレイヤーの攻撃力を入れる
		int damage2 = 0;							//エネミーの攻撃力を入れる

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// 画面クリア
		system("cls");
		switch (a)
		{
		case 1:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = 攻撃力に元ずくダメージ
			damage += (player->status.ATK / 2);
			enemy3->HP -= damage;														// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた!\n", &player->status.name[0], &enemy3->name[3], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy3->HP <= 0)
			{
				player->status.EXP += enemy3->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy3->name[3]);
			damage2 = rand() % (enemy3->ATK + (enemy3->ATK / 2));			// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy3->ATK / 2);
			player->status.HP -= damage2;									// 相手のHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy3->name[3], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;

			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		case 2:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = 攻撃力に元ずくダメージ
			damage += player->status.ATK;
			enemy3->HP -= damage;										// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &player->status.name[0], &enemy3->name[3], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy3->HP <= 0)
			{
				player->status.EXP += enemy3->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy3->name[3]);
			damage2 = rand() % (enemy3->ATK + 1);						// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy3->ATK / 2);
			player->status.HP -= damage2;								// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy3->name[3], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%sは回り込まれてしまった!\n", &player->status.name[0]);
			// 全員分行動したら１ターン終了
			//printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		}
		if (b == 1)
		{
			break;
		}
	}

}
/*******************************************************************************
関数名:	Battle_Boss( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/
void Battle_Boss(void)
{
	int round = 1;				//ターン数をカウントして入れておく変数
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy4 = GetEnemyAdr(4);

	system("cls");


	flag = 5;

	//kokokara
	while (1)
	{
		int damage = 0;								//プレイヤーの攻撃力を入れる
		int damage2 = 0;							//エネミーの攻撃力を入れる

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// 画面クリア
		system("cls");
		switch (a)
		{
		case 1:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = 攻撃力に元ずくダメージ
			damage += (player->status.ATK / 2);
			enemy4->HP -= damage;														// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた!\n", &player->status.name[0], &enemy4->name[4], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy4->HP <= 0)
			{
				player->status.EXP += enemy4->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				DrawEnding();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy4->name[4]);
			damage2 = rand() % (enemy4->ATK + (enemy4->ATK / 2));			// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy4->ATK / 2);
			player->status.HP -= damage2;								// 相手のHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy4->name[0], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;

			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		case 2:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = 攻撃力に元ずくダメージ
			damage += player->status.ATK;
			enemy4->HP -= damage;										// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &player->status.name[0], &enemy4->name[4], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy4->HP <= 0)
			{
				player->status.EXP += enemy4->EXP;
				printf("\n%sの勝利！\n", &player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				DrawEnding();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n", &enemy4->name[4]);
			damage2 = rand() % (enemy4->ATK + 1);						// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy4->ATK / 2);
			player->status.HP -= damage2;								// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &enemy4->name[4], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%sは回り込まれてしまった!\n", &player->status.name[0]);
			// 全員分行動したら１ターン終了
			//printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		}
		if (b == 1)
		{
			break;
		}
	}

}

/*******************************************************************************
関数名:	battle_Knight( void )
引数:	void
戻り値:	正常終了: int型の 0
説明:	メイン関数
*******************************************************************************/
void Battle_Knight(void)
{

	int round = 1;				//ターン数をカウントして入れておく変数
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy = GetEnemyAdr(0);

	system("cls");



	flag = 3;

	//kokokara
	while (1)
	{
		int damage = 0;								//プレイヤーの攻撃力を入れる
		int damage2 = 0;							//エネミーの攻撃力を入れる

		printf("\n                    HP : %d",player->status.HP);
		DrawBattleDisplay();

		// 画面クリア
		system("cls");
		switch (a)
		{
		case 1:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = 攻撃力に元ずくダメージ
			damage += (player->status.ATK / 2);
			enemy->HP -= damage;														// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた!\n", &player->status.name[0],&enemy->name[0], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy->HP <= 0)
			{
				player->status.EXP += enemy->EXP;
				printf("\n%sの勝利！\n",&player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n",&enemy->name[0]);
			damage2 = rand() % (enemy->ATK + (enemy->ATK / 2));			// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy->ATK / 2);
			player->status.HP -= damage2;								// 相手のHPを減らす
			printf("%sは%sに%dのダメージを与えた\n",&enemy->name[0], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;

			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		case 2:
			// プレイヤーがエネミーを攻撃する処理
			printf("%sの攻撃！\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = 攻撃力に元ずくダメージ
			damage += player->status.ATK;
			enemy->HP -= damage;										// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n", &player->status.name[0], &enemy->name[0], damage);
			//draw_enemy();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// エネミー死んだかチェック
			if (enemy->HP <= 0)
			{
				player->status.EXP += enemy->EXP;
				printf("\n%sの勝利！\n",&player->status.name[0]);
				b++;
				// キー入力待ち
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// エネミーがプレイヤーを攻撃する処理
			printf("%sの攻撃！\n",&enemy->name[0]);
			damage2 = rand() % (enemy->ATK + 1);						// damage2 = 攻撃力に元ずくダメージ
			damage2 += (enemy->ATK / 2);
			player->status.HP -= damage2;								// エネミーのHPを減らす
			printf("%sは%sに%dのダメージを与えた\n",&enemy->name[0], &player->status.name[0], damage2);
			//draw_player();

			// キー入力待ち
			rewind(stdin);
			_getch();

			// プレイヤー死んだかチェック
			if (player->status.HP <= 0)
			{
				printf("%sはやられてしまった！\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// 全員分行動したら１ターン終了
			printf("\n%dターン経過\n", round);
			round++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%sは回り込まれてしまった!\n",&player->status.name[0]);
			// 全員分行動したら１ターン終了
			//printf("\n%dターン経過\n", round);
			round++;
			b++;
			// キー入力待ち
			rewind(stdin);
			_getch();
			break;
		}
		if (b == 1)
		{
			break;
		}
	}
}

//kokomade
//***********************************************
//*			戦闘画面表示関数	
//***********************************************
void DrawBattleDisplay(void)
{
	/* 前回の表示位置の消去*/
	choice[arrow2_y][arrow2_x] = ' ';
	BattleDisplay_arrow();          //アローの初期化処理
	DrawBattleDisplayBG();          // BG描画 (背景描画)

	o = 0;							//ループ脱出用変数

	while (1)
	{

		// 何かキー入力があったら処理を行う
		if (_kbhit())
		{
			// 各種更新処理
			UpdateBattleDisplay_arrow();    // アローの更新処理

			DrawBattleDisplayArrow();	    // アローを描画する為に位置をセット
			DrawBattleDisplayBG();			// BG描画 (背景描画)

			
		}
		if (o > p)							//ループ脱出用変数処理
		{
			break;
		}

		/* 処理速度調整 */
		Sleep(30);
	}



}
/*******************************************************************************
関数名:	void BattleDisplay_arrow( void )
引数:	void
戻り値:	void
説明:	アローの初期化処理
*******************************************************************************/
void BattleDisplay_arrow(void)
{
	/* アローの初期位置設定 */
	arrow2_x = 2;
	arrow2_y = 1;
	choice[arrow2_y][arrow2_x] = '>';

	//本当はここのところでパラメーターの設定も行う

}
/*******************************************************************************
関数名:	void UpdateBattleDisplay_arrow( void )
引数:	void
戻り値:	void
説明:	アローの更新処理
*******************************************************************************/
void UpdateBattleDisplay_arrow(void)
{
	int key;
	int old_arrow2_x, old_arrow2_y;

	/* キーが入力されたら */
	key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}

	/* 前回の表示位置の消去*/
	choice[arrow2_y][arrow2_x] = ' ';

	/* プレイヤーの位置判定 */
	old_arrow2_x = arrow2_x;
	old_arrow2_y = arrow2_y;
	switch (key)
	{

	case 's':
	case 0x50:	// 下へ移動する
		arrow2_y++;
		break;

	case 'w':
	case 0x48:	// 上へ移動する
		arrow2_y--;
		break;

	case VK_RETURN:	// 決定
	{
		SelectCommand();
	}
	break;

	default:	// 移動しない
		break;
	}

	// 移動した先は上限界
	if (choice[arrow2_y][arrow2_x] == '+')
	{	// +なら下に
		arrow2_x = 2;
		arrow2_y = 3;
	}

	// 移動した先が下限界
	if (choice[arrow2_y][arrow2_x] == '-')
	{	// -なら上に移動させる
		arrow2_x = 2;
		arrow2_y = 1;
	}


}
/*******************************************************************************
関数名:	void DrawArrow( void )
引数:	void
戻り値:	void
説明:	プレイヤーの描画処理
*******************************************************************************/
void DrawBattleDisplayArrow(void)
{
	/* プレイヤーの位置更新 */
	choice[arrow2_y][arrow2_x] = '>';

}
/*******************************************************************************
関数名:	void DrawBattleDisplayBG( void )
引数:	void
戻り値:	void
説明:	BG表示 ( BG = バックグラウンド・背景の略だよ )
*******************************************************************************/
void DrawBattleDisplayBG(void)
{
	int i;

	PLAYER *player = GetPlayerAdr(0);							//プレイヤーのアドレスを取得
	ENEMY *enemy = GetEnemyAdr(0);								//エネミー(0)のアドレスを取得
	ENEMY *enemy1 = GetEnemyAdr(1);								//エネミー(1)のアドレスを取得
	ENEMY *enemy2 = GetEnemyAdr(2);								//エネミー(2)のアドレスを取得
	ENEMY *enemy3 = GetEnemyAdr(3);								//エネミー(3)のアドレスを取得
	ENEMY *enemy4 = GetEnemyAdr(4);								//エネミー(4)のアドレスを取得


	/* 画面クリア */
	system("cls");

	printf("\n                                     %s",&player->status.name[0]);
	printf("\n\n                                   HP : %d\n",player->status.HP);
	printf("________________________________________________________________________________\n");

	if (flag == 1)
	{
		printf("                                      ∩\n");
		printf("                                     ノヽ\n");
		printf("                                   ／　　＼\n");
		printf("                                  / (･)(･)∧\n");
		printf("                                 ｜(ヽ＿ノ)｜\n");
		printf("                                  ＼二二二／\n\n");
		printf("                                   %s\n", &enemy1->name[1]);

	}
	if (flag == 2)
	{
		printf("                                   (＼＿_／)\n");
		printf("                                    > ｡　｡<\n");
		printf("                                   (　 ヾヽヽ\n");
		printf("                                   / ＼＿▼ノ\n");
		printf("                                  ｜ (ﾟДﾟ)\n");
		printf("                                  ｜(ﾉ　 |)\n");
		printf("                                ＜人　ノノ\n");
		printf("                                    ∪ ∪\n\n");
		printf("                                   %s\n", &enemy2->name[2]);

	}
	if (flag == 3)
	{
		printf("                                    ､_ゞヽ|\n");
		printf("                                    νγγ￣ヽ_\n");
		printf("                                   `´ ﾉ""゛＿ゝ\n");
		printf("                               γ⌒ヽノ　ＧｲIIII)／/\n");
		printf("                            /　 〟ヽノヾ::::／／ヽ\n");
		printf("                             ＼＿＿ﾉ`ヽ_ニﾆ／∠ゝ::\n");
		printf("                             `/＿/:.〝 .:／／|L_L|:\n");
		printf("                             `＼￣＼＿､∠∠､ノ((uE}\n");
		printf("                                ＼√/Lミ}￣T｜::::: \n");
		printf("                                  `ﾆ∠／―´)ヾ:::ﾉ\n");
		printf("                                   %s\n", &enemy->name[0]);

	}
	if (flag == 4)
	{
		printf("\n");
		printf("                           　　 　,ｲ　_lＶi__, i \n");
		printf("                            　　.／/'＼>_ﾟvw>＼ \n");
		printf("                           　　/⌒Y´ﾞ/ i⌒〉Y⌒ヽ\n");
		printf("                           .　　＿___ノ(,,j.　{,) \n");
		printf("                          　　 ＼＿ゝ　)ノ)\n");
		printf("                          　 　 　　ヽm'ヽm\n\n");
		printf("                                   %s\n", &enemy3->name[3]);

	}
	if (flag == 5)
	{
		printf("                      -‐ = ＝ = ‐ - ミ、\n");
		printf("                   ／　　　　 　 　      　 ＼\n");
		printf("                  /              ´, , ⌒ヾ､_＿＼＿__　_＿　 __\n");
		printf("                〃^ｰ: 　 　      { {　◯━━‥…━…‥━…　…━\n");
		printf("                {{ ____｣[__　    　乂_____彡 ´￣￣|￣￣　 ￣￣　　￣￣\n");
		printf("               / ＾￢ゥ‐ｚT　匸Τ匸了＾7厂￣＼_\n");
		printf("               ＼ 弋__{ __ | ___ | __,ﾉ^¨ﾟ´ 　′ ィ⌒’ }i\n");
		printf("                 ｀ 、　　　　　　　 　      イ⌒　　　 八\n");
		printf("                     .＞‐ == = ‐ｚ:     ∠二ア⌒　　　冫\n");
		printf("                   . {￣｀¨7､__,ﾉ_.    ∠二二二 __　　 ′\n");
		printf("                                   %s\n", &enemy4->name[4]);
	}

	
	printf("________________________________________________________________________________\n");
	/* コマンド画面描画処理 */
	printf("\n\n\n");
	for (i = 0; i < TH_MAX; i++)
	{
		printf("                    %s\n", &choice[i][0]);
	}
	/* 処理速度調整 */
	Sleep(10);
}

/*******************************************************************************
関数名:	void SelectCommand( void )
引数:	void
戻り値:	void
説明:	プレイヤーの描画処理
*******************************************************************************/
void SelectCommand(void)
{
	switch (arrow2_y)
	{
	case 1:
		//printf("\n\n                              ");

		a = 1;
		o++;

		break;
	case 2:
		//printf("\n\n                              ");

		a = 2;
		o++;

		break;
	case 3:

		a = 3;
		o++;

		break;
	default:
		break;
	}
}
