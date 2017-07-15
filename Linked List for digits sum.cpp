/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/



#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x = 0) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* new_list = new ListNode((int)(l1->val+l2->val)%10);
    ListNode* node = new_list;
    ListNode* aux1 = new ListNode(), *aux2 = new ListNode();
    aux1 = l1->next;
    aux2 = l2->next;
    int carry = (l1->val+l2->val)/10;
    while(aux1 && aux2 ){
        int digit = (aux1->val + aux2->val)%10;
        node->next = new ListNode(digit+carry);
        node = node->next;
        carry = (aux1->val + aux2->val)/10;
        aux1=aux1->next;
        aux2 = aux2->next;
    }
    if ( aux1 ){
        node->next = new ListNode(carry + aux1->val);
        aux1 = aux1->next;
    }

    if ( aux2 ){
        node->next = new ListNode(carry + aux2->val);
        aux2 = aux2->next;
    }

    while(aux1){
        node->next = new ListNode(aux1->val);
        aux1 = aux1->next;
    }

    while(aux2){
        node->next = new ListNode(aux2->val);
        aux2 = aux2->next;
    }
    return new_list;
    }
};

int main(){
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    Solution s;
    ListNode* list_sum = s.addTwoNumbers(list1, list2);

    ListNode* aux = list_sum;
    while( aux ){
        cout << aux->val << " ";
        aux =  aux->next;
    }

}


