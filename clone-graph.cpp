/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode UG;
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        
        map<UG*, UG*> m;
        queue<UG*> q;
        UG *newNode = new UG(node->label);
        q.push(node);
        m[node] = newNode;
        
        while(!q.empty()) {
            UG *original = q.front(), *current = m[original];
            q.pop();
            for(vector<UG*>::iterator neighbor = original->neighbors.begin(); neighbor != original->neighbors.end(); ++neighbor) {
                map<UG*, UG*>::iterator p = m.find(*neighbor);
                if(p == m.end()) {
                    UG *tmp = new UG((*neighbor)->label);
                    m[*neighbor] = tmp;
                    q.push(*neighbor);
                    current->neighbors.push_back(tmp);
                } else {
                    current->neighbors.push_back(p->second);
                }
            }
        }
        return newNode;
    }
};