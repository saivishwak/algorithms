#include <iostream>
#include <vector>

// Adjecency list implementation
class Node{
    public:
        int val;
        std::vector<Node*> children;

        Node(int val){
            this->val = val;
        }
};

class Graph{
    public:
        std::vector<Node*> nodes;

        void print_graph(){
            for (auto x: nodes){
                std::cout << "Node - " << x->val << " -> ";
                for (auto y: x->children){
                    std::cout << " " << y->val << " ,";
                }
                std::cout << std::endl;
            }
        }
};

// Adjecency Matrix implementation
class NodeMat{
    public:
        int val;

        NodeMat(int val){
            this->val = val;
        }
};

class GraphMat{
    public:
        std::vector<std::vector<int>> matrix;
};

/*
 * 1 -> 2 ---
 *      |    ^
 *      |    |
 *      3 -> 4
 *
 *
 */

int main(){
    Graph* g_list = new Graph();
    Node* a_1 = new Node(1);
    Node* a_2 = new Node(2);
    Node* a_3 = new Node(3);
    Node* a_4 = new Node(4);
    Node* a_5 = new Node(5);

    // Connect all Nodes
    a_1->children.push_back(a_2);
    a_2->children.push_back(a_3);
    a_2->children.push_back(a_1);
    a_3->children.push_back(a_4);
    a_4->children.push_back(a_2);

    g_list->nodes.push_back(a_1);
    g_list->nodes.push_back(a_2);
    g_list->nodes.push_back(a_3);
    g_list->nodes.push_back(a_4);

    g_list->print_graph();


    GraphMat* g_mat = new GraphMat(); 

    g_mat->matrix.push_back(std::vector<int> {0, 1, 0, 0});
    g_mat->matrix.push_back(std::vector<int> {1, 0, 1, 0});
    g_mat->matrix.push_back(std::vector<int> {0, 0, 0, 1});
    g_mat->matrix.push_back(std::vector<int> {0, 2, 0, 0});


    return 0;
}
