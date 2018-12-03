/*******************************************************************************
* �^�C�g��:		�]���ۑ� RPG�Q�[��
* �v���O������:	Player.cpp
* �쐬��:		GP11B-341 29 �v�q�@����
* �쐬��:		2018/06/08
*******************************************************************************/

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "Player.h"
#include "BG.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/

#define PLAYER_MAX   (1)				//�v���C���[�̐l��

/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/


/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

PLAYER player[PLAYER_MAX];          //�v���C���[

/*******************************************************************************
�֐���:	InitPlayer( void )
����:	void
�߂�l:	����I��: int�^�� 0
����:	���C���֐�
*******************************************************************************/

void InitPlayer(void)
{

	PLAYER *player = GetPlayerAdr(0);			//�v���C���[( ) �̃A�h���X���擾����
	char *map;

	/* �v���C���[�̏����ʒu�ݒ� */
	player->fx = 1;
	player->fy = 1;

	map = GetMapAdr(player->fy, player->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = 'P';								// �v���C���[�L������������

	//�{���͂����̂Ƃ���Ńp�����[�^�[�̐ݒ���s��

	player->status.HP = 100;					//���݂�HP
	player->status.HP_MAX = 100;				//���݂̍ő�HP
	player->status.MP = 20;						//���݂�MP			(�������j
	player->status.MP_MAX = 20;					//���݂̍ő�MP		(�������j
	player->status.name[32];					//��l���̖��O
	player->status.ATK = 15;					//���݂̍U����
	player->status.DEF = 10;					//���݂̎����		(�������j
	player->status.SPD = 10;					//���݂̍s���D��l	(�������j
	player->status.EXP =  0;					//���݂̌o���l
	player->status.LV  =  1;					//���݂̃��x��
	player->status.GOLD = 0;					//���݂̏�����		(�������j

}

/*******************************************************************************
�֐���:	void UpdatePlayer( void )
����:	void
�߂�l:	void
����:	�v���C���[�̍X�V����
*******************************************************************************/
void UpdatePlayer(void)
{
	int key;
	int old_x, old_y;
	PLAYER *player = GetPlayerAdr(0);
	char *map;

	/* �L�[�����͂��ꂽ�� */
	key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}

	/* �O��̕\���ʒu�̏���*/
	map = GetMapAdr(player->fy, player->fx);	// �t�B�[���h�̃A�h���X���擾
	*map = ' ';

	/* �v���C���[�̈ʒu���� */
	old_x = player->fx;
	old_y = player->fy;
	switch (key)
	{
	case 'a':
	case 0x4b:	// ���ֈړ�����
		player->fx--;
		break;

	case 'd':
	case 0x4d:	// �E�ֈړ�����
		player->fx++;
		break;

	case 'w':
	case 0x48:	// ��ֈړ�����
		player->fy--;
		break;

	case 's':
	case 0x50:	// ���ֈړ�����
		player->fy++;
		break;

	default:	// �ړ����Ȃ�
		break;
	}

	// �ړ��������NG�ȏ��H
	map = GetMapAdr(player->fy, player->fx);				//�t�B�[���h�̃A�h���X���擾
	if (*map == '*')
	{	// NG�Ȃ�ړ��O�̏ꏊ�ɖ߂�
		player->fx = old_x;
		player->fy = old_y;
	}
	//DirectX�ł́A�A�j���[�V�����̍X�V�������s��

	if ((player->status.EXP >= 10) && (player->status.LV == 1))
	{
		int old_HP  = 0;					//���݂̍ő�HP�����Ă����ϐ�
		int old_ATK = 0;					//���݂̍ő�U���͂����Ă����ϐ�
		int old_LV = 0;						//���݂̃��x�������Ă����ϐ�

		old_HP = player->status.HP_MAX;		//���݂̍ő�HP�����Ă���
		old_ATK = player->status.ATK;		//���݂̍ő�U���͂����Ă���
		old_LV = player->status.LV;			//���݂̃��x�������Ă���


		player->status.HP_MAX += 400;					//�X�e�[�^�X�A�b�v
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HP����

		player->status.ATK +=     50;					//�X�e�[�^�X�A�b�v
		player->status.LV  +=      1;					//�X�e�[�^�X�A�b�v
		

		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("���x���A�b�v!!");
		// �L�[���͑҂�
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%s�� LV ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_LV, player->status.LV);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� HP ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ",old_HP,player->status.HP);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� ATK ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_ATK, player->status.ATK);		//�X�e�[�^�X�A�b�v

		// �L�[���͑҂�
		rewind(stdin);
		_getch();

		system("cls");


	}
	if ((player->status.EXP >= 100) && (player->status.LV == 2))
	{
		int old_HP = 0;						//���݂̍ő�HP�����Ă����ϐ�
		int old_ATK = 0;					//���݂̍ő�U���͂����Ă����ϐ�
		int old_LV = 0;						//���݂̃��x�������Ă����ϐ�

		old_HP = player->status.HP_MAX;		//���݂̍ő�HP�����Ă���
		old_ATK = player->status.ATK;		//���݂̍ő�U���͂����Ă���
		old_LV = player->status.LV;			//���݂̃��x�������Ă���


		player->status.HP_MAX += 1000;					//�X�e�[�^�X�A�b�v
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HP����

		player->status.ATK += 135;					//�X�e�[�^�X�A�b�v
		player->status.LV += 1;						//�X�e�[�^�X�A�b�v


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("���x���A�b�v!!");
		// �L�[���͑҂�
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%s�� LV ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_LV, player->status.LV);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� HP ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_HP, player->status.HP);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� ATK ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_ATK, player->status.ATK);		//�X�e�[�^�X�A�b�v

		// �L�[���͑҂�
		rewind(stdin);
		_getch();


		system("cls");

	}
	if ((player->status.EXP >= 1000) && (player->status.LV == 3))
	{
		int old_HP = 0;					//���݂̍ő�HP�����Ă����ϐ�
		int old_ATK = 0;					//���݂̍ő�U���͂����Ă����ϐ�
		int old_LV = 0;						//���݂̃��x�������Ă����ϐ�

		old_HP = player->status.HP_MAX;		//���݂̍ő�HP�����Ă���
		old_ATK = player->status.ATK;		//���݂̍ő�U���͂����Ă���
		old_LV = player->status.LV;			//���݂̃��x�������Ă���


		player->status.HP_MAX += 3000;					//�X�e�[�^�X�A�b�v
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HP����

		player->status.ATK += 300;					//�X�e�[�^�X�A�b�v
		player->status.LV +=    1;					//�X�e�[�^�X�A�b�v


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("���x���A�b�v!!");
		// �L�[���͑҂�
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%s�� LV ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_LV, player->status.LV);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� HP ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_HP, player->status.HP);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� ATK ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_ATK, player->status.ATK);		//�X�e�[�^�X�A�b�v

																// �L�[���͑҂�
		rewind(stdin);
		_getch();

		system("cls");


	}
	if ((player->status.EXP >= 10000) && (player->status.LV == 4))
	{
		int old_HP = 0;					//���݂̍ő�HP�����Ă����ϐ�
		int old_ATK = 0;					//���݂̍ő�U���͂����Ă����ϐ�
		int old_LV = 0;						//���݂̃��x�������Ă����ϐ�

		old_HP = player->status.HP_MAX;		//���݂̍ő�HP�����Ă���
		old_ATK = player->status.ATK;		//���݂̍ő�U���͂����Ă���
		old_LV = player->status.LV;			//���݂̃��x�������Ă���


		player->status.HP_MAX += 4500;					//�X�e�[�^�X�A�b�v
		player->status.HP = 0;
		player->status.HP += player->status.HP_MAX;		//HP����

		player->status.ATK += 500;					//�X�e�[�^�X�A�b�v
		player->status.LV += 1;					//�X�e�[�^�X�A�b�v


		system("cls");
		printf("\n\n\n\n\n                             ");
		printf("���x���A�b�v!!");
		// �L�[���͑҂�
		rewind(stdin);
		_getch();

		printf("\n\n                             ");
		printf("%s�� LV ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_LV, player->status.LV);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� HP ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_HP, player->status.HP);			//�X�e�[�^�X�A�b�v

		printf("\n\n                             ");
		printf("%s�� ATK ���オ����!", &player->status.name[0]);
		Sleep(300);
		printf("\n\n                             ");
		printf("%d �� %d ", old_ATK, player->status.ATK);		//�X�e�[�^�X�A�b�v

																// �L�[���͑҂�
		rewind(stdin);
		_getch();

		system("cls");
	}


}
/*******************************************************************************
�֐���:	void DrawPlayer( void )
����:	void
�߂�l:	void
����:	�v���C���[�̕`�揈��
*******************************************************************************/
void DrawPlayer(void)
{

	PLAYER *player = GetPlayerAdr(0);
	char *map = GetMapAdr(player->fy, player->fx);

	/* �v���C���[�̈ʒu�X�V */
	*map = 'P';

}
/*******************************************************************************
�֐���:	void UninitPlayer( void )
����:	void
�߂�l:	void
����:	�v���C���[�̏I������
*******************************************************************************/
void UninitPlayer(void)
{
//���܂̂Ƃ��Ȃ�
}

//******************************************************
//
//******************************************************
PLAYER *GetPlayerAdr(int pno)
{
	return &player[pno];
}
