#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* loop_start(ListNode* l){
    ListNode* slow = l, *fast = l;
    while ( slow != NULL && fast != NULL ){
        slow = slow->next;
        fast = fast->next->next;
        if ( slow == fast )
            break;
    }

    ListNode* slow2 = l;
    while( slow2 != fast ){
        slow2 = slow2->next;
        fast = fast->next;
    }

    return fast;
}




int main(){
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    ListNode* aux = l->next->next;
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    l->next->next->next->next->next = aux;

    ListNode* ll = loop_start(l);
    cout << ll->val;
    return 0;
}
