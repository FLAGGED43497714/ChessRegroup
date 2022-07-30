#include "BitwiseFunction.h"
#include <bitset>

unsigned long long int rZobTable[8][8] ;
unsigned long long int nZobTable[8][8] ;
unsigned long long int bZobTable[8][8] ;
unsigned long long int qZobTable[8][8] ;
unsigned long long int kZobTable[8][8] ;
unsigned long long int pZobTable[8][8] ;

unsigned long long int RZobTable[8][8] ;
unsigned long long int NZobTable[8][8] ;
unsigned long long int BZobTable[8][8] ;
unsigned long long int QZobTable[8][8] ;
unsigned long long int KZobTable[8][8] ;
unsigned long long int PZobTable[8][8] ;

unsigned long long int EnPassantZobTable[8][8] ;


/*unsigned long long int ZobristHash(unsigned long long int r,unsigned long long int n,unsigned long long int b,unsigned long long int q,
                                   unsigned long long int k,unsigned long long int p,unsigned long long int R,unsigned long long int N,
                                   unsigned long long int B,unsigned long long int Q,unsigned long long int K,unsigned long long int P,
                                   bool CstlL, bool CstlS , bool cstlL , bool cstlS, bool maximizingPlayer){

       CstlS <<= 1 ;
       CstlL <<= 2 ;
       cstlS <<= 3 ;
       cstlL <<= 4 ;
       maximizingPlayer <<= 5 ;

       return r^(n^(b^(q^(k^(p^(R^(N^(B^(Q^(K^(P^(CstlS^(CstlL^(cstlS^(cstlL^maximizingPlayer))))))))))))))) ;
}*/

void initZob(unsigned long long int rZobTable[8][8],unsigned long long int nZobTable[8][8],unsigned long long int bZobTable[8][8],
             unsigned long long int qZobTable[8][8],unsigned long long int kZobTable[8][8],unsigned long long int pZobTable[8][8],
             unsigned long long int RZobTable[8][8],unsigned long long int NZobTable[8][8],unsigned long long int BZobTable[8][8],
             unsigned long long int QZobTable[8][8],unsigned long long int KZobTable[8][8],unsigned long long int PZobTable[8][8]){

    unsigned long long int r30 ;
    unsigned long long int s30 ;
    unsigned long long int t4 ;

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            rZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

            //coutBitSet(rZobTable[line][col]) ;
            //std::cin>>nothing;
        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            nZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            bZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }

    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            qZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            kZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;


            pZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            RZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;


            NZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;


            BZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;


            QZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;


            KZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
    for (int line = 0 ; line < 8 ; line++){
        for (int col = 0 ; col < 8 ; col++){
            r30 = RAND_MAX*rand()+rand() ;
            s30 = RAND_MAX*rand()+rand() ;
            t4  = rand() & 0xf ;

            PZobTable[line][col] = (r30 << 34) + (s30 << 4) + t4 ;

        }
    }
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
