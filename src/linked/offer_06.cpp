#include <stdio.h>
#include <stdlib.h>

// 题目：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
// 解题思路，先将链表数据存储到数组，然后反转数组

struct ListNode
{
    int val;
    struct ListNode *next;
};

int *reversePrint(struct ListNode *head, int *returnSize)
{

    ListNode *p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    *returnSize = size;
    p = head;
    int *result = (int *)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; --i)
    {
        result[i] = p->val;
        p = p->next;
    }

    return result;
}

int main()
{
    ListNode *head = NULL;
    ListNode *p = NULL;
    for (size_t i = 0; i < 5; i++)
    {
        ListNode *n = (ListNode *)malloc(sizeof(ListNode));
        if (head == NULL)
        {
            head = p = n;
        }
        else
        {
            p->next = n;
            p = p->next;
        }
        n->val = i;
    }
    int size = 0;
    int *array = reversePrint(head, &size);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
