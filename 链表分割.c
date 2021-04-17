#include<stdio.h>

//����һ�����ͷָ�� ListNode* pHead��
//��һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

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