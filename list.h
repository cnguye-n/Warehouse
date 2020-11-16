#ifndef LIST_H
#define LIST_H

#include "item.h"
#include "date.h"
#include "linked_list_functions.h"
#include <iostream>
using namespace std;

/*******************************************************************
 * Node struct
 *
 * Nodes for List class
 ******************************************************************/
template <typename T>
struct Node
{
public:
    Node();
    Node(T item=T()):_item(item){}
    friend std::ostream& operator <<(std::ostream& outs,const node<T> &printMe)
    {
        outs<<"["<<printMe._item<<"]->";
        return outs;
    }

    T _item;
    Node<T>* next;
};

/*******************************************************************
 * List Class
 *
 * Used as a Linked_list that holds Item and Product objects
 ******************************************************************/
template<class T>
class List{
public:
    List();
    ~List();
    List(List const& copy);

    Node<T>*& ReturnHead();
    void insertHead(T item);     //insert at beginning of list
    void insertLast(T item);     //insert at end of list-doesn't work

    void insertAsc(T item);   //insert in a sorted way (is in ascending order)
    void insertDes(T item);   //inserted Descending
    void pop();                  //delete head node
    void setTail();


    Node<T>* searchList(T key);         //return pointer to node we want
    T seeTop(){return _head->_item;}   //return value
    T seeLast(){return _tail->_item;}  //return value
    size_t getSize() const {return _size;}
    bool isEmpty(){return (_head==nullptr);}

    //print function-prolly don't need this as we overloaded already
    void printList();
    //print linked list
    friend ostream& operator<<(ostream& outs, const List<T>& item){
        Node<T>* ptr= item._head;
        while(ptr!=nullptr){
            outs << ptr->_item << " ";
            ptr=ptr->next;
        }
        outs << "\n";
        return outs;
    }

    //friend class History;
private:
    Node<T>* _head;
    Node<T>* _tail;
    size_t _size;
};

/*******************************************
 * List();
 * Constructor: Constructs List object
 * Parameters : none
 * Return     : none
 ******************************************/
/*******************************************
 * ~List();
 * Destructor : Deconstructs list object
 * Parameters : None
 * Return     : None
 ******************************************/
/*******************************************
 * List(List const& copy);
 * Constructor: Copy Constructor
 * Parameters : List object
 * Return     : None
 ******************************************/
/*******************************************
 * Node<T>* ReturnHead();
 * Accessor   : Returns head pointer of linked-list
 * Parameters : None
 * Return     : head pointer
 ******************************************/
/*******************************************
 * void insertHead(T item);
 * Mutator    : Inserts item at head
 * Parameters : Item type T
 * Return     : None
 ******************************************/
/*******************************************
 * void insertLast(T item);
 * Mutator    : Inserts item at end
 * Parameters : Item type T
 * Return     : None
 ******************************************/
/*******************************************
 * void insertAsc(T item);
 * Mutator    : Inserts item in ascending order
 * Parameters : Item type T
 * Return     : none
 ******************************************/
/*******************************************
 * void insertDes(T item);
 * Mutator    : Inserts item in descending order
 * Parameters : Item type T
 * Return     : none
 ******************************************/
/*******************************************
 * void pop();
 * Mutator    : Removes item at head of list
 * Parameters : none
 * Return     : None
 ******************************************/
/*******************************************
 * void setTail();
 * Mutator    : Sets Tail pointer at end of List
 * Parameters : None
 * Return     : None
 ******************************************/
/*******************************************
 * Node<T>* searchList(T key);
 * Accessor   : Returns node based on location of Key
 * Parameters : Key type T
 * Return     : Node Pointer
 ******************************************/
/*******************************************
 * T seeTop(){return _head->_item;}
 * Accessor   : Returns item at top of linked-list
 * Parameters : None
 * Return     : Item type T
 ******************************************/
/*******************************************
 * T seeLast(){return _tail->_item;}
 * Accessor   : Returns item at end of list
 * Parameters : None
 * Return     : Item Type T
 ******************************************/
/*******************************************
 * size_t getSize() const {return _size;}
 * Accessor   : Returns size of linked-list
 * Parameters : None
 * Return     : Size_t
 ******************************************/
/*******************************************
 * bool isEmpty(){return (_head==nullptr);}
 * Accessor   : Checks if list is empty
 * Parameters : None
 * Return     : Boolean value
 ******************************************/
/*******************************************
 * void printList();
 * Accessor   : Prints list
 * Parameters : None
 * Return     : None
 ******************************************/
/*******************************************
 * friend ostream& operator<<(ostream& outs, const List<T>& item)
 * Accessor   : Extraction operator
 * Parameters : Cout, List object
 * Return     : Cout
 ******************************************/


#endif // LIST_H
