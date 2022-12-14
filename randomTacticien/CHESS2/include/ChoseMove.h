#ifndef CHOSEMOVE_H
#define CHOSEMOVE_H

#include <string>
#include <vector>

int minimax(unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P,
        bool & CstlL, bool & CstlS , bool & cstlL , bool & cstlS, unsigned long long int & enPassant,
        unsigned long long int & forbCstlS, unsigned long long int & forbCstlL,
        unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        unsigned long long int & tempForbCstlS, unsigned long long int & tempForbCstlL,
        unsigned long long int & tempForbcstlS, unsigned long long int & tempForbcstlL,
        std::vector<int>& variante,
        int depthInit, int depth, int veryMaxDepth, int alpha, int beta, bool maximizingPlayer,
        unsigned long long int & positionHash, int moveNb);

#endif // CHOSEMOVE_H
