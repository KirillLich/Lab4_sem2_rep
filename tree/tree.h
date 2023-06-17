#ifndef TREE_H
#define TREE_H

#include "../old_structs/MyStack.h"
#include "../based_structs/sequence_based/ArraySequence.h"

template <typename T>
class tree
{
	typedef struct Node
	{
		T root;
		Node* left, * right;
	} node;

	node Root;

	node* make_empty_node()
	{
		node* out = new node;
		out->left = NULL;
		out->right = NULL;
		return out;
	}

	void KLP(node* N, ArraySequence<T>* out)
	{
		out->Append(N->root);
		if (N->left != NULL)
			KLP(N->left,out);
		if (N->right != NULL)
			KLP(N->right,out);
	}

	void KPL(node* N, ArraySequence<T>* out)
	{
		out->Append(N->root);
		if (N->right != NULL)
			KLP(N->right, out);
		if (N->left != NULL)
			KLP(N->left, out);
	}

	void LKP(node* N, ArraySequence<T>* out)
	{
		if (N->left != NULL)
			LKP(N->left, out);
		out->Append(N->root);
		if (N->right != NULL)
			LKP(N->right, out);
	}

	void LPK(node* N, ArraySequence<T>* out)
	{
		if (N->left != NULL)
			LKP(N->left, out);
		if (N->right != NULL)
			LKP(N->right, out);
		out->Append(N->root);
	}

	void PKL(node* N, ArraySequence<T>* out)
	{
		if (N->right != NULL)
			PKL(N->right, out);
		out->Append(N->root);
		if (N->left != NULL)
			PKL(N->left, out);
	}

	void PLK(node* N, ArraySequence<T>* out)
	{
		if (N->right != NULL)
			PLK(N->right, out);
		if (N->left != NULL)
			PLK(N->left, out);
		out->Append(N->root);
	}

	void insert(T item, node* position)
	{
		if (position->root > item)
		{
			if (position->left == NULL)
			{
				position->left = make_empty_node();
				(position->left->root) = item;
			}
			else
				insert(item, position->left);
		}
		else
		{
			if (position->right == NULL)
			{
				position->right = make_empty_node();
				(position->right->root) = item;
			}
			else
				insert(item, position->right);
		}
	}

	bool search(T item, node* position)
	{
		if (position == NULL)
			return false;
		else
		{
			if (position->root == item)
				return true;
			else
			{
				if (position->root > item)
					return search(item, position->left);
				else
					return search(item, position->right);
			}
		}
	}

	void delete_node(node* n)
	{
		if (n->left != NULL)
		{
			delete_node(n->left);
			n->left = NULL;
		}
		if (n->right != NULL)
		{
			delete_node(n->right);
			n->right = NULL;
		}
		delete n;
	}

	ArraySequence<T>* detour_whithout(T item, node* position, ArraySequence<T>* out);

public: 

	tree(T root_item)
	{
		Root.root = root_item;
		Root.left = NULL;
		Root.right = NULL;
	}

	~tree()
	{
		if (Root.left != NULL)
			delete_node(Root.left);
		if (Root.right != NULL)
			delete_node(Root.right);
	}

	void insert(T item)
	{
		if (Root.root > item)
		{
			if (Root.left == NULL)
			{
				Root.left = make_empty_node();
				(Root.left->root) = item;
			}
			else 
				insert(item, Root.left);
		}
		else 
			if (Root.right == NULL)
			{
				Root.right = make_empty_node();
				(Root.right->root) = item;
			}
			else
				insert(item, Root.right);
	}

	bool search(T item)
	{
		if (Root.root == item) return true;
		else
		{
			if (Root.root > item)
				return search(item, Root.left);
			else
				return search(item, Root.right);
		}
	}

	bool delete_item(T item, tree<T>** res_tree)
	{
		if (!(this->search(item)))
			return false;
		else
		{
			ArraySequence<T>* res_arr = detour_whithout(item, NULL, NULL);
			if (res_arr == NULL)
			{
				res_tree = NULL;
				return true;
			}
			(*res_tree) = new tree(res_arr->GetFirst());
			for (size_t i = 1; i < res_arr->GetLenght(); i++)
			{
				(*res_tree)->insert(res_arr->Get(i));
			}
			return true;
		}
	}

	ArraySequence<T>* KLP()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		out->Append(Root.root);
		if (Root.left != NULL)
			KLP(Root.left, out);
		if (Root.right != NULL)
			KLP(Root.right, out);
		return out;
	}

	ArraySequence<T>* KPL()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		out->Append(Root.root);
		if (Root.right != NULL)
			KPL(Root.right, out);
		if (Root.left != NULL)
			KPL(Root.left, out);
		return out;
	}

	ArraySequence<T>* LKP()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		if (Root.left != NULL)
			LKP(Root.left, out);
		out->Append(Root.root);
		if (Root.right != NULL)
			LKP(Root.right, out);
		return out;
	}
	
	ArraySequence<T>* LPK()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		if (Root.left != NULL)
			LPK(Root.left, out);
		if (Root.right != NULL)
			LPK(Root.right, out);
		out->Append(Root.root);
		return out;
	}

	ArraySequence<T>* PKL()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		if (Root.right != NULL)
			PKL(Root.right, out);
		out->Append(Root.root);
		if (Root.left != NULL)
			PKL(Root.left, out);
		return out;
	}

	ArraySequence<T>* PLK()
	{
		ArraySequence<T>* out = new ArraySequence<T>;
		if (Root.right != NULL)
			PLK(Root.right, out);
		if (Root.left != NULL)
			PLK(Root.left, out);
		out->Append(Root.root);
		return out;
	}

	tree<T>* map(T(*func)(T))
	{
		ArraySequence<T>* kpl_arr = this->KPL();
		tree<T>* out = new tree<T>(func(kpl_arr->GetFirst()));
		for (size_t i = 1; i < kpl_arr->GetLenght(); i++)
		{
			out->insert(func(kpl_arr->Get(i)));
		}
		delete kpl_arr;
		return out;
	}

	tree<T>* merge(tree<T>* first, tree<T>* second)
	{
		ArraySequence<T>* first_arr, * second_arr;
		tree<T>* out = new tree<T>(first_arr->GetFirst());
		for (size_t i = 1; i < first_arr->GetLenght(); i++)
		{
			out->insert(first_arr->Get(i));
		}
		for (size_t i = 0; i < second_arr->GetLenght(); i++)
		{
			out->insert(second_arr->Get(i));
		}

		delete first_arr;
		delete second_arr;
		return out;
	}
};

template <typename T>
ArraySequence<T>* tree<T>::detour_whithout(T item, node* position, ArraySequence<T>* out)
{
	if (position == NULL)
	{
		ArraySequence<T>* out_ = new ArraySequence<T>;
		if(Root.root!=item)
			out_->Append(Root.root);
		if (Root.left != NULL)
			detour_whithout(item, Root.left, out_);
		if (Root.right != NULL)
			detour_whithout(item, Root.right, out_);
		if (Root.left == NULL && Root.right == NULL)
		{
			delete out;
			out = NULL;
		}
		return out_;
	}
	else
	{
		if(position->root!=item) 
			out->Append(position->root);
		if (position->left != NULL)
			KLP(position->left, out);
		if (position->right != NULL)
			KLP(position->right, out);
	}
}
#endif