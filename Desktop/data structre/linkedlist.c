#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Listnode {
	element data;
	struct Listnode* link;
}ListNode;
ListNode* insert_first(ListNode* head,element data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert(ListNode* head, ListNode* prev, element data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = prev->link;
	prev->link = p;
	return head;
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete(ListNode* head, ListNode* prev) {
	ListNode* removed;
	removed = prev->link;
	prev->link = removed->link;
	free(removed);
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
int get_length(ListNode* head) {
	int cnt=0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		cnt++;
	}
	return cnt;
}
int main() {
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	printf("%d\n", get_length(head));
	for (int i = 0; i < 5; i++) {
		head = delete_first(head, i);
		print_list(head);
	}
	return 0;
}