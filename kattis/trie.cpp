#include <bits/stdc++.h>
using namespace std;


struct Trie{
    struct Node{
        unordered_map<char, Node> children;
        bool isword;
    };

    Node* root;

    explicit Trie(){ root = new Node; }

    Trie(string& word){
        root = new Node;
        Node* curr = root;
        for(char c : word){
            
        }
    }

    void add(string& word){

    }

    Node* find(string& target){
        
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    Trie trie;
    
}