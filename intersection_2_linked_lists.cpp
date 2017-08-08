#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* intersection(ListNode* l1, ListNode* l2){
    if ( l1 == NULL || l2 == NULL ) return NULL;
    int length1 = 0, length2 = 0;
    ListNode *aux1 = l1, *aux2 = l2;
    while ( aux1->next ){
        length1 ++;
        aux1 = aux1->next;
    }
    while ( aux2->next ){
        length2 ++;
        aux2 = aux2->next;
    }
    if ( aux1 != aux2 ) return NULL;
    ListNode* shorter = length1 < length2 ? l1 : l2;
    ListNode* longer = length1 > length2 ? l1 : l2;
    int difference = abs(length1 - length2);
    while ( difference -- ){
        longer = longer->next;
    }

    while( shorter != longer ){
        shorter = shorter->next;
        longer = longer->next;
    }
    return longer;
}





int main(){
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = l->next->next;

    ListNode* inter = intersection(l, l2);
    cout << inter->val;
    return 0;
}
