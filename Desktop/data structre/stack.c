#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack;// 구조체를 이용하여, 스택 정의, 전역변수로도 정의 가능하다

void init_stack(Stack* s) {
	s->top = -1;
}
int is_empty(Stack* s) {
	return (s->top == -1);//empty이면 true 아닐 경우 false 리턴
}
int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));//full이면 true 아닐 경우 false 리턴
}
void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}//구조체 포인터를 활용하는 이유는 call by address를 실현하기 위해서이다.
element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peak(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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