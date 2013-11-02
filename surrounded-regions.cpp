class Solution {
public:
    //typedef pair<int, int> pair<int, int>;
    int rw,cl;
    
    queue<pair<int, int>> q;
    set<pair<int, int>> em;
    set<pair<int, int>> tmpset;
    
    bool isBound(pair<int, int> &tt)
    {
        if(tt.first == 0 || tt.first == (rw-1) || tt.second == 0 || tt.second == (cl-1))
            return true;
        return false;
    }
    void addNeighbor(int i, int j, vector<vector<char> > &board)
    {
        if(i < 0 || i >=rw || j < 0 || j >= cl || board[i][j] == 'X')
            return;
        if(tmpset.find(pair<int, int>(i,j)) != tmpset.end())
            return;
        pair<int, int> tt(i,j);
        tmpset.insert(tt);
        q.push(tt);
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size() == 0)
            return;
            
        rw = board.size();
        cl = board[0].size();
        em.clear();
        for(int i = 0; i < rw; i++)
         for(int j = 0; j < cl; j++)
         {
             if(board[i][j] == 'X')
                continue;
             else if(em.find(pair<int, int>(i, j)) != em.end())
                continue;
             tmpset.clear();
             bool f = true;
             q.push(pair<int, int>(i,j));
             tmpset.insert(pair<int, int>(i,j));
             while(!q.empty())
             {
                 pair<int, int> node = q.front();
                 q.pop();
                 if(isBound(node))
                    f = false;
                 addNeighbor(node.first - 1,node.second, board);
                 addNeighbor(node.first + 1,node.second, board);
                 addNeighbor(node.first,node.second-1, board);
                 addNeighbor(node.first,node.second+1, board);
             }
             set<pair<int, int>>::iterator p = tmpset.begin();
             if(f == false)
             {
                 while(p!=tmpset.end())
                    em.insert(*(p++));
             }
             else
             {
                 while(p!=tmpset.end())
                 {
                     board[(*p).first][(*p).second] = 'X';
                     p++;
                 }
             }
         }
    }
};
