/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/sum-of-two-integers/description

class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a & b) << 1;
            a = (a ^ b);
            b = carry;
        }
        return a;
    }
};


/*
1- XOR for partial sum: a ^ b adds bits where they differ (0+1 or 1+0) and leaves out carry where both are 1. So this is the sum ignoring carry.

2- (AND + shift) for carry: (a & b) finds positions where both bits are 1 (these generate a carry). 
Shifting left by 1 moves that carry into the position it needs to be added next.

3- Iterate: Now we need to add the carry back in. 
Replace a with the partial sum (a ^ b), and b with the carry. 
Loop until there is no carry (b == 0).

5- example:
getSum(5, 3): 5=0101, 3=0011 carry=(0101&0011)<<1 = (0001)<<1 = 0010
a=0101^0011=0110 (6), b=0010 (2) carry=(0110&0010)<<1=(0010)<<1=0100
a=0110^0010=0100 (4), b=0100 (4) carry=(0100&0100)<<1=(0100)<<1=1000
a=0100^0100=0000,     b=1000     carry=(0000&1000)<<1=0 
a=0000^1000=1000 (8), b=0 → result 8.

getSum(-2, 3) works similarly; bits propagate until carry zero; final two’s complement bits represent 1.

- Why it replaces +: Addition is precisely “sum without carry” (XOR) plus “carry” (AND then shift), repeated until no carry remains.
*/
