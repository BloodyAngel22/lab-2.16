#include "List.h"

void pushToHead(List& l, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;
	e->next = l.head;
	l.head = e;
	l.size++;
}

void pushToTail(List& l, int data) {
	Element* e = (Element*)malloc(sizeof(Element));
	e->data = data;
	e->next = NULL;
	if (l.head == NULL) {
		l.head = e;
	}
	else {
		Element* cur = l.head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = e;
	}
	l.size++;
}

void pushToPosition(List& l, int data, int pos) {
	if (pos <= 0) {
		printf("позиция должна быть > 0\n");
		return;
	}
	if (pos-1 > l.size) {
		printf("Ошибка: позиция выходит за границы списка!\n");
		return;
	}
	if (pos-1 == 0) {
		pushToHead(l, data);
		return;
	}
	if (pos-1 == l.size) {
		pushToTail(l, data);
		return;
	}
	else {
		Element* current = l.head;
		for (int i = 0; i < pos-2; i++) {
			if (current == NULL) {
				printf("Ошибка: позиция выходит за границы списка!\n");
				return;
			}
			current = current->next;
		}
		Element* e = (Element*)malloc(sizeof(Element));
		e->data = data;
		e->next = current->next;
		current->next = e;
		l.size++;
	}
}

int pullToHead(List& l) {
	if (l.head == NULL) return 0;
	int d = l.head->data;
	Element* e = l.head;
	l.head = l.head->next;
	free(e);
	l.size--;
	return d;
}

int pullToTail(List& l) {
	if (l.head == NULL) return 0;
	Element* cur = l.head;
	if (l.head->next == NULL) {
		int d = cur->data;
		l.head = NULL;
		free(cur);
		return d;
	}
	while (cur->next->next != NULL)
		cur = cur->next;
	int d = cur->next->data;
	free(cur->next);
	cur->next = NULL;
	l.size--;
	return d;
}

int pullToPosition(List& l, int pos) {
	int tmp;
	if (l.head == NULL) return 0;
	if (pos <= 0) {
		printf("позиция должна быть > 0\n");
		return 0;
	}
	if (pos-1 >= l.size) {
		printf("Ошибка: позиция выходит за границы списка!\n");
		return 0;
	}
	if (pos-1 == 0) {
		tmp = pullToHead(l);
		return tmp;
	}
	else {
		Element* current = l.head;
		for (int i = 0; i < pos-2; i++) {
			if (current == NULL) {
				printf("Ошибка: позиция выходит за границы списка!\n");
				return 0;
			}
			current = current->next;
		}
		Element* next = current->next->next;
		int d = current->next->data;
		free(current->next);
		current->next = next;
		l.size--;
		return d;
	}
}

void clear(List& l) {
	if (l.head == NULL) return;
	for (;l.head != NULL;) {
		Element* e = l.head;
		l.head = l.head->next;
		free(e);
	}
}

void pushSortedList(List& sortedList, int data) {
	if (sortedList.head == NULL) {
		Element* e = (Element*)malloc(sizeof(Element));
		e->data = data;
		e->next = sortedList.head;
		sortedList.head = e;
	}
	else {
		Element* cur = sortedList.head;
		for (cur; cur != NULL; cur = cur->next) {
			if (cur->data > data) {
				Element* e = (Element*)malloc(sizeof(Element));
				e->data = data;
				e->next = sortedList.head;
				sortedList.head = e;
				break;
			}
			if (cur->data < data and cur->next == NULL) {
				Element* e = (Element*)malloc(sizeof(Element));
				e->data = data;
				e->next = NULL;
				cur->next = e;
				break;
			}
			if (cur->data < data and cur->next->data > data) {
				Element* e = (Element*)malloc(sizeof(Element));
				e->data = data;
				e->next = cur->next;
				cur->next = e;
				break;
			}
		}
	}
	sortedList.size++;
}

void printList(List& l) {
	if (l.head == NULL) return;
	for (Element* cur = l.head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("\b\b\b   \n");
}

void printSortedList(List& l) {

}