class Solution {
public:
    bool isOperator(char c) {
        return c < '0' || c > '9';
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i].size() == 1 && isOperator(tokens[i][0])) {
                int tmp1 = sta.top(); sta.pop();
                int tmp2 = sta.top(); sta.pop();
                switch(tokens[i][0]) {
                    case '+':
                        sta.push(tmp1+tmp2);
                        break;
                    case '-':
                        sta.push(tmp2-tmp1);
                        break;
                    case '*':
                        sta.push(tmp1*tmp2);
                        break;
                    case '/':
                        sta.push(tmp2/tmp1);
                }
            } else {
                sta.push(atoi(tokens[i].c_str()));
            }
        }
        return sta.top();
    }
};