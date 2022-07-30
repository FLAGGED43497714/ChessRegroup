#ifndef BITWISEFUNCTION_H
#define BITWISEFUNCTION_H


void initZob(unsigned long long int rZobTable[8][8],unsigned long long int nZobTable[8][8],unsigned long long int bZobTable[8][8],
             unsigned long long int qZobTable[8][8],unsigned long long int kZobTable[8][8],unsigned long long int pZobTable[8][8],
             unsigned long long int RZobTable[8][8],unsigned long long int NZobTable[8][8],unsigned long long int BZobTable[8][8],
             unsigned long long int QZobTable[8][8],unsigned long long int KZobTable[8][8],unsigned long long int PZobTable[8][8]);


unsigned long long int reverseULL(unsigned long long int b);

unsigned int countSetBits1(unsigned long long int n);

unsigned int countSetBits2(unsigned long long int n);

#endif // BITWISEFUNCTION_H
