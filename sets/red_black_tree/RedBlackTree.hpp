#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

template <typename T>
class RedBlackTree {
        struct node{
                T data;
                bool red;
                union {
                        node *link[2];
                        struct {
                                node *left;
                                node *right;
                        };
                };
                node(T data): data(data), red(true), link() {}
                ~node() {
                        if(left)
                                delete left;
                        if(right)
                                delete right;
                }
                node *rotate(int dir) {
                        node *n = link[!dir];
                        link[!dir] = n->link[dir];
                        n->link[dir] = this;
                        red = true;
                        n->red = false;
                        return n;
                }
                node *doubleRotate(int dir) {
                        link[!dir] = link[!dir]->rotate(!dir);
                        return rotate(dir);
                }
                void dump(std::ostream &os) {
                        os << data << " (red  " << red << ")" << std::endl;
                        if(left)
                                left->dump(os);
                        if(right)
                                right->dump(os);
                }
        };
        node *root;
        bool is_red(node *n) {
                return n? n->red : false;
        }
        node *insert(node *n, T data) {
                if(!n)
                        return new node(data);
                if(data == n->data)
                        return n;
                int dir = n->data < data;
                n->link[dir] = insert(n->link[dir], data);
                /* XXX rebalance */
                return n;
        }
public:
        void add(T data) {
                root = insert(root, data);
                root->red = false;
        }
        bool contains(T data) {
                node *n = root;
                while(n) {
                        if(n->data == data)
                                return true;
                        n = n->link[n->data < data];
                }
                return false;
        }
        void dump(std::ostream &os) {
                if(root)
                        root->dump(os);
        }
};

#endif