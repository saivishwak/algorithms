#include <iostream>
#include <vector>
#include <algorithm>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

// Min-Heap is a complete binary tree where
// each node value is less than its children
class Tree{
    public:
        Node* root;
        int num_nodes;

        Tree(int val){
            this->root = new Node(val);
            this->num_nodes = 1;
        }

        void insert(int val){
            std::vector<Node*> arr;
            arr.push_back(this->root);
            int index = 0;
            Node* insert = NULL;

            while (index != this->num_nodes){
                Node* top = arr[index];
                if (top->left == NULL){
                    top->left = new Node(val);
                    this->num_nodes += 1;
                    insert = top->left;
                    break;
                }
                else {
                    arr.push_back(top->left);
                }
                if (top->right == NULL) {
                    top->right = new Node(val);
                    this->num_nodes += 1;
                    insert  = top->right;

                    break;
                }
                else {
                    arr.push_back(top->right);
                }
                index++;
            }
            // Do swapping
           int temp_insert = insert->data;
            while (index >= 0){
                Node* temp_i = insert;
                Node* parent = arr[index];
                if (insert == NULL){
                    return;
                }
                if (parent->data > temp_i->data) {
                    int temp = parent->data;
                    temp_i = parent;
                    parent->data = temp_insert;
                    insert->data = temp;
                    insert = temp_i;
                }
                if (index != 0 && index - 2 < 0) {
                    index = 0;
                }
                else {
                    index -= 2;
                }
            }
            return;
        }

        int get_min(){
            if (root == NULL){
                return -99999;
            }
            return root->data;
        }

        void in_order_print(Node* root){
            if (root == NULL) {
                return;
            }
            in_order_print(root->left);
            std::cout << root->data << " - ";
            in_order_print(root->right);
        }
};


int main(){
    Tree tree = Tree(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.in_order_print(tree.root);
    std::cout << std::endl;
    std::cout << tree.get_min() << std::endl;
    return 0;
}
