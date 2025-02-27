class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        fib_lens = {} # (a, b): length of subsequence
        set_arr = set(arr) # set of arrs for O(1) lookup

        for b, c in combinations(arr, 2):
            a = c - b # a + b = c
            if a < b and a in set_arr: # a < b since arr increasing, a found means (a, b, c) is fib
                # length of (b, c) = length of (a, b) + 1 for c. (a, b) is min 2
                fib_lens[(b, c)] = fib_lens.get((a, b), 2) + 1
                
        return max(fib_lens.values(), default = 0) # max length or 0 if no lengths
        