// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"quene.h"
#include<stdio.h>
#include<stdlib.h>


struct entry {
	int i;
	SLIST_ENTRY(entry) next;
};

SLIST_HEAD(top, entry) head;

int main() {

	SLIST_INIT(&head);
	SLIST_EMPTY(&head);

	struct entry *n1 = (entry*)malloc(sizeof(struct entry));
	n1->i = 1;
	SLIST_INSERT_HEAD(&head, n1, next);

	struct entry *n2 =(entry*) malloc(sizeof(struct entry));
	n2->i = 2;
	SLIST_INSERT_HEAD(&head, n2, next);

	{
		struct entry *n2 = (entry*)malloc(sizeof(struct entry));
		n2->i = 3;
		SLIST_INSERT_HEAD(&head, n2, next);
	}
	{
		struct entry *n2 = (entry*)malloc(sizeof(struct entry));
		n2->i = 4;
		SLIST_INSERT_HEAD(&head, n2, next);
	}
	{
		struct entry *n2 = (entry*)malloc(sizeof(struct entry));
		n2->i = 5;
		SLIST_INSERT_HEAD(&head, n2, next);
	}
	{
		struct entry *n2 = (entry*)malloc(sizeof(struct entry));
		n2->i = 6;
		SLIST_INSERT_HEAD(&head, n2, next);
	}

	struct entry *np = 0;
	SLIST_FOREACH(np, &head, next) {
		printf("Helo:%d\n",np->i);
	}

	while (head.slh_first != NULL)
	{
		struct entry* temp = head.slh_first;
		SLIST_REMOVE_HEAD(&head, next);
		printf("delete:%d\n", temp->i);
		free(temp);

	}

	return 0;
}





