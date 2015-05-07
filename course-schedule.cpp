//Solution 1: Topological sort, Use relations between in-degree and out-degree, 
//            you can only learn courses whose in-degree are 
//            0 (meaning that  all prerequisites finished)
//time:  O(n+e), where n = numCourses, v = prerequisites.size()
//space: O(n) <- O(3n)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> in_degree(numCourses, 0);
        vector<vector<int> > out_node(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); ++i) {
            ++in_degree[prerequisites[i][0]];
            out_node[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> zero_in_degree_node;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                zero_in_degree_node.push(i);
            }
        }

        int fin_course_num = 0;
        while (!zero_in_degree_node.empty()) {
            int todo_course_num = zero_in_degree_node.size();
            while (todo_course_num--) {
                int course_index = zero_in_degree_node.front();
                zero_in_degree_node.pop();
                ++fin_course_num;

                for (int i = 0; i < out_node[course_index].size(); ++i) {
                    if (--in_degree[out_node[course_index][i]] == 0) {
                        zero_in_degree_node.push(out_node[course_index][i]);
                    }
                }
            }
        }

        return fin_course_num == numCourses;
    }
};
