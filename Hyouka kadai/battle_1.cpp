/*******************************************************************************
* �^�C�g��:		�]���ۑ� RPG�Q�[��
* �v���O������:	battle_1.cpp
* �쐬��:		GP11B-341 29 �v�q�@����
* �쐬��:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "battle_1.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Ending.h"
#include "Gameover.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/

// �퓬��ʎ��s���I��p
#define TH_MAX      (5)        // �c��
#define TW_MAX      (30)        // ����

/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

int a = 0;					  //�s���I���̔���l
int o = 0;                    //while���甲���o�����߂̕ϐ�
int p = 0;                    //����
char choice[TH_MAX][TW_MAX + 1] = {
	"**+**",
	"*   *         Normal_Attack",
	"+   -         Strong_Attack",
	"*   *           R   U   N",
	"**-**",
};
int arrow2_x, arrow2_y, old_arrow2_x, old_arrow2_y;
int flag = 0;											//�G�l�~�[�̃��B�W���A���\���̔���l

/*******************************************************************************
 �֐���:	Battle_Wolf( void )
 ����:	void
 �߂�l:	����I��: int�^�� 0
 ����:	���C���֐�
*******************************************************************************/
void Battle_Wolf(void)
{
	int round = 1;				//�^�[�������J�E���g���ē���Ă����ϐ�
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy2 = GetEnemyAdr(2);

	system("cls");


	flag = 2;


	//kokokara
	while (1)
	{
		int damage = 0;								//�v���C���[�̍U���͂�����
		int damage2 = 0;							//�G�l�~�[�̍U���͂�����

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// ��ʃN���A
		system("cls");
		switch (a)
		{
		case 1:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK );			// damage = �U���͂Ɍ������_���[�W
			damage += (player->status.ATK / 2);
			enemy2->HP -= damage;														// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����!\n", &player->status.name[0], &enemy2->name[2], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy2->HP <= 0)
			{
				player->status.EXP += enemy2->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy2->name[2]);
			damage2 = rand() % (enemy2->ATK + (enemy2->ATK / 2));			// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy2->ATK / 2);
			player->status.HP -= damage2;								// �����HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy2->name[2], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;
		case 2:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = �U���͂Ɍ������_���[�W
			damage += player->status.ATK;
			enemy2->HP -= damage;										// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &player->status.name[0], &enemy2->name[2], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy2->HP <= 0)
			{
				player->status.EXP += enemy2->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy2->name[2]);
			damage2 = rand() % (enemy2->ATK + 1);						// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy2->ATK / 2);
			player->status.HP -= damage2;								// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy2->name[2], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%s�͉�荞�܂�Ă��܂���!\n", &player->status.name[0]);
			// �S�����s��������P�^�[���I��
			//printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
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
�֐���:	Battle_Slime( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/
void Battle_Slime(void)
{
	int round = 1;				//�^�[�������J�E���g���ē���Ă����ϐ�
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy1 = GetEnemyAdr(1);

	system("cls");


	flag = 1;


	//kokokara
	while (1)
	{
		int damage = 0;								//�v���C���[�̍U���͂�����
		int damage2 = 0;							//�G�l�~�[�̍U���͂�����

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// ��ʃN���A
		system("cls");
		switch (a)
		{
		case 1:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = �U���͂Ɍ������_���[�W
			damage += (player->status.ATK / 2);
			enemy1->HP -= damage;
			printf("%s��%s��%d�̃_���[�W��^����!\n", &player->status.name[0], &enemy1->name[1], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy1->HP <= 0)
			{
				player->status.EXP += enemy1->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy1->name[1]);
			damage2 = rand() % (enemy1->ATK + (enemy1->ATK / 2));			// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy1->ATK / 2);
			player->status.HP -= damage2;								// �����HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy1->name[1], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;
		case 2:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = �U���͂Ɍ������_���[�W
			damage += player->status.ATK;
			enemy1->HP -= damage;										// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &player->status.name[0], &enemy1->name[1], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy1->HP <= 0)
			{
				player->status.EXP += enemy1->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy1->name[1]);
			damage2 = rand() % (enemy1->ATK + 1);						// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy1->ATK / 2);
			player->status.HP -= damage2;								// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy1->name[1], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%s�͉�荞�܂�Ă��܂���!\n", &player->status.name[0]);
			// �S�����s��������P�^�[���I��
			//printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
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
�֐���:	Battle_Dragon( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/
void Battle_Dragon(void)
{
	int round = 1;				//�^�[�������J�E���g���ē���Ă����ϐ�
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy3 = GetEnemyAdr(3);

	system("cls");


	flag = 4;


	//kokokara
	while (1)
	{
		int damage = 0;								//�v���C���[�̍U���͂�����
		int damage2 = 0;							//�G�l�~�[�̍U���͂�����

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// ��ʃN���A
		system("cls");
		switch (a)
		{
		case 1:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = �U���͂Ɍ������_���[�W
			damage += (player->status.ATK / 2);
			enemy3->HP -= damage;														// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����!\n", &player->status.name[0], &enemy3->name[3], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy3->HP <= 0)
			{
				player->status.EXP += enemy3->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy3->name[3]);
			damage2 = rand() % (enemy3->ATK + (enemy3->ATK / 2));			// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy3->ATK / 2);
			player->status.HP -= damage2;									// �����HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy3->name[3], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;
		case 2:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = �U���͂Ɍ������_���[�W
			damage += player->status.ATK;
			enemy3->HP -= damage;										// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &player->status.name[0], &enemy3->name[3], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy3->HP <= 0)
			{
				player->status.EXP += enemy3->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy3->name[3]);
			damage2 = rand() % (enemy3->ATK + 1);						// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy3->ATK / 2);
			player->status.HP -= damage2;								// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy3->name[3], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%s�͉�荞�܂�Ă��܂���!\n", &player->status.name[0]);
			// �S�����s��������P�^�[���I��
			//printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
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
�֐���:	Battle_Boss( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/
void Battle_Boss(void)
{
	int round = 1;				//�^�[�������J�E���g���ē���Ă����ϐ�
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy4 = GetEnemyAdr(4);

	system("cls");


	flag = 5;

	//kokokara
	while (1)
	{
		int damage = 0;								//�v���C���[�̍U���͂�����
		int damage2 = 0;							//�G�l�~�[�̍U���͂�����

		printf("\n                    HP : %d", player->status.HP);
		DrawBattleDisplay();

		// ��ʃN���A
		system("cls");
		switch (a)
		{
		case 1:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = �U���͂Ɍ������_���[�W
			damage += (player->status.ATK / 2);
			enemy4->HP -= damage;														// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����!\n", &player->status.name[0], &enemy4->name[4], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy4->HP <= 0)
			{
				player->status.EXP += enemy4->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				DrawEnding();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy4->name[4]);
			damage2 = rand() % (enemy4->ATK + (enemy4->ATK / 2));			// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy4->ATK / 2);
			player->status.HP -= damage2;								// �����HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy4->name[0], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;
		case 2:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = �U���͂Ɍ������_���[�W
			damage += player->status.ATK;
			enemy4->HP -= damage;										// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &player->status.name[0], &enemy4->name[4], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy4->HP <= 0)
			{
				player->status.EXP += enemy4->EXP;
				printf("\n%s�̏����I\n", &player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				DrawEnding();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n", &enemy4->name[4]);
			damage2 = rand() % (enemy4->ATK + 1);						// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy4->ATK / 2);
			player->status.HP -= damage2;								// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &enemy4->name[4], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n", &player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%s�͉�荞�܂�Ă��܂���!\n", &player->status.name[0]);
			// �S�����s��������P�^�[���I��
			//printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
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
�֐���:	battle_Knight( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/
void Battle_Knight(void)
{

	int round = 1;				//�^�[�������J�E���g���ē���Ă����ϐ�
	int b = 0;

	PLAYER *player = GetPlayerAdr(0);
	ENEMY *enemy = GetEnemyAdr(0);

	system("cls");



	flag = 3;

	//kokokara
	while (1)
	{
		int damage = 0;								//�v���C���[�̍U���͂�����
		int damage2 = 0;							//�G�l�~�[�̍U���͂�����

		printf("\n                    HP : %d",player->status.HP);
		DrawBattleDisplay();

		// ��ʃN���A
		system("cls");
		switch (a)
		{
		case 1:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK);			// damage = �U���͂Ɍ������_���[�W
			damage += (player->status.ATK / 2);
			enemy->HP -= damage;														// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����!\n", &player->status.name[0],&enemy->name[0], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy->HP <= 0)
			{
				player->status.EXP += enemy->EXP;
				printf("\n%s�̏����I\n",&player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n",&enemy->name[0]);
			damage2 = rand() % (enemy->ATK + (enemy->ATK / 2));			// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy->ATK / 2);
			player->status.HP -= damage2;								// �����HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n",&enemy->name[0], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;

			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;
		case 2:
			// �v���C���[���G�l�~�[���U�����鏈��
			printf("%s�̍U���I\n", &player->status.name[0]);
			damage = rand() % (player->status.ATK + 1);					// damage = �U���͂Ɍ������_���[�W
			damage += player->status.ATK;
			enemy->HP -= damage;										// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n", &player->status.name[0], &enemy->name[0], damage);
			//draw_enemy();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �G�l�~�[���񂾂��`�F�b�N
			if (enemy->HP <= 0)
			{
				player->status.EXP += enemy->EXP;
				printf("\n%s�̏����I\n",&player->status.name[0]);
				b++;
				// �L�[���͑҂�
				rewind(stdin);
				_getch();
				UpdatePlayer();
				break;
			}


			// �G�l�~�[���v���C���[���U�����鏈��
			printf("%s�̍U���I\n",&enemy->name[0]);
			damage2 = rand() % (enemy->ATK + 1);						// damage2 = �U���͂Ɍ������_���[�W
			damage2 += (enemy->ATK / 2);
			player->status.HP -= damage2;								// �G�l�~�[��HP�����炷
			printf("%s��%s��%d�̃_���[�W��^����\n",&enemy->name[0], &player->status.name[0], damage2);
			//draw_player();

			// �L�[���͑҂�
			rewind(stdin);
			_getch();

			// �v���C���[���񂾂��`�F�b�N
			if (player->status.HP <= 0)
			{
				printf("%s�͂���Ă��܂����I\n",&player->status.name[0]);
				DrawGameOver();
				exit(0);
			}

			// �S�����s��������P�^�[���I��
			printf("\n%d�^�[���o��\n", round);
			round++;
			// �L�[���͑҂�
			rewind(stdin);
			_getch();
			break;

		case 3:
			printf("%s�͉�荞�܂�Ă��܂���!\n",&player->status.name[0]);
			// �S�����s��������P�^�[���I��
			//printf("\n%d�^�[���o��\n", round);
			round++;
			b++;
			// �L�[���͑҂�
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
//*			�퓬��ʕ\���֐�	
//***********************************************
void DrawBattleDisplay(void)
{
	/* �O��̕\���ʒu�̏���*/
	choice[arrow2_y][arrow2_x] = ' ';
	BattleDisplay_arrow();          //�A���[�̏���������
	DrawBattleDisplayBG();          // BG�`�� (�w�i�`��)

	o = 0;							//���[�v�E�o�p�ϐ�

	while (1)
	{

		// �����L�[���͂��������珈�����s��
		if (_kbhit())
		{
			// �e��X�V����
			UpdateBattleDisplay_arrow();    // �A���[�̍X�V����

			DrawBattleDisplayArrow();	    // �A���[��`�悷��ׂɈʒu���Z�b�g
			DrawBattleDisplayBG();			// BG�`�� (�w�i�`��)

			
		}
		if (o > p)							//���[�v�E�o�p�ϐ�����
		{
			break;
		}

		/* �������x���� */
		Sleep(30);
	}



}
/*******************************************************************************
�֐���:	void BattleDisplay_arrow( void )
����:	void
�߂�l:	void
����:	�A���[�̏���������
*******************************************************************************/
void BattleDisplay_arrow(void)
{
	/* �A���[�̏����ʒu�ݒ� */
	arrow2_x = 2;
	arrow2_y = 1;
	choice[arrow2_y][arrow2_x] = '>';

	//�{���͂����̂Ƃ���Ńp�����[�^�[�̐ݒ���s��

}
/*******************************************************************************
�֐���:	void UpdateBattleDisplay_arrow( void )
����:	void
�߂�l:	void
����:	�A���[�̍X�V����
*******************************************************************************/
void UpdateBattleDisplay_arrow(void)
{
	int key;
	int old_arrow2_x, old_arrow2_y;

	/* �L�[�����͂��ꂽ�� */
	key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}

	/* �O��̕\���ʒu�̏���*/
	choice[arrow2_y][arrow2_x] = ' ';

	/* �v���C���[�̈ʒu���� */
	old_arrow2_x = arrow2_x;
	old_arrow2_y = arrow2_y;
	switch (key)
	{

	case 's':
	case 0x50:	// ���ֈړ�����
		arrow2_y++;
		break;

	case 'w':
	case 0x48:	// ��ֈړ�����
		arrow2_y--;
		break;

	case VK_RETURN:	// ����
	{
		SelectCommand();
	}
	break;

	default:	// �ړ����Ȃ�
		break;
	}

	// �ړ�������͏���E
	if (choice[arrow2_y][arrow2_x] == '+')
	{	// +�Ȃ牺��
		arrow2_x = 2;
		arrow2_y = 3;
	}

	// �ړ������悪�����E
	if (choice[arrow2_y][arrow2_x] == '-')
	{	// -�Ȃ��Ɉړ�������
		arrow2_x = 2;
		arrow2_y = 1;
	}


}
/*******************************************************************************
�֐���:	void DrawArrow( void )
����:	void
�߂�l:	void
����:	�v���C���[�̕`�揈��
*******************************************************************************/
void DrawBattleDisplayArrow(void)
{
	/* �v���C���[�̈ʒu�X�V */
	choice[arrow2_y][arrow2_x] = '>';

}
/*******************************************************************************
�֐���:	void DrawBattleDisplayBG( void )
����:	void
�߂�l:	void
����:	BG�\�� ( BG = �o�b�N�O���E���h�E�w�i�̗����� )
*******************************************************************************/
void DrawBattleDisplayBG(void)
{
	int i;

	PLAYER *player = GetPlayerAdr(0);							//�v���C���[�̃A�h���X���擾
	ENEMY *enemy = GetEnemyAdr(0);								//�G�l�~�[(0)�̃A�h���X���擾
	ENEMY *enemy1 = GetEnemyAdr(1);								//�G�l�~�[(1)�̃A�h���X���擾
	ENEMY *enemy2 = GetEnemyAdr(2);								//�G�l�~�[(2)�̃A�h���X���擾
	ENEMY *enemy3 = GetEnemyAdr(3);								//�G�l�~�[(3)�̃A�h���X���擾
	ENEMY *enemy4 = GetEnemyAdr(4);								//�G�l�~�[(4)�̃A�h���X���擾


	/* ��ʃN���A */
	system("cls");

	printf("\n                                     %s",&player->status.name[0]);
	printf("\n\n                                   HP : %d\n",player->status.HP);
	printf("________________________________________________________________________________\n");

	if (flag == 1)
	{
		printf("                                      ��\n");
		printf("                                     �m�R\n");
		printf("                                   �^�@�@�_\n");
		printf("                                  / (�)(�)��\n");
		printf("                                 �b(�R�Q�m)�b\n");
		printf("                                  �_����^\n\n");
		printf("                                   %s\n", &enemy1->name[1]);

	}
	if (flag == 2)
	{
		printf("                                   (�_�Q_�^)\n");
		printf("                                    > ��@�<\n");
		printf("                                   (�@ �S�R�R\n");
		printf("                                   / �_�Q���m\n");
		printf("                                  �b (߄D�)\n");
		printf("                                  �b(Ɂ@ |)\n");
		printf("                                ���l�@�m�m\n");
		printf("                                    �� ��\n\n");
		printf("                                   %s\n", &enemy2->name[2]);

	}
	if (flag == 3)
	{
		printf("                                    �_�U�R|\n");
		printf("                                    �˃����P�R_\n");
		printf("                                   `�L �""�J�Q�T\n");
		printf("                               ���܁R�m�@�f�IIII)�^/\n");
		printf("                            /�@ ���R�m�S::::�^�^�R\n");
		printf("                             �_�Q�Q�`�R_�jƁ^�ځT::\n");
		printf("                             `/�Q/:.�� .:�^�^|L_L|:\n");
		printf("                             `�_�P�_�Q��ځڤ�m((uE}\n");
		printf("                                �_��/L�~}�PT�b::::: \n");
		printf("                                  `Ɓځ^�\�L)�S:::�\n");
		printf("                                   %s\n", &enemy->name[0]);

	}
	if (flag == 4)
	{
		printf("\n");
		printf("                           �@�@ �@,��@_l�ui__, i \n");
		printf("                            �@�@.�^/'�_>_�vw>�_ \n");
		printf("                           �@�@/��Y�L�/ i�܁rY�܁R\n");
		printf("                           .�@�@�Q___�m(,,j.�@{,) \n");
		printf("                          �@�@ �_�Q�T�@)�m)\n");
		printf("                          �@ �@ �@�@�Rm'�Rm\n\n");
		printf("                                   %s\n", &enemy3->name[3]);

	}
	if (flag == 5)
	{
		printf("                      -�] = �� = �] - �~�A\n");
		printf("                   �^�@�@�@�@ �@ �@      �@ �_\n");
		printf("                  /              �L, , �܁S�_�Q�_�Q__�@_�Q�@ __\n");
		printf("                �V^�: �@ �@      { {�@�������d�c���c�d���c�@�c��\n");
		printf("                {{ ____�[__�@    �@��_____�c �L�P�P|�P�P�@ �P�P�@�@�P�P\n");
		printf("               / �O�ʃD�]��T�@���������O7�ʁP�__\n");
		printf("               �_ �T__{ __ | ___ | __,�^�N߁L �@�� �B�܁f }i\n");
		printf("                 �M �A�@�@�@�@�@�@�@ �@      �C�܁@�@�@ ��\n");
		printf("                     .���] == = �]��:     �ړ�A�܁@�@�@�q\n");
		printf("                   . {�P�M�N7�__,�_.    �ړ��� __�@�@ ��\n");
		printf("                                   %s\n", &enemy4->name[4]);
	}

	
	printf("________________________________________________________________________________\n");
	/* �R�}���h��ʕ`�揈�� */
	printf("\n\n\n");
	for (i = 0; i < TH_MAX; i++)
	{
		printf("                    %s\n", &choice[i][0]);
	}
	/* �������x���� */
	Sleep(10);
}

/*******************************************************************************
�֐���:	void SelectCommand( void )
����:	void
�߂�l:	void
����:	�v���C���[�̕`�揈��
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
