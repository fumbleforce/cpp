#include "llist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;





ListNode::ListNode(string value)
{
    this->value = value;
    this->next = NULL;
}

const string& ListNode::getValue() const
{
    return value;
}

ListNode* ListNode::getNext() const
{
    return next;
}

LinkedList::LinkedList()
{
    head = NULL;
    last = NULL;
}

LinkedList::~LinkedList()
{
    destroy 
}

bool LinkedList::isEmpty()
{
    return head == NULL && last == NULL;
}

void LinkedList::insertAtFront(const string &value)
{
    if (head == NULL)
        head = ListNode(value);
}

void LinkedList::insertAtBack(const string &value)
{
    if (head == NULL)
        head = ListNode(value);
}

bool LinkedList::removeFromFront(string &output)
{
    if (!isEmpty())
    {
        output = (*head).value;
        next = (*head).next;
        delete *head;
        head = next;
    }
    else
        return false
}

bool LinkedList::removeFromBack(string &output)
{
    if (!isEmpty())
    {
        output = (*last).value;
        last = (*last).
    }
    else
        return false
}

friend ostream & operator<<(ostream & stream, const linkedList & list )
{

}