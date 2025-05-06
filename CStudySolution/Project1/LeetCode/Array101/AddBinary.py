from typing import List

# 1 <= a.length, b.length <= 104
# a and b consist only of '0' or '1' characters.
# Each string does not contain leading zeros except for the zero itself.

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        out = []

        while i >= 0 or j >= 0 or carry:
            carry += (i >= 0 and a[i] == '1') + (j >= 0 and b[j] == '1')
            out.append(str(carry & 1))
            carry >>= 1
            i -= 1
            j -= 1
        
        return "".join(reversed(out))
