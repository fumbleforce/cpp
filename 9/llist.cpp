#include "llist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;





ListNode::ListNode(const string& value)
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
    // todo
}

bool LinkedList::isEmpty() const
{
    return head == NULL && last == NULL;
}

void LinkedList::insertAtFront(const string &value)
{
    ListNode *currNode = head;
    ListNode *newNode = new ListNode(value);
    if (head != NULL)
    {
        newNode->next = head;
    }

    if (last == NULL)
        last = newNode;

    head = newNode;
}

void LinkedList::insertAtBack(const string &value)
{
    if (head == NULL)
    {
        head = new ListNode(value);
        last = head;
    }
    else
    {
        ListNode* atBack = new ListNode(value);
        if (last != NULL)
            last->next = atBack;

        last = atBack;
    }
}

bool LinkedList::removeFromFront(string &output)
{
    if (!isEmpty())
    {
        output = head->value;
        ListNode* next = head->next;
        delete head;
        head = next;
        return true;
    }
    else
    {
        return false;
    }
        
}

bool LinkedList::removeFromBack(string &output)
{
    if (!isEmpty())
    {

        ListNode* currNode = head;
        ListNode* prevNode;


        // move to second last node
        while (currNode->getNext() != NULL)
        {
            prevNode = currNode;
            currNode = currNode->getNext();
        }
            

        output = currNode->value;
        delete currNode;
        prevNode->next = NULL;
        last = prevNode;
    }
    else
    {
        return false;
    }
        
}


ListNode *LinkedList::search(const string &value)
{
    ListNode* currNode = head;

    if (head == NULL) return NULL;

    while (currNode != NULL)
    {
        if (currNode->getValue() == value)
            return currNode;

        currNode = currNode->getNext();
    }
}


void LinkedList::remove(const string &value)
{
    ListNode* currNode = head;
    ListNode* prevNode;

    if (head == NULL) return;

    while (currNode != NULL)
    {
        if (currNode->getValue() == value)
        {
            if (prevNode != NULL)
                prevNode->next = currNode->getNext();
            else
                head = currNode->getNext();

            delete currNode;
        }
        prevNode = currNode;
        currNode = currNode->getNext();
    }
    last = currNode;
}



ostream & operator<<(ostream & stream, const LinkedList & list )
{
    ListNode* currNode = list.head;

    while (currNode != NULL)
    {
        cout << currNode->getValue();
        currNode = currNode->getNext();
    }
    
    return stream;
}