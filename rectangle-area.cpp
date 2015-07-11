class Solution { 
public: 
    struct Line {
        int left, right;
        Line(int _left, int _right) : left(_left), right(_right) {}
    };

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > C) {
            swap(A, C);
            swap(B, D);
        }
        if (E > G) {
            swap(E, G);
            swap(F, H);
        }
        int x_overlap = getOverlapLength(Line(A, C), Line(E, G));
        int y_overlap = getOverlapLength(Line(B, D), Line(F, H));
        return ((C - A) * (D - B) + (G - E) * (H - F)) - x_overlap * y_overlap;
    } 

private:
    int getOverlapLength(Line a, Line b) {
        if (a.left > b.left) {
            swap(a, b);
        }

        if (a.right <= b.left) {
            return 0;
        } else if (a.right >= b.right) {
            return b.right - b.left;
        } else {
            return a.right - b.left;
        }
    }
};
