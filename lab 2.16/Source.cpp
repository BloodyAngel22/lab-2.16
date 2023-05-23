#include "List.h"

/*Сформировать список динамических элементов, упорядоченный
по возрастанию. Включить в список новый элемент, сохранив
свойство упорядоченности. Из каждой группы подряд идущих
одинаковых элементов оставить один. Распечатать исходный и
результирующий списки.*/

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
			if (choicePush == 1) {
				pushToHead(list, tmp);
			}
			if (choicePush == 2)
				pushToTail(list, tmp);
			if (choicePush == 3) {
				int pos; printf("Введите позицию куда вставить элемент\n"); scanf_s("%d", &pos);
				pushToPosition(list, tmp, pos);
			}
			pushSortedList(sortedList, tmp);
		}
		if (choice == 2) {
			int tmp1, tmp2, choicePull;
			printf("Откуда удалить элемент?\n1 - голова; 2 - хвост; 3 - позиция\n"); scanf_s("%d", &choicePull);
			if (choicePull == 1) {
				tmp1 = pullToHead(list);
				tmp2 = pullToHead(sortedList);
			}
			if (choicePull == 2) {
				tmp1 = pullToTail(list);
				tmp2 = pullToTail(sortedList);
			}
			if (choicePull == 3) {
				int pos; printf("Введите позицию откуда удалить элемент\n"); scanf_s("%d", &pos);
				tmp1 = pullToPosition(list, pos);
				tmp2 = pullToPosition(sortedList, pos);
			}
			printf("Удаление %d, %d\n", tmp1, tmp2);
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

		printf("Неотсортированный list\n");
		printList(list);
		printf("Отсортированный list\n");
		printList(sortedList);
	}
}