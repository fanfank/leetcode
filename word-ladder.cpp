class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start.size()!=end.size() || dict.empty())
            return 0;
        //dict.insert(end);
        queue<string> q[2];
        int cur = 0;
        q[cur].push(start);
        int length = 0;
        bool find = false;
        while(!q[cur].empty())
        {
            while(!q[cur].empty())
            {
                string s = q[cur].front();
                q[cur].pop();
                int ssize = s.size();
                for(int i = 0; i < ssize && !find; i++)
                {
                    string tmp = s;
                    for(int j = 'a'; j <= 'z'; j++)
                    {
                        tmp[i] = j;
                        if(tmp == s)
                        {
                            dict.erase(s);
                            continue;
                        }
                        if(tmp == end && length != 0)
                        {
                            find = true;
                            break;
                        }
                        if(dict.find(tmp) != dict.end())
                        {
                            if(tmp == end)
                            {
                                find = true;
                                break;
                            }
                            q[cur^1].push(tmp);
                            dict.erase(tmp);
                        }
                    }
                }
                if(find)
                    return length+2;
            }
            cur ^= 1;
            length++;
        }
        return 0;
    }
};

