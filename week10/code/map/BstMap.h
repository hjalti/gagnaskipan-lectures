#ifndef BSTMAP_H
#define BSTMAP_H

#include <iostream>

#include "Map.h"
#include "Stack.h"

using namespace std;

template<class K, class V>
class BstMap : public Map<K,V>
{

    private:
		struct TreeNode
		{
			TreeNode(K key, V value, TreeNode* left = NULL, TreeNode* right = NULL);
			bool is_leaf();

			K key;
			V value;
			TreeNode *left;
			TreeNode *right;
		};

		typedef BstMap<K,V>::TreeNode* NodePtr;

        NodePtr root;

        void free_memory(NodePtr node);
        int size(NodePtr node) const;
        void add(NodePtr& node, K key, V value);
        bool contains(NodePtr node, K key) const;
        V& get(NodePtr node, K key) const;
        void remove(NodePtr& node, K key);
        void remove_root(NodePtr& node);
        NodePtr remove_min(NodePtr& node);

		class BstIterator : public Map<K,V>::Iterator
		{
			public:
				BstIterator(BstMap<K,V>& map);
				virtual ~BstIterator() { }

				virtual bool has_next();
				virtual Pair<K,V> next();

			private:
				Stack<NodePtr> stack;
		};

    public:
        // Creates an empty map.
        BstMap ();
        virtual ~BstMap();
        virtual int size() const;
        virtual bool empty() const;
        virtual void add(K key, V value);
        virtual bool contains(K key) const;
        virtual V& get(K key) const;
        virtual void remove(K key);
		virtual V& operator[] (const K& key);
		virtual typename Map<K,V>::Iterator* get_iterator();

		template<class A, class B>
        friend ostream& operator <<(ostream& out, const BstMap<A,B>& map);
};


template<class K, class V>
BstMap<K,V>::TreeNode::TreeNode(K key, V value, TreeNode* left, TreeNode* right)
{
	this->key = key;
	this->value = value;
	this->left = NULL;
	this->right = NULL;
}

template<class K, class V>
bool BstMap<K,V>::TreeNode::is_leaf()
{
	return (left == NULL && right == NULL);
}

template<class K, class V>
BstMap<K,V>::BstMap()
{
	root = NULL;
}

template<class K, class V>
BstMap<K,V>::~BstMap()
{
	free_memory(root);
}

template<class K, class V>
int BstMap<K,V>::size() const
{
	return size(root);
}

template<class K, class V>
bool BstMap<K,V>::empty() const
{
	return root == NULL;
}

template<class K, class V>
void BstMap<K,V>::add(K key, V value)
{
	add(root, key, value);
}

template<class K, class V>
void BstMap<K,V>::remove(K key)
{
	remove(root, key);
}

template<class K, class V>
bool BstMap<K,V>::contains(K key) const
{
	return contains(root, key);
}

template<class K, class V>
V& BstMap<K,V>::get(K key) const
{
	return get(root, key);
}

template<class K, class V>
int BstMap<K,V>::size(NodePtr node) const
{
	if(node == NULL) {
		return 0;
	}
	return 1 + size(node->left) + size(node->right);
}

template<class K, class V>
void BstMap<K,V>::free_memory(NodePtr node)
{
	if(node == NULL) {
		return;
	}
	free_memory(node->left);
	free_memory(node->right);
	delete node;
}

template<class K, class V>
void BstMap<K,V>::add(NodePtr& node, K key, V value)
{
	if(node == NULL) {
		node = new BstMap<K,V>::TreeNode(key, value);
	}
	else if(node->key == key) {
		node->value = value;
	}
	else if(key < node->key) {
		add(node->left, key, value);
	}
	else {
		add(node->right, key, value);
	}
}

template<class K, class V>
bool BstMap<K,V>::contains(NodePtr node, K key) const
{
	if(node == NULL) {
		return false;
	}
	if(node->key == key) {
		return true;
	}
	if(key < node->key) {
		return contains(node->left, key);
	}
	return contains(node->right, key);

}

template<class K, class V>
void BstMap<K,V>::remove(NodePtr& node, K key)
{
	if(node == NULL) {
		return;
	} else if(node->key == key) {
		remove_root(node);
	} else if(key < node->key) {
		remove(node->left, key);
	} else {
		remove(node->right, key);
	}
}

template<class K, class V>
void BstMap<K,V>::remove_root(NodePtr& root)
{
	NodePtr succ;
	if(root->is_leaf()) {
		delete root;
		root = NULL;
	} else if(root->left == NULL) {
		succ = root->right;
		delete root;
		root = succ;
	} else if(root->right == NULL) {
		succ = root->left;
		delete root;
		root = succ;
	} else {
		NodePtr new_root = remove_min(root->right);
		new_root->left = root->left;
		new_root->right = root->right;
		delete root;
		root = new_root;
	}
}

template<class K, class V>
typename BstMap<K,V>::TreeNode* BstMap<K,V>::remove_min(NodePtr& node)
{
	if(node->left == NULL) {
		NodePtr old_node = node;
		node = node->right;
		return old_node;
	} else {
		return remove_min(node->left);
	}
}

template<class K, class V>
V& BstMap<K,V>::get(NodePtr node, K key) const
{
	if(node == NULL) {
		throw KeyException();
	}
	if(node->key == key) {
		return node->value;
	}
	if(key < node->key) {
		return get(node->left, key);
	}
	return get(node->right, key);
}

template<class K, class V>
V& BstMap<K,V>::operator[] (const K& key)
{
	if(!contains(key)) {
		add(key, V());
	}
	return get(key);
}

template<class K, class V>
typename Map<K,V>::Iterator* BstMap<K,V>::get_iterator()
{
	return new BstIterator(*this);
}

template<class K, class V>
BstMap<K,V>::BstIterator::BstIterator(BstMap<K,V>& map)
{
	NodePtr curr = map.root;

	if(curr != NULL) {
		stack.push(curr);

		while(curr->left != NULL) {
			stack.push(curr->left);
			curr = curr->left;
		}
	}
}

template<class K, class V>
bool BstMap<K,V>::BstIterator::has_next()
{
	return !stack.empty();
}

template<class K, class V>
Pair<K,V> BstMap<K,V>::BstIterator::next()
{
	if(!has_next()) {
		throw NoMoreElementsException();
	}

	NodePtr res = stack.pop();

	NodePtr curr = res;
	if(curr->right != NULL) {
		stack.push(curr->right);
		curr = curr->right;
		while(curr->left != NULL) {
			stack.push(curr->left);
			curr = curr->left;
		}
	}
	return Pair<K,V>(res->key, res->value);
}

template<class K, class V>
ostream& operator <<(ostream& out, const BstMap<K,V>& map)
{
	return out;
}

#endif
