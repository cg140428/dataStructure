#ifndef MAIN_CPP
#define MAIN_CPP
#include "Tree.h"

int main(void) {
	//1) 8+9-2*3
	char modify1[100];
	cout << "Enter the modification: ";
	cin >> modify1;

	Tree tree1;
	tree1.bulidTree(modify1);

	cout << "Inorder: ";
	tree1.inOrder(tree1.getRoot());
	cout << endl;
	cout << "Postorder: ";
	tree1.postOrder(tree1.getRoot());
	cout << endl;
	cout << "Preorder: ";
	tree1.preOrder(tree1.getRoot());
	cout << endl;
	cout << endl;
	cout << "Evaluation the first modification: ";
	cout << tree1.evalTree(tree1.getRoot()) << endl;
	cout << endl;

	//2) a+b*c-d
	char modify2[100];
	cout << "Enter the modification: ";
	cin >> modify2;

	Tree tree2;
	tree2.bulidTree(modify2);

	cout << "Inorder: ";
	tree2.inOrder(tree2.getRoot());
	cout << endl;
	cout << "Postorder: ";
	tree2.postOrder(tree2.getRoot());
	cout << endl;
	cout << "Preorder: ";
	tree2.preOrder(tree2.getRoot());
	cout << endl;
	return 0;
}
#endif
