/*******************************************************************************
* タイトル:		評価課題 RPGゲーム
* プログラム名:	Enemy.h
* 作成者:		GP11B-341 29 益子　聖渚
* 作成日:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* main.h	メインヘッダーファイル
*******************************************************************************/
#ifndef	ENEMY_H
#define	ENEMY_H

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/

/*******************************************************************************
* マクロ定義
*******************************************************************************/

#define ENEMY_MAX   (5)				//エネミーの人数
#define NAME_MAX   (256)			//エネミーの名前の最大値


/*******************************************************************************
* 構造体定義
*******************************************************************************/
typedef struct					// キャラクターの基本構造体
{
	char name[NAME_MAX];			//エネミーの名前
	int   HP;						//エネミーの体力
	int  ATK;						//エネミーの攻撃力
	int  EXP;						//エネミーから得られる経験値
	int   fx;						// フィールドX座標
	int   fy;						// フィールドY座標

} ENEMY;


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void InitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void UninitEnemy(void);

ENEMY *GetEnemyAdr(int pno);


#endif
