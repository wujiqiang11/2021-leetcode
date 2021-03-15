#include<stack>
#include<iostream>
using namespace std;
class treeNode
{
public:
	treeNode(int n);
	treeNode* left;
	treeNode* right;
	int val;	
};

treeNode::treeNode(int n)
{
	val = n;
	left = nullptr;
	right = nullptr;
}

treeNode* buildTree()
{
	treeNode* treeNodeList[7];
	for (int i = 1; i <= 7; i++)
	{
		treeNodeList[i - 1] = new treeNode(i);
	}
	for (int i = 0; i < 3; i++)
	{
		treeNodeList[i]->left = treeNodeList[(i + 1) * 2 - 1];
		treeNodeList[i]->right = treeNodeList[(i + 1) * 2];
	}
	return treeNodeList[0];
}

treeNode* buildTree1()
{
	treeNode* treeNodeList[3];
	for (int i = 1; i <= 3; i++)
	{
		treeNodeList[i - 1] = new treeNode(i);
	}
	for (int i = 0; i < 2; i++)
	{
		treeNodeList[i]->right = treeNodeList[i+1];
	}
	return treeNodeList[0];
}

void pre_oder_tra(treeNode* node)  //前序遍历
{
	if (node == NULL)
		return;
	stack<treeNode*> node_stack;
	while (1)
	{
		while (node)
		{
			cout << node->val << " ";
			node_stack.push(node);
			node = node->left;
		}
		while (node == nullptr)
		{
			if (node_stack.empty())
			{
				cout << endl;
				return;
			}
			node = node_stack.top();
			node_stack.pop();
			node = node->right;
		}
	}
}
void mid_oder_tra(treeNode* node)  //中序遍历
{
	if (node == NULL)
		return;
	stack<treeNode*> node_stack;
	while (1)
	{
		while (node)
		{
			//cout << node->val << " ";
			node_stack.push(node);
			node = node->left;
		}
		while (node == nullptr)
		{
			if (node_stack.empty())
			{
				cout << endl;
				return;
			}
			node = node_stack.top();
			node_stack.pop();
			cout << node->val << " ";
			node = node->right;
		}
	}
}
void post_oder_tra(treeNode* node)  //后序遍历
{
	if (node == NULL)
		return;
	stack<treeNode*> node_stack;
	treeNode* lastnode=nullptr;
	while (1)
	{
		while (node)
		{
			//cout << node->val << " ";
			node_stack.push(node);
			node = node->left;
		}
		while (node == nullptr)
		{
			if (node_stack.empty())
			{
				cout << endl;
				return;
			}
			node = node_stack.top();
			
			if (lastnode == node->right || node->right == NULL)
			{
				cout << node->val << " ";
				lastnode = node;
				node_stack.pop();
				node = nullptr;
				continue;
			}
			node = node->right;
		}
	}
}


/*

int main()
{
	treeNode* head = buildTree();
	pre_oder_tra(head);
	mid_oder_tra(head);
	post_oder_tra(head);
	return 0;
}
*/