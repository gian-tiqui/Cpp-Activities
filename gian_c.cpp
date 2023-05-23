#include <iostream>
#include <stack>

using namespace std;

struct node {
	
	int val;
	node *left, *right;
	
	node(int num) {
		this->val = num;
		this->left = this->right = NULL;
	}
};


class binary_tree {
	public:
		
		node* root;
		
		binary_tree(int num) { root = new node(num); }
		
		node* insert(node* root, int num) {
			if (root == NULL) root = new node(num);
			else if (num < root->val)root->left = insert(root->left, num);
			else root->right = insert(root->right, num);
				
			return root;
		}
		
		void in_order(node* root) {
			if (!root) return;
				
			in_order(root->left);
			cout<<root->val<<endl;
			in_order(root->right);
		}
		
};


int main() {
	
	binary_tree bt(5);
	bt.insert(bt.root, 3);
	bt.insert(bt.root, 7);
	bt.in_order(bt.root);
	
	return 0;
}