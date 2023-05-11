#pragma once
#include <iostream>

struct Element {
	int data;
	Element* next;
};

struct List {
	Element* head = NULL; 
	int size = 0;
};

void printSortedList(List& l); void printList(List& l);
void clear(List& l); int pullToHead(List& l); void pushToHead(List& l, int data);
void pushToTail(List& l, int data); void pushToPosition(List& l, int data, int pos);
int pullToTail(List& l); int pullToPosition(List& l, int pos); void pushSortedList(List& sortedList, int data);