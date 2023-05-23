#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::string;

class Node
{

	int key;
	Node *left, *right;

public:
	Node()
	{
		key = 0;
		left = right = NULL;
	}

	Node(int data)
	{
		key = data;
		left = right = NULL;
	}

	Node *insert(Node *root, int data)
	{

		if (root == NULL)
			root = new Node(data);
		else if (data < root->key)
			root->left = insert(root->left, data);
		else
			root->right = insert(root->right, data);

		return root;
	}

	void in_order(Node *root)
	{

		if (root != NULL)
		{
			in_order(root->left);
			cout << root->key << " ";
			in_order(root->right);
		}
	}

	void post_order(Node *root)
	{

		if (root != NULL)
		{
			post_order(root->left);
			post_order(root->right);
			cout << root->key << " ";
		}
	}

	void pre_order(Node *root)
	{

		if (root != NULL)
		{
			cout << root->key << " ";
			pre_order(root->left);
			pre_order(root->right);
		}
	}

	void iterative_in_order(Node *root)
	{

		std::stack<Node *> s;

		while (s.empty() == false || root != NULL)
		{
			if (root != NULL)
			{

				s.push(root);
				root = root->left;
			}
			else
			{
				root = s.top();
				s.pop();

				cout << root->key << " ";
				root = root->right;
			}
		}
	}

	void inverse(Node *root)
	{

		if (root != NULL)
		{
			inverse(root->left);
			inverse(root->right);

			Node *temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
	}

	void delete_deepest(Node *root, Node *deleting_node)
	{

		std::queue<Node *> nodes;
		nodes.push(root);
		Node *temp;

		while (!nodes.empty())
		{
			temp = nodes.front();
			nodes.pop();

			if (temp == deleting_node)
			{
				temp = NULL;
				delete (deleting_node);
				return;
			}
			if (temp->right)
			{
				if (temp->right == deleting_node)
				{
					temp->right = NULL;
					delete deleting_node;
					return;
				}
				else
					nodes.push(temp->right);
			}
			if (temp->left)
			{
				if (temp->left == deleting_node)
				{
					temp->left = NULL;
					delete deleting_node;
					return;
				}
				else
					nodes.push(temp->left);
			}
		}
	}

	Node *delete_node(Node *root, int num)
	{

		if (root == NULL)
			return NULL;
		else if (root->left == NULL && root->right == NULL)
		{
			if (root->key == num)
				return NULL;
			else
				return root;
		}

		std::queue<Node *> nodes;
		nodes.push(root);
		Node *temp;
		Node *key_node = NULL;

		while (!nodes.empty())
		{
			temp = nodes.front();
			nodes.pop();
			if (temp->key == num)
				key_node = temp;
			if (temp->left)
				nodes.push(temp->left);
			if (temp->right)
				nodes.push(temp->right);
		}
		if (key_node != NULL)
		{
			int deepest_node_data = temp->key;
			delete_deepest(root, temp);
			key_node->key = deepest_node_data;
		}

		return root;
	}

	bool search(Node *root, int num)
	{
		int depth = 0;
		Node *temp = new Node();
		temp = root;

		while (temp != NULL)
		{
			depth++;
			if (temp->key == num)
				return true;
			else if (temp->key > num)
				temp = temp->left;
			else
				temp = temp->right;
		}

		return false;
	}
};

int main()
{

deletion:

	Node *root = NULL, tree;

start:

	int choice, x;

	cout << "\n\nWelcome to Binary Tree program." << '\n';
	cout << "1. Insert a Node" << '\n';
	cout << "2. Search a Node" << '\n';
	cout << "3. Delete a Node" << '\n';
	cout << "4. Print Pre-Order" << '\n';
	cout << "5. Print In-Order" << '\n';
	cout << "6. Print Post-Order" << '\n';
	cout << "7. Inverse the Tree" << '\n';
	cout << "8. Delete the Tree" << '\n';
	cout << "9. Exit" << '\n';
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice > 0 && choice <= 9)
	{
		if (choice == 1)
		{
			if (root == NULL)
			{
				cout << "Tree is empty, ";
			insert:
				cout << "Enter the root: ";
				cin >> x;

				root = tree.insert(root, x);
				goto start;
			}
			else
			{
				cout << "Enter a node: ";
				cin >> x;

				tree.insert(root, x);
				goto start;
			}
		}
		else if (choice == 2)
		{
			if (root == NULL)
			{
				char choice_insert;

				cout << "Tree is empty, enter the root? Enter 'Y' or 'N': ";
			search:
				cin >> choice_insert;

				if (tolower(choice_insert) == 'y')
					goto insert;
				else if (tolower(choice_insert) == 'n')
					goto start;
				else
				{
					cout << "Invalid input, Try again: ";
					goto search;
				}
			}
			else
			{
				cout << "Enter the node you want to search: ";
				cin >> x;

				string found = (tree.search(root, x)) ? "does" : "does not";

				cout << "The Node " << x << " " << found << " exist." << '\n';
				goto start;
			}
		}
		else if (choice == 3)
		{
			int delete_this;
			char safe_delete;

			if (root == NULL)
			{
				char choice_delete;

				cout << "Tree is empty, enter the root? Enter 'Y' or 'N': ";
			delete_node:
				cin >> choice_delete;

				if (tolower(choice_delete) == 'y')
					goto insert;
				else if (tolower(choice_delete) == 'n')
					goto start;
				else
				{
					cout << "Invalid input, Try again: ";
					goto delete_node;
				}
			}
			else
			{
			delete_back:
				cout << "Enter the node you want to delete: ";
				cin >> delete_this;

				cout << "Are you sure that you want to delete this node?";
			delete_invalid:
				cout << " Enter 'Y' or 'N': ";
				cin >> safe_delete;

				if (tolower(safe_delete) == 'y')
				{
					if (tree.search(root, delete_this))
					{
						tree.delete_node(root, delete_this);
						cout << "Node deleted." << '\n';
						goto start;
					}
					else
					{
						cout << "Node not found. ";
						goto delete_back;
					}
				}
				else if (tolower(safe_delete == 'n'))
					goto delete_back;
				else
				{
					cout << "Invalid input. ";
					goto delete_invalid;
				}
			}
		}
		else if (choice == 4)
		{
			if (root != NULL)
			{
				cout << "Preorder" << '\n';
				tree.pre_order(root);
				goto start;
			}
			else
			{
				cout << "Tree is empty." << '\n';
				goto start;
			}
		}
		else if (choice == 5)
		{

			if (root != NULL)
			{
				cout << "Inorder:" << '\n';
				tree.in_order(root);
				goto start;
			}
			else
			{
				cout << "Tree is empty." << '\n';
				goto start;
			}
		}
		else if (choice == 6)
		{

			if (root != NULL)
			{
				cout << "Postorder" << '\n';
				tree.post_order(root);
				goto start;
			}
			else
			{
				cout << "Tree is empty." << '\n';
				goto start;
			}
		}
		else if (choice == 7)
		{
			char choice_invert, choice_sure, choice_empty;

			if (root == NULL)
			{
				cout << "Tree is empty, enter the root?";
			invert:
				cout << " Enter 'Y' or 'N': ";
				cin >> choice_empty;

				if (tolower(choice_empty) == 'y')
					goto insert;
				else if (tolower(choice_empty) == 'n')
					goto start;
				else
				{
					cout << "Invalid input. ";
					goto invert;
				}
			}

			cout << "NOTE:" << '\n';
			cout << "Once you reversed the tree, you should not use the search function." << '\n';
			cout << "If you want to use the search function, you should revert the tree to its first state." << '\n';
		inverse:
			cout << "Do you want to continue? Enter 'Y' or 'N': ";
			cin >> choice_invert;

			if (tolower(choice_invert) == 'y')
			{
				cout << "Are you sure? Enter 'Y' or 'N': ";
				cin >> choice_sure;

				if (tolower(choice_sure == 'y'))
				{
					tree.inverse(root);
					cout << "Tree has been inversed." << '\n';
					goto start;
				}
			}
			else if (tolower(choice_sure == 'n'))
			{
				goto start;
			}
			else
			{
				cout << "Invalid input. ";
				goto inverse;
			}
		}
		else if (choice == 8)
		{

			char delete_tree;

			if (root == NULL)
			{
				cout << "Tree is empty, enter the root?";
			delete_tree_back:
				cout << "Enter 'Y' or 'N': ";
				cin >> delete_tree;

				if (tolower(delete_tree) == 'y')
					goto insert;
				else if (tolower(delete_tree) == 'n')
					goto start;
				else
				{
					cout << "Invalid input ";
					goto delete_tree_back;
				}
			}
			else
			{
				cout << "Are you sure you want to delete the tree? ";
			delete_tree_back2:
				cout << "Enter 'Y' or 'N': ";
				cin >> delete_tree;

				if (tolower(delete_tree) == 'y')
				{
					cout << "Tree has been deleted." << '\n';
					goto deletion;
				}
				else if (tolower(delete_tree) == 'n')
					goto start;
				else
				{
					cout << "Invalid input. ";
					goto delete_tree_back2;
				}
			}
		}
	}
	else
	{
	back:

		char choice2;
		cout << "Invalid input, try again? Enter 'Y' or 'N': ";
		cin >> choice2;

		if (tolower(choice2) == 'y')
			goto start;
		else if (tolower(choice2) == 'n')
			goto end;
		else
			goto back;
	}

end:

	cout << "Terminating Binary Tree program..." << '\n';

	return 0;
}
