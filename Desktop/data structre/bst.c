#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;
TreeNode* search(TreeNode* root, element data) {
	if (root == NULL)return NULL;
	if (data == root->data) {
		return root;
	}
	else if (data < root->data) {
		root->left= search(root->left, data);
	}
	else if (data > root->data) {
		root->right= search(root->right, data);
	}
}
TreeNode* newnode(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* root, element data) {
	if (root == NULL)return newnode(data);
	if (data > root->data) {
		root->right= insert_node(root->right, data);
	}
	else if (data < root->data) {
		root->left= insert_node(root->left, data);
	}
	return root;
}
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* temp = node;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->data)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->data)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		TreeNode* temp = min_value_node(root->right);

		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->data = temp->data;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}
int main() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = delete_node(root, 30);
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
	return 0;
}