/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<double, int> m;
        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            m.clear();
            int tmpmax = 0, vertical = 0, overlap = 1;
            for(int j = i + 1; j < points.size(); ++j) {
                int dy = points[i].y - points[j].y, dx = points[i].x - points[j].x;
                double k = 0;
                if(dx == 0) {
                    if(dy == 0)
                        ++overlap;
                    else
                        tmpmax = max(tmpmax, ++vertical);
                } else {
                    if(dy == 0) {
                        tmpmax = max(tmpmax, ++(m[0]));
                    } else {
                        int minus = (dy * dx < 0)?-1 : 1;
                        dy = dy < 0? -dy : dy;
                        dx = dx < 0? -dx : dx;
                        k = (dy * 1.0 / dx) * minus;
                        tmpmax = max(tmpmax, ++(m[k]));
                    }
                }
            }
            res = max(res, tmpmax + overlap);
        }
        return res;
    }
};