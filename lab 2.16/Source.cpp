#include "List.h"

int main() {
	system("chcp 1251");
	List list;
	List sortedList;
	int choice;
	while (true) {
		printf("1 - �������� �������; 2 - ������� �������; 3 - �������� list; 4 - �����\n"); scanf_s("%d", &choice);
		if (choice == 1) {
			int tmp; printf("������� �������: "); scanf_s("%d", &tmp);
			int choicePush;
			printf("���� �������� �������?\n1 - ������; 2 - �����; 3 - �������\n"); scanf_s("%d", &choicePush);
			if (choicePush == 1)
				pushToHead(list, tmp);
			if (choicePush == 2)
				pushToTail(list, tmp);
			if (choicePush == 3) {
				int pos; printf("������� ������� ���� �������� �������\n"); scanf_s("%d", &pos);
				pushToPosition(list, tmp, pos);
			}
		}
		if (choice == 2) {
			int tmp, choicePull;
			printf("������ ������� �������?\n1 - ������; 2 - �����; 3 - �������\n"); scanf_s("%d", &choicePull);
			if (choicePull == 1)
				tmp = pullToHead(list);
			if (choicePull == 2)
				tmp = pullToTail(list);
			if (choicePull == 3) {
				int pos; printf("������� ������� ������ ������� �������\n"); scanf_s("%d", &pos);
				tmp = pullToPosition(list, pos);
			}
			printf("�������� %d\n", tmp);
		}
		if (choice == 3) {
			clear(list);
		}
		if (choice == 4) {
			clear(list);
			exit(1);
		}

		printf("����������������� list\n");
		printList(list);
		/*printf("��������������� list\n");
		printList(sortedList);*/
	}
}