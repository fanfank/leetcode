class Solution { 
public: 
    vector<int> findOrder(int numCourses, 
            vector<pair<int, int> >& prerequisites) { 
        
        vector<int> order;
        vector<int> in_edge_num(numCourses, 0);
        vector<vector<int> > out_edge_list(numCourses, vector<int>());

        for (size_t i = 0; i < prerequisites.size(); ++i) {
            ++in_edge_num[prerequisites[i].first];
            out_edge_list[prerequisites[i].second].push_back(
                    prerequisites[i].first);
        }

        queue<int> seq;
        for (size_t i = 0; i < in_edge_num.size(); ++i) {
            if (in_edge_num[i] == 0) {
                seq.push(i);
                order.push_back(i);
            }
        }

        while (!seq.empty()) {
            if (order.size() == numCourses) {
                break;
            }

            int course = seq.front();
            seq.pop();
            for (size_t i = 0; i < out_edge_list[course].size(); ++i) {
                int out_node = out_edge_list[course][i];
                if (--in_edge_num[out_node] == 0) {
                    seq.push(out_node);
                    order.push_back(out_node);
                }
            }
        }
        
        if (order.size() == numCourses) {
            return order;
        } else {
            return vector<int>();
        }
    } 
};
