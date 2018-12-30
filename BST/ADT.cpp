#ifndef ADT_CPP
#define ADT_CPP
#include "BST.h"

//Node ������
Node::Node(int data)
	//���� ����Ʈ���� ������ ����Ʈ���� ����Ű�� �������� ���� NULL�� �ʱ�ȭ
	:left(NULL), right(NULL) {
	this->data = data; //�ְ������� ���� data���� Ŭ������ ������� data�� �Ҵ�
}

//Tree ������
Tree::Tree() {
	root = NULL; //root�� ����Ű�� ������ ���� NULL�� �ʱ�ȭ
}

//������ ���� �Լ� - recursive
//recursive �Լ� ������ ���� ��ȯ���� Node�� �����ͷ� ����
Node* Tree::insert(Node* p, int data) {
	//����ִ� ���� Ž�� Ʈ����� Node�� ����
	if (p == NULL) {
		p = new Node(data);
		//root �����Ͱ� �ƹ��͵� ����Ű�� ���� �ʴٸ� ���� ������ Node�� ������ root�� ����Ű�� ��
		if (root == NULL)
			root = p;
	}
	//������ ������ ���� ������ �� ���� ������ ���� ����Ʈ���� �̵�
	else if(data < p->data){
		p->left = Tree::insert(p->left, data);
	}
	//������ ������ ���� ������ �� ���� ũ�� ������ ����Ʈ���� �̵�
	else if (data > p->data) {
		p->right = Tree::insert(p->right, data);
	}
	//���� ��ġ�ϰ� �ִ� Node�� ������ ��ȯ
	return p;
}

//������ Ž���ϴ� �Լ�
//recursive �Լ� ������ ���� ��ȯ���� Node�� �����ͷ� ����
Node* Tree::search(Node* p, int data) {
	//����ִ� ���� Ž�� Ʈ����� ������ ���� ã�� �� ������ ���
	if (p == NULL) {
		cout << data << " is not found" << endl;
		return NULL; //NULL�� ��ȯ
	}
	else {
		//Ÿ�� ������ ���� ������ ���� ���� ��� ã���� ���
		if (data == p->data) {
			cout << p->data << " is found" << endl;
			//���� ��ġ�ϰ� �ִ� Node�� ������ ��ȯ
			return p;
		}
		//Ÿ�� ������ ���� ������ �� ���� ������ ���� ����Ʈ���� �̵�
		else if (data < p->data)
			p = search(p->left, data);
		//Ÿ�� ������ ���� ������ �� ���� ũ�� ������ ����Ʈ���� �̵�
		else if (data > p->data)
			p = search(p->right, data);
	}
	//���� ��ġ�ϰ� �ִ� Node�� ������ ��ȯ
	return p;
}

// ������ ���� �Լ�
//recursive �Լ� ������ ���� ��ȯ���� Node�� �����ͷ� ����
Node* Tree::del(Node* p, int data) {
	//����ִ� ���� Ž�� Ʈ���� �ƴ϶�� ���ǹ� ����
	if (p != NULL) {
		//������ ������ ���� ������ �� ���� ������ ���� ����Ʈ���� �̵�
		if (data < p->data)
			p->left = del(p->left, data);
		//������ ������ ���� ������ �� ���� ũ�� ������ ����Ʈ���� �̵�
		else if (data > p->data)
			p->right = del(p->right, data);
		//1) �ڽ��� ���� ��� (leaf)
		else if ((p->left == NULL) && (p->right == NULL))
			//���� ���� NULL�� ����� ������ �����ش�.
			p = NULL;
		//2) �ڽ��� �ϳ��� �ִ� ��� (single)
		//������ �ڽĸ� �ִ� ��� ��� Node�� �������ڽ�Node�� ������ Node�� �������ְ�, ���Node�� ����
		else if (p->left == NULL) {
			Node* q;
			q = p;
			p = p->right;
			if (q == root)
				root = p;
			delete(q);
		}
		//���� �ڽĸ� �ִ� ��� ��� Node�� �����ڽ�Node�� ������ Node�� �������ְ�, ���Node�� ����
		else if (p->right == NULL) {
			Node* q;
			q = p;
			p = p->left;
			if (q == root)
				root = p;
			delete(q);
		}
		//3) ����, ���� �ڽ��� ��� ���� ���
		else {
			//������ Node�� �� �ڽ� ������ �� ������ ���� �İ��ڷ� �����Ͽ� ������ Node�� ��ġ�� �ű�
			//�İ����� �ڽ� Node���� �� �ܰ辿 ���� �̵����� Ʈ���� �籸��
			Node* temp;
			temp = Tree::find_min(p->right);
			p->data = temp->data;
			p->right = del(p->right, p->data);
		}
	}
	//����ִ� ���� Ž�� Ʈ���̰ų�, �ش� ���� ã�� ���ϸ� ã�� �� ������ ���
	else
		cout << "Not found" << endl;
	//���� ��ġ�ϰ� �ִ� Node�� ������ ��ȯ
	return p;
}

// ���� ������ ���� ����Ʈ���� Ž���ϴ� �Լ�
//���� ����Ʈ������ ���� ���� ���� Node�� �����͸� ��ȯ
Node* Tree::find_min(Node* p) {
	//���� ����Ʈ���� NULL�̸� ������ p ��ȯ
	if (p->left == NULL) {
		return p;
	}
	//���� ����Ʈ���� NULL�� �ƴ϶�� �� ���� ���� ����Ʈ���� �̵�
	else {
		find_min(p->left);
	}
}

//���� Ž�� Ʈ�� ��� �����ռ� - ����� ��
//������ �Ű������� ���� Ž�� Ʈ���� ��ü �Լ��� ȣ��
void Tree::printBTS() {
	Tree::display(Tree::getRoot(), 1);
}

// ���� Ž�� Ʈ�� ��� ���� �Լ� - ��ü - recursive
//������ root�̰� �������� leaf�� ������ Ʈ��
void Tree::display(Node* p, int level) {
	//����ִ� ���� Ž�� Ʈ���� �ƴϰų� ���̰� 7���϶��
	if (p != 0 && level <= 7) {
		//������ ����Ʈ���� �������� ���� 1 �߰�
		display(p->right, level + 1);
		//���̸�ŭ ������ �߰��Ͽ� Ʈ�� ���� ����
		for (int i = 0; i <= level - 1; i++)
			cout << "     ";
		//������ �� ���
		cout << p->data;
		//�ΰ��� �ڽ��� ������ '<' ���� ���
		if (p->left != 0 && p->right != 0)
			cout << "<" << endl;
		//������ �ڽĸ��� ������  '/'���� ���
		else if (p->right != 0)
			cout << " /" << endl;
		//���� �ڽĸ��� ������  '\'���� ���
		else if (p->left != 0)
			cout << " \\" << endl;
		else
			cout << endl;
		//���� ����Ʈ���� �������� ���� 1 �߰�
		display(p->left, level + 1);
	}
}

//root�� ����Ű�� �����͸� ��ȯ�ϴ� �Լ�
Node* Tree::getRoot() {
	return root; // �Լ��� ȣ���ϸ� root�� ����Ű�� �����͸� ��ȯ
}

#endif