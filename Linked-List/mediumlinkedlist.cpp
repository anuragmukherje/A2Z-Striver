#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode *convertArrToLL(vector<int> &arr)
{
    ListNode *headNode = new ListNode(arr[0]);
    ListNode *curNode = headNode;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);
        curNode->next = newNode;
        curNode = curNode->next;
    }

    return headNode;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int x = l1->val + l2->val;
    int carryNum = x / 10;
    ListNode *firstNode = l1->next;
    ListNode *secondNode = l2->next;

    ListNode *head = new ListNode(x % 10);
    ListNode *curNode = head;
    while (firstNode != NULL && secondNode != NULL)
    {
        int sum = firstNode->val + secondNode->val + carryNum;
        carryNum = sum / 10;

        ListNode *newNode = new ListNode(sum % 10);
        curNode->next = newNode;
        curNode = curNode->next;

        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }

    while (firstNode != NULL)
    {
        int sum = firstNode->val + carryNum;
        carryNum = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        curNode->next = newNode;
        curNode = curNode->next;
        firstNode = firstNode->next;
    }

    while (secondNode != NULL)
    {
        int sum = secondNode->val + carryNum;
        carryNum = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        curNode->next = newNode;
        curNode = curNode->next;
        secondNode = secondNode->next;
    }

    if (carryNum != 0)
    {
        ListNode *newNode = new ListNode(carryNum);
        curNode->next = newNode;
    }

    return head;
}

int main()
{

    return 0;
}