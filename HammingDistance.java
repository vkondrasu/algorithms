class Solution {
    public int hammingDistance(int x, int y) {
        
        int r = x^y; // r -- will have '1' bit set in place where x and y in bit representation differ
        int count = 0;
        
        while(r > 0){ // Now count the '1' bits in r
            count+= r&1; // if the bit is 1 add 1 to count -- otherwise 0 is added, we elimintaed if statement here
            r = r>>1;
        }
        
        return count;
        
    }
}
