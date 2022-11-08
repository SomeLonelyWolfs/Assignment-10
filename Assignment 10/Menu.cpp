#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"Input.h"
#include"Menu.h"
#include"binary_tree_node.h"
using namespace std;

int menuOption() {
    cout << "\n\tCMPR131 Chapter 10: Trees by  (11/6/21)"
        << "\n\t" << string(60, char(205))
        << "\n\t 1. Tree of strings"
        << "\n\t 2. Tree container of integers"
        << "\n\t 3. Animal Guessing Game"
        << "\n\t" << string(60, char(196))
        << "\n\t 0. Exit"
        << "\n\t" << string(60, char(205)) << endl;
    return inputInteger("\tOption: ", 0, 3);
}

void init_mainMenu() {
    do {
        switch (menuOption()) {
        case 0: exit(1); break;
        case 1:
            system("cls");
            init_tree_strings();
            break;
        case 2:
            system("cls");
            init_tree_container();
            break;
        case 3:
            system("cls");
			init_animal_guessing_game();
            break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
        system("cls");
    } while (true);
}

// 1. Tree of strings
void init_tree_strings()
{
	system("cls");

	cout << "n\t1. Growing a tree (strings)\n";
	binary_tree_node<string>* root = nullptr;
	binary_tree_node<string>* branch1 = new binary_tree_node<string>;
	binary_tree_node<string>* branch2 = new binary_tree_node<string>;
	binary_tree_node<string>* leftLeaf1 = new binary_tree_node<string>;
	binary_tree_node<string>* leftLeaf2 = new binary_tree_node<string>;
	binary_tree_node<string>* rightLeaf1 = new binary_tree_node<string>;
	binary_tree_node<string>* rightLeaf2 = new binary_tree_node<string>;
	binary_tree_node<string>* fruit = new binary_tree_node<string>;
	binary_tree_node<string>* fruit2 = new binary_tree_node<string>;
	binary_tree_node<string>* fruit3 = new binary_tree_node<string>;

	root = new binary_tree_node<string>;
	root->setData("trunk");

	cout << "\n\tA> root (trunk) with no branches.\n\n";
	print_tree("\t\t", root, false, true, false);


	branch1->setData("branch #1");

	branch2->setData("branch #2");

	cout << "\n\tB> " << root->getData() << " grows two branches...\n\n";
	root->setLeft(branch1);
	root->setRight(branch2);
	print_tree("\t\t", root, false, true, false);


	leftLeaf1->setData("leaf #1");
	root->getLeft()->setLeft(leftLeaf1);
	leftLeaf2->setData("leaf #2");
	root->getLeft()->setRight(leftLeaf2);

	cout << "\n\tC> " << root->getLeft()->getData() << " grows two leaves: " << leftLeaf1->getData() << " and " << leftLeaf2->getData() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';

	rightLeaf1->setData("leaf #3");
	root->getRight()->setLeft(rightLeaf1);
	rightLeaf2->setData("leaf #4");
	root->getRight()->setRight(rightLeaf2);

	cout << "\n\tD> " << root->getRight()->getData() << " grows two leaves: " << rightLeaf1->getData() << " and " << rightLeaf2->getData() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';

	fruit->setData("apple");
	leftLeaf1->setLeft(fruit);
	cout << "\n\tE> " << root->getLeft()->getLeft()->getData() << " sprouts and yields a fruit (" << fruit->getData() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';

	fruit2->setData("orange");
	fruit3->setData("coconut");
	rightLeaf1->setLeft(fruit2);
	rightLeaf1->setRight(fruit3);
	cout << "\n\tF> " << root->getRight()->getLeft()->getData() << " sprouts and yields two fruits (" << fruit2->getData() << " and " << fruit3->getData() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';

	cout << "\n\tG> Delete tree (recursive).\n";
	delete_tree<string>(root);
	cout << '\n';
	root = NULL;
	if (root != NULL)
	{
		cout << '\n';
		print_tree("\t\t", root, false, true, false);
	}

}



// 2. Tree container of integers
char tree_container_Menu() {
	system("cls");
	char menuChoice[] = "abcdefg0";
	cout << "\n\n\t 2. Template MyBag of doubles"
		<< "\n\t" << string(80, char(205))
		<< "\n\t\t A. Insert a node/leaf"
		<< "\n\t\t B. Count of Nodes/leaves"
		<< "\n\t\t C. Search a node/leaf"
		<< "\n\t\t D. Pre-order traversal"
		<< "\n\t\t E. In-order traversal"
		<< "\n\t\t F. Post-order traveral"
		<< "\n\t\t G. Delete the entire tree"
		<< "\n\t" << string(80, char(196))
		<< "\n\t\t 0. return"
		<< "\n\t" << string(80, char(205)) << endl;
	return inputChar("\n\t\tOption: ", menuChoice, strlen(menuChoice));
}

void init_tree_container() {
	int count = 0;
	int search = 0;
	bool node_set = false;
	binary_tree_node<int>* root = nullptr;
	root = new binary_tree_node<int>;
	root->setData(-1);

	do {
		switch (tree_container_Menu())
		{
		case 'A':
			node_set = true;
			system("pause");
			break;
		case 'B':
			cout << "\n\tCount of Nodes: " << (tree_count(root,count) - (node_set == true) ? 0 : 1) << "\n\n\t";
			count = 0;
			system("pause");
			break;
		case 'C':
			if (node_set == true) {
				search = inputInteger("\n\tEnter an integer key to search: ");
				if (binary_search(root, search)) {
					cout << "\n\t" << search << " has been found." << "\n\n\t";
				}
				else {
					cout << "\n\t" << search << " has not been found." << "\n\n\t";
				}
			}
			else {
				cout << "\n\tERROR: bTree is empty." << "\n\n\t";
			}
			system("pause");
			break;
		case 'D':
			if (node_set == true) {
				preorder_print(root);
			}
			else {
				cout << "\n\tERROR: bTree is empty." << "\n\n\t";
			}
			system("pause");
			break;
		case 'E':
			if (node_set == true) {
				inorder_print(root);
			}
			else {
				cout << "\n\tERROR: bTree is empty." << "\n\n\t";
			}
			system("pause");
			break;
		case 'F':
			if (node_set == true) {
				postorder_print(root);
			}
			else {
				cout << "\n\tERROR: bTree is empty." << "\n\n\t";
			}
			system("pause");
			break;
		case 'G':
			if (node_set == true) {
				delete_tree<int>(root);
				root = NULL;
				cout << "\n\n\t";
				node_set = false;
			}
			else {
				cout << "\n\tERROR: bTree is empty." << "\n\n\t";
			}
			system("pause");
			break;
		case '0': return; break;
		}
	} while (true);
	
	
	/*
		// New Testing:
	preorder_print(root);
	system("pause");
	
	inorder_print(root);
	system("pause");
	
	postorder_print(root);
	system("pause");

	string search = "pineapple";
	if (binary_search(root, search)) {
		cout <<"\n\t" << search << " has been found.";
	}
	else {
		cout <<"\n\t" << search << " has not been found.";
	}
	int count = 0;
	cout << "\n\tTree count: " << tree_count(root,count) << "\n\t";

	system("pause");
	// End testing
	*/
}

// 3. Animal Guessing Game

char animal_Menu() {
	system("cls");
	char menuChoice[] = "ab0";
	cout << "\n\n\t 3. Welcome to Animal Guessing Game"
		<< "\n\t" << string(80, char(205))
		<< "\n\t\t A. Play the game"
		<< "\n\t\t B. Save the game file"
		<< "\n\t" << string(80, char(196))
		<< "\n\t\t 0. return"
		<< "\n\t" << string(80, char(205)) << endl;
	return inputChar("\n\t\tOption: ", menuChoice, strlen(menuChoice));
}

void init_animal_guessing_game() {
	fstream file;
	
}
