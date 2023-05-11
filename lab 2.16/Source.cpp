#include "List.h"

int main() {
	system("chcp 1251");
	List list;
	List sortedList;
	int choice;
	while (true) {
		printf("1 - добавить элемент; 2 - удалить элемент; 3 - очистить list; 4 - выход\n"); scanf_s("%d", &choice);
		if (choice == 1) {
			int tmp; printf("Введите элемент: "); scanf_s("%d", &tmp);
			int choicePush;
			printf("Куда добавить элемент?\n1 - голова; 2 - хвост; 3 - позиция\n"); scanf_s("%d", &choicePush);
			if (choicePush == 1)
				pushToHead(list, tmp);
			if (choicePush == 2)
				pushToTail(list, tmp);
			if (choicePush == 3) {
				int pos; printf("Введите позицию куда вставить элемент\n"); scanf_s("%d", &pos);
				pushToPosition(list, tmp, pos);
			}
		}
		if (choice == 2) {
			int tmp, choicePull;
			printf("Откуда удалить элемент?\n1 - голова; 2 - хвост; 3 - позиция\n"); scanf_s("%d", &choicePull);
			if (choicePull == 1)
				tmp = pullToHead(list);
			if (choicePull == 2)
				tmp = pullToTail(list);
			if (choicePull == 3) {
				int pos; printf("Введите позицию откуда удалить элемент\n"); scanf_s("%d", &pos);
				tmp = pullToPosition(list, pos);
			}
			printf("Удаление %d\n", tmp);
		}
		if (choice == 3) {
			clear(list);
		}
		if (choice == 4) {
			clear(list);
			exit(1);
		}

		printf("Неотсортированный list\n");
		printList(list);
		/*printf("Отсортированный list\n");
		printList(sortedList);*/
	}
}