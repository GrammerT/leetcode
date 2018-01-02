#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *firstNode = l1;
        ListNode *tmpNode = firstNode;
        int i=0;
        bool isNeedAdd = false;
        while(l1&&l2)
        {

            int rv = l1->val+l2->val;
            if(rv/10>0)
            {
                rv = rv%10;
                if(l1->next!=NULL)
                {
                    l1->next->val+=1;
                }
                else if(l2->next!=NULL)
                {
                    l2->next->val+=1;
                }
                else
                {
                    isNeedAdd = true;
                }
            }
            else
            {
                rv = rv%10;
            }
            firstNode->val=rv;
            firstNode = l1->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(isNeedAdd) //! all null
        {
            ListNode *lastNode = new ListNode(1);
            firstNode->next = lastNode;
            return tmpNode;
        }
        if(firstNode) //! l2 NULL
        {
            firstNode->next = l1->next;
        }
        else if(l2!=NULL) //! l1 NULL
        {
            firstNode->next = l2;
        }
        return tmpNode;
    }
};

int main(int argc, char *argv[])
{
    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    ListNode *l13 = new ListNode(3);
    l11->next=l12;
    l12->next=l13;
    ListNode *l21 = new ListNode(5);
    ListNode *l22 = new ListNode(6);
    ListNode *l23 = new ListNode(4);
    l21->next=l22;
    l22->next=l23;
    Solution so;
    ListNode *tmp = so.addTwoNumbers(l11,l21);
    while(tmp)
    {
        cout<<" "<<tmp->val;
        tmp = tmp->next;
    }
    return 0;
}
