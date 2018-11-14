#ifndef AVLTREE_HPP
#define AVLTREE_HPP

template <typename T>
class AVLTree {
        struct node {
                T data;
                node *left;
                node *right;
                unsigned height;
                node(T data): data(data), left(NULL), right(NULL), height(1) {}
                ~node() {
                        if(left)
                                delete left;
                        if(right)
                                delete right;
                }
                void dump(std::ostream &os) {
                        os << data << std::endl;
                        if(left)
                                left->dump(os);
                        if(right)
                                right->dump(os);
                }
        };
        node *root;
        
        static unsigned height(node *n) {
                return n? n->height : 0;
        }
        static int balance(node *n) {
                return n? height(n->left) - height(n->right) : 0;
        }
        static node *rightRotate(node *y) {
                node *x = y->left;
                node *T2 = x->right;
                x->right = y;
                y->left = T2;
                y->height = std::max(height(y->left), height(y->right)) + 1;
                x->height = std::max(height(x->left), height(x->right)) + 1;
                return x;
        }
        static node *leftRotate(node *x) {
                node *y = x->right;
                node *T2 = y->left;
                y->left = x;
                x->right = T2;
                x->height = std::max(height(x->left), height(x->right)) + 1;
                y->height = std::max(height(y->left), height(y->right)) + 1;
                return y;
        }
        static node *insert(node *n, T data) {
                if(!n)
                        return new node(data);
                if(data < n->data)
                        n->left = insert(n->left, data);
                else if(data > n->data)
                        n->right = insert(n->right, data);
                else
                        return n;
                n->height = std::max(height(n->left), height(n->right)) + 1;
                int b = balance(n);

                if(b > 1 && data < n->data)
                        return rightRotate(n);
                if(b < -1 && data > n->data)
                        return leftRotate(n);
                if(b > 1 && data > n->data) {
                        n->left = leftRotate(n);
                        return rightRotate(n);
                }
                if(b < -1 && data < n->data) {
                        n->right = rightRotate(n);
                        return leftRotate(n);
                }
                return n;

        }
public:
        AVLTree(): root(NULL) {}
        ~AVLTree() {
                if(root)
                        delete root;
        }
        void add(T data) { root = insert(root, data); }
        bool contains(T data) {
                node *n = root;
                while(n) {
                        if(n->data == data)
                                return true;
                        else if(n->data < data)
                                n = n->right;
                        else
                                n = n->left;
                }
                return false;
        }
        void dump(std::ostream &os) {
                if(root)
                        root->dump(os);
        }
};

#endif