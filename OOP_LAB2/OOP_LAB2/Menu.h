#ifndef _MENU_H_
#define _MENU_H_
#include "classLib.h"
#include "binaryTree.h"

class Menu : public BinaryTree {
public:

	Menu();
	~Menu();

	//Методы

	void run();
	void createTree();
	void arrayToTree(int* data, int n);
	void inputElementToArray(int element);
	void inputAndCreateToArray(int element);
	void outputBinaryTree(int& point);
	int countArrayElements(int* arr);
	void showArray();
	void interactionDisk();
	int countElements(Node* root);

	void writeIntsToFile(const char* filename);
	void readIntsFromFile(const char* filename);

	//Пукты меню

	void case_1_1();
	void case_1_2();
	void case_1_3();
	void case_1_4();
	void case_1_5();

	void case_2_1();
	void case_2_2();
	void case_2_3();

	void case_3_1();
	void case_3_2();

private:

	//Изменчивые значения

	int current;
	int currentIndex;
	bool check = false;

	//Размеровка

	int sizeTree = 10;
	int sizeData = 10;
	int Index = 10;

	//Для массивов

	BinaryTree* arrayTrees = new BinaryTree[sizeTree];
	int* arraySize = new int[sizeData]();
	int** arrayForIndexAndData = new int* [Index]();

	//Счетчики

	int pointerTree = 0;
	int pointerData = 0;
	int pointIndex = 0;

};

#endif