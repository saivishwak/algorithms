#include <iostream>
#include <vector>

class Node{
    public:
        int val;
        bool visited;
        std::vector<Node*> children;

        Node(int val){
            this->val = val;
        }
};

// Adjeceny List
class Graph{
    public:
        std::vector<Node*> nodes;
        Node* root;

        void dfs(Node* root, bool visited){
            if (root == NULL) return;
            std::cout << " Node - " << root->val;
            root->visited = visited;

            for (Node* x: root->children){
                if (x->visited == !visited){
                    dfs(x, visited);
                }
            }
            std::cout << std::endl;

            return;
        }

        void bfs(Node* root){
            int index = 0;
            std::vector<Node*> queue;
            queue.push_back(root);
            while (index < queue.size()){
                Node* parent = queue[index];
                index++;
                if (parent->visited == false){
                    std::cout << "Node - " << parent->val;
                }
                for (Node* x: parent->children){
                   queue.push_back(x); 
                }
                std::cout << std::endl;
            }
        }

        void make_all_not_visited(Node* root){
            this->dfs(root, false);
        }

};

int main(){
    Graph* g_list = new Graph();

    Node* n_0 = new Node(0);
    Node* n_1 = new Node(1);
    Node* n_2 = new Node(2);
    Node* n_3 = new Node(3);
    Node* n_4 = new Node(4);
    Node* n_5 = new Node(5);


    //Make connections
    n_0->children.push_back(n_5);
    n_0->children.push_back(n_1);
    n_0->children.push_back(n_4);
    n_1->children.push_back(n_3);
    n_1->children.push_back(n_4);
    n_3->children.push_back(n_2);

    g_list->root = n_0;
    std::cout << "DFS" << std::endl;
    g_list->dfs(g_list->root, true);

    std::cout << "Making all nodes as not visited" << std::endl;
    g_list->make_all_not_visited(g_list->root);
    
    std::cout << "BFS" << std::endl;
    g_list->bfs(g_list->root);
    return 0;
}
