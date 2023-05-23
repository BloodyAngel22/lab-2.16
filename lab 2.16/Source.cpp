#include "List.h"

/*������������ ������ ������������ ���������, �������������
�� �����������. �������� � ������ ����� �������, ��������
�������� ���������������. �� ������ ������ ������ ������
���������� ��������� �������� ����. ����������� �������� �
�������������� ������.*/

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
			if (choicePush == 1) {
				pushToHead(list, tmp);
			}
			if (choicePush == 2)
				pushToTail(list, tmp);
			if (choicePush == 3) {
				int pos; printf("������� ������� ���� �������� �������\n"); scanf_s("%d", &pos);
				pushToPosition(list, tmp, pos);
			}
			pushSortedList(sortedList, tmp);
		}
		if (choice == 2) {
			int tmp1, tmp2, choicePull;
			printf("������ ������� �������?\n1 - ������; 2 - �����; 3 - �������\n"); scanf_s("%d", &choicePull);
			if (choicePull == 1) {
				tmp1 = pullToHead(list);
				tmp2 = pullToHead(sortedList);
			}
			if (choicePull == 2) {
				tmp1 = pullToTail(list);
				tmp2 = pullToTail(sortedList);
			}
			if (choicePull == 3) {
				int pos; printf("������� ������� ������ ������� �������\n"); scanf_s("%d", &pos);
				tmp1 = pullToPosition(list, pos);
				tmp2 = pullToPosition(sortedList, pos);
			}
			printf("�������� %d, %d\n", tmp1, tmp2);
		}
		if (choice == 3) {
			clear(list);
			clear(sortedList);
		}
		if (choice == 4) {
			clear(list);
			clear(sortedList);
			exit(1);
		}

		printf("����������������� list\n");
		printList(list);
		printf("��������������� list\n");
		printList(sortedList);
	}
}