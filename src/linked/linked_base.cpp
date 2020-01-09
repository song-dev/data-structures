// 链表基础功能的创建、增、删、改查
// crated by chensongsong on 20201.9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{

    int id; //数据域
    char *name;
    struct Node *next; //指针域
} Node;

//创建节点
Node *make_node(int id, char *name);
//添加节点，从尾部添加
void llist_append_node(Node *head, Node *newP);
//添加节点，从头部添加
void llist_append_head(Node *head, Node *newP);
//遍历打印列表
void llist_print_each(Node *head);
//将节点添加指定节点的后面
void llist_insert_node_after_by_id(Node *head, Node *newP, int id);
//根据id查找节点
Node *llist_search_node_by_id(Node *head, int id);
//根据名字查询节点
Node *llist_search_node_by_name(Node *head, char *name);
//根据id找到改节点的上一个节点
Node *llist_search_node_by_prev(Node *head, int id);
//根据id删除节点
void llist_delete_node_by_id(Node *head, int id);

int main(int argc, char *argv[])
{
    //创建头结点
    Node *head = make_node(-1, (char *)"head");

    //创建4个结点
    Node *n1 = make_node(1, (char *)"name1");
    Node *n2 = make_node(2, (char *)"name2");
    Node *n3 = make_node(3, (char *)"name3");
    Node *n4 = make_node(4, (char *)"name4");

    //添加结点n1->n2->n3->n4
    llist_append_node(head, n1);
    llist_append_node(head, n2);
    llist_append_node(head, n3);
    llist_append_node(head, n4);

    printf("printf crated linked:\n");
    llist_print_each(head);

    //根据id插入结点，把第5个结点插入到id为2的结点后面
    Node *n5 = make_node(5, (char *)"name5");
    llist_insert_node_after_by_id(head, n5, 2);

    printf("printf insert linked:\n");
    llist_print_each(head);

    //根据id插入结点，把第7个结点插入到id为6的结点后面
    Node *n7 = make_node(7, (char *)"name7");
    llist_insert_node_after_by_id(head, n7, 6);

    printf("printf insert linked:\n");
    llist_print_each(head);

    //根据id删除节点4
    llist_delete_node_by_id(head, 4);
    printf("printf delete linked:\n");
    llist_print_each(head);

    return 0;
}

//创建节点
Node *make_node(int id, char *const name)
{
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->id = id;
    ret->name = name;
    ret->next = NULL;
    return ret;
}

//添加节点，从尾部添加
void llist_append_node(Node *head, Node *newP)
{
    Node *cur = head;
    //找到最后的节点
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newP;
}
//添加节点，从头部添加
void llist_append_head(Node *head, Node *newP)
{
    Node *cur = head;
    if (cur != NULL)
    {
        newP->next = cur->next;
        cur->next = newP;
    }
}

//根据id查找节点
Node *llist_search_node_by_id(Node *head, int id)
{
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->id == id)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//将节点添加指定节点的后面
void llist_insert_node_after_by_id(Node *head, Node *newP, int id)
{
    Node *cur = llist_search_node_by_id(head, id);
    if (cur != NULL)
    {
        newP->next = cur->next;
        cur->next = newP;
    }
    else
    {
        llist_append_node(head, newP);
    }
}

//根据名字查询节点
Node *llist_search_node_by_name(Node *head, char *name)
{
    Node *cur = head;
    while (cur != NULL)
    {

        if (strcmp(cur->name, name) == 0)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//根据id找到改节点的上一个节点
Node *llist_search_node_by_prev(Node *head, int id)
{
    Node *cur = head;
    while (cur->next != NULL)
    {

        if (cur->next->id == id)
        {
            printf("searched node by prev.\n");
            return cur;
        }
        cur = cur->next;
    }
    printf("not search node by prev.\n");
    return NULL;
}
//根据id删除节点
void llist_delete_node_by_id(Node *head, int id)
{
    Node *prev_node = llist_search_node_by_prev(head, id);
    if (prev_node != NULL)
    {
        printf("llist_search_node_by_prev.\n");
        //先保存要删除的节点
        Node *saveNode = prev_node->next;
        prev_node->next = saveNode->next;
        saveNode->next = NULL;
        free(saveNode);
    }
}

//遍历打印列表
void llist_print_each(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *cur = head->next;
    while (cur != NULL)
    {
        printf("%p| %d | %s| next: %p->\n", cur, cur->id, cur->name, cur->next);
        cur = cur->next;
    }
}