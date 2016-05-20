/*
	파일명 : musicIndex.c
	파일 내용 : 주어진 데이터를 읽을 수 있는 프로그램 구현
	작성자 : 141060 이근원
	작성일자 : 16.05.04
*/


#include "musicIndex.h"



// 메뉴를 출력하는 함수


void printTopLine(void) {
	
	// TopLine을 출력하는 함수.
	int i;

	printf("┌");

	for (i = 0; i < LINENUM; i++) {

		printf("─");

	}

	printf("┐\n");
}

void printBottomLine(void) {
	
	// BottomLine을 출력하는 함수.
	int i;

	printf("└");
	
	for (i = 0; i < LINENUM; i++) {
	
		printf("─");
	}

	printf("┘\n");
}

void printTitle(void) {
	
	// 메뉴 위 타이틀을 출력하는 함수 printTitle.

	printf("\n MUSIC INDEX : 자신의 인생곡을 저장하세요! \n");
	printf(" Ver. 1.3 (16.05.16) - 음악 목록, 음악 등록, 음악 검색, 저장 기능, 종료 기능 가능 \n\n");

}

void printMenu(int* selectVal, int* decisionPrintListVal) {
	// selectVal에 따라 어떤 메뉴를 선택할지 표시해 주는 함수.

	int i;

	printTitle();
	printTopLine();

	printf("│ ");

	switch (*selectVal) {

	case 0:

		printf("▶ 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 1:

		printf("1. 음악 목록  ");
		printf("▶ 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 2:

		printf("1. 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("▶ 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 3:

		printf("1. 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("▶ 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 4:

		printf("1. 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("▶ 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 5:

		printf("1. 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("▶ 목록 저장  ");
		printf("7. 종료  ");
		break;

	case 6:

		printf("1. 음악 목록  ");
		printf("2. 음악 등록  ");
		printf("3. 음악 삭제  ");
		printf("4. 목록 수정  ");
		printf("5. 음악 검색  ");
		printf("6. 목록 저장  ");
		printf("▶ 종료  ");
		break;

	}

	printf("│\n");
	printBottomLine();

	if (*decisionPrintListVal == 0) {

		printf("←,→ : 메뉴이동 / ↑,↓ : 메뉴 진입, 해제 \n\n");

	}

	else {

		switch (*selectVal) {

		case 0:

			printf("←,→ : 페이지 이동 / ↑,↓ : 메뉴 진입, 해제 \n\n");
			break;

		}
	}
}




void inputKeyboard(int* selectVal, int* decisionPrintListVal) {

	// 키보드 방향키 LEFT,RIGNT,UP,DOWN을 받아 selectVal, decisionPrintListVal을 바꾸는 함수.
	
	char input = _getch();

	switch (input) {
	
	case LEFT:
	
		if (*selectVal == selectionStartVal) {
		
			*selectVal = selectionEndVal;
			
			break;
		
		}
		
		else {
		
			*selectVal -= 1;
			
			break;
		
		}
	
	case RIGHT:
	
		if (*selectVal == selectionEndVal) {
		
			*selectVal = selectionStartVal;
			
			break;
		}
		
		else {
		
			*selectVal += 1;
		
			break;
	
		}
	case DOWN: case ENTER:
	
		if (*decisionPrintListVal == 1) {
		
			break;
		
		}
		else {
		
			*decisionPrintListVal += 1;
	
			break;
	
		}
	case UP:
	
		if (*decisionPrintListVal == 0) {
		
			break;
	
		}
	
		else {
		
			*decisionPrintListVal -= 1;
			
			break;
		
		}

	case '1': case '2': case '3': case '4': case '5': case '6': case '7':
		
		input -= '0';
		makeFunctionStart(selectVal, decisionPrintListVal, input);
		break;

	}
}

void makeFunctionStart(int* selectVal, int* decisionPrintListVal, int input) {
	// FunctionStart가 숫자키로도 작동할 수 있도록 하는 보조 함수.


	*decisionPrintListVal = 1;
	*selectVal = input - 1;

	return;
}




void readMusicIndex(int count) {
	// 파일 데이터를 읽어들이는 함수.

	
	FILE* data;
	char inputBuffer[sizeof(Music)];
	int i;

	if (count == 0) {
		printf("새로운 파일을 생성합니다... \n");
		data = fopen("data.txt", "w");
	}
	else {
		data = fopen("data.txt", "r");
		for (i = 0; i < count; i++) {
			fgets(inputBuffer, sizeof(Music), data);
			divData(inputBuffer, i);
		}
	}

	fclose(data);
	return;
}

void divData(char* inputBuffer, int listVal) {
	// 파일을 읽어 Music구조체 형식에 맞게 나누어 저장하는 함수.

	int i, j;
	int count = 0;
	char temp[sizeof(Music)];

	for (i = 0; inputBuffer[i] != SAPARATE; i++) {
		temp[i] = inputBuffer[i];
		count++;
	}
	temp[count] = '\0';
	strcpy(m[listVal].name, temp);
	count++;
	for (i = count, j = 0; inputBuffer[i] != SAPARATE; i++, j++) {
		temp[j] = inputBuffer[i];
		count++;
	}
	temp[j] = '\0';
	strcpy(m[listVal].artist, temp);
	count++;
	for (i = count, j = 0; inputBuffer[i] != '\n'; i++, j++) {
		temp[j] = inputBuffer[i];
	}
	m[listVal].release = atoi(temp);

	return;
}


int countMusic() {
	// 음악 목록에 등록된 음악 개수를 세어주는 함수.
	
	int count = 0;
	FILE *data;
	int i;
	char buffer[sizeof(Music)];

	data = fopen("data.txt", "r");

	if (data == NULL) {
		return 0;
	}
	else {
		for (i = 0; ; i++) {
			if (fgets(buffer, sizeof(Music), data) == NULL) {
				break;
			}
			else {
				count++;
			}
		}
	}

	fclose(data);

	return count;
}


void fuctionStart(int* selectVal, int* decisionPrintListVal, int* pageNum, int* count, int* oriCount, int* savTrigger, int* findTrigger) {
	// 입력받은 방향키와 selectVal에 따라 기능을 시작하게 하는 함수 fuctionStart.


	if (*decisionPrintListVal == 0) {

		return;

	}
	else if (*decisionPrintListVal == 1) {
		
		switch (*selectVal) {
		
		case 0:
		
			printMusicIndex(pageNum, count);
			selectPrintPage(decisionPrintListVal, pageNum, selectVal, count);
			break;
		
		case 1:
		
			registerMusic(decisionPrintListVal, selectVal, count, savTrigger);
			*savTrigger = 1;
			break;
		
		case 2:
		
			findOfLayout(selectVal, decisionPrintListVal, count, findTrigger, savTrigger, FINDANDDEL);
			break;
		
		case 3:
		
			findOfLayout(selectVal, decisionPrintListVal, count, findTrigger, savTrigger, FINDANDFIX);
			*decisionPrintListVal = 0;
			break;
		
		case 4:
		
			findOfLayout(selectVal, decisionPrintListVal, count, findTrigger, savTrigger, ONLYFIND);
			break;
		
		case 5:
		
			saveMemoryData(count, oriCount, savTrigger);
			afterSave(selectVal, decisionPrintListVal, count, oriCount);
			break;
		
		case 6:
		
			endFunction(savTrigger, selectVal, decisionPrintListVal, count, oriCount);

		}
	}

	return;
}




void delMusic(int* tempArr[], int tempIdx, int* decisionPrintListVal, int* count) {

	int num;
	int delNum;
	int i;
	char temp[SIZEOFELEMENT];


	while (1) {

		printf("	삭제하실 음악의 번호를 입력하십시오 ( 0 to exit ) : ");
		gets(temp);

		temp[SIZEOFELEMENT - 1] = '\0';

		num = atoi(temp);

		if (num == 0) {
			*decisionPrintListVal = 0;
			return;

		}
		else if (num > tempIdx + 1 || num < 0) {

			printf("	INPUT ERROR! Plz type again. \n");

		}
		else {

			break;

		}
	}

	delNum = tempArr[num - 1];

	for (i = delNum + 1; i <= *count; i++) {

		strcpy(m[i - 1].name, m[i].name);
		strcpy(m[i - 1].artist, m[i].artist);
		m[i - 1].release = m[i].release;

	}

	*count -= 1;


	printf("	삭제가 완료되었습니다! \n");
	afterDel(decisionPrintListVal);
}


void findOfLayout(int* selectVal, int* decisionPrintListVal, int* count, int* findTrigger, int* savTrigger, int findType) {
	
	char input;
	int menuNum = 1;

	LayoutView(menuNum, selectVal, decisionPrintListVal, findType);

	while (1) {

		input = _getch();

		switch (input) {

			case UP:

				*decisionPrintListVal = 0;
				return;
				break;

			case DOWN: case ENTER :

				*decisionPrintListVal = 1;
				findMusic(decisionPrintListVal, menuNum, count, findTrigger, savTrigger, findType);
				return;
				break;

			case RIGHT :

				if (menuNum == 3) {

					LayoutView(menuNum, selectVal, decisionPrintListVal, findType);
					break;

				}
				else {

					menuNum += 1;
					LayoutView(menuNum, selectVal, decisionPrintListVal, findType);
					break;

				}

			case LEFT :

				if (menuNum == 1) {

					LayoutView(menuNum, selectVal, decisionPrintListVal, findType);
					break;

				}
				else {

					menuNum -= 1;
					LayoutView(menuNum, selectVal, decisionPrintListVal, findType);
					break;

				}

			case '1':
				*decisionPrintListVal = 1;
				menuNum = 1;
				findMusic(decisionPrintListVal, menuNum, count, findTrigger, savTrigger, findType);
				return;
				break;

			case '2':
				*decisionPrintListVal = 1;
				menuNum = 2;
				findMusic(decisionPrintListVal, menuNum, count, findTrigger, savTrigger, findType);
				return;
				break;

			case '3':
				*decisionPrintListVal = 1;
				menuNum = 3;
				findMusic(decisionPrintListVal, menuNum, count, findTrigger, savTrigger, findType);
				return;
				break;

			default :
				LayoutView(menuNum, selectVal, decisionPrintListVal, findType);

		}
	}

	return;
}

void LayoutView(int menuNum, int* selectVal, int* decisionPrintListVal, int findType) {
	
	system("cls");
	printMenu(selectVal, decisionPrintListVal);

	if (findType == FINDANDDEL) {

		printf("	음악 삭제 기능입니다. \n");
		printf("	삭제할 곡을 검색합니다. 어떤 주제로 찾으시겠습니까? \n");
		printf("	( ↔ : 이동 , ↓ or ENTER : 결정 , ↑ : 메뉴 나가기 ) \n\n");

	}
	else if (findType == FINDANDFIX) {
		
		printf("	음악 수정 기능입니다. \n");
		printf("	수정할 곡을 검색합니다. 어떤 주제로 찾으시겠습니까? \n");
		printf("	( ↔ : 이동 , ↓ or ENTER : 결정 , ↑ : 메뉴 나가기 ) \n\n");

	}
	else {

		printf("	 음악 검색 기능입니다. 어떤 주제로 찾으시겠습니까? \n");
		printf("	( ↔ : 이동 , ↓ or ENTER : 결정 , ↑ : 메뉴 나가기 ) \n\n");

	}


	if (menuNum == 1){
	
		printf("	▶ 곡 이름    2. 가수 이름    3. 발매 년도 \n");
		return;

	}
	else if (menuNum == 2) {

		printf("	1. 곡 이름    ▶ 가수 이름    3. 발매 년도 \n");
		return;

	}
	else {

		printf("	1. 곡 이름    2. 가수 이름    ▶ 발매 년도 \n");
		return;

	}
}

void findMusic(int* decisionPrintListVal, int menuNum, int* count, int* findTrigger, int* savTrigger, int findType) {

	int i;
	int j;
	int tempIdx = 0;
	int tempArr[INDEXLISTMAXNUM];
	char name[20];
	char artist[20];
	int release;
	char temp[SIZEOFELEMENT];


	if (menuNum == 1) {

		printf("\n	곡 이름으로 검색합니다. \n");
		printf("	찾으시는 곡 이름 또는 일부분을 입력해주세요 :");

		while (1) {

			gets(name);

			if ((name == NULL) || (strlen(name) > SIZEOFELEMENT - 1) || (name[0] == '\n')) {

				printf("	가수 이름은 1~20자입니다. 다시 입력해주세요 :");

			}
			else {

				break;

			}

		}
		

		for (i = 0; i <= *count; i++) {

			if (strstr(m[i].name, name) != NULL) {

				tempArr[tempIdx] = i;
				tempIdx++;

			}

		}



		if (tempIdx != 0) {

			printf("	찾으시는 곡은 다음과 같습니다. \n \n");
			printf("	         곡 이름                   가수 이름           발매 년도 \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i + 1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	찾으시는 키워드의 곡은 존재하지 않습니다. \n");

		}
	}

	else if (menuNum == 2) {


		printf("\n	가수 이름으로 검색합니다. \n");
		printf("	찾으시는 가수 이름 또는 일부분을 입력해주세요 :");

		while (1) {

			gets(artist);

			if ((artist == NULL) || (strlen(artist) > SIZEOFELEMENT - 1) || (artist[0] == '\n')) {

				printf("	가수 이름은 1~20자입니다. 다시 입력해주세요 :");

			}
			else {

				break;

			}

		}


		for (i = 0; i <= *count; i++) {

			if (strstr(m[i].artist, artist) != NULL) {

				tempArr[tempIdx] = i;
				tempIdx++;

			}

		}

		if (tempIdx != 0) {
		
			printf("	찾으시는 곡은 다음과 같습니다. \n \n");
			printf("	         곡 이름                   가수 이름           발매 년도 \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i + 1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	찾으시는 키워드의 곡은 존재하지 않습니다. \n");

		}
	}

	else {

		printf("\n	발매 년도으로 검색합니다. \n");
		printf("	찾으시는 발매년도를 입력해주세요 :");

		while (1) {

			gets(temp);

			release = atoi(temp);

			if ((release <= 0) || (release > YEAR)) {

				printf("	발매년도는 1~3000까지 입력할 수 있습니다. 다시 입력해주세요 :");

			}
			else {

				break;

			}

		}


		for (i = 0; i <= *count; i++) {

			if (m[i].release == release) {

				tempArr[tempIdx] = i;
				tempIdx++;

			}

		}

		if (tempIdx != 0) {

			printf("	찾으시는 곡은 다음과 같습니다. \n \n");
			printf("	번호	         곡 이름                   가수 이름           발매 년도 \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i+1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	찾으시는 키워드의 곡은 존재하지 않습니다. \n");

		}
		*findTrigger = 1;

	}

	if (findType == ONLYFIND) {

		afterFindMusic(decisionPrintListVal);
		return;

	}
	else if (findType == FINDANDDEL) {

		if (tempIdx == 0) {

			afterDel(decisionPrintListVal);

		}
		else {

			*savTrigger = 2;
			delMusic(tempArr, tempIdx, decisionPrintListVal, count);

		}
	}
	else if (findType == FINDANDFIX) {

		if (tempIdx == 0) {

			afterFix(decisionPrintListVal);

		}
		else {

			*savTrigger = 2;
			fixMusic(tempArr, tempIdx, decisionPrintListVal, count);
		}

	}

	return;

}


void fixMusic(int* tempArr[], int tempIdx, int* decisionPrintListVal, int* count) {

	char temp[SIZEOFELEMENT];
	int num;
	int fixNum;
	int i;
	int itemNum;


	while (1) {

		printf("\n	수정하실 음악의 번호를 입력하십시오 ( 0 to exit ) : ");
		gets(temp);

		temp[SIZEOFELEMENT - 1] = '\0';

		num = atoi(temp);

		if (num == 0) {

			*decisionPrintListVal = 0;
			return;

		}
		else if (num > tempIdx + 1 || num < 0) {

			printf("	INPUT ERROR! Plz type again. \n");

		}
		else {

			break;

		}
	}

	fixNum = tempArr[num - 1];
	
	temp[0] = '\0';

	printf("\n	수정할 항목을 선택해주십시오 ( 1: 곡 이름, 2: 가수 이름, 3: 발매 년도 ) : \n");
	
	gets(temp);
	temp[SIZEOFELEMENT - 1] = '\0';
	itemNum = atoi(temp);
	
	fixItem(itemNum, num - 1);


	printf("	수정이 완료되었습니다!\n");
	afterFix(decisionPrintListVal);

}

void fixItem(int itemNum, int idxToFix) {

	char temp[SIZEOFELEMENT];


	if (itemNum == 1) {

		printf("\n	곡 이름을 수정합니다. \n");
		printf("	바꿀 곡 이름을 입력해주세요 :");
		fgets(temp, SIZEOFELEMENT, stdin);

		strcpy(m[idxToFix].name, temp);

	}
	else if (itemNum == 2) {

		printf("\n	가수 이름을 수정합니다. \n");
		printf("	바꿀 가수 이름을 입력해주세요 :");
		fgets(temp, SIZEOFELEMENT, stdin);

		strcpy(m[idxToFix].artist, temp);

	}
	else {

		while (1) {

			printf("\n	가수 이름을 수정합니다. \n");
			printf("	바꿀 가수 이름을 입력해주세요 :");
			fgets(temp, SIZEOFELEMENT, stdin);

			if (atoi(temp) == 0 || atoi(temp) > YEAR) {

				printf("	INPUT ERROR! Plz type again \n");

			}
			else {

				m[idxToFix].release = atoi(temp);
				return;
			}
		}
	}

	return;
}

void afterFix(int* decisionPrintListVal) {

	char input;

	printf("	↑ : 메뉴 돌아가기 \n");

	while (1) {

		input = _getch();

		switch (input) {

		case UP:

			*decisionPrintListVal = 0;
			return;
			break;

		default:
			break;
		}

	}
}


void afterDel(int* decisionPrintListVal) {

	char input;

	printf("	↑ : 메뉴 돌아가기 \n");

	while (1) {

		input = _getch();

		switch (input) {

			case UP :

				*decisionPrintListVal = 0;
				return;
				break;

			default :
				break;
		}

	}

}


void afterFindMusic(int* decisionPrintListVal) {

	char input;

	printf("\n	↑ : 메뉴 돌아가기\n");

	while (1) {

		input = _getch();
	
		switch (input) {

			case UP :

				*decisionPrintListVal = 0;
				return;
				break;

			default :

				break;

		}
	}

	return;
}

void endFunction(int* savTrigger, int* selectVal, int* decisionPrintListVal, int* count, int* oriCount) {

	char input;
	int select = 0;
	FILE *savData;
	int i;

	if (*savTrigger == 0) {

		printf("	프로그램을 종료합니다.  \n");

		exit(0);

	}
	else if (*savTrigger == 1 || *savTrigger == 2) {

		printf("	현재의 변경사항을 저장하시겠습니까? ( ↔ : 이동 , ↓ or ENTER : 결정, ↑ : 메뉴 나가기 )\n");
		printf("	▶ 네	2. 아니오 \n");

		while (*decisionPrintListVal == 1) {

			input = _getch();

			switch (input) {

			case RIGHT:

				if (select == 0) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	현재의 변경사항을 저장하시겠습니까? ( ↔ : 이동 , ↓ or ENTER : 결정, ↑ : 메뉴 나가기 )\n");
					printf("	 1. 네	▶ 아니오 \n");
					select = 1;
					break;

				}
				else {

					break;
				}

			case LEFT:

				if (select == 1) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	현재의 변경사항을 저장하시겠습니까? ( ↔ : 이동 , ↓ or ENTER : 결정, ↑ : 메뉴 나가기 )\n");
					printf("	▶ 네	2. 아니오 \n");
					select = 0;
					break;

				}
				else {

					break;

				}

			case ENTER: case DOWN: case '1':

				if (select == 1) {

					printf("	프로그램을 종료합니다. \n");
					exit(0);

				}
				else if (select == 0) {

					if (*savTrigger == 1) {
					
						savData = fopen("data.txt", "a");
					

						for (i = *oriCount; i < *count; i++) {

							fprintf(savData, "\n%s%c%s%c%d", m[i].name, SAPARATE, m[i].artist, SAPARATE, m[i].release);

						}


						fclose(savData);

					}
					else if (*savTrigger == 2) {

						savData = fopen("data.txt", "w+");

						for (i = 0; i < *count; i++) {

							fprintf(savData, "%s%c%s%c%d\n", m[i].name, SAPARATE, m[i].artist, SAPARATE, m[i].release);

						}


						fclose(savData);
					}




					printf("	저장이 완료되었습니다. 프로그램을 종료합니다. \n");
					exit(0);

				}


			case UP: case '2':

				*decisionPrintListVal = 0;
				return;


			default :
				
				if (select == 0) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	현재의 변경사항을 저장하시겠습니까? ( ↔ : 이동 , ↓ or ENTER : 결정, ↑ : 메뉴 나가기 )\n");
					printf("	 1. 네	▶ 아니오 \n");
					select = 1;
					break;

				}

				if (select == 1) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	현재의 변경사항을 저장하시겠습니까? ( ↔ : 이동 , ↓ or ENTER : 결정, ↑ : 메뉴 나가기 )\n");
					printf("	▶ 네	2. 아니오 \n");
					select = 0;
					break;

				}
			}
		}
	}
}


void selectPrintPage(int* decisionPrintListVal, int* pageNum, int* selectVal, int* count) {
	// 음악 목록 출력이 끝난 후 입력을 받아 다음 작업을 실행하는 함수.

	char input; // input에 따라 메뉴 진입 취소, 페이지 이동을 위한 변수.

	while (*decisionPrintListVal == 1) {

		input = _getch(); // 새로운 커맨드를 입력받아 페이지를 넘길지, 메뉴로 돌아갈지 결정.

		switch (input) {

		case LEFT:

			if (*pageNum != 0) {

				system("cls");
				*pageNum -= 1;
				printMenu(selectVal, decisionPrintListVal);
				printMusicIndex(pageNum, count);
				break;
			}

			else {

				system("cls");
				printMenu(selectVal, decisionPrintListVal);
				printMusicIndex(pageNum, count);
				break;
			}

		case RIGHT:

			if (*pageNum != (*count / INDEXLISTNUM)) {

				system("cls");
				*pageNum += 1;
				printMenu(selectVal, decisionPrintListVal);
				printMusicIndex(pageNum, count);
				break;
			}
			else {

				system("cls");
				printMenu(selectVal, decisionPrintListVal);
				printMusicIndex(pageNum, count);
				break;
			}

		case UP:
			*decisionPrintListVal = 0;
			break;

		default:

			system("cls");
			printMenu(selectVal, decisionPrintListVal);
			printMusicIndex(pageNum, count);
		}
	}
}

void printMusicIndex(int* pageNum, int* count) {
	
	int i;
	int wholePage = (*count / INDEXLISTNUM) + 1;
	char name[] = "곡이름";
	char artist[] = "가수이름";
	char release[] = "발매년도";

	printf("	번호   %20s %20s   %6s\n", name, artist, release);

	for (i = (*pageNum * INDEXLISTNUM); i < ((*pageNum + 1) * INDEXLISTNUM); i++) {

		if (*count - i == 0) {

			printf("\n ▶ 음악 목록의 끝입니다. \n");
			printf(" ◎ 목록에 총 %d개의 곡이 등록되어 있습니다. \n", *count);
			printf(" ◎ 총 %d 페이지 중 현재 %d 페이지. ( ←,→ : 페이지 이동 )\n", wholePage, *pageNum + 1);
			return;

		}
		else {

			printf("	[%3d] %20s %20s   %6d\n",i+1, m[i].name, m[i].artist, m[i].release);

		}
	}

	printf("\n ▶ 현재 페이지의 끝입니다. \n");
	printf(" ◎ 목록에 총 %d개의 곡이 등록되어 있습니다. \n", *count);
	printf(" ◎ 총 %d 페이지 중 현재 %d 페이지. ( ←,→ : 페이지 이동 )\n", wholePage, *pageNum + 1);

	return;
}

void registerMusic(int *decisionPrintListVal, int* selectVal, int* count, int* savTrigger) {

	char name[SIZEOFELEMENT];
	char artist[SIZEOFELEMENT];
	int release;
	char temp[SIZEOFELEMENT];

	if (*count >= INDEXLISTMAXNUM) {

		printf("	255곡 이상 등록하실수 없습니다. \n");
		printf("	죄송합니다. 업그레이드 된 다음 버전을 기다려주세요!! :) \n");
		printf("	↑ : 메뉴 돌아가기\n");
		selectAfterRegist(decisionPrintListVal, selectVal, count, savTrigger);
		return;

	}


	printf("		등록하실 음악의 정보를 입력해주세요.  ( 취소 : 0 입력 )\n");
	printf("	%d번째 곡 \n", *count + 1);

	while (1) {

		printf("	곡 이름 : ");

		fgets(name, SIZEOFELEMENT, stdin);

		if ((name[0] == '\n') || (strlen(name) > SIZEOFELEMENT - 1)) {

			printf("	이름은 1~20자입니다. 다시 입력해주세요. \n");

		}
		else if (name[0] == '0') {

			*decisionPrintListVal = 0;
			return;

		}
		else {

			break;
		}
		
	}

	

	while (1) {

		printf("	가수 이름 : ");

		gets(artist);

		if ((artist[0] == '\n') || (strlen(artist) > SIZEOFELEMENT - 1)) {

			printf("	가수 이름은 1~20자입니다. 다시 입력해주세요. \n");

		}
		else if (artist[0] == '0') {

			*decisionPrintListVal = 0;
			return;

		}
		else {

			break;

		}

	}

	fflush(stdin);

	while (1) {

		printf("	발매 년도 : ");

		gets(temp);

		release = atoi(temp);

		if ((release == NULL) || (release > YEAR) || (release < 0)) {

			printf("	뭐라구요? 다시 입력해주세요. \n "); 
			//getchar();

		}
		else if (release == 0) {

			*decisionPrintListVal = 0;
			return;

		}
		else {

			break;

		}

	}

	fflush(stdin);

	strcpy(m[*count].name, name);
	strcpy(m[*count].artist, artist);
	m[*count].release = release;
	*count = *count + 1;
	*savTrigger = 1;

	printf("	등록이 완료되었습니다! \n");
	printf("	↑ : 메뉴 돌아가기, → : 새로운 곡 등록 \n");

	selectAfterRegist(decisionPrintListVal, selectVal, count, savTrigger);

	return;
}


void selectAfterRegist(int* decisionPrintListVal, int* selectVal, int* count, int* savTrigger) {

	char input; // input에 따라 메뉴 진입 취소, 페이지 이동을 위한 변수.

	while (*decisionPrintListVal == 1) {

		input = _getch(); // 새로운 커맨드를 입력받아 페이지를 넘길지, 메뉴로 돌아갈지 결정.

		switch (input) {

		case RIGHT:

			system("cls");
			printMenu(selectVal, decisionPrintListVal);
			registerMusic(decisionPrintListVal, selectVal, count, savTrigger);
			break;

		case UP:

			*decisionPrintListVal = 0;
			break;

		default:

			selectAfterRegist(decisionPrintListVal, selectVal, count, savTrigger);

		}
	}
}

void saveMemoryData(int* count, int* oriCount, int* savTrigger) {

	FILE *savData;
	int i;

	if (*savTrigger == 1) {

		savData = fopen("data.txt", "a");

		for (i = *oriCount; i < *count; i++) {

			fprintf(savData, "\n%s%c%s%c%d", m[i].name, SAPARATE, m[i].artist, SAPARATE, m[i].release);

		}

		*savTrigger = 0;

		
	}
	else if (*savTrigger == 2) {

		savData = fopen("data.txt", "w+");

		for (i = 0; i < *count; i++) {

			fprintf(savData, "%s%c%s%c%d\n", m[i].name, SAPARATE, m[i].artist, SAPARATE, m[i].release);

		}

		*savTrigger = 0;

	}
	else {

		printf("	이미 데이터가 최신 상태입니다. \n");
		printf("	↑ : 메뉴 돌아가기 \n");


		return;
	}
	
	fclose(savData);
	
	printf("	저장이 성공적으로 완료되었습니다! \n");
	printf("	↑ : 메뉴 돌아가기 \n");

	return;
}

void afterSave(int* selectVal, int* decisionPrintListVal, int* count, int* oriCount) {

	char input;

	while (*decisionPrintListVal == 1) {

		input = _getch(); // 새로운 커맨드를 입력받아 페이지를 넘길지, 메뉴로 돌아갈지 결정.

		switch (input) {
			case UP :

				*decisionPrintListVal = 0;
				break;

			default :

				continue;
		}
	}
}


int main(void) {
	
	int count = countMusic();
	int oriCount = countMusic();
	int selectVal = 0;
	int decisionPrintListVal = 0;
	int pageNum = 0;
	int savTrigger = 0;
	int findTrigger = 0;

	readMusicIndex(count);

	while (1) {
		system("cls");
		printMenu(&selectVal, &decisionPrintListVal);
		inputKeyboard(&selectVal, &decisionPrintListVal);
		fuctionStart(&selectVal, &decisionPrintListVal, &pageNum, &count, &oriCount, &savTrigger, &findTrigger);
	}


	return 0;
}