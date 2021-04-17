#include<stdio.h>

//现有一链表的头指针 ListNode* pHead，
//给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

ListNode* partition(ListNode* pHead, int x) {
    // write code here
    ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
    head1->next = NULL;
    ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->next = NULL;
    ListNode* cur = head1;
    ListNode* cur2 = head2;
    while (pHead)
    {
        if (pHead->val < x)
        {
            cur->next = pHead;
            cur = cur->next;
        }
        else
        {
            cur2->next = pHead;
            cur2 = cur2->next;
        }
        pHead = pHead->next;
    }
    cur->next = head2->next;
    cur2->next = NULL;
    ListNode* tmp = head1->next;
    free(head1);
    free(head2);
    return tmp;
}