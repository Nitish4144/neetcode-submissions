/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // NOde* clone()
    unordered_map<Node*,Node*> mp;
    Solution(){
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        // unordered_map<Node*,Node*>& cp = this->mp;
        if(this->mp.find(node) !=  this->mp.end()){
            return this->mp[node];
        }
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for(auto& nei:node->neighbors){
            copy->neighbors.push_back(cloneGraph(nei));
        } 
        return copy;

        
    }
};
