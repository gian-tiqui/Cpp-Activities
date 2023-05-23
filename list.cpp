#include <iostream>

using std::cout;



class Node {
public:
    int val;
    Node *next;
};

typedef Node* NodePtr;

void print_list(NodePtr head) {
    NodePtr curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

void reverse(NodePtr head) {
    NodePtr curr = head;
    while (curr) {
        curr = curr->next;
    }

}

void insert_front(NodePtr* head, int new_num) {
	NodePtr new_guy = new Node(); 
	
	new_guy->val = new_num; 
	new_guy->next = *head; // New Guy is now the head

	*head = new_guy; // The head ptr now is New Guy
}

void append(NodePtr* head, int new_num) {
	NodePtr new_guy = new Node();

	new_guy->val = new_num;
	new_guy->next = NULL;
	
	if (!*head) {
		*head = new_guy;
		return;
	}

	NodePtr last = *head;

	while (last->next) {
		last = last->next;
	}

	last->next = new_guy;
}

int main() {

    NodePtr head = new Node();

    head->val = 0;
    head->next = NULL;

	int n = 1;

	insert_front(&head, (n - (n * 2)));
	append(&head, n);

    print_list(head);

    return 0;
}