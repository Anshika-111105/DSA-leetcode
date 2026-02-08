class Solution {
    public int longestSubarray(int[] nums, int limit) {
        var left = 0;
        var maxSize = 0;
        var count = new TreeMap<Integer, Integer>();

        for (var right = 0; right < nums.length; right++) {

            count.compute(nums[right], (_, v) -> v == null ? 1 : ++v); // increment frequency

            for (; count.lastKey() - count.firstKey() > limit; left++)
                if (count.compute(nums[left], (_, v) -> --v) == 0) // decrement frequency
                    count.remove(nums[left]); // remove entry if frequency becomes 0

            maxSize = Math.max(maxSize, right - left + 1);
        }

        return maxSize;
    }
}