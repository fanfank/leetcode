class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
		if(start.size() != end.size() || dict.empty())
			return ans;

        dict.erase(start);
		unordered_map<string, vector<string> > m;
		bool f = true, found = false;
		int cur = 0;
		vector<string> q[2];
		q[cur].push_back(start);
        int depth = 1;
		while(!q[cur].empty())
		{
            depth++;
			while(!q[cur].empty())
			{
				string s = q[cur].back();
				q[cur].pop_back();
                //dict.erase(s);
				int ssize = s.size();
				for(int i = 0; i < ssize; i++)
				{
					string stmp = s;
					for(char j = 'a'; j <= 'z'; j++)
					{
						if(j == s[i])
							continue;
						stmp[i] = j;
						if(dict.find(stmp) != dict.end())
						{
							if(stmp == end)
							{
                                found = true;
								m[end].push_back(s);
								break;
							}
							else if(found)
								continue;
							else
							{
								if(m.find(stmp) == m.end())
									q[cur^1].push_back(stmp);
								m[stmp].push_back(s);
							}
						}
					}
				}
			}
			if(found)
			{
				vector<string> trace;
                trace.clear();
				dfs(start, end, m, trace, depth);
				return ans;
			}
			cur ^= 1;
            for(int i = q[cur].size() - 1; i >= 0; i--)
                dict.erase(q[cur][i]);
			if(f){f = false; dict.insert(end);}
		}
		return ans;
	}
private:
	vector<vector<string> > ans; 
	void dfs(string &start, string cur, unordered_map<string, vector<string> > &m, vector<string> &trace, int depth)
	{
		if(cur == start)
		{
            vector<string> vv;
            vv.push_back(cur);
            for(int i = trace.size() - 1; i >= 0; i--)
                vv.push_back(trace[i]);
			ans.push_back(vv);
			return;
		}
        if(depth == 1)
            return;
        
        trace.push_back(cur);
		unordered_map<string, vector<string> >::iterator p = m.find(cur);
		for(int i = p->second.size() - 1; i >= 0; i--)
		{
			dfs(start, p->second[i], m, trace, depth - 1);
		}
		trace.pop_back();
	}
};

