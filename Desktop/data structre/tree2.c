#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
typedef TreeNode* element;
typedef struct {
	element data[100];
	int front, rear;
}Queue;
void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(Queue* q) {
	return (q->front == q->rear);
}
int is_full(Queue* q) {
	return ((q->rear + 1) % 100 == q->front); 
}
void enqueue(Queue* q, element data) {
	if (is_full(q)) { exit(1); }
	q->rear = (q->rear + 1) % 100;
	q->data[q->rear] = data;
}
element dequeue(Queue* q) {
	if (is_empty(q))exit(1);
	q->front = (q->front + 1) % 100;
	return (q->data[q->front]);
}
void level_order(TreeNode* root) {
	Queue q;
	init(&q);
	enqueue(&q, root);
	while (!is_empty(&q)) {
		root = dequeue(&q);
		printf("[%d]", root->data);
		if (root->left)enqueue(&q, root->left);
		if (root->right)enqueue(&q, root->right);
	}
}
void preorder(TreeNode* t) {
	if (t != NULL) {
		printf("[%d]", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(TreeNode* t) {
	if (t != NULL) {
		inorder(t->left);
		printf("[%d]", t->data);
		inorder(t->right);
	}
}
void postorder(TreeNode* t) {
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		printf("[%d]", t->data);
	}
}
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main() {
	postorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	level_order(root);
	printf("\n");
	return 0;
}