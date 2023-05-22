#include "Menu.h"
#include <conio.h>
void Menu::run() {
	Node* root = NULL;
	int choice;
	do {

		std::cout << "1. Create a binary tree" << std::endl;
		std::cout << "2. Input element to array" << std::endl;
		std::cout << "3. Push array to binaryTree" << std::endl;
		std::cout << "4. Output the binary tree" << std::endl;
		std::cout << "5. Insert tree into tree" << std::endl;
		std::cout << "6. Save/load object to disk" << std::endl;
		std::cout << "7. End the program" << std::endl;
		choice = _getch();
		switch (choice)
		{
		case '1': {
			std::cout << std::endl;
			case_1_1();
			std::cout << std::endl;
		} break;
		case '2': {
			std::cout << std::endl;
			case_1_2();
			std::cout << std::endl;
		}break;
		case '3': {
			std::cout << std::endl;
			case_1_3();
			std::cout << std::endl;
		}break;
		case '4': {
			std::cout << std::endl;
			case_1_4();
			std::cout << std::endl;
		}break;
		case '5': {
			std::cout << std::endl;
			case_1_5();
			std::cout << std::endl;
		}break;
		case '6': {
			std::cout << std::endl;
			interactionDisk();
			std::cout << std::endl;
		}break;
		case '7': {
			std::cout << "Goodbye my dear friend" << std::endl;
		}break;

		default:
			std::cout << "error" << std::endl;
		}

	} while (choice != '7');
}

//Методы логики

void Menu::readIntsFromFile(const char* filename) {
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	int number;
	int sequence_length = 0;
	while (infile >> number)
		sequence_length++;

	infile.clear();
	infile.seekg(0, std::ios::beg);
	int* arr = new int[sequence_length]();
	for (int i = 0; i < sequence_length; i++) {
		if (infile.eof()) {
			std::cerr << "Reached end of file before reading " << sequence_length << " integers." << std::endl;
			break;
		}
		infile >> arr[i];
		inputElementToArray(arr[i]);
	}
	std::cout << "Array has been road from file" << std::endl;
	infile.close();
}

void Menu::writeIntsToFile(const char* filename) {
	std::ofstream outfile(filename);
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	int x1 = arraySize[currentIndex];
	in_order_traversal(arrayTrees[currentIndex].root, arrayForIndexAndData[currentIndex], x1, false);
	int count = arrayTrees[currentIndex].countNodes(arrayTrees[currentIndex].root);
	for (int i = count; i >= 0; i--) {
		outfile << arrayForIndexAndData[currentIndex][i] << std::endl;
	}
	std::cout << "Tree has been wrote in file" << std::endl;
	outfile.close();
}

void Menu::interactionDisk() {
	int choice;
	do {
		std::cout << "1. Load" << std::endl;
		std::cout << "2. Save" << std::endl;
		std::cout << "3. Exit" << std::endl;
		choice = _getch();
		switch (choice) {
		case '1': {
			case_3_1();
			std::cout << std::endl;
		}break;
		case '2': {
			case_3_2();
			std::cout << std::endl;
		}break;
		case '3': {
			std::cout << "Goodbye my dear friend" << std::endl;
		}break;
		default:
			std::cout << "error" << std::endl;
		}
	} while (choice != '3');
}

void Menu::showArray() {
	std::cout << arraySize[currentIndex] << " " << currentIndex << std::endl;
	for (int i = 0; i < arraySize[currentIndex]; i++) {
		std::cout << arrayForIndexAndData[currentIndex][i] << " ";
	}
	std::cout << std::endl;
}

int Menu::countArrayElements(int* arr) {
	int size = 0;
	size = arr[currentIndex];
	return size;
}

void Menu::createTree() {
	
	BinaryTree newTree;

	if (pointerTree == sizeTree) {
		BinaryTree* newArrayTrees = new BinaryTree[sizeTree * 2];
		for (int i = 0; i < sizeTree; i++) {
			newArrayTrees[i] = arrayTrees[i];
		}
		delete[] arrayTrees;
		arrayTrees = newArrayTrees;
		sizeTree *= 2;
	}
	arrayTrees[pointerTree] = newTree;
	pointerTree++;
}

void Menu::arrayToTree(int* data, int n) {
	if (current > pointerTree) {
		do {
			std::cout << "There is no tree number " << current << " in the binary tree array" << std::endl;
			std::cin >> current;
		} while ((current > pointerTree));
	}
	arrayTrees[current].constructBST(data,0,n-1);
}

void Menu::inputElementToArray(int element) {
	if (pointerData == sizeData) {
		int* newArray = new int[sizeData * 2];
		for (int i = 0; i < sizeData; i++) {
			newArray[i] = arrayForIndexAndData[currentIndex][i];
		}
		delete[] arrayForIndexAndData[currentIndex];
		arrayForIndexAndData[currentIndex] = newArray;
		sizeData *= 2;
	}
	arrayForIndexAndData[currentIndex][arraySize[currentIndex]] = element;
	arraySize[currentIndex] = arraySize[currentIndex]++;
}

void Menu::inputAndCreateToArray(int element) {
	if (pointIndex == Index) {
		int** newArray = new int* [Index * 2];
		for (int i = 0; i < Index; i++) {
			newArray[i] = arrayForIndexAndData[i];
		}
		delete[] arrayForIndexAndData;
		arrayForIndexAndData = newArray;
		Index *= 2;
	}
	if (pointerData == sizeData) {
		int* newArray = new int[sizeData * 2];
		for (int i = 0; i < sizeData; i++) {
			newArray[i] = arrayForIndexAndData[pointIndex][i];
		}
		delete[] arrayForIndexAndData[pointIndex];
		arrayForIndexAndData[pointIndex] = newArray;
		sizeData *= 2;
	}
	arrayForIndexAndData[pointIndex][arraySize[pointIndex]] = element;
	arraySize[pointIndex] = arraySize[pointIndex]++;
	pointIndex++;
}

void Menu::outputBinaryTree(int& point) {
	if (pointerTree < point) {
		do {
			std::cout << "There is no binary tree for the output, create a tree or choose another" << std::endl;
			std::cin >> point;
		} while (pointerTree < point);
	}
	arrayTrees[point].printBT();
}

Menu::Menu() {
	for (int i = 0; i < Index; i++) {
		arrayForIndexAndData[i] = new int[sizeData];
	}
}
Menu::~Menu() {
	for (int i = 0; i < Index; i++) {
		delete[] arrayForIndexAndData[i];
	}
	delete[] arrayForIndexAndData;
}

//Пункты меню

//Пункты меню 1 переключатель

void Menu::case_1_1() {
	std::cout << "A binary tree has been created and placed on the position " << pointerTree << std::endl;
	createTree();
	check = true;
}

void Menu::case_1_2() {
	int choice1;
	do {
		std::cout << "1. Create a new array and add an element to it" << std::endl;
		std::cout << "2. Add an element to an existing array" << std::endl;
		std::cout << "3. Show Array" << std::endl;
		std::cout << "4. Exit" << std::endl;
		choice1 = _getch();
		switch (choice1)
		{
		case '1': {
			std::cout << std::endl;
			case_2_1();
			std::cout << std::endl;
		}break;
		case '2': {
			std::cout << std::endl;
			case_2_2();
			std::cout << std::endl;
		}break;
		case '3': {
			std::cout << std::endl;
			case_2_3();
			std::cout << std::endl;
		}break;
		case'4': {
			std::cout << "Goodbye my dear friend" << std::endl;
		}break;
		default:
			std::cout << "error" << std::endl;
		}
	} while (choice1 != '4');
}

void Menu::case_1_3() {
	if (check) {
		std::cout << "Select the position in the binary tree array to which you would like to push" << std::endl;
		std::cin >> current;
		std::cout << "Select the array you want to include in the tree" << std::endl;
		std::cin >> currentIndex;
		int n = countArrayElements(arraySize);
		arrayToTree(arrayForIndexAndData[currentIndex], n);

	}
	else {
		std::cout << "Create at least one tree to put something in it!" << std::endl;
	}
}

void Menu::case_1_4() {
	if (check) {
		int point;
		std::cout << "Enter the number of the binary tree you want to output: ";
		std::cin >> point;
		std::cout << std::endl;
		outputBinaryTree(point);
	}
	else {
		std::cout << "Create at least one tree to put something in it!" << std::endl;
	}
}

void Menu::case_1_5() {
	if (check) {
		int i, j;
		int val, val1;
		std::cout << "Enter which binary tree you want to insert another binary tree into" << std::endl;
		std::cin >> val;
		std::cout << "Enter the tree you want to insert" << std::endl;
		std::cin >> val1;
		std::cout << "Enter to which position of the tree (i;j) you want to insert the tree" << std::endl;
		std::cin >> i >> j;
		arrayTrees[val].insertArray(arrayTrees[val].root, i, j, arrayTrees[val1].root);
	}
	else {
		std::cout << "Create at least one tree to put something in it!" << std::endl;
	}
}

//Пункты меню 2 переключатель

void Menu::case_2_1() {
	int num;
	std::cout << "Input element to the new array: ";
	std::cin >> num;
	inputAndCreateToArray(num);
	std::cout << std::endl << "Your element has been added to the new array. Array index = " << pointIndex - 1<< std::endl;
}

void Menu::case_2_2() {
	std::cout << "Choose which array you want to fluff the item into" << std::endl;
	std::cin >> currentIndex;
	if (currentIndex > Index) {
		do {
			std::cout << "Error that array is not exist" << std::endl;
			std::cout << "Choose which array you want to fluff the item into" << std::endl;
			std::cin >> currentIndex;
		} while(currentIndex > Index);
	}
	int num;
	std::cout << "Input element: ";
	std::cin >> num;
	inputElementToArray(num);
	std::cout << std::endl << "Your element has been added" << std::endl;
}

void Menu::case_2_3() {
	std::cout << std::endl << "Select which array you want to see" << std::endl;
	std::cin >> currentIndex;
	showArray();
}

//Пункты меню 3 переключатель

void Menu::case_3_1() {
	char nameFile[256];
	std::cout << std::endl << "Select the array into which you want to add elements from the file: ";
	std::cin >> currentIndex;
	std::cout << std::endl << "Enter a file name: ";
	std::cin.ignore(UCHAR_MAX,'\n');
	std::cin.getline(nameFile, sizeof(nameFile));
	readIntsFromFile(nameFile);
}

void Menu::case_3_2() {
	char nameFile[256];
	std::cout << std::endl << "Select which tree you want to write into the file: ";
	std::cin >> currentIndex;
	std::cout << std::endl << "Enter a file name: ";
	std::cin.ignore(UCHAR_MAX, '\n');
	std::cin.getline(nameFile, sizeof(nameFile));
	writeIntsToFile(nameFile);
}