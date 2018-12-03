/*******************************************************************************
* タイトル:		評価課題 RPGゲーム
* プログラム名:	BG.h
* 作成者:		GP11B-341 29 益子　聖渚
* 作成日:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* main.h	メインヘッダーファイル
*******************************************************************************/
#ifndef	BG_H
#define	BG_H

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

// フィールド用
#define FH_MAX      (15)        // 縦幅
#define FW_MAX      (80)        // 横幅

/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void InitBG(void);
void UpdataBG(void);
void DrawBG(void);
void UninitBG(void);
char *GetMapAdr(int y, int x);

#endif
