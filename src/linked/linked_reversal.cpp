#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

/**
 * 打印链表
 */
void printf_listnode(ListNode *node)
{
    // ListNode *node = head->next;
    while (node)
    {
        printf("num: %d\n", node->val);
        node = node->next;
    }
    return;
}

/**
 * 反转链表
 * 
 * 思路：
 * 1. 保存 current next 节点为 node
 * 2. 将 current next 切换成 prev 节点
 * 3. 将 prev 指针移动到 current 节点
 * 4. 将保存的 node 节点赋值到 current 指针
 */
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *current = head;

    while (current)
    {
        ListNode *node = current->next;
        current->next = prev;
        prev = current;
        current = node;
    }

    return prev;
}

int main()
{

    // 生成 5 个节点单链表
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *current = head;

    for (int i = 0; i < 5; i++)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->val = i;
        p->next = NULL;
        current->next = p;
        current = current->next;
    }

    head = head->next;
    // 测试创建单链表
    printf_listnode(head);
    // 提供函数调用
    ListNode *result = reverseList(head);
    // 输出结果
    printf_listnode(result);

    return 0;
}
