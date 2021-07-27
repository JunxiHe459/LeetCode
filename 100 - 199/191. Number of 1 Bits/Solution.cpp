class Solution {
public:
    // Only loop how many 1 in n times.
    int hammingWeight(uint32_t n) {
        int total = 0;
        while(n)
        {
            // Genius
            n &= (n-1);
            total++;
        }
        return total;
    }

    // Loop 32 bits, O(32)
    int hammingWeight(uint32_t n) {
        int total = 0;
        while(n > 0)
        {
            total += n & 1;
            n = n >> 1;
        }
        return total;
    }
};