#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* llink;
	struct ListNode* rlink;
}ListNode;
void init(ListNode* head) {
	head->llink = head;
	head->rlink = head;
}
void print_list(ListNode* head) {
	ListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}
void insert(ListNode* before, element data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->llink = before;
	p->rlink = before->rlink;
	before->rlink->llink = p;
	before->rlink = p;
}
void delete(ListNode* before) {
	ListNode* removed;
	removed = before->rlink;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
int main() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);
	for (int i = 0; i < 5; i++) {
		insert(head, i);
		print_list(head);
	}
	free(head);
	return 0;
}