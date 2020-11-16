#include "list.h"

//CONSTRUCTOR
/**************************************************************
* List()
* ____________________________________________________________
* Constructor
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Private  member data initialized
***************************************************************/
template <class T>
List<T>::List(){
    _head=nullptr;
    _tail=nullptr;
    _size=0;
}

/**************************************************************
* List(const List &copy)
* ____________________________________________________________
* Copy constructor, copies over private data
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Private member data set
***************************************************************/
template <class T>
List<T>::List(const List &copy)
{
    if (copy._head == nullptr)
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_size = 0;
        return;
    }

    Node<T>* p = copy._head;
    while(p != nullptr)
    {
        this->insertLast(p->_item);
        p=p->next;
    }
}

//DESTRUCTOR
/**************************************************************
* ~List()
* ____________________________________________________________
* Deletes nodes and sets pointers to null
* ___________________________________________________________
* PRE-CONDITIONS
* -
* POST-CONDITIONS
* -
***************************************************************/
template <class T>//good
List<T>::~List(){
    while(!isEmpty()){
        pop();
    }
    _head=nullptr;
}

/**************************************************************
* void List<T>::insertHead(T item)
* ____________________________________________________________
* Insert new node
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -New node is the first node in list
***************************************************************/
template <class T>  //good
void List<T>::insertHead(T item){
    Node<T>* N = new Node<T>(item);
    N->next=_head;
    _head=N;
    _tail=N->next;
    _size++;
}

/**************************************************************
* void List<T>::insertLast(T item)
* ____________________________________________________________
* Inserts item to last node
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* - Inserts node at end of list
***************************************************************/

template <class T>
void List<T>::insertLast(T item){ //doesn't work...
//    Node<T>* N= new Node<T>(item);
//    _tail->next=N;
//    _tail=N;
//    _size++;

    Node<T>* walk = _head;

    if (_head == nullptr)
    {
        insertHead(item);
        return;
    }

    while (walk->next != nullptr)
        walk = walk->next;

    _tail = walk;

    Node<T>* N = new Node<T>(item);

    _tail->next = N;

    _tail = _tail->next;

    _tail->next = nullptr;

    return;
}

/**************************************************************
* void List<T>::insertAsc(T item)
* ____________________________________________________________
* Inserts node in ascending order
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Node inserted in ascending order
* -Size is incremented
***************************************************************/
//insert in a sorted way -ASCENDING 1,2,3,4...
template <class T>
void List<T>::insertAsc(T item)
{
    Node<T>* walker=_head;
    Node<T>* N= new Node<T>(item);
    _size++;
    //if empty insert in head node or value less than head node
    if(walker==nullptr || walker->_item > item){ //works
        N->next=walker;
        _head=N;
    }
   else{
        //find before insertion
        //assume sorted so N must be between values or at end
        while(walker->next!= nullptr &&
              walker->next->_item <= item){
            walker=walker->next;
        }
        //if the insertion is at the end,set tail
        if(walker==nullptr){
            _tail->next=N;
            _tail=N;
        }
        //value is between two nodes in list
        else{
            N->next=walker->next;
            walker->next=N;
        }

    }
}

/**************************************************************
* void List<T>::insertDes(T item)
* ____________________________________________________________
* Inserts node in descending order
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Node inserted in descending order
* -Size is decremented
***************************************************************/
//INSERT SORTED DESCENDING 5,4,3,2,1....
template<class T>
void List<T>::insertDes(T item){
    _size++;
    Node<T>* walker=_head;
    Node<T>* N= new Node<T>(item);

    //if empty insert in head node or value less than head node
    if(walker==nullptr || walker->_item < item){ //works
        N->next=walker;
        _head=N;
    }
   else{
        //find before insertion
        //assume sorted so N must be between values or at end
        while(walker->next!= nullptr &&
              walker->next->_item >= item){
            walker=walker->next;
        }
        //if the insertion is at the end,set tail
        if(walker==nullptr){
            _tail->next=N;
            _tail=N;
        }
        //value is between two nodes in list
        else{
            N->next=walker->next;
            walker->next=N;
        }

    }
}

/**************************************************************
* void List<T>::pop()
* ____________________________________________________________
* Deletes first node
* ___________________________________________________________
* PRE-CONDITIONS
* -list must not be empty
* POST-CONDITIONS
* -size decremented
* -First node is removed
***************************************************************/
template <class T>
void List<T>::pop(){
    assert(!isEmpty());
    _size--;
    Node<T>* p=_head;
    _head=p->next;
     delete p;
}

/**************************************************************
* void List<T>::setTail()
* ____________________________________________________________
* Sets tail node
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Points tail pointer to last node
***************************************************************/
template <class T>
void List<T>::setTail(){
    Node<T> *p=_head;
    while(p->next != nullptr){
        p=p->next;
    }
    _tail=p;

}

/**************************************************************
* Node<T>* List<T>::searchList(T key)
* ____________________________________________________________
* Searches list for key
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Returns position of node
* -If not found, return null
***************************************************************/
template <class T>
Node<T>* List<T>::searchList(T key){
    Node<T>* p=_head;
    for(;p!=nullptr;p=p->next){
        if(p->_item ==key){
            return p;
        }
    }
    return nullptr;    //didn't find anything
}

/**************************************************************
* void List<T>::printList()
* ____________________________________________________________
* Prints list
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
//template <class T>
//void List<T>::printList(){
//    Node<T>* p;
//    for(p=_head; p!=nullptr;p=p->next){
//        cout << p->_item;
//    }
//}

/**************************************************************
* Node<T>* List<T>::ReturnHead()
* ____________________________________________________________
* Return head_pointer
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
template <class T>
Node<T>*& List<T>::ReturnHead()
{
    return _head;
}

//declared these when I was testing the class but don't think I need to do this for
//type Product or Item or Date bc we initialized that in history class
template class List<char>;
template class List<int>;
template class List<Date>;
template class List<Item>;
template class List<Product>;
