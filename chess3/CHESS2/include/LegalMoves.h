#ifndef LEGALMOVES_H
#define LEGALMOVES_H

#include <vector>
#include <bitset>

void legPaW (std::vector<int>& moves, unsigned long long int P,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant);

void legPaB (std::vector<int>& moves, unsigned long long int p,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant);

void sliderHV (std::vector<int>& moves, unsigned long long int piece,
             unsigned long long int allyPieces,
             unsigned long long int occupied);

void sliderD (std::vector<int>& moves, unsigned long long int piece,
             unsigned long long int allyPieces,
             unsigned long long int occupied);

void sliderCD (std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied);

void KnightMoves(std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces);

void KingMoves(std::vector<int>& moves, unsigned long long int piece, unsigned long long int rook,
         unsigned long long int allyPieces, unsigned long long int occupied, bool CstlL, bool CstlS, bool cstlL, bool cstlS);

void legPaW2 (std::vector<int>& moves, unsigned long long int P,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant);

void legPaB2 (std::vector<int>& moves, unsigned long long int p,
             unsigned long long int whitePieces, unsigned long long int blackPieces,
             unsigned long long int occupied, unsigned long long int enPassant);

void sliderHV2 (std::vector<int>& moves, unsigned long long int piece,
             unsigned long long int allyPieces,
             unsigned long long int occupied);

void sliderD2 (std::vector<int>& moves, unsigned long long int piece,
             unsigned long long int allyPieces,
             unsigned long long int occupied);

void sliderCD2 (std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces,
         unsigned long long int occupied);

void KnightMoves2(std::vector<int>& moves, unsigned long long int piece, unsigned long long int occupied,
         unsigned long long int allyPieces);

void KingMoves2(std::vector<int>& moves, unsigned long long int piece,
         unsigned long long int allyPieces, unsigned long long int occupied);

bool isCheck(unsigned long long int r,unsigned long long int n,unsigned long long int b, unsigned long long int q,
             unsigned long long int k,unsigned long long int p,unsigned long long int R, unsigned long long int N,
             unsigned long long int B, unsigned long long int Q,unsigned long long int K, unsigned long long int P,
             unsigned long long int whitePieces, unsigned long long int blackPieces, unsigned long long int occupied,
             unsigned long long int enPassant, bool whiteTurn);


#endif // LEGALMOVES_H

