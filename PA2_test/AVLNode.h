#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
template <class T>
class AVLNode
{
public:
    AVLNode();
    ~AVLNode();
    AVLNode<T>* getLeft();
    AVLNode<T>* getRight();
    int getHeight();
    T getData();
    void setLeft(AVLNode<T>* newNode);
    void setRight(AVLNode<T>* newNode);
    void setHeight(int newHeight);
    void setData(T newData);
private:
    AVLNode<T>* left;
    AVLNode<T>* right;
    T data;
    int height;
    int curHeight;
};
template <class T>
AVLNode<T>::AVLNode() {
    left = nullptr;
    right = nullptr;
    height = 0;
    curHeight = 0;
}

template <class T>
AVLNode<T>::~AVLNode() {
}

template <class T>
AVLNode<T>* AVLNode<T>::getLeft() {
    return this->left;
}

template <class T>
AVLNode<T>* AVLNode<T>::getRight() {
    return this->right;
}

template <class T>
int AVLNode<T>::getHeight() {
    if (this == nullptr) {
        return 0;
    }
    return this->height;
}

template <class T>
T AVLNode<T>::getData() {
    return this->data;
}

template <class T>
void AVLNode<T>::setLeft(AVLNode<T>* newNode) {
    this->left = newNode;
}

template <class T>
void AVLNode<T>::setRight(AVLNode<T>* newNode) {
    this->right = newNode;
}

template <class T>
void AVLNode<T>::setHeight(int newHeight) {
    this->height = newHeight;
}

template <class T>
void AVLNode<T>::setData(T newData) {
    data = newData;
}


template <class T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    AVLNode<T>* getRoot();
    void setRoot(AVLNode<T>* node);
    int height();
    AVLNode<T>* insert(AVLNode<T>* node, int key);
    int contains();
    int validate();
    AVLNode<T>* rightRotate(AVLNode<T>* y);
    AVLNode<T>* leftRotate(AVLNode<T>* x);

private:
    AVLNode<T>* root;
    int treeHeight;
};
template <class T>
AVLTree<T>::AVLTree() {
    this->root = nullptr;
}

template <class T>
AVLTree<T>::~AVLTree() {

}

template <class T>
AVLNode<T>* AVLTree<T>::getRoot() {
    return this->root;
}

template<class T>
inline void AVLTree<T>::setRoot(AVLNode<T>* node)
{
    this->root = node;
}

template <class T>
int AVLTree<T>::height() {
    if (root == nullptr) {
        return 0;
    }
    return this->root->getHeight();
}

template <class T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y)
{
    AVLNode<T>* x = y->getLeft();
    AVLNode<T>* z = x->getRight();

    // Perform rotation
    x->setRight(y);
    y->setLeft(z);

    // Update heights
    y->setHeight(std::max(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);
    x->setHeight(std::max(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);

    // Return new root
    return x;
}

template <class T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x)
{
    AVLNode<T>* y = x->getRight();
    AVLNode<T>* z = y->getLeft();

    // Perform rotation
    y->setLeft(x);
    x->setRight(z);

    // Update heights
    x->setHeight(std::max(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);
    y->setHeight(std::max(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);

    // Return new root
    return y;
}

template <class T>
int getBalance(AVLNode<T>* node)
{
    if (node == nullptr)
        return 0;
    return node->getLeft()->getHeight() - node->getRight()->getHeight();
}

template <class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, int key) {
    /* 1. Perform the normal BST insertion */
    AVLNode<T>* newNode = new AVLNode<T>;
    if (node == nullptr) {
        newNode->setData(key);
        node = newNode;
        return(newNode);
    }
        

    if (key < node->getData())
        node->setLeft(insert(node->getLeft(), key));
    else if (key > node->getData())
        node->setRight(insert(node->getRight(), key));
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->setHeight(1 + std::max(node->getLeft()->getHeight(), node->getRight()->getHeight()));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->getLeft()->getData())
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->getRight()->getData())
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->getLeft()->getData())
    {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->getRight()->getData())
    {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

template <class T>
int AVLTree<T>::contains() {

}

template <class T>
int AVLTree<T>::validate() {

}