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

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		TreeNode* temp = min_value_node(root->right);

		// 중외 순회시 후계 노드를 복사한다. 
		root->data = temp->data;
		// 중외 순회시 후계 노드를 삭제한다. 
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
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}