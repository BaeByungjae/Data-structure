#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;// ����ü�� �̿��Ͽ�, ���� ����, ���������ε� ���� �����ϴ�

void init_stack(Stack* s) {
	s->top = -1;
}
int is_empty(Stack* s) {
	return (s->top == -1);//empty�̸� true �ƴ� ��� false ����
}
int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));//full�̸� true �ƴ� ��� false ����
}
void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}//����ü �����͸� Ȱ���ϴ� ������ call by address�� �����ϱ� ���ؼ��̴�.
element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peak(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main() {
	Stack s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	return 0;
}