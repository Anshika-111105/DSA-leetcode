class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = frozenset("aeiou")
        current_count = 0
        max_count = 0 
        window_start = 0

        for window_end in range(len(s)):
            if s[window_end] in vowels:
                current_count += 1

            if window_end >= k - 1:  
                if current_count > max_count:
                    max_count = current_count
                if s[window_start] in vowels:
                    current_count -= 1
                window_start += 1

        return max_count