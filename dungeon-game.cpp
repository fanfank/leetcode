class Solution {
public:
    int nr_row, nr_col;

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        nr_row = dungeon.size();
        nr_col = dungeon[0].size();

        dungeon[nr_row - 1][nr_col - 1] = 1 - dungeon[nr_row - 1][nr_col - 1];

        for (int i = nr_row - 1; i >= 0; --i) {
            for (int j = nr_col - 1; j >= 0; --j) {
                if (i == nr_row - 1 && j == nr_col - 1) {
                    continue;
                }

                int min_req_health;
                if (i + 1 < nr_row && j + 1 < nr_col) {
                    min_req_health = min(dungeon[i+1][j] - dungeon[i][j], 
                            dungeon[i][j+1] - dungeon[i][j]);
                } else if (i + 1 >= nr_row) {
                    min_req_health = dungeon[i][j+1] - dungeon[i][j];
                } else {
                    min_req_health = dungeon[i+1][j] - dungeon[i][j];
                }
                dungeon[i][j] = max(1 - dungeon[i][j], min_req_health);
            }
        }

        return dungeon[0][0] <= 1 ? 1 : dungeon[0][0];
    }
};

/*
//invalid code time O(n^4)
class Solution {
public:
    class Point {
    public:
        bool checked;
        int row, col;
        list<pair<int, int> > health_record; //first : min_ever_health
                                             //second: cur_health;
        Point(int _row = 0, int _col = 0) : 
                row(_row), col(_col), checked(false) {

            health_record.clear();
        }

        void clear() {
            health_record.clear();
        }
    };

    int nr_row;
    int nr_col;
    queue<Point*> bfs_queue;
    vector<vector<Point> > health_map;
    vector<vector<int> >* p_dungeon;

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        //initialize
        initRowCol(dungeon);
        initHealthMap(dungeon);
        while (!bfs_queue.empty()) {
            bfs_queue.pop();
        }

        p_dungeon = &dungeon;
        health_map[0][0].health_record.push_back(
                pair<int, int>(dungeon[0][0], dungeon[0][0]));
        
        bfs_queue.push(&health_map[0][0]);

        while (!bfs_queue.empty()) {
            Point* cur_point = bfs_queue.front();
            bfs_queue.pop();

            if (cur_point->row == nr_row - 1 && cur_point->col == nr_col - 1) {
                break;
            }

            if (cur_point->checked) {
                continue;
            } else {
                cur_point->checked = true;
            }

            updateNeighbor(cur_point, 0, 1);
            updateNeighbor(cur_point, 1, 0);

            cur_point->clear();
        }
        
        int min_health = 0x7fffffff;
        list<pair<int, int> >::iterator iter_record = 
                health_map[nr_row-1][nr_col-1].health_record.begin();

        for (; iter_record != health_map[nr_row-1][nr_col-1].health_record.end(); 
                ++iter_record) {
            min_health = min(min_health, abs(iter_record->first));
        }

        return min_health;
    }

private:
    void updateNeighbor(Point* point, int d_row, int d_col) {
        int row = point->row + d_row;
        int col = point->col + d_col;
        if (row >= nr_row || col >= nr_col) {
            return;
        }

        Point* neighbor = &health_map[row][col];
        list<pair<int, int> >::iterator iter_point = 
                point->health_record.begin();
        list<pair<int, int> >::iterator iter_neighbor;

        for (; iter_point != point->health_record.end(); ++iter_point) {
            bool add_record = true;
            iter_neighbor = neighbor->health_record.begin();
            int health = iter_point->second + 
                    (*p_dungeon)[neighbor->row][neighbor->col];
            int min_health = min(iter_point->first, health);

            while (iter_neighbor != neighbor->health_record.end()) {
                if (health <= iter_neighbor->second && 
                        min_health <= iter_neighbor->first) {

                    add_record = false;
                    break;
                } else if (health > iter_neighbor->second &&
                        min_health > iter_neighbor->first) {

                    iter_neighbor = neighbor->health_record.erase(iter_neighbor);
                    continue;
                }
                ++iter_neighbor;
            }

            if (add_record) {
                neighbor->health_record.push_back(
                        pair<int, int>(min_health, health));
            }
        }

        bfs_queue.push(neighbor);
    }

    void initHealthMap(const vector<vector<int> > &dungeon) {
        health_map.clear();
        for (int i = 0; i < nr_row; ++i) {
            health_map.push_back(vector<Point>());
            for (int j = 0; j < nr_col; ++j) {
                health_map[i].push_back(Point(i, j));
            }
        }
    }

    void initRowCol(const vector<vector<int> > &dungeon) {
        nr_row = dungeon.size();
        nr_col = dungeon[0].size();
    }
};
*/
