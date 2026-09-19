class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest horizontal distance to the rectangle
        int closestXDistance = calculateDistanceToRange(x1, x2, xCenter);

        // Find the closest vertical distance to the rectangle
        int closestYDistance = calculateDistanceToRange(y1, y2, yCenter);

        // If distance to the closest point <= radius, they overlap
        return closestXDistance * closestXDistance
             + closestYDistance * closestYDistance
             <= radius * radius;
    }

private:
    int calculateDistanceToRange(int rangeStart, int rangeEnd, int point) {

        // Point is already inside the range
        if (rangeStart <= point && point <= rangeEnd) {
            return 0;
        }

        // Otherwise, return distance to the nearest boundary
        return point < rangeStart ? rangeStart - point : point - rangeEnd;
    }
};