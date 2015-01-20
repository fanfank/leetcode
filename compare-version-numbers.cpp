class Solution { //3ms solution. O(1) space, O(n) time complexity
public:
    int compareVersion(string version1, string version2) {
        int v1_index = 0;
        int v2_index = 0;
        int res      = 0;
        while (res == 0 && (v1_index < version1.size() || v2_index < version2.size())) {
            //judge if has preceeding 0s
            while (v1_index < version1.size() && version1[v1_index] == '0') {
                ++v1_index;
            }
            while (v2_index < version2.size() && version2[v2_index] == '0') {
                ++v2_index;
            }

            int current_res = 0;
            while (v1_index < version1.size() && version1[v1_index] != '.'
                    && v2_index < version2.size() && version2[v2_index] != '.') {
                if (version1[v1_index] > version2[v2_index]) {
                    current_res = 1;
                } else if (version2[v2_index] > version1[v1_index]){
                    current_res = -1;
                }
                ++v1_index, ++v2_index;
            }

            while (v1_index < version1.size() && version1[v1_index++] != '.') {
                current_res = 1;
            }
            while (v2_index < version2.size() && version2[v2_index++] != '.') {
                current_res = -1;
            }

            res = current_res;
        }
        
        return res;
    }
};
