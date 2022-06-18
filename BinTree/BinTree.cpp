#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
};


void newTreeEl(int val, Tree** t) {
	if (nullptr == *t) {
		*t = (Tree*)calloc(1,sizeof(Tree));
		(*t)->data = val;
		(*t)->left = nullptr;
		(*t)->right = nullptr;
	}
	else {
		if (val == (*t)->data) {
			printf("\nЭлемент %d уже есть в дереве!\n", val);
			return;
		}
		if (val > (*t)->data)
			newTreeEl(val, &(*t)->right);
		else
			newTreeEl(val, &(*t)->left);
	}
}

void destroy(Tree* t) {
	if (nullptr != t){
		destroy(t->left);
		destroy(t->right);
		free(t);
	}
}

int countNodes(Tree* t) {
	if (nullptr == t) return 0;
	return countNodes(t->left) + countNodes(t->right) + 1;
}


void Print(Tree* t, int space = 0) {
	if (t == nullptr) return;

	Print(t->right, space + 3);
	for (int i = 0; i < space; i++) { printf(" "); }
	printf("%d\n", t->data);
	Print(t->left, space + 3);
}


void Menu()
{
	printf("\nБинарное дерево - динамическая структура данных, где есть корневой элемент и листья.");
	int k = 0;
	int i = 0;
	int inpt = 0;
	char s[10] = { " " };
	char* str;
	Tree* root = nullptr;
	int val = 0;

	printf("\nПроцесс создания дерева...\n");
	printf("\nВведите элементы, ввод 2 enter подряд означает окончание ввода: \n");
	while (1) {
		str = gets_s(s);
		if ('\0' == s[0]) break;
		newTreeEl(atoi(str), &root);
	}
	
	printf("\nДерево создано.");
	const char* ss[] = { " 0 - Пересоздание бинарного дерева", " 1 - Добавление элемента в дерево",\
	" 2 - Рекурсивный вывод элементов дерева", " 3 - Удаление текущего дерева",\
	" 4 - Вывод количества элементов в дереве", " 5 - Выход"};
	k = sizeof(ss) / sizeof(ss[0]);

	while (1)
	{
		puts("\n-------------------- РАБОТА С БИНАРНЫМ ДЕРЕВОМ ----------------");
		for (i = 0; i < k; i++) puts(ss[i]);
		//getchar();
		printf("Ввод команды: ");
		scanf_s("%d", &inpt);
		switch (inpt)
		{
		case 0:
			printf("При создании дерева прошлое удаляется");
			destroy(root);
			root = nullptr;
			printf("\nВведите элементы, ввод 2 enter подряд означает окончание ввода: \n");
			getchar();
			while (1) {
				str = gets_s(s);
				if ('\0' == s[0]) break;
				newTreeEl(atoi(str), &root);
			}
			break;
		case 1:
			if (nullptr == root)	printf("При добавлении элемента в пустое дерево создается дерево размера 1\n");
			
			printf("Число: "); 
			scanf_s("%d", &val); 
			newTreeEl(val, &root);
			break;
		case 2: 
			if (nullptr == root) {
				printf("Дерева нет!");
				break;
			}
			Print(root,0);     
			break;
		case 3: 
			free(root);
			root = nullptr;
			break;
		case 4:
			printf("Количество элементов в дереве: %d", countNodes(root));
			break;
		case 5: 
			printf("Спасибо за использование! До свидания!");
			destroy(root);
			return;
		default: printf("Неизвестная команда!");
		}
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");
	Menu();
}
