#include "Eval.h"
#include "BitwiseFunction.h"
#include "Constants.h"

#include <bitset>
//#include "Constants.h"
#include <limits>

//int EVALintINFINITY = std::numeric_limits<int>::max();

std::bitset<64> const bitsetPawnSqTbW50("0000000011111111000000000000000000000000000000000000000000000000") ;
unsigned long long int const PawnSqTbW50 = bitsetPawnSqTbW50.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW30("0000000000000000000110000000000000000000000000000000000000000000") ;
unsigned long long int const PawnSqTbW30 = bitsetPawnSqTbW30.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW27("0000000000000000000000000001100000000000000000000000000000000000") ;
unsigned long long int const PawnSqTbW27 = bitsetPawnSqTbW27.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW25("0000000000000000000000000000000000011000000000000000000000000000") ;
unsigned long long int const PawnSqTbW25 = bitsetPawnSqTbW25.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW20("0000000000000000001001000000000000000000000000000000000000000000") ;
unsigned long long int const PawnSqTbW20 = bitsetPawnSqTbW20.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW10("0000000000000000110000110010010000000000000000000110011000000000") ;
unsigned long long int const PawnSqTbW10 = bitsetPawnSqTbW10.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbW5("0000000000000000000000001100001100000000100000011000000100000000") ;
unsigned long long int const PawnSqTbW5 = bitsetPawnSqTbW5.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbWm5("0000000000000000000000000000000000000000010000100000000000000000") ;
unsigned long long int const PawnSqTbWm5 = bitsetPawnSqTbWm5.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbWm10("0000000000000000000000000000000000000000001001000000000000000000") ;
unsigned long long int const PawnSqTbWm10 = bitsetPawnSqTbWm10.to_ullong() ;

std::bitset<64> const bitsetPawnSqTbWm25("0000000000000000000000000000000000000000000000000001100000000000") ;
unsigned long long int const PawnSqTbWm25 = bitsetPawnSqTbWm25.to_ullong() ;

std::bitset<64> const bitsetN20("0000000000000000000000000001100000011000000000000000000000000000") ;
unsigned long long int const N20 = bitsetN20.to_ullong() ;

std::bitset<64> const bitsetN15("0000000000000000000110000010010000100100000110000000000000000000") ;
unsigned long long int const N15 = bitsetN15.to_ullong() ;

std::bitset<64> const bitsetN10("0000000000000000001001000000000000000000001001000000000000000000") ;
unsigned long long int const N10 = bitsetN10.to_ullong() ;


std::bitset<64> const bitsetN5("0000000000000000000000000100001000000000010000100000000000000000") ;
unsigned long long int const N5 = bitsetN5.to_ullong() ;

std::bitset<64> const bitsetNm20("0000000001000010000000000000000000000000000000000100001000100100") ;
unsigned long long int const Nm20 = bitsetNm20.to_ullong() ;

std::bitset<64> const bitsetNm30("0011110000000000100000011000000110000001100000010000000000011000") ;
unsigned long long int const Nm30 = bitsetNm30.to_ullong() ;

std::bitset<64> const bitsetNm40("0100001010000001000000000000000000000000000000001000000101000010") ;
unsigned long long int const Nm40 = bitsetNm40.to_ullong() ;

std::bitset<64> const bitsetNm50("1000000100000000000000000000000000000000000000000000000010000001") ;
unsigned long long int const Nm50 = bitsetNm50.to_ullong() ;

std::bitset<64> const bitsetB10("0000000000000000000110000001100000111100011001100000000000000000") ;
unsigned long long int const B10 = bitsetB10.to_ullong() ;

std::bitset<64> const bitsetB5("0000000000000000001001000110011000000000000000000100001000000000") ;
unsigned long long int const B5 = bitsetB5.to_ullong() ;

std::bitset<64> const bitsetBm10("0111111010000001100000011000000110000001100000011000000101011010") ;
unsigned long long int const Bm10 = bitsetBm10.to_ullong() ;

std::bitset<64> const bitsetBm20("1000000100000000000000000000000000000000000000000000000010000001") ;
unsigned long long int const Bm20 = bitsetBm20.to_ullong() ;

std::bitset<64> const bitsetBm40("0000000000000000000000000000000000000000000000000000000000100100") ;
unsigned long long int const Bm40 = bitsetBm40.to_ullong() ;

std::bitset<64> const bitsetK30("0000000000000000000000000000000000000000000000000000000001000010") ;
unsigned long long int const K30 = bitsetK30.to_ullong() ;

std::bitset<64> const bitsetK20("0000000000000000000000000000000000000000000000001100001110000001") ;
unsigned long long int const K20 = bitsetK20.to_ullong() ;

std::bitset<64> const bitsetK10("0000000000000000000000000000000000000000000000000000000000100100") ;
unsigned long long int const K10 = bitsetK10.to_ullong() ;

std::bitset<64> const bitsetKm10("0000000000000000000000000000000000000000100000010000000000000000") ;
unsigned long long int const Km10 = bitsetKm10.to_ullong() ;

std::bitset<64> const bitsetKm20("0000000000000000000000000000000010000001011111100000000000000000") ;
unsigned long long int const Km20 = bitsetKm20.to_ullong() ;

std::bitset<64> const bitsetKm30("1000000110000001100000011000000101100110000000000000000000000000") ;
unsigned long long int const Km30 = bitsetKm30.to_ullong() ;

std::bitset<64> const bitsetKm40("0110011001100110011001100110011000011000000000000000000000000000") ;
unsigned long long int const Km40 = bitsetKm40.to_ullong() ;

std::bitset<64> const bitsetKm50("0001100000011000000110000001100000000000000000000000000000000000") ;
unsigned long long int const Km50 = bitsetKm50.to_ullong() ;

std::bitset<64> const bitsetKLm50("1100001100000000000000000000000000000000000000000000000010000001") ;
unsigned long long int const KLm50 = bitsetKLm50.to_ullong() ;

std::bitset<64> const bitsetKLm30("0011110011000011100000011000000110000001100000011100001101111110") ;
unsigned long long int const KLm30 = bitsetKLm30.to_ullong() ;

std::bitset<64> const bitsetKLm10("0000000000100100010000100100001001000010010000100000000000000000") ;
unsigned long long int const KLm10 = bitsetKLm10.to_ullong() ;

std::bitset<64> const bitsetKL30("0000000000000000001111000010010000100100001111000000000000000000") ;
unsigned long long int const KL30 = bitsetKL30.to_ullong() ;

std::bitset<64> const bitsetKL40("0000000000000000000000000001100000011000000000000000000000000000") ;
unsigned long long int const KL40 = bitsetKL40.to_ullong() ;


std::bitset<64> const bitsetR10("0000000001111110000000000000000000000000000000000000000000000000") ;
unsigned long long int const R10 = bitsetR10.to_ullong() ;

std::bitset<64> const bitsetR5("0000000010000001000000000000000000000000000000000000000000011000") ;
unsigned long long int const R5 = bitsetR5.to_ullong() ;

std::bitset<64> const bitsetRm5("0000000000000000100000011000000110000001100000011000000100000000") ;
unsigned long long int const Rm5 = bitsetRm5.to_ullong() ;

unsigned long long int const p50 (65280) ;
unsigned long long int const p30 (1572864) ;
unsigned long long int const p27 (402653184) ;
unsigned long long int const p25 (103079215104) ;
unsigned long long int const p20 (2359296);
unsigned long long int const p10 (28710448241246208) ;
unsigned long long int const p5 (36452112267214848) ;
unsigned long long int const pm5 (72567767433216) ;
unsigned long long int const pm10 (39582418599936) ;
unsigned long long int const pm25 (6755399441055744) ;

unsigned long long int const n20 (103481868288) ;
unsigned long long int const n15 (26543503441920) ;
unsigned long long int const n10 (39582420959232) ;
unsigned long long int const n5 (72568874729472) ;
unsigned long long int const nm20 (2612650733828325888) ;
unsigned long long int const nm30 (1729524650133749820) ;
unsigned long long int const nm40 (4792111478498951490) ;
unsigned long long int const nm50 (9295429630892703873) ;

unsigned long long int const b10 (112408288296960) ;
unsigned long long int const b5 (18577350176538624) ;
unsigned long long int const bm10 (6521636128632701310) ;
unsigned long long int const bm20 (9295429630892703873) ;
unsigned long long int const bm40 (2594073385365405696) ;

unsigned long long int const k30 (4755801206503243776) ;
unsigned long long int const k20 (9350317251351281664) ;
unsigned long long int const k10 (2594073385365405696) ;
unsigned long long int const km10 (141836999983104) ;
unsigned long long int const km20 (139092515880960) ;
unsigned long long int const km30 (440259412353) ;
unsigned long long int const km40 (104797202022) ;
unsigned long long int const km50 (404232216) ;

unsigned long long int const klm50(9295429630892703939) ; 
unsigned long long int const klm30(9134286862461027132) ; 
unsigned long long int const klm10(72852346905600) ; 
unsigned long long int const kl30(66125924401152) ; 
unsigned long long int const kl40(103481868288) ; 


unsigned long long int const r10 = 32256 ;
unsigned long long int const r5 = 1729382256910303488 ;
unsigned long long int const rm5 = 36452665219153920 ;



/*
unsigned long long int PawnSqTbW50 = constants::PawnSqTbW50 ;
unsigned long long int p50 = constants::p50 ;
unsigned long long int PawnSqTbW27 = constants::PawnSqTbW27 ;
unsigned long long int p27 = constants::p27 ;
unsigned long long int PawnSqTbW25 = constants::PawnSqTbW25 ;
unsigned long long int p25 = constants::p25 ;
unsigned long long int PawnSqTbW20 = constants::PawnSqTbW20 ;
unsigned long long int p20 = constants::p20 ;
unsigned long long int PawnSqTbW10 = constants::PawnSqTbW10 ;
unsigned long long int p10 = constants::p10 ;
unsigned long long int PawnSqTbW5 = constants::PawnSqTbW5 ;
unsigned long long int p5 = constants::p5 ;
unsigned long long int PawnSqTbWm5 = constants::PawnSqTbWm5 ;
unsigned long long int pm5 = constants::pm5 ;
unsigned long long int PawnSqTbWm10 = constants::PawnSqTbWm10 ;
unsigned long long int pm10 = constants::pm10 ;
unsigned long long int PawnSqTbWm25 = constants::PawnSqTbWm25 ;
unsigned long long int pm25 = constants::pm25 ;

unsigned long long int N20 = constants::N20 ;
unsigned long long int n20 = constants::n20 ;
unsigned long long int N15 = constants::N15 ;
unsigned long long int n15 = constants::n15 ;
unsigned long long int N10 = constants::N10 ;
unsigned long long int n10 = constants::n10 ;
unsigned long long int N5 = constants::N5 ;
unsigned long long int n5 = constants::n5 ;
unsigned long long int Nm20 = constants::Nm20 ;
unsigned long long int nm20 = constants::nm20 ;
unsigned long long int Nm30 = constants::Nm30 ;
unsigned long long int nm30 = constants::nm30 ;
unsigned long long int Nm40 = constants::Nm40 ;
unsigned long long int nm40 = constants::nm40 ;
unsigned long long int Nm50 = constants::Nm50 ;
unsigned long long int nm50 = constants::nm50 ;


unsigned long long int B10 = constants::B10 ;
unsigned long long int b10 = constants::b10 ;
unsigned long long int B5 = constants::B5 ;
unsigned long long int b5 = constants::b5 ;
unsigned long long int Bm10 = constants::Bm10 ;
unsigned long long int bm10 = constants::bm10 ;
unsigned long long int Bm20 = constants::Bm20 ;
unsigned long long int bm20 = constants::bm20 ;
unsigned long long int Bm40 = constants::Bm40 ;
unsigned long long int bm40 = constants::bm40 ;

unsigned long long int K30 = constants::K30 ;
unsigned long long int k30 = constants::k30 ;
unsigned long long int K20 = constants::K20 ;
unsigned long long int k20 = constants::k20 ;
unsigned long long int K10 = constants::K10 ;
unsigned long long int k10 = constants::k10 ;
unsigned long long int Km10 = constants::Km10 ;
unsigned long long int km10 = constants::km10 ;
unsigned long long int Km20 = constants::Km20 ;
unsigned long long int km20 = constants::km20 ;
unsigned long long int Km30 = constants::Km30 ;
unsigned long long int km30 = constants::km30 ;
unsigned long long int Km40 = constants::Km40 ;
unsigned long long int km40 = constants::km40 ;
unsigned long long int Km50 = constants::Km50 ;
unsigned long long int km50 = constants::km50 ;
*/




int EvalPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P);

int PieceSquareTables(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P);

int PieceSquareTables2(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P);

int RelativeEvalPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P);

int EVALintINFINITY = std::numeric_limits<int>::max() ;

extern int const LateThreshold ;

int EvalFunction(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P, int moveNb)
{
    int eval(0);

    eval += EvalPieces(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // eval += RelativeEvalPieces(r,n,b,q,k,p,R,N,B,Q,K,P) ; 
    eval += PieceSquareTables(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // if ( moveNb <= LateThreshold ){
    //     eval += PieceSquareTables(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // }


    return eval ;
}

int EvalFunction2(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P, int moveNb)
{
    int eval(0);

    eval += EvalPieces(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // eval += RelativeEvalPieces(r,n,b,q,k,p,R,N,B,Q,K,P) ; 
    eval += PieceSquareTables2(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // if ( moveNb <= LateThreshold ){
    //     eval += PieceSquareTables(r,n,b,q,k,p,R,N,B,Q,K,P) ;
    // }
    return eval ;
}


int EvalPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P)
{
    int sum (0) ;

    sum += (countSetBits2(R) - countSetBits2(r)) * 510 ;
    sum += (countSetBits2(N) - countSetBits2(n)) * 320 ;
    sum += (countSetBits2(B) - countSetBits2(b)) * 333 ;
    sum += (countSetBits2(Q) - countSetBits2(q)) * 880 ;
    sum += (countSetBits2(K) - countSetBits2(k)) * 10000 ;
    sum += (countSetBits2(P) - countSetBits2(p)) * 100 ;

    return sum ;
}

// int RelativeEvalPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
//         unsigned long long int q,unsigned long long int k,unsigned long long int p,
//         unsigned long long int R,unsigned long long int N,unsigned long long int B,
//         unsigned long long int Q,unsigned long long int K,unsigned long long int P)
// {
//     int sum1 (0) ;
//     int sum2 (0) ;

//     sum1 += countSetBits2(R) * 510 ;  
//     sum2 += countSetBits2(r) * 510 ;
    
//     sum1 += countSetBits2(N) * 320 ; 
//     sum2 += countSetBits2(n) * 320 ;
    
//     sum1 += countSetBits2(B)* 333 ; 
//     sum2 += countSetBits2(b) * 333 ;
    
//     sum1 += countSetBits2(Q) * 880 ; 
//     sum2 += countSetBits2(q) * 880 ;
    
//     sum1 += countSetBits2(K) * 10000 ; 
//     sum2 += countSetBits2(k) * 10000 ;
    
//     sum1 += countSetBits2(P) * 100 ;
//     sum2 += countSetBits2(p) * 100 ;

//     return (sum1 - sum2) * (100000 - (sum1+sum2)) ;
// }


int EvalMajorPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q)
{
    int sum1 (0) ;
    int sum2 (0) ;

    sum1 += countSetBits2(r)*5 ;
    sum1 += countSetBits2(n)*3 ;
    sum1 += countSetBits2(b)*3 ;
    sum1 += countSetBits2(q)*9 ;

    sum2 += countSetBits2(R)*5 ;
    sum2 += countSetBits2(N)*3 ;
    sum2 += countSetBits2(B)*3 ;
    sum2 += countSetBits2(Q)*9 ;

    return std::min(sum1,sum2) ;
    // sum += (countSetBits2(K) - countSetBits2(k)) * 10000 ;
    // sum += (countSetBits2(P) - countSetBits2(p)) * 100 ;x    
}


// int 

int PieceSquareTables(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P)
{
    int sum (0) ;

    sum += ( countSetBits2(P&PawnSqTbW50) - countSetBits2(p&p50) ) * 50 ;
    sum += ( countSetBits2(P&PawnSqTbW30) - countSetBits2(p&p30) ) * 30 ;
    sum += ( countSetBits2(P&PawnSqTbW27) - countSetBits2(p&p27) ) * 27 ;
    sum += ( countSetBits2(P&PawnSqTbW25) - countSetBits2(p&p25) ) * 25 ;
    sum += ( countSetBits2(P&PawnSqTbW20) - countSetBits2(p&p20) ) * 20 ;
    sum += ( countSetBits2(P&PawnSqTbW10) - countSetBits2(p&p10) ) * 10 ;
    sum += ( countSetBits2(P&PawnSqTbW5) - countSetBits2(p&p5) ) * 5 ;
    sum += ( countSetBits2(P&PawnSqTbWm5) - countSetBits2(p&pm5) ) * -5 ;
    sum += ( countSetBits2(P&PawnSqTbWm10) - countSetBits2(p&pm10) ) * -10 ;
    sum += ( countSetBits2(P&PawnSqTbWm25) - countSetBits2(p&pm25) ) * -25 ;

    if (N || n){
    sum += ( countSetBits2(N&N20) - countSetBits2(n&n20) ) * 20 ;
    sum += ( countSetBits2(N&N15) - countSetBits2(n&n15) ) * 15 ;
    sum += ( countSetBits2(N&N10) - countSetBits2(n&n10) ) * 10 ;
    sum += ( countSetBits2(N&N5) - countSetBits2(n&n5) ) * 5 ;
    sum += ( countSetBits2(N&Nm20) - countSetBits2(n&nm20) ) * -20 ;
    sum += ( countSetBits2(N&Nm30) - countSetBits2(n&nm30) ) * -30 ;
    sum += ( countSetBits2(N&Nm40) - countSetBits2(n&nm40) ) * -40 ;
    sum += ( countSetBits2(N&Nm50) - countSetBits2(n&nm50) ) * -50 ;
    }

    if(B || b){
        sum += ( countSetBits2(B&B10) - countSetBits2(b&b10) ) * 10 ;
        sum += ( countSetBits2(B&B5) - countSetBits2(b&b5) ) * 5 ;
        sum += ( countSetBits2(B&Bm10) - countSetBits2(b&bm10) ) * -10 ;
        sum += ( countSetBits2(B&Bm20) - countSetBits2(b&bm20) ) * -20 ;
        sum += ( countSetBits2(B&Bm40) - countSetBits2(b&bm40) ) * -40 ;
    }

    sum += ( countSetBits2(K&K30) - countSetBits2(k&k30) ) * 30 ;
    sum += ( countSetBits2(K&K20) - countSetBits2(k&k20) ) * 20 ;
    sum += ( countSetBits2(K&K10) - countSetBits2(k&k10) ) * 10 ;
    sum += ( countSetBits2(K&Km10) - countSetBits2(k&km10) ) * -10 ;
    sum += ( countSetBits2(K&Km20) - countSetBits2(k&km20) ) * -20 ;
    sum += ( countSetBits2(K&Km30) - countSetBits2(k&km30) ) * -30 ;
    sum += ( countSetBits2(K&Km40) - countSetBits2(k&km40) ) * -40 ;
    sum += ( countSetBits2(K&Km50) - countSetBits2(k&km50) ) * -50 ;

    if(R || r )
    {
        sum += ( countSetBits2(R&R10) - countSetBits2(r&r10) ) * 10 ;
        sum += ( countSetBits2(R&R5) - countSetBits2(r&r5) ) * 5 ;
        sum += ( countSetBits2(R&Rm5) - countSetBits2(r&rm5) ) * -5 ;
    }
    // if(Q || q )
    // {
    //     sum += ( countSetBits2(R&R10) - countSetBits2(r&r10) ) * 10 ;
    //     sum += ( countSetBits2(R&R5) - countSetBits2(r&r5) ) * 5 ;
    //     sum += ( countSetBits2(R&Rm5) - countSetBits2(r&rm5) ) * -5 ;
    // }

    return sum ;
}

int PieceSquareTables2(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P)
{
    int sum (0) ;

    sum += ( countSetBits2(P&PawnSqTbW50) - countSetBits2(p&p50) ) * 50 ;
    sum += ( countSetBits2(P&PawnSqTbW30) - countSetBits2(p&p30) ) * 30 ;
    sum += ( countSetBits2(P&PawnSqTbW27) - countSetBits2(p&p27) ) * 27 ;
    sum += ( countSetBits2(P&PawnSqTbW25) - countSetBits2(p&p25) ) * 25 ;
    sum += ( countSetBits2(P&PawnSqTbW20) - countSetBits2(p&p20) ) * 20 ;
    // sum += ( countSetBits2(P&PawnSqTbW10) - countSetBits2(p&p10) ) * 10 ;
    // sum += ( countSetBits2(P&PawnSqTbW5) - countSetBits2(p&p5) ) * 5 ;
    // sum += ( countSetBits2(P&PawnSqTbWm5) - countSetBits2(p&pm5) ) * -5 ;
    // sum += ( countSetBits2(P&PawnSqTbWm10) - countSetBits2(p&pm10) ) * -10 ;
    // sum += ( countSetBits2(P&PawnSqTbWm25) - countSetBits2(p&pm25) ) * -25 ;

    if (N || n){
    sum += ( countSetBits2(N&N20) - countSetBits2(n&n20) ) * 20 ;
    sum += ( countSetBits2(N&N15) - countSetBits2(n&n15) ) * 15 ;
    sum += ( countSetBits2(N&N10) - countSetBits2(n&n10) ) * 10 ;
    sum += ( countSetBits2(N&N5) - countSetBits2(n&n5) ) * 5 ;
    sum += ( countSetBits2(N&Nm20) - countSetBits2(n&nm20) ) * -20 ;
    sum += ( countSetBits2(N&Nm30) - countSetBits2(n&nm30) ) * -30 ;
    sum += ( countSetBits2(N&Nm40) - countSetBits2(n&nm40) ) * -40 ;
    sum += ( countSetBits2(N&Nm50) - countSetBits2(n&nm50) ) * -50 ;
    }

    if(B || b){
        sum += ( countSetBits2(B&B10) - countSetBits2(b&b10) ) * 10 ;
        sum += ( countSetBits2(B&B5) - countSetBits2(b&b5) ) * 5 ;
        sum += ( countSetBits2(B&Bm10) - countSetBits2(b&bm10) ) * -10 ;
        sum += ( countSetBits2(B&Bm20) - countSetBits2(b&bm20) ) * -20 ;
        sum += ( countSetBits2(B&Bm40) - countSetBits2(b&bm40) ) * -40 ;
    }

    sum += ( countSetBits2(K&KL40) - countSetBits2(k&kl40) ) * 40 ;
    sum += ( countSetBits2(K&KL30) - countSetBits2(k&kl30) ) * 30 ;
    sum += ( countSetBits2(K&KLm10) - countSetBits2(k&klm10) ) * -10 ;
    sum += ( countSetBits2(K&KLm30) - countSetBits2(k&klm30) ) * -30 ;
    sum += ( countSetBits2(K&KLm50) - countSetBits2(k&klm50) ) * -50 ;

    // if(R || r )
    // {
    //     sum += ( countSetBits2(R&R10) - countSetBits2(r&r10) ) * 10 ;
    //     sum += ( countSetBits2(R&R5) - countSetBits2(r&r5) ) * 5 ;
    //     sum += ( countSetBits2(R&Rm5) - countSetBits2(r&rm5) ) * -5 ;
    // }
    // if(Q || q )
    // {
    //     sum += ( countSetBits2(R&R10) - countSetBits2(r&r10) ) * 10 ;
    //     sum += ( countSetBits2(R&R5) - countSetBits2(r&r5) ) * 5 ;
    //     sum += ( countSetBits2(R&Rm5) - countSetBits2(r&rm5) ) * -5 ;
    // }

    return sum ;
}

