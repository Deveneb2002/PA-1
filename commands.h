#include <iostream>
#include <string>
#include <fstream>

template <typename T, typename H>
class Node {
public:
    Node(T newCommand, H newDesc);
    ~Node();
    T getCommand();
    H getDesc();
    void setCommand(T);
    void setDesc(H);
    void setpNext(Node<T, H>* const newPNext);
    Node<T, H>* getpNext();
private:
    T Command;
    H Description;
    Node* pNext;
};

template <typename T, typename H>
class CommandList { // T is for commands and H is for Descriptions
public:
    CommandList();
    ~CommandList();
    int insertAtFront(); // Adds Node at Front
    int removeNode(T); // Removes node based on Command
    Node<T, H>* getPHead(); // Returns the head node
    void setPHead(); // Sets current node
    int populateList(); // populates list
private:
    Node<T, H>* pHead;
    std::fstream commandFile;
};

// NODE //

template<typename T, typename H>
Node<T, H>::Node(T newCommand, H newDesc)
{
    this->Command = newCommand;
    this->Description = newDesc;
    this->pNext = NULL;
}
template<typename T, typename H>
void Node<T, H>::setpNext(Node<T, H>* const newPNext)
{
    this->pNext = newPNext;
}

template<typename T, typename H>
Node<T, H>* Node<T, H>::getpNext()
{
    return pNext;
}

template<typename T, typename H>
T Node<T, H>::getCommand()
{
    return Command;
}

template<typename T, typename H>
H Node<T, H>::getDesc()
{
    return Description;
}


// LIST //

template<typename T, typename H>
inline CommandList<T, H>::CommandList()
{
    this->pHead = NULL;
    commandFile.open("commands.csv");
    this->populateList();
}

template<typename T, typename H>
inline CommandList<T, H>::~CommandList()
{
    pHead = NULL;
    commandFile.close();
}

template<typename T, typename H>
Node<T, H>* CommandList<T, H>::getPHead()
{
    return this->pHead;
}

template<typename T, typename H>
inline int CommandList<T, H>::populateList()
{
    Node<T, H>* pCur;
    pCur = pHead;
    T newCommand;
    H newDesc;

    getline(commandFile, newCommand);
    getline(commandFile, newDesc);
    pCur = new Node<T,H>(newCommand, newDesc);
    
    while(commandFile.peek() != EOF) {
        getline(commandFile, newCommand);
        getline(commandFile, newDesc);
        pCur->setpNext(new Node<T,H>(newCommand, newDesc));
        pCur = pCur->getpNext();
    }

}