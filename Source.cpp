#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "Stack.h"
#include <time.h>
#include <math.h>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

static int level;
static int node;

TreeNode* createTree(int num);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
void treeTraversal(TreeNode* root, char choice);

// void inordernonrecursive(TreeNode* root);

// TreeNode *nodeholder;

void addLeftNode(TreeNode *root, int data)
{
	node++;
	double x = pow(2, level);
	if (node == (int)x)
		level++;
	TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	root->left = newnode;
//	nodeholder = newnode;
}

void addRightNode(TreeNode *root, int data)
{
	node++;
	double x = pow(2, level);
	if (node == (int)x)
		level++;
	TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	root->right = newnode;
//	nodeholder = newnode;
}

/*
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
// Base case for recursion
if (i < n)
{

TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
temp->data = arr[i];
temp->left = NULL;
temp->right = NULL;
root = temp;
// insert left child
root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
//arr = 1,2,3,4,5 ... 10
//      0,1,2,3,4,5,
// insert right child
root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
}
return root;
}
*/

int main()
{
	int num;
	printf("Enter number of nodes : ");
	scanf("%d", &num);
	TreeNode *root = createTree(num);
	TreeNode* temp = root;

	printf("Inorder : \n");
	treeTraversal(temp, 'i');
	printf("\n");
	temp = root;
	printf("\nPreorder : \n");
	treeTraversal(temp, 'p');
	printf("\n");

	temp = root;
	printf("\nPostorder : \n");
	treeTraversal(temp, 't');

	_getch();
}

TreeNode* createTree(int num)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(struct TreeNode));
	node++;
	level++;
//	nodeholder = root;

	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10
	//	root = insertLevelOrder(arr, root, 0, num);

	//	srand(time(0));
	root->data = rand() % 2;

	for (int i = 2; i <= num; i++)
	{

		int value = rand() % 2;
		if (value == 0)
			addLeftNode(root, i);
	//		addLeftNode(nodeholder, i);
		else
			addRightNode(root, i);
	//		addRightNode(nodeholder, i);
	}

	return root;
}

void treeTraversal(TreeNode* root, char choice)
{
	switch (choice)
	{
	case 'i':
		inorder(root);
		break;
	case 'p':
		preorder(root);
		break;
	case 't':
		postorder(root);
		break;
	default:
		printf("\nWrong choice \n");
	}
}

void inorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d \t", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d \t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{

		postorder(root->left);
		postorder(root->right);
		printf("%d \t", root->data);
	}
}

/*
void inordernonrecursive(TreeNode* root, int numberofnode)
{
Stack *stk = createStack(numberofnode);

}*/