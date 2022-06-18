#include <iostream>
using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
	Tree(int val = 0){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

Tree* push(int val, Tree* root) {
	if (nullptr == root)
	{
		root = new Tree(val);
		return root;
	}
	Tree* temp = root;
	while (true) {
		if (val < temp->data)
			if (temp->left != nullptr) {
				temp = temp->left;
				continue;
			}
			else {
				Tree* lchild = new Tree(val);
				temp->left = lchild;
				break;
			}
		if (val > temp->data)
			if (temp->right != nullptr) {
				temp = temp->right;
				continue;
			}
			else {
				Tree* rchild = new Tree(val);
				temp->right = rchild;
				break;
			}
	}
	return root;
}

Tree* enterTree() {
	Tree* root = nullptr;
	int count = 0;
	printf("\nВведите количесвто элементов дерева: ");
	scanf_s("%d", &count);


	int input = 0;
	printf("\nВведите значение корня дерева: ");
	scanf_s("%d", &input);
	root = push(input, root);
	getchar();
	for (int i = 1; i < count; i++) {
		printf("\nВведите значение листка дерева: ");
		scanf_s("%d", &input);
		root = push(input, root);
	}
	return root;
}

void Print(Tree* root, int l) {
	if (root == nullptr) return;
	Print(root->right, l + 3);
	for (int i = 0; i < l; i++) { printf(" "); }
	printf("%d\n", root->data);
	Print(root->left, l + 3);
}

void Menu()
{
	int i;
	int inpt;
	const char* ss[] = { " 0 - Создание бинарного дерева", " 1 - Добавление элемента в дерево",\
	" 2 - Рекурсивный вывод элементов дерева", " 3 - Удаление текущего дерева"," 4 - Выход"};
	int k = sizeof(ss) / sizeof(ss[0]);

	Tree* root = nullptr;
	int checkInpt = -1;
	int num = 0;

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
			free(root);
			root = nullptr;
			root = enterTree();            
			break;
		case 1:
			if (nullptr == root)
				printf("При добавлении элемента в пустое дерево создается дерево размера 1");
			
			printf("Число: "); 
			scanf_s("%d", &num); 
			root = push(num, root);      
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
			printf("Спасибо за использование! До свидания!");
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
