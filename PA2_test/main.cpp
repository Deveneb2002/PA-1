#include "AVLNode.h"


int main() {
    AVLTree<int> tree1;
    AVLTree<int> tree2;
    AVLTree<int> tree3;
    int i = 0;

    std::vector<int> v1(50, 0);
    std::vector<int> v2(50, 0);
    std::vector<int> v3(50, 0);

    for (i = 0; i < 50; i++) {
        v1[i] = i * 2 + 1;
    }
    for (i = 0; i < 50; i++) {
        v2[i] = i * 2 + 1;
    }
    for (i = 0; i < 50; i++) {
        v3[i] = i * 2 + 1;
    }

    std::random_shuffle(v1.begin(), v1.end());
    std::random_shuffle(v2.begin(), v2.end());
    std::random_shuffle(v3.begin(), v3.end());

    for (i = 0; i < 50; i++) {
        tree1.setRoot(tree1.insert(tree1.getRoot(), v1[i]));
    }
    std::cout << "tree 1 validate: " << tree1.validate() << std::endl;

    for (i = 0; i < 50; i++) {
        tree2.setRoot(tree1.insert(tree1.getRoot(), v1[i]));
    }
    std::cout << "tree 2 validate: " << tree2.validate() << std::endl;

    for (i = 0; i < 50; i++) {
        tree3.setRoot(tree1.insert(tree1.getRoot(), v1[i]));
    }
    std::cout << "tree 3 validate: " << tree2.validate() << std::endl;

    for (i = 0; i < 100; i++) {
        std::cout << "tree 1 contains " << i << ": "<< tree1.contains(i) << std::endl;
    }
    for (i = 0; i < 100; i++) {
        std::cout << "tree 2 contains " << i << ": " << tree2.contains(i) << std::endl;
    }
    for (i = 0; i < 100; i++) {
        std::cout << "tree 3 contains " << i << ": " << tree3.contains(i) << std::endl;
    }

}



