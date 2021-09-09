class Solution {
public:
    
    void dfs(vector<Node*> &vis, Node* node, Node* copy)
    {
        vis[copy->val] = copy;
        for(auto x : node->neighbors)
        {
//             if not visited then explore nodes of its neighbors
            if(vis[x->val] == NULL)
            {
                Node* newnode = new Node(x->val);
                (copy->neighbors).push_back(newnode);
                dfs(vis, x, newnode);
            }
//             if visited then push the value in its adjacency list
            else
            {
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector<Node*> vis(1001, NULL);
        Node* copy = new Node(node->val);
        dfs(vis, node, copy);
        return copy;
    }
};
