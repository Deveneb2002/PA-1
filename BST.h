#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	void removeSubtree(Node<T>* ptr) {
		if (ptr != NULL) {
			if (ptr->left != NULL) {
				removeSubtree(ptr->left);
			}
			if (ptr->right != NULL) {
				removeSubtree(ptr->right);
			}
			delete ptr;
		}
	}

	bool containsHelper(Node<T>* ptr, T key) {
		if (ptr == NULL) {
			return false;
		}
		else {
			if (key == ptr->value) {
				return true;
			}
			else if (key < ptr->value) {
				return containsHelper(ptr->left, key);      //you forgot to return the value
			}
			else if (key > ptr->value) {
				return containsHelper(ptr->right, key);
			}
		}
	}

	void printMaxPathHelper(Node<T>* ptr) {
		if (!ptr) return;
		cout << ptr->value << ' ';
		if (heightHelper(ptr->left) > heightHelper(ptr->right)) {
			printMaxPathHelper(ptr->left);
		}
		else {
			printMaxPathHelper(ptr->right);
		}
	}


	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 */
	~BST() {
		removeSubtree(_root);
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 */
	void printLevelOrder()
	{
		int h = heightHelper(this->_root);
		int i;
		for (i = 1; i <= h+1; i++)
		{
			printGivenLevel(_root, i);
			printf("\n");
		}
	}

	/* Print nodes at a given level */
	void printGivenLevel(struct Node<T>* root, int level)
	{
		if (root == NULL)
			return;
		if (level == 1)
			printf("%d ", root->value);
		else if (level > 1)
		{
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 */
	void printMaxPath() {
		printMaxPathHelper(this->_root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 */
	bool contains(T value) {
		return containsHelper(_root, value);
	}
};

#endif

