
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

#define LINENUM 47

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define SAPARATE 38
#define ESC 27

#define selectionStartVal 0
#define selectionEndVal 6

#define INDEXLISTMAXNUM 255
#define INDEXLISTNUM 15
#define SIZEOFELEMENT 20
#define YEAR 3000

#define FINDANDDEL 300
#define FINDANDFIX 400
#define ONLYFIND 500



typedef struct music {
	// ���� ���� �����͸� ���� ����ü Music ����.

	char name[20];
	char artist[20];
	int release;

	// ���, �����̸�, �߸ų⵵�� ���� ���� ����.
}Music;

Music m[INDEXLISTMAXNUM];



// �޴� ���
void printTitle(void); // ������ ����ϴ� �Լ�.
void printTopLine(void);
void printBottomLine(void); // ������ ����ϴ� �Լ�

// ���� �б�
void readMusicIndex();
void divData(char);

// ���ο��� Ű���� �Է� �ޱ�
void inputKeyboard(int*, int*); // Ű���� ����Ű �Է��� �޴� �Լ�
void printMenu(int*); // �¿� ����Ű �Է¿� ���� �޴��� ����ϴ� �Լ�.


// Ű���� �Է��� ��� ����.
void functionStart(int*, int*, int*, int*); // ���Ʒ� ����Ű �Է¿� ���� ���� �޴����� ����� �����ϴ� �Լ�.
void makeFunctionStart(int*, int*, int); // ���� �Լ�


// 1�� ��� �Լ� - ��� ���
//void readMusicIndex(int*); // 1�� ���, ���� ��� ����Լ�.
void printMusicIndex(int*, int);
void selectPrintPage(int*, int*, int*, int);


// 2�� ��� �Լ� - ���� ���
void registerMusic(int*, int*, int*, int*); // 2�� ���, ���� ��� �Լ�.
void selectAfterRegist(int*, int*);


// 3�� ��� �Լ� - ���� ����
void delMusic(); // ���������� ������ �����ϴ� �Լ�.
void afterDel(); // ���� �� �Է��� �޴� �Լ�.


// 4�� ��� �Լ� - ���� ����
void fixMusic(); // ������ � �κ��� �������� �����ϴ� �Լ�.
void fixItem(); // ���������� �׸��� �����ϴ� �Լ�.
void afterFix(); // ���� �� �Է��� �޴� �Լ�.


// 5�� ��� �Լ�
void findMusic(); // 5�� ���, ���� �˻� �Լ�.
void findOfLayout(int*); // findMusic�� ������ �������� �� �� ���Ƽ�, 5�� ��ɸ��� ���� ���̾ƿ��� �������ִ� �Լ�.
void LayoutView(int, int*, int*); // ���̾ƿ����� ���õ� ���ڿ� ���� �޴��� ������ִ� �Լ�.
void afterFindMusic();

// 6�� ��� �Լ�
void saveMemoryData(int*, int*, int*); // ���� �޸𸮻��� �����͸� Data.txt�� �����ϴ� �Լ�.
void afterSave(int*, int*, int*, int*);


// 7 �� ��� �Լ�
void endFunction(int*, int*, int*, int* ,int*);

// ��ƿ �Լ�
int countMusic(); // ���� ����� ������ ���� �Լ�.

