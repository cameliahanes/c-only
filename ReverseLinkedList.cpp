
class Node{
public:
        int val;
        Node* next;
        Node(int c){
        this->val = c;
        this->next = NULL;
        }
};


Node* reverseLL(Node* node){
        Node* prev = NULL;
        Node* current = node;
        Node* next;
        while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }
        node = prev;
        return node;
}

void printList(Node* root){
        while (root != NULL){ cout << root->val <<" "; root = root->next; } cout << endl;
}
