#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int x)
    {
        this->data = x;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Q. Convert a given array to Linked List
Node *convertArrToLL(vector<int> &arr)
{
    Node *headNode = new Node(arr[0]);
    Node *curNode = headNode;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        curNode->next = newNode;
        curNode = curNode->next;
    }

    return headNode;
}

// Q. Find the length of the Linked List
int returnLengthOfLL(Node *head)
{
    Node *curNode = head;
    int lenOfLL = 0;
    while (curNode != NULL)
    {
        lenOfLL++;
        curNode = curNode->next;
    }
    return lenOfLL;
}

// Q. Print the given Singly Linked List
void printLL(Node *head)
{
    Node *node = head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    return;
}

// Q. Convert array to Doubly Linked List
DNode *convertArrToDLL(vector<int> &arr)
{
    DNode *headNode = new DNode(arr[0]);
    DNode *curNode = headNode;

    for (int i = 1; i < arr.size(); i++)
    {
        DNode *newNode = new DNode(arr[i]);
        curNode->next = newNode;
        newNode->prev = curNode;

        curNode = curNode->next;
    }

    return headNode;
}

// Q. Return the length of the doubly Linked List
int lengthOfDLL(DNode *head)
{
    DNode *curNode = head;
    int lenOfDL = 0;
    while (curNode != NULL)
    {
        lenOfDL++;
        curNode = curNode->next;
    }
    return lenOfDL;
}

// Q. Print the given Linked List (Doubly)
void printDLL(DNode *head)
{
    DNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return;
}

// Q. Entry at position ahead of pos in Doubly Linked List
DNode *addNodeAtPos(int val, DNode *head, int pos)
{
    DNode *curNode = head;
    // cout << curNode->data << "\n";

    int posIs = 1;
    while (posIs != pos + 1)
    {
        posIs++;
        // cout << curNode->data << "\n";
        curNode = curNode->next;
    }

    // cout << curNode->data << "\n";

    if (curNode->next == NULL)
    {
        DNode *newNode = new DNode(val);
        newNode->prev = curNode;

        curNode->next = newNode;
    }
    else
    {
        DNode *newNode = new DNode(val);
        newNode->prev = curNode;
        newNode->next = curNode->next;

        curNode->next->prev = newNode;
        curNode->next = newNode;
    }

    return head;
}

int main()
{
    vector<int> arr = {2, 4, 5, 7, 3, 8, 9};
    // Node *head = convertArrToLL(arr);
    // printLL(head);

    // cout << endl;

    // int len = returnLengthOfLL(head);
    // cout << len << endl;

    DNode *dHead = convertArrToDLL(arr);
    printDLL(dHead);

    cout << endl;

    dHead = addNodeAtPos(6, dHead, 3);
    printDLL(dHead);

    cout << endl;

    dHead = addNodeAtPos(1, dHead, 7);
    printDLL(dHead);
}