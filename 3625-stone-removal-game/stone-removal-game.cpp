class Solution {
public:
    int canAliceWin(int n) {
        if (n < 10) return 0;
        if (n < 19) return 1;
        if (n < 27) return 0;
        if (n < 34) return 1;
        if (n < 40) return 0;
        if (n < 45) return 1;
        if (n < 49) return 0;

        return 1;
    }
};