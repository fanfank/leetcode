class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> instack;
        vector<int> lpleft;
        vector<string> res;
        res.push_back(""); instack.push_back(0); lpleft.push_back(n);
        for(int i = 1; i <= 2 * n; i++)
        {
            int sz = res.size();
            bool canadd;
            for(int j = 0; j < sz; j++)
            {
                if(lpleft[j]>0 && instack[j]>0)
                    canadd = true;
                else
                    canadd = false;
                if(lpleft[j] > 0)
                {
                    if(canadd)
                    {
                        res.push_back(res[j]+"(");
                        instack.push_back(instack[j]+1);
                        lpleft.push_back(lpleft[j]-1);
                    }
                    else
                    {
                        res[j] += "(";
                        instack[j]++;
                        lpleft[j]--;
                        continue;
                    }
                }
                if(instack[j]>0)
                {
                    res[j] += ")";
                    instack[j]--;
                }
            }
        }
        return res;
    }
};
