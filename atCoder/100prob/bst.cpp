#include <iostream>
#include <random>
using namespace std;

class BST{
    struct Node{
        Node* left = nullptr;
        Node* right = nullptr;
        int val;

        Node(int n) : val(n) {}
    };
    Node* root;

public:
    void insert(int target) {
        if(root == nullptr){
            root = new Node(target);
            return;
        }
        insert(root, target);
    }

    void contains(int target){
        contains(root, target);
    }

    void print(){
        print(root);
    }

private:
    void insert(Node* curr, int val){
        if(curr == nullptr) return;
        if(val <= curr->val){
            if(curr->left == nullptr) {
                curr->left = new Node(val);
            } else {
                insert(curr->left, val);
            }
        } else {
            if(curr->right == nullptr){
                curr->right = new Node(val);
            } else {
                insert(curr->right, val);
            }
        }
    }

    bool contains(Node* curr, int target){
        if(curr == nullptr) return false;
        if(target == curr->val) return true;
        if(target < curr->val){
            return contains(curr->left, target);
        } else {
            return contains(curr->right, target);
        }
    }

    bool isValidBST(Node* root) {
        if(root == nullptr) return true;
        std::vector<int> v;
        inOrder(root, v);
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] >= v[i + 1]) return false;
        }
        return true;
    }
    
    void inOrder(Node* curr, std::vector<int>& v){
        if(curr == nullptr) return;
        inOrder(curr->left, v);
        v.push_back(curr->val);
        inOrder(curr->right, v);
    }

    void print(Node* curr){
        if(curr == nullptr) return;
        print(curr->left);
        std::cout << curr->val << ' ';
        print(curr->right);
    }
};


int main(){
    // demo
    BST bst;
    for(int i = 0; i < 5; i++){
        int newNum = std::rand() % 10;
        bst.insert(newNum);
    }
    bst.print();
}