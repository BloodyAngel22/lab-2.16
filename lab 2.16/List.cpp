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
		printf("позиция должна быть > 0");
		return;
	}
	if (pos == 1) {
		pushToHead(l, data);
		return;
	}
	if (pos == l.size + 1) {
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
	}
}

int pullToHead(List& l) {
	if (l.head == NULL) return 0;
	int d = l.head->data;
	Element* e = l.head;
	l.head = l.head->next;
	free(e);
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
	return d;
}

void clear(List& l) {
	if (l.head == NULL) return;
	for (l.head; l.head != NULL; l.head = l.head->next) {
		Element* e = l.head;
		l.head = l.head->next;
		free(e);
		if (l.head == NULL) return;
	}
}

void sortedList(List& l) {
	Element* e = l.head;

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