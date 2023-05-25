#include <iostream>

using std::cout;

class Node {
public:
    int val;
    Node *next;

	Node() {
		this->val = 0;
		this->next = NULL;
	}

	Node(int n) {
		this->val = n;
		this->next = NULL;
	}
private:
	std::string meow = "meow";
};

typedef Node* NodePtr;

void print_list(NodePtr head) {
    NodePtr curr = head;
    while (curr) {
        cout << curr->val << " ";
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

NodePtr reverse(NodePtr head) { 
	NodePtr curr = head;
	NodePtr next = NULL;
	NodePtr prev = NULL;

	while (curr) {
		next = curr->next; //  (curr)0 - (next)1 - 2 - 3 - null
		curr->next = prev; //  (curr)0 - (next)(prev)1 - 2 - 3 - null
		prev = curr; 	   //  (curr)0 - (next)(prev)0 - 2 - 3 null
		curr = next;  	   //  (curr)1 - (next)(prev)0 - 2 - 3 - null
	}

	head = prev;

	return head;
}

int main() {
    NodePtr head = new Node();

	for (int n = 1; n <= 3; ++n) append(&head, n);

	head = reverse(head);

    print_list(head);

    return 0;
}