int Solution::numSetBits(unsigned int A) {
            unsigned int x = A;
            unsigned int total_ones = 0;
            while (x != 0) {
                x = x & (x-1);
                total_ones++;
            }
            return total_ones;
}
