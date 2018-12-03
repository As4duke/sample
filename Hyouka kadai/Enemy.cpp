/*******************************************************************************
* �^�C�g��:		�]���ۑ� RPG�Q�[��
* �v���O������:	Enemy.cpp
* �쐬��:		GP11B-341 29 �v�q�@����
* �쐬��:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "Enemy.h"
#include "BG.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

ENEMY enemy[ENEMY_MAX];          //�v���C���[

int flag1 = 0;											//�G�l�~�[�̐�������
int flag2 = 0;											//�G�l�~�[�̐�������
int flag3 = 0;											//�G�l�~�[�̐�������
int flag4 = 0;											//�G�l�~�[�̐�������
int flag5 = 0;											//�G�l�~�[�̐�������


/*******************************************************************************
�֐���:	( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/

/*******************************************************************************
�֐���:	void InitEnemy( void )
����:	void
�߂�l:	void
����:	�G�l�~�[�̏���������
*******************************************************************************/
void InitEnemy(void)
{
	ENEMY *enemy  = GetEnemyAdr(0);			//�G�l�~�[(0) �̃A�h���X���擾����
	ENEMY *enemy1 = GetEnemyAdr(1);			//�G�l�~�[(1) �̃A�h���X���擾����
	ENEMY *enemy2 = GetEnemyAdr(2);			//�G�l�~�[(2) �̃A�h���X���擾����
	ENEMY *enemy3 = GetEnemyAdr(3);			//�G�l�~�[(3) �̃A�h���X���擾����
	ENEMY *enemy4 = GetEnemyAdr(4);			//�G�l�~�[(4) �̃A�h���X���擾����

	char *map;


	/* �G�̏����ʒu�ݒ� */
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


	map = GetMapAdr(enemy->fy, enemy->fx);	    // �t�B�[���h�̃A�h���X���擾
	*map = 'K';
	map = GetMapAdr(enemy1->fy, enemy1->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = 'S';
	map = GetMapAdr(enemy2->fy, enemy2->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = 'W';
	map = GetMapAdr(enemy3->fy, enemy3->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = 'D';
	map = GetMapAdr(enemy4->fy, enemy4->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = 'A';


	//�G�l�~�[�̃p�����[�^�[�ݒ�
	//�G�l�~�[(0)��
	strcpy(&enemy->name[0], "�i�C�g");
	enemy->HP  = 1000;
	enemy->ATK =  100;
	enemy->EXP = 1000;

	//�G�l�~�[(1)��
	strcpy(&enemy1->name[1], "�X���C��");
	enemy1->HP =  25;
	enemy1->ATK = 10;
	enemy1->EXP = 10;

	//�G�l�~�[(2)��
	strcpy(&enemy2->name[2], "�E���t");
	enemy2->HP  = 300;
	enemy2->ATK =  45;
	enemy2->EXP = 100;

	//�G�l�~�[(3)��
	strcpy(&enemy3->name[3], "�h���S��");
	enemy3->HP  =  3000;
	enemy3->ATK =   300;
	enemy3->EXP = 10000;

	//�G�l�~�[(4)��
	strcpy(&enemy4->name[4], "S  A  N  S");
	enemy4->HP =   10000;
	enemy4->ATK =    999;
	enemy4->EXP =  99999;



	
}


/*******************************************************************************
�֐���:	void UpdateEnemy( void )
����:	void
�߂�l:	void
����:	�G�l�~�[�̍X�V����
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


	/* �O��̕\���ʒu�̏���*/
	map = GetMapAdr(enemy->fy, enemy->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = ' ';
	map1 = GetMapAdr(enemy1->fy, enemy1->fx);	// �t�B�[���h�̃A�h���X���擾
	*map1 = ' ';
	map2 = GetMapAdr(enemy2->fy, enemy2->fx);	// �t�B�[���h�̃A�h���X���擾
	*map2 = ' ';
	map3 = GetMapAdr(enemy3->fy, enemy3->fx);	// �t�B�[���h�̃A�h���X���擾
	*map3 = ' ';
	map4 = GetMapAdr(enemy4->fy, enemy4->fx);	// �t�B�[���h�̃A�h���X���擾
	*map4 = ' ';


	/* �G�l�~�[�̈ʒu���� */
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


	// �G�l�~�[�̈ړ�����


	/*  �G�l�~�[(0)�̈ړ���������_���Ō��肷��B  */
	if (flag1 == 0) 
	{
		key = rand() % (9 + 1);

		switch (key)
		{
		case 1:
		case 5:
			enemy->fx--;     //���Ɉړ�����B
			break;

		case 2:
		case 6:
			enemy->fx++;     //�E�Ɉړ�����B
			break;

		case 3:
		case 7:
			enemy->fy--;     //��Ɉړ�����B
			break;

		case 4:
		case 8:
			enemy->fy++;     //���Ɉړ�����B
			break;

		case 9:
		default:           //�ړ����Ȃ��B
			break;
		}
	}
	/*  �G�l�~�[(1)�̈ړ���������_���Ō��肷��B  */
	if (flag2 == 0)
	{
		key1 = rand() % (9 + 1);

		switch (key1)
		{
		case 1:
		case 5:
			enemy1->fx--;     //���Ɉړ�����B
			break;

		case 2:
		case 6:
			enemy1->fx++;     //�E�Ɉړ�����B
			break;

		case 3:
		case 7:
			enemy1->fy--;     //��Ɉړ�����B
			break;

		case 4:
		case 8:
			enemy1->fy++;     //���Ɉړ�����B
			break;

		case 9:
		default:           //�ړ����Ȃ��B
			break;
		}
	}

	/*  �G�l�~�[(2)�̈ړ���������_���Ō��肷��B  */
	if (flag3 == 0)
	{

		key2 = rand() % (9 + 1);

		switch (key2)
		{
		case 1:
		case 5:
			enemy2->fx--;     //���Ɉړ�����B
			break;

		case 2:
		case 6:
			enemy2->fx++;     //�E�Ɉړ�����B
			break;

		case 3:
		case 7:
			enemy2->fy--;     //��Ɉړ�����B
			break;

		case 4:
		case 8:
			enemy2->fy++;     //���Ɉړ�����B
			break;

		case 9:
		default:           //�ړ����Ȃ��B
			break;
		}
	}
	/*  �G�l�~�[(3)�̈ړ���������_���Ō��肷��B  */
	if (flag4 == 0)
	{

		key3 = rand() % (9 + 1);

		switch (key3)
		{
		case 1:
		case 5:
			enemy3->fx--;     //���Ɉړ�����B
			break;

		case 2:
		case 6:
			enemy3->fx++;     //�E�Ɉړ�����B
			break;

		case 3:
		case 7:
			enemy3->fy--;     //��Ɉړ�����B
			break;

		case 4:
		case 8:
			enemy3->fy++;     //���Ɉړ�����B
			break;

		case 9:
		default:           //�ړ����Ȃ��B
			break;
		}
	}

	/*  �G�l�~�[(4)�̈ړ���������_���Ō��肷��B  */
	if (flag5 == 0)
	{
		key4 = rand() % (9 + 1);

		switch (key4)
		{
		case 1:
		case 5:
			//enemy4->fx--;     //���Ɉړ�����B
			break;

		case 2:
		case 6:
			//enemy4->fx++;     //�E�Ɉړ�����B
			break;

		case 3:
		case 7:
			//enemy4->fy--;     //��Ɉړ�����B
			break;

		case 4:
		case 8:
			//enemy4->fy++;     //���Ɉړ�����B
			break;

		case 9:
		default:           //�ړ����Ȃ��B
			break;
		}
	}
	else if (flag5 == 1)
	{
		map = GetMapAdr(enemy4->fy, enemy4->fx);	    // �t�B�[���h�̃A�h���X���擾
		*map4 = ' ';									//�G�l�~�[������
	}


	// �ړ��������NG�ȏ��H
	map = GetMapAdr(enemy->fy, enemy->fx);				    //�G�l�~�[�̃t�B�[���h�̃A�h���X���擾
	if (*map == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		enemy->fx = old_x;
		enemy->fy = old_y;
	}

	map1 = GetMapAdr(enemy1->fy, enemy1->fx);				//�G�l�~�[ 1 �̃t�B�[���h�̃A�h���X���擾
	if (*map1 == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		enemy1->fx = old1_x;
		enemy1->fy = old1_y;
	}

	map2 = GetMapAdr(enemy2->fy, enemy2->fx);				//�G�l�~�[ 2 �̃t�B�[���h�̃A�h���X���擾
	if (*map2 == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		enemy2->fx = old2_x;
		enemy2->fy = old2_y;
	}

	map3 = GetMapAdr(enemy3->fy, enemy3->fx);				//�G�l�~�[ 3 �̃t�B�[���h�̃A�h���X���擾
	if (*map3 == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		enemy3->fx = old3_x;
		enemy3->fy = old3_y;
	}

	map4 = GetMapAdr(enemy4->fy, enemy4->fx);				//�G�l�~�[ 4 �̃t�B�[���h�̃A�h���X���擾
	if (*map4 == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		enemy4->fx = old4_x;
		enemy4->fy = old4_y;
	}

	//�G�l�~�[��Direct X�ł͂����ŃA�j���[�V�����̍X�V�������s���B

}


/*******************************************************************************
�֐���:	void DrawEnemy( void )
����:	void
�߂�l:	void
����:	�G�l�~�[�̕`�揈��
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


	/* �G�l�~�[�̈ʒu�X�V */
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
�֐���:	void UninitEnemy( void )
����:	void
�߂�l:	void
����:	�G�l�~�[�̏I������
*******************************************************************************/
void UninitEnemy(void)
{
	//���܂̂Ƃ���Ȃ�
}


//*************************************************************
//
//*************************************************************
ENEMY *GetEnemyAdr(int pno)
{
	return &enemy[pno];
}

