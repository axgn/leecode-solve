class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])

s = "the sky is blue"
print(Solution().reverseWords(s))
