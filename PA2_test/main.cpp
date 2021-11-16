#include "AVLNode.h"


int main() {
    AVLTree<int> tree1;
    AVLTree<int> tree2;
    AVLTree<int> tree3;
    std::cout << tree1.height() << std::endl;
    std::cout << tree2.height() << std::endl;
    std::cout << tree3.height() << std::endl;
    tree1.setRoot(tree1.insert(tree1.getRoot(), 1));
    tree1.setRoot(tree1.insert(tree1.getRoot(), 2));
    tree1.setRoot(tree1.insert(tree1.getRoot(), 3));
    tree1.setRoot(tree1.insert(tree1.getRoot(), 4));
    std::cout << tree1.height() << std::endl;

}



