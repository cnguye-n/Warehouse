#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <iostream>
using namespace std;

/*******************************************************************
* node struct
*
* Creates struct for nodes for linked list
******************************************************************/
template <typename ITEM_TYPE>
struct node
{
public:
    node();
    node(ITEM_TYPE item);

    friend std::ostream& operator <<(std::ostream& outs,
                                const node<ITEM_TYPE> &printMe);
    ITEM_TYPE _item;
    node* next;
};

/**************************************************************
* void _PrintList(node<ITEM_TYPE>* head)
* ____________________________________________________________
* Iterator parses through linked-list
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
template <typename ITEM_TYPE>
void _PrintList(node<ITEM_TYPE>* head)
{
    node<ITEM_TYPE>* iter;                                  //use pointer to move through linked list
    for (iter=head; iter!= NULL; iter->next)
    {
        cout << iter->_item;
    }
}

/*-optional
template <typename T>
void PrintList_backwards(node<T> *head);*/

/* SearchList
 * Precondition : -pointer head points to the head of a linked list
 *                -pointer variable in the last node is Null
 *                -if list is empty then head is NULL
 *
 * Postcondition: -returns a pointer that points to first node that contains key
 *                -if no node contains the key, return NULL
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _SearchList(node<ITEM_TYPE>* head, //our linked list         //return ptr to key or NULL
                            ITEM_TYPE key) //what we want to locate
{
    //make pointer variable point to head
    node<ITEM_TYPE>* here = head;

    if (here== NULL)
    {
        return NULL;
    }

    while ((here->_item != key) && (here->next!= NULL))
    {
        here=here->next;
    }
    if (here->_item == key)
        return here;
    else
        return NULL;
}

/**************************************************************
* node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,         //insert at the head of list
*                           ITEM_TYPE insertThis)
* ____________________________________________________________
* Inserts node at head pointer
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* - New node inserted at head
* - Node Not Null
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,         //insert at the head of list
                            ITEM_TYPE insertThis)
{
    //1.
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    //2.
    temp->next = head;
    //3.
    head= temp;
}

/**************************************************************
* node<ITEM_TYPE>* _InsertAfter(         //insert after ptr
*                            node<ITEM_TYPE> *afterThis,
*                            ITEM_TYPE insertThis)
* ____________________________________________________________
* Inserts node after specified node
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -New node is not null
* - New node after specified node
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(         //insert after ptr
                             node<ITEM_TYPE> *afterThis,
                             ITEM_TYPE insertThis)
{
    //assert function
    node<ITEM_TYPE>* nwalker = new node<ITEM_TYPE>(insertThis);
    nwalker->next = afterThis;
    afterThis->next=nwalker;

}

/**************************************************************
* node<ITEM_TYPE>* _InsertBefore(       //insert before ptr
*                             node<ITEM_TYPE>* beforeThis,
*                             ITEM_TYPE insertThis)
* ____________________________________________________________
* Inserts node before specific pointer
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* - New node before specified node
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(       //insert before ptr
                              node<ITEM_TYPE>* beforeThis,
                              ITEM_TYPE insertThis)
{
    insert_after(beforeThis,beforeThis->insertThis);
    beforeThis->insertThis=insertThis;
}

/**************************************************************
* node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        //ptr to previous node
*                              node<ITEM_TYPE>* prevToThis)
* ____________________________________________________________
* Returns pointer to previous node
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* - None
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        //ptr to previous node
                              node<ITEM_TYPE>* prevToThis)
{
    node<ITEM_TYPE>* walker = head;
    if (head == prevToThis) //that means that it is only one node
    return NULL;
    assert(head!=NULL); //will terminate program if this statement is false

    while (walker != NULL)
    {
        if (walker->next == prevToThis)
            return walker;
        walker=walker->next;
    }

}

/**************************************************************
* ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //delete, return item
*                     node<ITEM_TYPE>* deleteThis)
* ____________________________________________________________
* Deletes node and returns data
* ___________________________________________________________
* PRE-CONDITIONS
* -Node not null
* POST-CONDITIONS
* -Linked-list has one less node
***************************************************************/
template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //delete, return item
                     node<ITEM_TYPE>* deleteThis)
{
    node<ITEM_TYPE>*walker = head;
    while (walker != deleteThis)
    {
        if (walker == deleteThis)
        {
            PreviousNode(head,deleteThis)->next=deleteThis->next;
            delete walker;
            return walker->_item;
        }
        walker=walker->next;
    }
}

/**************************************************************
* node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head)
* ____________________________________________________________
* Copies linked-list to another linked-list
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -New Linked-list contains the same data as original
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head)           //duplicate the list... //copy node by node -done
{
    if (head==NULL)
        return NULL;
    //what instances should I return Null and no assert or assert and no null or both?
    node<ITEM_TYPE>* walker=head;
    node<ITEM_TYPE>* result = new node<ITEM_TYPE>;

    result->_item=walker->_item;
    result->next=_CopyList(walker->next); //add new node and copy each time-recursive
    return result;
}

/**************************************************************
* void _ClearList(node<ITEM_TYPE>*& head)
* ____________________________________________________________
* Clears list by deleting nodes
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -All nodes are deleted
* -All pointers set back to null
***************************************************************/
template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head)                     //delete all the nodes
{
    node<ITEM_TYPE>* walker=head;
    if(walker==NULL)
    {
        walker=NULL;
        return;
    }

    assert(walker!=NULL);

    node<ITEM_TYPE>* walker2 = walker;

    while (walker!=NULL)
    {
        walker2 = walker;
        walker = walker->next;
        delete walker2;
    }

    walker2=NULL;
    walker=NULL;

}

/**************************************************************
* ITEM_TYPE& _At(node<ITEM_TYPE>* head, int pos)
* ____________________________________________________________
* Returns data at specified node
* ___________________________________________________________
* PRE-CONDITIONS
* -Data not null
* POST-CONDITIONS
* -Object passed can be altered
***************************************************************/
template <typename ITEM_TYPE>
ITEM_TYPE& _At(node<ITEM_TYPE>* head, int pos)              //_item at this position
{
    node<ITEM_TYPE>*walker = head;
    for (int i=0; i<pos;i++)
    {
        walker=walker->next;
    }
    return walker->item;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

/**************************************************************
* node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,       //insert in a sorted way
*                             ITEM_TYPE item,
*                             bool ascending=true)
* ____________________________________________________________
* Inserts node based on data in ascending or descending order
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Data inserted into proper position
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,       //insert in a sorted way
                              ITEM_TYPE item,
                              bool ascending=true)
{
    node<ITEM_TYPE>* walker = head;
    //if only one node exists
    if(head==NULL)
    {
        return _InsertHead(head, item);
    }

    if(ascending)
    {
        while(walker->item<=item && walker->next!=NULL)
        {
            walker=walker->next;
        }
        if(walker->item>=item)
        {
            _InsertBefore(walker, item);
        }
        else {
            _InsertAfter(walker, item);
        }

    }
    else
    {
        while(walker->item>=item && walker->next!=NULL)
        {
            walker=walker->next;
        }
        if(walker->item>=item)
        {
            _InsertAfter(walker, item);
        }
        else {
            _InsertBefore(walker, item);
        }
    }

}

/**************************************************************
* node<ITEM_TYPE>* _InsertLast(node<ITEM_TYPE>* &head,       //insert in a sorted way
*                             ITEM_TYPE item
*                             )
* ____________________________________________________________
* Node inserted into last end of list
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* - Node inserted to end of list
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertLast(node<ITEM_TYPE>* &head,       //insert in a sorted way
                              ITEM_TYPE item
                              )
{
    node<ITEM_TYPE>* walker = _LastNode(head);
    return _InsertAfter(walker, item);
}

/**************************************************************
* node<ITEM_TYPE>* _WhereThisGoes(node<ITEM_TYPE>* head,         //node after which this
*                              ITEM_TYPE item,                //    item goes
*                              bool ascending=true)
* ____________________________________________________________
* Returns node that identifies proper position for data entry
* ___________________________________________________________
* PRE-CONDITIONS
* -Must identify if data is in ascending or descending order
* POST-CONDITIONS
* -Position given after a specific node
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _WhereThisGoes(node<ITEM_TYPE>* head,         //node after which this
                               ITEM_TYPE item,                //    item goes
                               bool ascending=true)          //order: 0 ascending
{
    node<ITEM_TYPE>* walker = head;
    if (walker == NULL)
        return NULL;
    assert(walker!=NULL);
    while (walker != NULL && walker->_item < item)
    {
        ascending=false;
        if (walker->_item < item && walker->next->_item > item)
        {
             ascending=true;
             return walker->item;
        }
        walker=walker->next;
    }
}

/**************************************************************
* node<ITEM_TYPE>* _LastNode(node<ITEM_TYPE>* head)
* ____________________________________________________________
* Returns position of last node
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Given last position of node
***************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _LastNode(node<ITEM_TYPE>* head)            //Last Node in the list
{
    node<ITEM_TYPE>* walker = head;
    if (head==NULL)
        return walker;
    assert(head!=NULL);

    while(walker->next!=NULL)
    {
        walker=walker->next;
     }

     return walker;
}

#endif
