#include <iostream>
#include <queue>

using namespace std;

// This approach counts the number of nodes from root to the
// leaf to calculate the height of the tree.

// Defining the structure of a Node.

class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

// Helper function to create a newnode.
// Input: Data for the newnode.
// Return: Address of the newly created node.

Node *createNode(int data)
{

	Node *newnode = new Node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

// Function to calculate the height of given Binary Tree.
// Input: Address of the root node of Binary Tree.
// Return: Height of Binary Tree as a integer. This includes
// the number of nodes from root to the leaf.

int calculateHeight(Node *root)
{
	queue<Node *> nodesInLevel;
	int height = 0;
	int nodeCount = 0; // Calculate number of nodes in a level.
	Node *currentNode; // Pointer to store the address of a
										 // node in the current level.
	if (root == NULL)
	{
		return 0;
	}
	nodesInLevel.push(root);
	while (!nodesInLevel.empty())
	{
		// This while loop runs for every level and
		// increases the height by 1 in each iteration. If
		// the queue is empty then it implies that the last
		// level of tree has been parsed.
		height++;
		// Create another while loop which will insert all
		// the child nodes of the current level in the
		// queue.

		nodeCount = nodesInLevel.size();
		while (nodeCount--)
		{
			currentNode = nodesInLevel.front();

			// Check if the current nodes has left child and
			// insert it in the queue.

			if (currentNode->left != NULL)
			{
				nodesInLevel.push(currentNode->left);
			}

			// Check if the current nodes has right child
			// and insert it in the queue.
			if (currentNode->right != NULL)
			{
				nodesInLevel.push(currentNode->right);
			}

			// Once the children of the current node are
			// inserted. Delete the current node.

			nodesInLevel.pop();
		}
	}
	return height;
}

Node *InsertNode(Node *root, int data)
{
	// If the tree is empty, assign new node address to root
	if (root == NULL)
	{
		root = createNode(data);
		return root;
	}

	// Else, do level order traversal until we find an empty
	// place, i.e. either left child or right child of some
	// node is pointing to NULL.
	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else
		{
			temp->left = createNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else
		{
			temp->right = createNode(data);
			return root;
		}
	}
}

Node *deletion(Node *root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->data == key)
			return NULL;
		else
			return root;
	}
	Node *key_node = NULL;
	Node *temp;
	Node *last;
	queue<Node *> q;
	q.push(root);
	// Do level order traversal to find deepest
	// node(temp), node to be deleted (key_node)
	// and parent of deepest node(last)
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->data == key)
			key_node = temp;
		if (temp->left)
		{
			last = temp; // storing the parent node
			q.push(temp->left);
		}
		if (temp->right)
		{
			last = temp; // storing the parent node
			q.push(temp->right);
		}
	}
	if (key_node != NULL)
	{
		key_node->data = temp->data; // replacing key_node's data to deepest node's data
		if (last->right == temp)
			last->right = NULL;
		else
			last->left = NULL;
		delete (temp);
	}
	return root;
}

//Searching for a node

static bool flag = false; 

bool searchNode(Node *root, int key){
	if(root==NULL){
		cout<<"Tree is empty";
	}
	else{
		if(root->data == key){
			flag = true;
			return;
		}
	  if(root->left != NULL && flag==false){
			searchNode(root->left,key);
		}
		if(root->right != NULL && flag==false){
			searchNode(root->right,key);
		}
	}
}

// Driver Function.

int main()
{
	// Creating a binary tree.

	Node *root = NULL;

	root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right = createNode(3);

	cout << "The height of the binary tree using iterative "
					"method is: "
			 << calculateHeight(root) << ".";

	return 0;
}
