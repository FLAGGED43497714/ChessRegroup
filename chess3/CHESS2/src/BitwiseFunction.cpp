#include "BitwiseFunction.h"
#include <bitset>

unsigned long long int ZobristHash(unsigned long long int r,unsigned long long int n,unsigned long long int b,unsigned long long int q,
                                   unsigned long long int k,unsigned long long int p,unsigned long long int R,unsigned long long int N,
                                   unsigned long long int B,unsigned long long int Q,unsigned long long int K,unsigned long long int P,
                                   bool CstlL, bool CstlS , bool cstlL , bool cstlS, bool maximizingPlayer) {

                                   CstlS <<= 1 ;
                                   CstlL <<= 2 ;
                                   cstlS <<= 3 ;
                                   cstlL <<= 4 ;
                                   maximizingPlayer <<= 5 ;


                                   return r^(n^(b^(q^(k^(p^(R^(N^(B^(Q^(K^(P^(CstlS^(CstlL^(cstlS^(cstlL^maximizingPlayer))))))))))))))) ;
                                   }

unsigned long long int reverseULL(unsigned long long int b) {
    b = (b & 0xFFFFFFFF00000000) >> 32 | (b & 0x00000000FFFFFFFF) << 32 ;
    b = (b & 0xFFFF0000FFFF0000) >> 16 | (b & 0x0000FFFF0000FFFF) << 16 ;
    b = (b & 0xFF00FF00FF00FF00) >> 8  | (b & 0x00FF00FF00FF00FF) << 8 ;
    b = (b & 0xF0F0F0F0F0F0F0F0) >> 4  | (b & 0x0F0F0F0F0F0F0F0F) << 4 ;
    b = (b & 0xCCCCCCCCCCCCCCCC) >> 2  | (b & 0x3333333333333333) << 2 ;
    b = (b & 0xAAAAAAAAAAAAAAAA) >> 1  | (b & 0x5555555555555555) << 1 ;

    return b ;
}

unsigned int countSetBits1(unsigned long long int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

unsigned int countSetBits2(unsigned long long int n)
{
    std::bitset<64> nBit (n) ;
    unsigned int count = nBit.count() ;
}
