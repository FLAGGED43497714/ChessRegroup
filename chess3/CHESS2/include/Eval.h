#ifndef EVAL_H
#define EVAL_H

int EvalFunction(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P, int moveNb) ;

int EvalFunction2(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,unsigned long long int k,unsigned long long int p,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q,unsigned long long int K,unsigned long long int P, int moveNb) ;

int EvalMajorPieces(unsigned long long int r,unsigned long long int n,unsigned long long int b,
        unsigned long long int q,
        unsigned long long int R,unsigned long long int N,unsigned long long int B,
        unsigned long long int Q);


#endif // EVAL_H
