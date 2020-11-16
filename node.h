#ifndef NODE_H
#define NODE_H

using namespace std;
template <typename T>
struct Node
{
public:
    Node();
    Node(T item=T()):_item(item){}

    T _item;
    Node<T>* next;
};

#endif // NODE_H
