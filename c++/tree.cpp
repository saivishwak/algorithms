#include <iostream>
#include <vector>
#include <list>

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        };

};

// Will be a complete binary tree
class Tree {
    public:
        Node* root;
        int num_nodes;

        Tree(int val) {
            root = new Node(val);
            num_nodes = 1;
        };

        //Insert into a complete binary tree
        void insert(int val){
            Node* curr = this->root;
            std::vector<Node*> arr;
            arr.push_back(root);
            int index = 0;
            while (index != this->num_nodes) {
                Node* top = arr[index];
                if (top->left == NULL) {
                    top->left = new Node(val);
                    this->num_nodes += 1;
                    return;
                }
                else {
                    arr.push_back(top->left);
                }
                if (top->right == NULL){
                    top->right = new Node(val);
                    this->num_nodes += 1;
                    return;
                }
                else {
                    arr.push_back(top->right);
                }
                index++;
            }
            return;
        };

        void in_order_print(Node* root){
            if (root == NULL) {
                return;
            };
            in_order_print(root->left);
            std::cout << root->data << " - ";
            in_order_print(root->right);
        };

        void pre_order_print(Node* root){
            if (root == NULL) {
                return;
            }
            std::cout << root->data << " - ";
            pre_order_print(root->left);
            pre_order_print(root->right);
        }

        void post_order_print(Node* root){
            if (root == NULL) {
                return;
            }
            post_order_print(root->left);
            post_order_print(root->right);
            std::cout << root->data << " - ";
        }
};

int main(){ 

    Tree* tree = new Tree(0);
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->in_order_print(tree->root);
    std::cout << std::endl;
    tree->pre_order_print(tree->root);
    std::cout << std::endl;
    tree->post_order_print(tree->root);
    std::cout << std::endl;

    return 0;
}
