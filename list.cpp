#include <iostream>
#include <queue>

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
	new_guy->next = *head;

	*head = new_guy;
}

void append(NodePtr* head, int new_num) {
	NodePtr new_guy = new Node();
	NodePtr curr = *head;

	new_guy->val = new_num;
	new_guy->next = NULL;
	
	if (!curr) {
		curr = new_guy;
		return;
	}

	NodePtr last = *head;

	while (last->next) {
		last = last->next;
	}

	last->next = new_guy;
}

int len(NodePtr head, int n = 0) {
	while (head) {
		n++;
		head = head->next;
	}

	return n;
}

NodePtr reverse(NodePtr head) { 
	NodePtr curr = head;
	NodePtr next = NULL;
	NodePtr prev = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;  	  
	}

	head = prev;

	return head;
}

NodePtr merge_two_list(NodePtr list1, NodePtr list2) {
	NodePtr curr = list1;
    NodePtr curr2 = list2;
    NodePtr last = list1; 

    std::queue<int> nodes;

    while (curr2) {
        nodes.push(curr2->val);
        curr2 = curr2->next; 
    }

    while (curr) {
        last = curr; 
        curr = curr->next;
    }

    while (!nodes.empty()) {
        NodePtr new_guy = new Node(nodes.front());
        nodes.pop();
        last->next = new_guy; 
        last = new_guy; 
    }

    return list1; 
}

NodePtr merge_two_sorted_list(NodePtr list1, NodePtr list2) { 
	return NULL;
}

int main() {
    NodePtr list1 = new Node(1);
	NodePtr list2 = new Node(2);

	for (int n = 2; n <= 5; ++n) {
		append(&list1, n);
		append(&list2, n + n);
	}
	
	print_list(merge_two_list(list1, list2));
	
    return 0;
}
