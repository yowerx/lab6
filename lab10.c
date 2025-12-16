#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define NUM_ELEMENTS 10
int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void Task_10_1_1_dynamic() {
	int n;
	int* arr;
	printf("n = ");
	scanf_s("%d", &n);

	arr = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	printf("\n");
}

void Task_10_1_1_static() {
	int arr[NUM_ELEMENTS];
	int n;

	printf("n = ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Task_10_1_2_dynamic() {
	int n;
	int* arr;

	printf("n = ");
	scanf_s("%d", &n);

	arr = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int n2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			n2++;
		}
	}

	int* arr2 = malloc(n * sizeof(int));

	for (int i = 0,j = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr2[j++] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n2; i++) {
		printf("%d ", arr2[i]);
	}
	free(arr);
	printf("\n");
}

void Task_10_1_3_dynamic() {
	int n;
	int* arr;

	printf("n = ");
	scanf_s("%d", &n);

	arr = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");


	int min = arr[0];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}

	int n2 = 0;
	for (int i = index; i < n; i++) {
		if (arr[i] % 2 == 1) {
			n2++;
		}
	}

	int* arr2 = malloc(n * sizeof(int));

	for (int i = index, j = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr2[j++] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n2; i++) {
		printf("%d ", arr2[i]);
	}
	free(arr);
	printf("\n");
}

void Task_10_1_4_dynamic() {

	int n;
	int* arr;

	printf("n = ");
	scanf_s("%d", &n);

	arr = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int n2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 10) {
			n2++;
		}
	}

	int* arr2 = malloc(n * sizeof(int));

	for (int i = 0, j = 0; i < n; i++) {
		if (arr[i] < 10) {
			arr2[j++] = arr[i] * 10;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n2; i++) {
		printf("%d ", arr2[i]);
	}
	free(arr);
	printf("\n");

}

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum()
{
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

void exampleSum() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(9);
	printList();

	printf("sum = %d\n", sum());

	clearList();
	printList();
	printf("sum = %d\n", sum());
	{
		int x;
		scanf_s("%d", &x);
	}
}


int sumEven()
{
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			s++;
		}
		ptr = ptr->next;
	}
	return s;
}

void exampleSumEven() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	printf("even numbers = %d\n", sumEven());

	clearList();
	printList();
	printf("even numbers = %d\n", sumEven());
	{
		int x;
		scanf_s("%d", &x);
	}
}

void printListX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 1) {
			printf("(%d) -> ", ptr->data * 10);
		}
		else {
			printf("(%d) -> ", ptr->data);
		}
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void examplePrintListX10() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	printListX10();
	printList();

	clearList();
	printList();

	{
		int x;
		scanf_s("%d", &x);
	}
}

void elementIx100(int i)
{
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementFromLeftIx10(int i)
{
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index < i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}


void testIx10() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementFromLeftIx10(1);
	printList();
	elementFromLeftIx10(2);
	printList();
	elementFromLeftIx10(4);
	printList();

	clearList();
	printList();
	{
		int x;
		scanf_s("%d", &x);
	}
}


void elementFromRightIx10(int i)
{
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void testRIx10() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementFromRightIx10(1);
	printList();
	elementFromRightIx10(2);
	printList();
	elementFromRightIx10(4);
	printList();

	clearList();
	printList();
	{
		int x;
		scanf_s("%d", &x);
	}
}

void exampleIx100() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	elementIx100(0);
	printList();

	elementIx100(2);
	printList();

	elementIx100(0);
	printList();

	clearList();
	printList();

	{
		int x;
		scanf_s("%d", &x);
	}
}

void example() {
	first = NULL;
	printList();

	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	int x1 = deleteFromHead();
	printf("x1 = %d\n", x1);
	printList();

	int x2 = deleteFromHead();
	printf("x2 = %d\n", x2);
	printList();

}

void cont() {
	first = NULL;
	printList();

	addToHead(400);
	addToHead(300);
	addToHead(200);
	addToHead(100);
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));

	clearList();
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("========================================================\n");
		printf("1. Cортировка статик\n");
		printf("2. Cортировка динамическая\n");

		printf("\n");
		printf("0. Выход из программы\n");
		printf("========================================================\n");


		scanf_s("%d", &item);
		switch (item) {
		case 1:
		{
			Task_10_1_1_static();
			break;
		}
		case 2:
			Task_10_1_1_dynamic();
			break;
		case 3:
			Task_10_1_2_dynamic();
			break;
		case 4:
			Task_10_1_3_dynamic();
			break;
		case 5:
			Task_10_1_4_dynamic();
			break;
		case 6:
			example();
			break;
		case 7:
			cont();
			break;
		case 8:
			exampleSum();
			break;
		case 9:
			exampleSumEven();
			break;
		case 10:
			examplePrintListX10();
			break;
		case 11:
			exampleIx100();
			break;
		case 12:
			testIx10();
			break;
		case 13:
			testRIx10();
			break;
		}
	} while (item != 0);
}