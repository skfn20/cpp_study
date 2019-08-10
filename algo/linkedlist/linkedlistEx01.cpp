#include<iostream>

using namespace std;

struct ListNode{
    int element;
    ListNode *prev, *next;
};

void deleteNode(ListNode* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void recoverNode(ListNode* node){
    node->prev->next = node;
    node->next->prev = node;
}
