/*
	���ϸ� : musicIndex.c
	���� ���� : �־��� �����͸� ���� �� �ִ� ���α׷� ����
	�ۼ��� : 141060 �̱ٿ�
	�ۼ����� : 16.05.04
*/


#include "musicIndex.h"



// �޴��� ����ϴ� �Լ�


void printTopLine(void) {
	
	// TopLine�� ����ϴ� �Լ�.
	int i;

	printf("��");

	for (i = 0; i < LINENUM; i++) {

		printf("��");

	}

	printf("��\n");
}

void printBottomLine(void) {
	
	// BottomLine�� ����ϴ� �Լ�.
	int i;

	printf("��");
	
	for (i = 0; i < LINENUM; i++) {
	
		printf("��");
	}

	printf("��\n");
}

void printTitle(void) {
	
	// �޴� �� Ÿ��Ʋ�� ����ϴ� �Լ� printTitle.

	printf("\n MUSIC INDEX : �ڽ��� �λ����� �����ϼ���! \n");
	printf(" Ver. 1.3 (16.05.16) - ���� ���, ���� ���, ���� �˻�, ���� ���, ���� ��� ���� \n\n");

}

void printMenu(int* selectVal, int* decisionPrintListVal) {
	// selectVal�� ���� � �޴��� �������� ǥ���� �ִ� �Լ�.

	int i;

	printTitle();
	printTopLine();

	printf("�� ");

	switch (*selectVal) {

	case 0:

		printf("�� ���� ���  ");
		printf("2. ���� ���  ");
		printf("3. ���� ����  ");
		printf("4. ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("7. ����  ");
		break;

	case 1:

		printf("1. ���� ���  ");
		printf("�� ���� ���  ");
		printf("3. ���� ����  ");
		printf("4. ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("7. ����  ");
		break;

	case 2:

		printf("1. ���� ���  ");
		printf("2. ���� ���  ");
		printf("�� ���� ����  ");
		printf("4. ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("7. ����  ");
		break;

	case 3:

		printf("1. ���� ���  ");
		printf("2. ���� ���  ");
		printf("3. ���� ����  ");
		printf("�� ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("7. ����  ");
		break;

	case 4:

		printf("1. ���� ���  ");
		printf("2. ���� ���  ");
		printf("3. ���� ����  ");
		printf("4. ��� ����  ");
		printf("�� ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("7. ����  ");
		break;

	case 5:

		printf("1. ���� ���  ");
		printf("2. ���� ���  ");
		printf("3. ���� ����  ");
		printf("4. ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("�� ��� ����  ");
		printf("7. ����  ");
		break;

	case 6:

		printf("1. ���� ���  ");
		printf("2. ���� ���  ");
		printf("3. ���� ����  ");
		printf("4. ��� ����  ");
		printf("5. ���� �˻�  ");
		printf("6. ��� ����  ");
		printf("�� ����  ");
		break;

	}

	printf("��\n");
	printBottomLine();

	if (*decisionPrintListVal == 0) {

		printf("��,�� : �޴��̵� / ��,�� : �޴� ����, ���� \n\n");

	}

	else {

		switch (*selectVal) {

		case 0:

			printf("��,�� : ������ �̵� / ��,�� : �޴� ����, ���� \n\n");
			break;

		}
	}
}




void inputKeyboard(int* selectVal, int* decisionPrintListVal) {

	// Ű���� ����Ű LEFT,RIGNT,UP,DOWN�� �޾� selectVal, decisionPrintListVal�� �ٲٴ� �Լ�.
	
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
	// FunctionStart�� ����Ű�ε� �۵��� �� �ֵ��� �ϴ� ���� �Լ�.


	*decisionPrintListVal = 1;
	*selectVal = input - 1;

	return;
}




void readMusicIndex(int count) {
	// ���� �����͸� �о���̴� �Լ�.

	
	FILE* data;
	char inputBuffer[sizeof(Music)];
	int i;

	if (count == 0) {
		printf("���ο� ������ �����մϴ�... \n");
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
	// ������ �о� Music����ü ���Ŀ� �°� ������ �����ϴ� �Լ�.

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
	// ���� ��Ͽ� ��ϵ� ���� ������ �����ִ� �Լ�.
	
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
	// �Է¹��� ����Ű�� selectVal�� ���� ����� �����ϰ� �ϴ� �Լ� fuctionStart.


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

		printf("	�����Ͻ� ������ ��ȣ�� �Է��Ͻʽÿ� ( 0 to exit ) : ");
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


	printf("	������ �Ϸ�Ǿ����ϴ�! \n");
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

		printf("	���� ���� ����Դϴ�. \n");
		printf("	������ ���� �˻��մϴ�. � ������ ã���ðڽ��ϱ�? \n");
		printf("	( �� : �̵� , �� or ENTER : ���� , �� : �޴� ������ ) \n\n");

	}
	else if (findType == FINDANDFIX) {
		
		printf("	���� ���� ����Դϴ�. \n");
		printf("	������ ���� �˻��մϴ�. � ������ ã���ðڽ��ϱ�? \n");
		printf("	( �� : �̵� , �� or ENTER : ���� , �� : �޴� ������ ) \n\n");

	}
	else {

		printf("	 ���� �˻� ����Դϴ�. � ������ ã���ðڽ��ϱ�? \n");
		printf("	( �� : �̵� , �� or ENTER : ���� , �� : �޴� ������ ) \n\n");

	}


	if (menuNum == 1){
	
		printf("	�� �� �̸�    2. ���� �̸�    3. �߸� �⵵ \n");
		return;

	}
	else if (menuNum == 2) {

		printf("	1. �� �̸�    �� ���� �̸�    3. �߸� �⵵ \n");
		return;

	}
	else {

		printf("	1. �� �̸�    2. ���� �̸�    �� �߸� �⵵ \n");
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

		printf("\n	�� �̸����� �˻��մϴ�. \n");
		printf("	ã���ô� �� �̸� �Ǵ� �Ϻκ��� �Է����ּ��� :");

		while (1) {

			gets(name);

			if ((name == NULL) || (strlen(name) > SIZEOFELEMENT - 1) || (name[0] == '\n')) {

				printf("	���� �̸��� 1~20���Դϴ�. �ٽ� �Է����ּ��� :");

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

			printf("	ã���ô� ���� ������ �����ϴ�. \n \n");
			printf("	         �� �̸�                   ���� �̸�           �߸� �⵵ \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i + 1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	ã���ô� Ű������ ���� �������� �ʽ��ϴ�. \n");

		}
	}

	else if (menuNum == 2) {


		printf("\n	���� �̸����� �˻��մϴ�. \n");
		printf("	ã���ô� ���� �̸� �Ǵ� �Ϻκ��� �Է����ּ��� :");

		while (1) {

			gets(artist);

			if ((artist == NULL) || (strlen(artist) > SIZEOFELEMENT - 1) || (artist[0] == '\n')) {

				printf("	���� �̸��� 1~20���Դϴ�. �ٽ� �Է����ּ��� :");

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
		
			printf("	ã���ô� ���� ������ �����ϴ�. \n \n");
			printf("	         �� �̸�                   ���� �̸�           �߸� �⵵ \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i + 1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	ã���ô� Ű������ ���� �������� �ʽ��ϴ�. \n");

		}
	}

	else {

		printf("\n	�߸� �⵵���� �˻��մϴ�. \n");
		printf("	ã���ô� �߸ų⵵�� �Է����ּ��� :");

		while (1) {

			gets(temp);

			release = atoi(temp);

			if ((release <= 0) || (release > YEAR)) {

				printf("	�߸ų⵵�� 1~3000���� �Է��� �� �ֽ��ϴ�. �ٽ� �Է����ּ��� :");

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

			printf("	ã���ô� ���� ������ �����ϴ�. \n \n");
			printf("	��ȣ	         �� �̸�                   ���� �̸�           �߸� �⵵ \n");

			for (i = 0; i < tempIdx; i++) {

				j = tempArr[i];
				printf("	%3d	%20s   %20s		%6d\n", i+1, m[j].name, m[j].artist, m[j].release);

			}
		}
		else {

			printf("	ã���ô� Ű������ ���� �������� �ʽ��ϴ�. \n");

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

		printf("\n	�����Ͻ� ������ ��ȣ�� �Է��Ͻʽÿ� ( 0 to exit ) : ");
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

	printf("\n	������ �׸��� �������ֽʽÿ� ( 1: �� �̸�, 2: ���� �̸�, 3: �߸� �⵵ ) : \n");
	
	gets(temp);
	temp[SIZEOFELEMENT - 1] = '\0';
	itemNum = atoi(temp);
	
	fixItem(itemNum, num - 1);


	printf("	������ �Ϸ�Ǿ����ϴ�!\n");
	afterFix(decisionPrintListVal);

}

void fixItem(int itemNum, int idxToFix) {

	char temp[SIZEOFELEMENT];


	if (itemNum == 1) {

		printf("\n	�� �̸��� �����մϴ�. \n");
		printf("	�ٲ� �� �̸��� �Է����ּ��� :");
		fgets(temp, SIZEOFELEMENT, stdin);

		strcpy(m[idxToFix].name, temp);

	}
	else if (itemNum == 2) {

		printf("\n	���� �̸��� �����մϴ�. \n");
		printf("	�ٲ� ���� �̸��� �Է����ּ��� :");
		fgets(temp, SIZEOFELEMENT, stdin);

		strcpy(m[idxToFix].artist, temp);

	}
	else {

		while (1) {

			printf("\n	���� �̸��� �����մϴ�. \n");
			printf("	�ٲ� ���� �̸��� �Է����ּ��� :");
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

	printf("	�� : �޴� ���ư��� \n");

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

	printf("	�� : �޴� ���ư��� \n");

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

	printf("\n	�� : �޴� ���ư���\n");

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

		printf("	���α׷��� �����մϴ�.  \n");

		exit(0);

	}
	else if (*savTrigger == 1 || *savTrigger == 2) {

		printf("	������ ��������� �����Ͻðڽ��ϱ�? ( �� : �̵� , �� or ENTER : ����, �� : �޴� ������ )\n");
		printf("	�� ��	2. �ƴϿ� \n");

		while (*decisionPrintListVal == 1) {

			input = _getch();

			switch (input) {

			case RIGHT:

				if (select == 0) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	������ ��������� �����Ͻðڽ��ϱ�? ( �� : �̵� , �� or ENTER : ����, �� : �޴� ������ )\n");
					printf("	 1. ��	�� �ƴϿ� \n");
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
					printf("	������ ��������� �����Ͻðڽ��ϱ�? ( �� : �̵� , �� or ENTER : ����, �� : �޴� ������ )\n");
					printf("	�� ��	2. �ƴϿ� \n");
					select = 0;
					break;

				}
				else {

					break;

				}

			case ENTER: case DOWN: case '1':

				if (select == 1) {

					printf("	���α׷��� �����մϴ�. \n");
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




					printf("	������ �Ϸ�Ǿ����ϴ�. ���α׷��� �����մϴ�. \n");
					exit(0);

				}


			case UP: case '2':

				*decisionPrintListVal = 0;
				return;


			default :
				
				if (select == 0) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	������ ��������� �����Ͻðڽ��ϱ�? ( �� : �̵� , �� or ENTER : ����, �� : �޴� ������ )\n");
					printf("	 1. ��	�� �ƴϿ� \n");
					select = 1;
					break;

				}

				if (select == 1) {

					system("cls");
					printMenu(selectVal, decisionPrintListVal);
					printf("	������ ��������� �����Ͻðڽ��ϱ�? ( �� : �̵� , �� or ENTER : ����, �� : �޴� ������ )\n");
					printf("	�� ��	2. �ƴϿ� \n");
					select = 0;
					break;

				}
			}
		}
	}
}


void selectPrintPage(int* decisionPrintListVal, int* pageNum, int* selectVal, int* count) {
	// ���� ��� ����� ���� �� �Է��� �޾� ���� �۾��� �����ϴ� �Լ�.

	char input; // input�� ���� �޴� ���� ���, ������ �̵��� ���� ����.

	while (*decisionPrintListVal == 1) {

		input = _getch(); // ���ο� Ŀ�ǵ带 �Է¹޾� �������� �ѱ���, �޴��� ���ư��� ����.

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
	char name[] = "���̸�";
	char artist[] = "�����̸�";
	char release[] = "�߸ų⵵";

	printf("	��ȣ   %20s %20s   %6s\n", name, artist, release);

	for (i = (*pageNum * INDEXLISTNUM); i < ((*pageNum + 1) * INDEXLISTNUM); i++) {

		if (*count - i == 0) {

			printf("\n �� ���� ����� ���Դϴ�. \n");
			printf(" �� ��Ͽ� �� %d���� ���� ��ϵǾ� �ֽ��ϴ�. \n", *count);
			printf(" �� �� %d ������ �� ���� %d ������. ( ��,�� : ������ �̵� )\n", wholePage, *pageNum + 1);
			return;

		}
		else {

			printf("	[%3d] %20s %20s   %6d\n",i+1, m[i].name, m[i].artist, m[i].release);

		}
	}

	printf("\n �� ���� �������� ���Դϴ�. \n");
	printf(" �� ��Ͽ� �� %d���� ���� ��ϵǾ� �ֽ��ϴ�. \n", *count);
	printf(" �� �� %d ������ �� ���� %d ������. ( ��,�� : ������ �̵� )\n", wholePage, *pageNum + 1);

	return;
}

void registerMusic(int *decisionPrintListVal, int* selectVal, int* count, int* savTrigger) {

	char name[SIZEOFELEMENT];
	char artist[SIZEOFELEMENT];
	int release;
	char temp[SIZEOFELEMENT];

	if (*count >= INDEXLISTMAXNUM) {

		printf("	255�� �̻� ����ϽǼ� �����ϴ�. \n");
		printf("	�˼��մϴ�. ���׷��̵� �� ���� ������ ��ٷ��ּ���!! :) \n");
		printf("	�� : �޴� ���ư���\n");
		selectAfterRegist(decisionPrintListVal, selectVal, count, savTrigger);
		return;

	}


	printf("		����Ͻ� ������ ������ �Է����ּ���.  ( ��� : 0 �Է� )\n");
	printf("	%d��° �� \n", *count + 1);

	while (1) {

		printf("	�� �̸� : ");

		fgets(name, SIZEOFELEMENT, stdin);

		if ((name[0] == '\n') || (strlen(name) > SIZEOFELEMENT - 1)) {

			printf("	�̸��� 1~20���Դϴ�. �ٽ� �Է����ּ���. \n");

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

		printf("	���� �̸� : ");

		gets(artist);

		if ((artist[0] == '\n') || (strlen(artist) > SIZEOFELEMENT - 1)) {

			printf("	���� �̸��� 1~20���Դϴ�. �ٽ� �Է����ּ���. \n");

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

		printf("	�߸� �⵵ : ");

		gets(temp);

		release = atoi(temp);

		if ((release == NULL) || (release > YEAR) || (release < 0)) {

			printf("	���󱸿�? �ٽ� �Է����ּ���. \n "); 
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

	printf("	����� �Ϸ�Ǿ����ϴ�! \n");
	printf("	�� : �޴� ���ư���, �� : ���ο� �� ��� \n");

	selectAfterRegist(decisionPrintListVal, selectVal, count, savTrigger);

	return;
}


void selectAfterRegist(int* decisionPrintListVal, int* selectVal, int* count, int* savTrigger) {

	char input; // input�� ���� �޴� ���� ���, ������ �̵��� ���� ����.

	while (*decisionPrintListVal == 1) {

		input = _getch(); // ���ο� Ŀ�ǵ带 �Է¹޾� �������� �ѱ���, �޴��� ���ư��� ����.

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

		printf("	�̹� �����Ͱ� �ֽ� �����Դϴ�. \n");
		printf("	�� : �޴� ���ư��� \n");


		return;
	}
	
	fclose(savData);
	
	printf("	������ ���������� �Ϸ�Ǿ����ϴ�! \n");
	printf("	�� : �޴� ���ư��� \n");

	return;
}

void afterSave(int* selectVal, int* decisionPrintListVal, int* count, int* oriCount) {

	char input;

	while (*decisionPrintListVal == 1) {

		input = _getch(); // ���ο� Ŀ�ǵ带 �Է¹޾� �������� �ѱ���, �޴��� ���ư��� ����.

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