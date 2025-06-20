class Solution {
    public int maxDistance(String s, int k) {
        int x = 0, y = 0;
        int[] distances = new int[s.length()];

        // Simulate movement and record Manhattan distances
        for (int i = 0; i < s.length(); i++) {
            char move = s.charAt(i);
            if (move == 'N') y++;
            else if (move == 'S') y--;
            else if (move == 'E') x++;
            else if (move == 'W') x--;
            distances[i] = Math.abs(x) + Math.abs(y);
        }

        if (k == 0) {
            int max = 0;
            for (int d : distances) max = Math.max(max, d);
            return max;
        }

        int maxDist = distances[1];
        int prev = distances[0];
        int addedBoost = 0;

        for (int i = 1; i < distances.length; i++) {
            if (distances[i] < prev && k > 0) {
                addedBoost += 2;
                k--;
            }
            prev = distances[i];
            distances[i] += addedBoost;
            maxDist = Math.max(maxDist, distances[i]);
        }

        return maxDist;
    }
}