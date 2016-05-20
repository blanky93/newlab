
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
	// 음악 관련 데이터를 담을 구조체 Music 선언.

	char name[20];
	char artist[20];
	int release;

	// 곡명, 가수이름, 발매년도를 담을 변수 선언.
}Music;

Music m[INDEXLISTMAXNUM];



// 메뉴 출력
void printTitle(void); // 제목을 출력하는 함수.
void printTopLine(void);
void printBottomLine(void); // 라인을 출력하는 함수

// 파일 읽기
void readMusicIndex();
void divData(char);

// 메인에서 키보드 입력 받기
void inputKeyboard(int*, int*); // 키보드 방향키 입력을 받는 함수
void printMenu(int*); // 좌우 방향키 입력에 따라 메뉴를 출력하는 함수.


// 키보드 입력후 기능 시작.
void functionStart(int*, int*, int*, int*); // 위아래 방향키 입력에 따라 현재 메뉴상의 기능을 실행하는 함수.
void makeFunctionStart(int*, int*, int); // 보조 함수


// 1번 기능 함수 - 목록 출력
//void readMusicIndex(int*); // 1번 기능, 음악 목록 출력함수.
void printMusicIndex(int*, int);
void selectPrintPage(int*, int*, int*, int);


// 2번 기능 함수 - 음악 등록
void registerMusic(int*, int*, int*, int*); // 2번 기능, 음악 등록 함수.
void selectAfterRegist(int*, int*);


// 3번 기능 함수 - 음악 삭제
void delMusic(); // 직접적으로 음악을 삭제하는 함수.
void afterDel(); // 삭제 후 입력을 받는 함수.


// 4번 기능 함수 - 음악 수정
void fixMusic(); // 음악의 어떤 부분을 수정할지 결정하는 함수.
void fixItem(); // 직접적으로 항목을 수정하는 함수.
void afterFix(); // 수정 후 입력을 받는 함수.


// 5번 기능 함수
void findMusic(); // 5번 기능, 음악 검색 함수.
void findOfLayout(int*); // findMusic이 삭제와 수정에도 쓸 것 같아서, 5번 기능만을 위한 레이아웃을 제공해주는 함수.
void LayoutView(int, int*, int*); // 레이아웃에서 선택된 숫자에 따라 메뉴를 출력해주는 함수.
void afterFindMusic();

// 6번 기능 함수
void saveMemoryData(int*, int*, int*); // 현재 메모리상의 데이터를 Data.txt에 저장하는 함수.
void afterSave(int*, int*, int*, int*);


// 7 번 기능 함수
void endFunction(int*, int*, int*, int* ,int*);

// 유틸 함수
int countMusic(); // 음악 목록의 개수를 세는 함수.

