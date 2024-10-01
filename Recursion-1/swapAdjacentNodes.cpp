#include<bits/stdc++.h>
using namespace std;

struct ListNode{
        int val;
        ListNode *next;
        ListNode(): val(0),next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x,ListNode *next) : val(x), next(next) {}
    };

void printLinkedList(ListNode* head){
    ListNode *temp = head;
    while(temp!=nullptr){
        // (*temp) dereferencing a pointer --> go to the address stored in temp and access the object/content in that address
        // note temp->val == (*temp).val
        // the -> combines these 2 steps
        // 1. derefercing
        // 2. member access
        cout<<(*temp).val<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
ListNode* swapAjacentNodes(ListNode *head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    ListNode* firstNode = head;
    ListNode* secondNode = head->next;
    
    
    firstNode->next = swapAjacentNodes(secondNode->next);
    secondNode->next = firstNode;
    return secondNode;
}
int main(){
    
    ListNode* head = new ListNode(1);
    // the ListNode constructor doesn't return a obj
    // the new keyword allocates memory and returns a reference to the newly created object.
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // ip: 1->2->3->4
    // op: 2->1->4->3
    printLinkedList(head);
    ListNode* rev = swapAjacentNodes(head);
    printLinkedList(rev);
    return 0;
}