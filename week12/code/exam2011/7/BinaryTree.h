template <class T>
class BinaryNode
{
	public:
		BinaryNode() {};
		BinaryNode(const T& nodeItem, BinaryNode *left=NULL, BinaryNode
				*right=NULL) :
			item(nodeItem), leftChild(left), rightChild(right) {}
		~BinaryNode() {};
		bool isLeaf() const {return (leftChild==NULL && rightChild==NULL);};
		T item;
		// The item
		BinaryNode<T> *leftChild; // The left child
		BinaryNode<T> *rightChild; // The right child
};

template <class T>
class BinaryTree
{
	public:
		BinaryTree() : root(NULL) {};
		BinaryTree(const T& rootItem) {root = new BinaryNode<T>(rootItem);};
		~BinaryTree() {delete root;};
		BinaryNode<T>* getRoot() const {return root;};
		bool isEmpty() const {return (root==NULL);};
		void attachLeft(const T& anItem); // Creates a left node with anItem as the root
		void attachRight(const T& anItem);// Creates a right node with anItem as the root
		void attachLeftTree(BinaryTree<T>* tree); // Attaches a left tree to the root
		void attachRightTree(BinaryTree<T>* tree);//Attaches a right tree to the root
		void flip(BinaryNode<T>* node); // After this operation the tree below this node is a mirror image of its original value
	private:
			BinaryNode<T> *root;
};
