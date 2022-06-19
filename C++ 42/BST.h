#pragma once

template<class T = Country>
class BST
{
	struct Node
	{
		T key;
		Node* left, * right;

		Node(T key) : key(key), left(), right() {}
	};

	Node* root = NULL;

	Node* insertRec(Node* tree, T key)
	{
		if (tree == NULL)
		{
			tree = new Node(key); 
			return tree;
		}

		if (key < tree->key)
			tree->left = insertRec(tree->left, key);
		else if (key > tree->key)
			tree->right = insertRec(tree->right, key);

		return tree;
	}
	// Traversal
	// 1) inOrder	LNR RNL
	// 2) preOrder	NLR NRL
	// 3) postOrder LRN RLN

	void inOrderRec(Node* tree)
	{
		if (tree != NULL)
		{
			inOrderRec(tree->left);
			cout << tree->key << endl;
			inOrderRec(tree->right);
		}
	}

	Node* searchRec(Node* tree, T key)
	{
		if (tree == NULL)
			return NULL;
		else if (key == tree->key)
			return tree;
		else if (key > tree->key)
			return searchRec(tree->right, key);

		return searchRec(tree->left, key);
	}

	T minValue(Node* tree)
	{
		T min = tree->key;

		while (tree->left != NULL)
		{
			min = tree->left->key;
			tree = tree->left;
		}

		return min;
	}

	T maxValue(Node* tree)
	{
		T max = tree->key;

		while (tree->right != NULL)
		{
			max = tree->right->key;
			tree = tree->right;
		}

		return max;
	}

	Node* deleteRec(Node* tree, T key)
	{
		if (tree == NULL)
			return NULL;

		if (key < tree->key)
			tree->left = deleteRec(tree->left, key);
		else if (key > tree->key)
			tree->right = deleteRec(tree->right, key);
		else
		{
			if (tree->left == NULL)
				return tree->right;
			else if (tree->right == NULL)
				return tree->left;

			tree->key = minValue(tree->right);

			tree->right = deleteRec(tree->right, tree->key);
		}

		return tree;
	}


public:
	BST() = default;


	void insert(T key)
	{
		root = insertRec(root, key);
	}

	void inOrder()
	{
		inOrderRec(root);
	}

	Node* search(T key)
	{
		return searchRec(root, key);
	}

	int minValue()
	{
		minValue(root);
	}
	int maxValue()
	{
		maxValue(root);
	}

	void deleteKey(T key)
	{
		root = deleteRec(root, key);
	}


	Node* getRoot()
	{
		return root;
	}


	//Node* equality(Node* tree, Node* other)
	//{
	//	if (tree == NULL)
	//		return NULL;
	//	else
	//	{
	//		if (tree->left == NULL)
	//			equality(root->right, tree->right);
	//		else if (tree->right == NULL)
	//			equality(root->right, tree->right);
	//		else
	//			return NULL;

	//		other = tree;
	//		other->left = tree->left;
	//		other->right = tree->right;
	//		equality(root->left, other->left);
	//	}
	//}



	//BST<T> operator=(BST<T> other)
	//{
	//	equality(root, other.root);
	//	return other;
	//}

};

