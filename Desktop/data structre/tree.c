#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Tree {
	element data;
	struct Tree* left;
	struct Tree* right;
}Tree;
int get_node_count(Tree* root) {
	int count = 0;
	if (root != NULL) {
		count = 1 + get_node_count(root->left) + get_node_count(root->right);
	}
	return count;
}
int get_leaf_count(Tree* node) {
	int count = 0;
	if (node->left == NULL && node->right == NULL)return 1;
	else
		count = get_leaf_count(node->left) + get_leaf_count(node->right);
	return count;
}
int get_height(Tree* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}
int main() {
	Tree* n1, * n2, * n3;
	n1 = (Tree*)malloc(sizeof(Tree));
	n2 = (Tree*)malloc(sizeof(Tree));
	n3 = (Tree*)malloc(sizeof(Tree));
	n1->left = n2; n1->right = n3; n2->left = NULL; n2->right = NULL; n3->left = NULL; n3->right = NULL;
	n1->data = 10;
	n2->data = 20; n3->data = 30;
	printf("%d %d %d\n", get_node_count(n1),get_leaf_count(n1),get_height(n1));
	return 0;
}