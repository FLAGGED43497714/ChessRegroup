#include "ChoseMove.h"
#include "Eval.h"
#include "MakeMove.h"
#include "LegalMoves.h"
//#include "Constants.h"
#include "coutBoard.h"
#include "BitwiseFunction.h"

#include <unistd.h>
#include <limits>
#include <iostream>
#include <vector>
#include <unordered_map>
//#include <string>

int intINFINITY = std::numeric_limits<int>::max() ;


//extern std::unordered_map<unsigned long long int, int> ump ;
//extern std::unordered_map<unsigned long long int, int>::iterator it ;


int minimax(unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P,
        bool & CstlL, bool & CstlS , bool & cstlL , bool & cstlS, unsigned long long int & enPassant,
        unsigned long long int & forbCstlS, unsigned long long int & forbCstlL,
        unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        unsigned long long int & tempForbCstlS, unsigned long long int & tempForbCstlL,
        unsigned long long int & tempForbcstlS, unsigned long long int & tempForbcstlL,
        std::vector<int>& rootVariant,
        int depthInit, int depth, int veryMaxDepth, int alpha, int beta, bool maximizingPlayer, int moveNb){




        if (((R|N|B|Q|K|P)&(tempForbcstlS|tempForbcstlL))){
            //std::cout<<"*" ;
            return 10020 ;
        }
        if (((r|n|b|q|k|p)&(tempForbCstlS|tempForbCstlL))){
            //std::cout<<"." ;
            return -10020 ;
        }




        /*unsigned long long int zobKey ;
        zobKey = ZobristHash(r,n,b,q,k,p,R,N,B,Q,K,P,CstlS,CstlL,cstlS,cstlL, maximizingPlayer) ;

        it = ump.find(zobKey); //Finding an element

        if(it != ump.end()){
            return it->second ;
        }*/






        if ( ( depth == 0 ) || ( veryMaxDepth == 0 )){
            return EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;

        }

        if (k == 0){
            rootVariant.clear() ;
            return 10000 + veryMaxDepth ;
        }
        if (K == 0){
            rootVariant.clear() ;
            return -10000 - veryMaxDepth ;
        }

        std::string nothing ;

        std::vector<int> moves ;


        std::vector<int> tempSuffix ;
        std::vector<int> tempVariante ;

        unsigned long long int tempEnPassant;
        // unsigned long long int tempForbCstlS;
        // unsigned long long int tempForbCstlL;
        // unsigned long long int tempForbcstlS;
        // unsigned long long int tempForbcstlL;

        if ( ( depth == 0 ) || ( veryMaxDepth == 0 )){
            return EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P, moveNb) ;

        }

        if (k == 0){
            rootVariant.clear() ;
            return 10000 + veryMaxDepth ;
        }
        if (K == 0){
            rootVariant.clear() ;
            return -10000 - veryMaxDepth ;
        }

        // std::string nothing ;

        // std::vector<int> moves ;

        //redef
        // std::vector<int> tempSuffix ;
        // std::vector<int> tempVariante ;

        // unsigned long long int tempEnPassant;


        bool brokeCastleL = false ;
        bool brokeCastleS = false ;
        bool brokecastleL = false ;
        bool brokecastleS = false ;


        // bool verbose = false ;

        //std::cout << "in minimax " << std::endl ;
        //std::cout << "maximizingPlayer = " << maximizingPlayer << std::endl ;
        //std::cin >> nothing ;
        unsigned long long int whitePieces = R | N | B | Q | K | P ;
        unsigned long long int blackPieces = r | n | b | q | k | p ;
        unsigned long long int occupied = whitePieces | blackPieces ;

        int pieceCaptured  ;
        bool wasCastle  ;
        bool wasPromote  ;

        int position ;
        int destination ;


        int maxEval (0) ;
        int minEval (0) ;
        int eval (0) ;

        bool depthIncreased ;

        //move ordering
        int captInd =0 ;
        int captInd2 =0 ;
        int captInd3 =0 ;
        int captInd4 =0 ;
        // int captInd5 =0 ;
        int dest = 0 ;
        unsigned long long int destInt  = 1;
        int temp1 = 0;
        int temp2 = 0;

        //std::vector<int> moves2 ;


        if (maximizingPlayer){

            if (depthInit <= 0){
                legPaW2(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, N, occupied, whitePieces) ;
                sliderD2(moves, B, whitePieces, occupied) ;
                sliderCD2(moves, B, whitePieces, occupied) ;
                sliderHV2(moves, Q, whitePieces, occupied) ;
                sliderD2(moves, Q, whitePieces, occupied) ;
                sliderCD2(moves, Q, whitePieces, occupied) ;
                sliderHV2(moves, R, whitePieces, occupied) ;
                KingMoves2(moves, K, whitePieces, occupied) ;
                
                maxEval = EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;
                

            } else {
                legPaW(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, N, whitePieces) ;
                sliderD(moves, B, whitePieces, occupied) ;
                sliderCD(moves, B, whitePieces, occupied) ;
                sliderHV(moves, Q, whitePieces, occupied) ;
                sliderD(moves, Q, whitePieces, occupied) ;
                sliderCD(moves, Q, whitePieces, occupied) ;
                sliderHV(moves, R, whitePieces, occupied) ;
                KingMoves(moves, K, R,  whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
                maxEval = - intINFINITY ;
            }


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            // captInd5 = 0 ;
            for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&blackPieces){
                    temp1 = moves[2*captInd] ;
                    temp2 = moves[2*captInd+1] ;
                    moves[2*captInd] = moves[2*semInd] ;
                    moves[2*captInd+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q|r|n|b)){
                        temp1 = moves[2*captInd2] ;
                        temp2 = moves[2*captInd2+1] ;
                        moves[2*captInd2] = moves[2*semInd] ;
                        moves[2*captInd2+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd2 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q|r)){
                        temp1 = moves[2*captInd3] ;
                        temp2 = moves[2*captInd3+1] ;
                        moves[2*captInd3] = moves[2*semInd] ;
                        moves[2*captInd3+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd3 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }
                // }
                // for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
                //     destInt = 1 ;
                //     dest = moves[2*semInd+1] ;
                //     destInt <<= dest ;
                //     if (destInt&(k)){
                //         temp1 = moves[2*captInd5] ;
                //         temp2 = moves[2*captInd5+1] ;
                //         moves[2*captInd5] = moves[2*semInd] ;
                //         moves[2*captInd5+1] = moves[2*semInd+1] ;
                //         moves[2*semInd] = temp1 ;
                //         moves[2*semInd+1] = temp2 ;

                //         captInd5 +=1 ;
                //     }
                // }



            // maxEval = - intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            unsigned long long int tempForbCstlS2 = forbCstlS ;
            unsigned long long int tempForbCstlL2 = forbCstlL ;
            unsigned long long int tempForbcstlS2 = forbcstlS ;
            unsigned long long int tempForbcstlL2 = forbcstlL ;

            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;
                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P, enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote, pieceCaptured) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                if (/*((depth == 2)||*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }

                eval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,tempForbCstlS,tempForbCstlL,tempForbcstlS,tempForbcstlL, tempSuffix, depthInit-1,depth-1, veryMaxDepth-1, alpha,beta,false, moveNb+1) ;
                tempForbCstlL = tempForbCstlL2 ;
                tempForbcstlL = tempForbcstlL2 ;
                tempForbCstlS = tempForbCstlS2 ;
                tempForbcstlS = tempForbcstlS2 ;

                if (eval > maxEval){
                    tempVariante = {position, destination} ;
                    tempVariante.insert(tempVariante.end(), tempSuffix.begin(), tempSuffix.end() );
                    tempSuffix.clear() ;
                }


                if (depthIncreased){
                    depth -= 1 ;
                }

                enPassant = tempEnPassant ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;

                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    std::cin >> nothing ;}*/

                maxEval = std::max(maxEval,eval) ;
                alpha = std::max(alpha, eval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            rootVariant = tempVariante ;
            return maxEval ;
        }



        else { // not maximizing player

            /* compute legal moves */
            if (depthInit <= 0){
                legPaB2(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, n, occupied, blackPieces) ;
                sliderD2(moves, b, blackPieces, occupied) ;
                sliderCD2(moves, b, blackPieces, occupied) ;
                sliderHV2(moves, q, blackPieces, occupied) ;
                sliderD2(moves, q, blackPieces, occupied) ;
                sliderCD2(moves, q, blackPieces, occupied) ;
                sliderHV2(moves, r, blackPieces, occupied) ;
                KingMoves2(moves, k, blackPieces, occupied) ;
                
                minEval = EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;
                

            } else {
                legPaB(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, n, blackPieces) ;
                sliderD(moves, b, blackPieces, occupied) ;
                sliderCD(moves, b, blackPieces, occupied) ;
                sliderHV(moves, q, blackPieces, occupied) ;
                sliderD(moves, q, blackPieces, occupied) ;
                sliderCD(moves, q, blackPieces, occupied) ;
                sliderHV(moves, r, blackPieces, occupied) ;
                KingMoves(moves, k, r,  blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
                minEval = intINFINITY ;
            }



            /*______________________*/


            /*for (int movInd = 0 ; movInd < moves.size() ; movInd++)
            {
                moves2.push_back(moves[movInd]) ;
            }*/


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            // captInd5 = 0 ;
            for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&whitePieces){
                    temp1 = moves[2*captInd] ;
                    temp2 = moves[2*captInd+1] ;
                    moves[2*captInd] = moves[2*semInd] ;
                    moves[2*captInd+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q|R|N|B)){
                    temp1 = moves[2*captInd2] ;
                    temp2 = moves[2*captInd2+1] ;
                    moves[2*captInd2] = moves[2*semInd] ;
                    moves[2*captInd2+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd2 +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q|R)){
                    temp1 = moves[2*captInd3] ;
                    temp2 = moves[2*captInd3+1] ;
                    moves[2*captInd3] = moves[2*semInd] ;
                    moves[2*captInd3+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd3 +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q)){
                    temp1 = moves[2*captInd4] ;
                    temp2 = moves[2*captInd4+1] ;
                    moves[2*captInd4] = moves[2*semInd] ;
                    moves[2*captInd4+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd4 +=1 ;
                }
            }
            // for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
            //     destInt = 1 ;
            //     dest = moves[2*semInd+1] ;
            //     destInt <<= dest ;
            //     if (destInt&(K)){
            //         temp1 = moves[2*captInd5] ;
            //         temp2 = moves[2*captInd5+1] ;
            //         moves[2*captInd5] = moves[2*semInd] ;
            //         moves[2*captInd5+1] = moves[2*semInd+1] ;
            //         moves[2*semInd] = temp1 ;
            //         moves[2*semInd+1] = temp2 ;

            //         captInd5 +=1 ;
            //     }
            // }


            // minEval = intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            unsigned long long int tempForbCstlS2 = forbCstlS ;
            unsigned long long int tempForbCstlL2 = forbCstlL ;
            unsigned long long int tempForbcstlS2 = forbcstlS ;
            unsigned long long int tempForbcstlL2 = forbcstlL ;

            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;
                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote,pieceCaptured) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    std::cout << "done move" << std::endl ;
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cin >> nothing ;}*/
                if (/*((depth == 2)||*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }



                eval = minimax(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,tempForbCstlS,tempForbCstlL,tempForbcstlS,tempForbcstlL, tempSuffix, depthInit-1,depth-1,veryMaxDepth-1,alpha,beta,true, moveNb+1) ;
                //ump.insert(std::pair<unsigned long long int, int>(zobKey, eval));

                tempForbCstlL = tempForbCstlL2 ;
                tempForbcstlL = tempForbcstlL2 ;
                tempForbCstlS = tempForbCstlS2 ;
                tempForbcstlS = tempForbcstlS2 ;

                if (eval < minEval){

                    tempVariante = {position, destination} ;
                    tempVariante.insert(tempVariante.end(), tempSuffix.begin(), tempSuffix.end());
                    tempSuffix.clear() ;

                }

                if (depthIncreased){
                    depth -= 1 ;
                }

                enPassant = tempEnPassant ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    std::cin >> nothing ;}*/

                minEval =  std::min(minEval,eval) ;
                beta = std::min(beta,eval) ;
                if ( beta <= alpha ){
                    // if (verbose){
                    // std::cout << "Beta <= alpha : break" << std::endl ;
                    // std::cin >> nothing ;
                    // }
                    break ;
                }
            }
            rootVariant = tempVariante ;
            return minEval ;
    }
}
        


int minimax2(unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P,
        bool & CstlL, bool & CstlS , bool & cstlL , bool & cstlS, unsigned long long int & enPassant,
        unsigned long long int & forbCstlS, unsigned long long int & forbCstlL,
        unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        unsigned long long int & tempForbCstlS, unsigned long long int & tempForbCstlL,
        unsigned long long int & tempForbcstlS, unsigned long long int & tempForbcstlL,
        std::vector<int>& rootVariant,
        int depthInit, int depth, int veryMaxDepth, int alpha, int beta, bool maximizingPlayer, int moveNb){




        if (((R|N|B|Q|K|P)&(tempForbcstlS|tempForbcstlL))){
            //std::cout<<"*" ;
            return 10020 ;
        }
        if (((r|n|b|q|k|p)&(tempForbCstlS|tempForbCstlL))){
            //std::cout<<"." ;
            return -10020 ;
        }




        /*unsigned long long int zobKey ;
        zobKey = ZobristHash(r,n,b,q,k,p,R,N,B,Q,K,P,CstlS,CstlL,cstlS,cstlL, maximizingPlayer) ;

        it = ump.find(zobKey); //Finding an element

        if(it != ump.end()){
            return it->second ;
        }*/






        if ( ( depth == 0 ) || ( veryMaxDepth == 0 )){
            return EvalFunction2(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;

        }

        if (k == 0){
            // rootVariant.clear() ;
            return 10000 + veryMaxDepth ;
        }
        if (K == 0){
            // rootVariant.clear() ;
            return -10000 - veryMaxDepth ;
        }

        std::string nothing ;

        std::vector<int> moves ;


        std::vector<int> tempSuffix ;
        std::vector<int> tempVariante ;

        unsigned long long int tempEnPassant;
        // unsigned long long int tempForbCstlS;
        // unsigned long long int tempForbCstlL;
        // unsigned long long int tempForbcstlS;
        // unsigned long long int tempForbcstlL;

        if ( ( depth == 0 ) || ( veryMaxDepth == 0 )){
            return EvalFunction2(r,n,b,q,k,p,R,N,B,Q,K,P, moveNb) ;

        }

        if (k == 0){
            rootVariant.clear() ;
            return 10000 + veryMaxDepth ;
        }
        if (K == 0){
            rootVariant.clear() ;
            return -10000 - veryMaxDepth ;
        }

        // std::string nothing ;

        // std::vector<int> moves ;


        // std::vector<int> tempSuffix ;
        // std::vector<int> tempVariante ;

        // unsigned long long int tempEnPassant;


        bool brokeCastleL = false ;
        bool brokeCastleS = false ;
        bool brokecastleL = false ;
        bool brokecastleS = false ;


        // bool verbose = false ;

        //std::cout << "in minimax " << std::endl ;
        //std::cout << "maximizingPlayer = " << maximizingPlayer << std::endl ;
        //std::cin >> nothing ;
        unsigned long long int whitePieces = R | N | B | Q | K | P ;
        unsigned long long int blackPieces = r | n | b | q | k | p ;
        unsigned long long int occupied = whitePieces | blackPieces ;

        int pieceCaptured  ;
        bool wasCastle  ;
        bool wasPromote  ;

        int position ;
        int destination ;


        int maxEval (0) ;
        int minEval (0) ;
        int eval (0) ;

        bool depthIncreased ;

        //move ordering
        int captInd =0 ;
        int captInd2 =0 ;
        int captInd3 =0 ;
        int captInd4 =0 ;
        // int captInd5 =0 ;
        int dest = 0 ;
        unsigned long long int destInt  = 1;
        int temp1 = 0;
        int temp2 = 0;

        //std::vector<int> moves2 ;


        if (maximizingPlayer){

            if (depthInit <= 0){
                
                legPaW2(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, N,occupied,whitePieces) ;
                sliderD2(moves, B, whitePieces, occupied) ;
                sliderCD2(moves, B, whitePieces, occupied) ;
                sliderHV2(moves, Q, whitePieces, occupied) ;
                sliderD2(moves, Q, whitePieces, occupied) ;
                sliderCD2(moves, Q, whitePieces, occupied) ;
                sliderHV2(moves, R, whitePieces, occupied) ;
                KingMoves2(moves, K, whitePieces, occupied) ;
                maxEval = EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;
                

            } else {
                legPaW(moves, P, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, N, whitePieces) ;
                sliderD(moves, B, whitePieces, occupied) ;
                sliderCD(moves, B, whitePieces, occupied) ;
                sliderHV(moves, Q, whitePieces, occupied) ;
                sliderD(moves, Q, whitePieces, occupied) ;
                sliderCD(moves, Q, whitePieces, occupied) ;
                sliderHV(moves, R, whitePieces, occupied) ;
                KingMoves(moves, K, R,  whitePieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
                maxEval = - intINFINITY ;
            }


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            // captInd5 = 0 ;
            for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&blackPieces){
                    temp1 = moves[2*captInd] ;
                    temp2 = moves[2*captInd+1] ;
                    moves[2*captInd] = moves[2*semInd] ;
                    moves[2*captInd+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q|r|n|b)){
                        temp1 = moves[2*captInd2] ;
                        temp2 = moves[2*captInd2+1] ;
                        moves[2*captInd2] = moves[2*semInd] ;
                        moves[2*captInd2+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd2 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q|r)){
                        temp1 = moves[2*captInd3] ;
                        temp2 = moves[2*captInd3+1] ;
                        moves[2*captInd3] = moves[2*semInd] ;
                        moves[2*captInd3+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd3 +=1 ;
                    }
                }
                for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                    destInt = 1 ;
                    dest = moves[2*semInd+1] ;
                    destInt <<= dest ;
                    if (destInt&(k|q)){
                        temp1 = moves[2*captInd4] ;
                        temp2 = moves[2*captInd4+1] ;
                        moves[2*captInd4] = moves[2*semInd] ;
                        moves[2*captInd4+1] = moves[2*semInd+1] ;
                        moves[2*semInd] = temp1 ;
                        moves[2*semInd+1] = temp2 ;

                        captInd4 +=1 ;
                    }
                }
                // }
                // for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
                //     destInt = 1 ;
                //     dest = moves[2*semInd+1] ;
                //     destInt <<= dest ;
                //     if (destInt&(k)){
                //         temp1 = moves[2*captInd5] ;
                //         temp2 = moves[2*captInd5+1] ;
                //         moves[2*captInd5] = moves[2*semInd] ;
                //         moves[2*captInd5+1] = moves[2*semInd+1] ;
                //         moves[2*semInd] = temp1 ;
                //         moves[2*semInd+1] = temp2 ;

                //         captInd5 +=1 ;
                //     }
                // }



            //maxEval = - intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            unsigned long long int tempForbCstlS2 = forbCstlS ;
            unsigned long long int tempForbCstlL2 = forbCstlL ;
            unsigned long long int tempForbcstlS2 = forbcstlS ;
            unsigned long long int tempForbcstlL2 = forbcstlL ;

            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;
                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P, enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote, pieceCaptured) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                if (/*((depth == 2)||*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }

                eval = minimax2(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,tempForbCstlS,tempForbCstlL,tempForbcstlS,tempForbcstlL, tempSuffix, depthInit-1,depth-1, veryMaxDepth-1, alpha,beta,false, moveNb+1) ;
                tempForbCstlL = tempForbCstlL2 ;
                tempForbcstlL = tempForbcstlL2 ;
                tempForbCstlS = tempForbCstlS2 ;
                tempForbcstlS = tempForbcstlS2 ;

                if (eval > maxEval){
                    tempVariante = {position, destination} ;
                    tempVariante.insert(tempVariante.end(), tempSuffix.begin(), tempSuffix.end() );
                    tempSuffix.clear() ;
                }


                if (depthIncreased){
                    depth -= 1 ;
                }

                enPassant = tempEnPassant ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;

                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    std::cin >> nothing ;}*/

                maxEval = std::max(maxEval,eval) ;
                alpha = std::max(alpha, eval) ;
                if (beta <= alpha) {
                    break ;
                }
            }
            rootVariant = tempVariante ;
            return maxEval ;
        }



        else { // not maximizing player

            /* compute legal moves */
            if (depthInit <= 0){
                legPaB2(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves2(moves, n, occupied, blackPieces) ;
                sliderD2(moves, b, blackPieces, occupied) ;
                sliderCD2(moves, b, blackPieces, occupied) ;
                sliderHV2(moves, q, blackPieces, occupied) ;
                sliderD2(moves, q, blackPieces, occupied) ;
                sliderCD2(moves, q, blackPieces, occupied) ;
                sliderHV2(moves, r, blackPieces, occupied) ;
                KingMoves2(moves, k, blackPieces, occupied) ;
                
                minEval = EvalFunction(r,n,b,q,k,p,R,N,B,Q,K,P,moveNb) ;
                

            } else {
                legPaB(moves, p, whitePieces, blackPieces, occupied, enPassant) ;
                KnightMoves(moves, n, blackPieces) ;
                sliderD(moves, b, blackPieces, occupied) ;
                sliderCD(moves, b, blackPieces, occupied) ;
                sliderHV(moves, q, blackPieces, occupied) ;
                sliderD(moves, q, blackPieces, occupied) ;
                sliderCD(moves, q, blackPieces, occupied) ;
                sliderHV(moves, r, blackPieces, occupied) ;
                KingMoves(moves, k, r,  blackPieces, occupied, CstlL, CstlS, cstlL, cstlS) ;
                minEval = intINFINITY ;
            }



            /*______________________*/


            /*for (int movInd = 0 ; movInd < moves.size() ; movInd++)
            {
                moves2.push_back(moves[movInd]) ;
            }*/


            captInd = 0 ;
            captInd2 = 0 ;
            captInd3 = 0 ;
            captInd4 = 0 ;
            // captInd5 = 0 ;
            for (int semInd = 0 ; semInd < moves.size()/2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&whitePieces){
                    temp1 = moves[2*captInd] ;
                    temp2 = moves[2*captInd+1] ;
                    moves[2*captInd] = moves[2*semInd] ;
                    moves[2*captInd+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q|R|N|B)){
                    temp1 = moves[2*captInd2] ;
                    temp2 = moves[2*captInd2+1] ;
                    moves[2*captInd2] = moves[2*semInd] ;
                    moves[2*captInd2+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd2 +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd2 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q|R)){
                    temp1 = moves[2*captInd3] ;
                    temp2 = moves[2*captInd3+1] ;
                    moves[2*captInd3] = moves[2*semInd] ;
                    moves[2*captInd3+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd3 +=1 ;
                }
            }
            for (int semInd = 1 ; semInd < captInd3 ; semInd ++){
                destInt = 1 ;
                dest = moves[2*semInd+1] ;
                destInt <<= dest ;
                if (destInt&(K|Q)){
                    temp1 = moves[2*captInd4] ;
                    temp2 = moves[2*captInd4+1] ;
                    moves[2*captInd4] = moves[2*semInd] ;
                    moves[2*captInd4+1] = moves[2*semInd+1] ;
                    moves[2*semInd] = temp1 ;
                    moves[2*semInd+1] = temp2 ;

                    captInd4 +=1 ;
                }
            }
            // for (int semInd = 1 ; semInd < captInd4 ; semInd ++){
            //     destInt = 1 ;
            //     dest = moves[2*semInd+1] ;
            //     destInt <<= dest ;
            //     if (destInt&(K)){
            //         temp1 = moves[2*captInd5] ;
            //         temp2 = moves[2*captInd5+1] ;
            //         moves[2*captInd5] = moves[2*semInd] ;
            //         moves[2*captInd5+1] = moves[2*semInd+1] ;
            //         moves[2*semInd] = temp1 ;
            //         moves[2*semInd+1] = temp2 ;

            //         captInd5 +=1 ;
            //     }
            // }


            // minEval = intINFINITY ;
            tempEnPassant = enPassant ;
            tempForbcstlS = forbcstlS ;
            tempForbcstlL = forbcstlL ;
            tempForbCstlS = forbCstlS ;
            tempForbCstlL = forbCstlL ;
            unsigned long long int tempForbCstlS2 = forbCstlS ;
            unsigned long long int tempForbCstlL2 = forbCstlL ;
            unsigned long long int tempForbcstlS2 = forbcstlS ;
            unsigned long long int tempForbcstlL2 = forbcstlL ;

            for (int semIdx = 0 ; semIdx < moves.size()/2 ; semIdx++){
                pieceCaptured = 0 ;
                wasCastle = false ;
                wasPromote = false ;
                depthIncreased = false ;
                brokeCastleL = false ;
                brokeCastleS = false ;
                brokecastleL = false ;
                brokecastleS = false ;

                position = moves[2*semIdx] ;
                destination = moves[2*semIdx+1] ;
                Do_move(position,destination,CstlL,CstlS,cstlL,cstlS,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,r,n,b,q,k,p,R,N,B,Q,K,P,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,wasCastle, wasPromote,pieceCaptured) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    std::cout << "done move" << std::endl ;
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cin >> nothing ;}*/
                if (/*((depth == 2)||*/(depth == 1) && (pieceCaptured != 0)){
                    depth += 1 ;
                    depthIncreased = true ;
                }



                eval = minimax2(r,n,b,q,k,p,R,N,B,Q,K,P,CstlL,CstlS,cstlL,cstlS,enPassant,forbCstlS,forbCstlL,forbcstlS,forbcstlL,tempForbCstlS,tempForbCstlL,tempForbcstlS,tempForbcstlL, tempSuffix, depthInit-1,depth-1,veryMaxDepth-1,alpha,beta,true, moveNb+1) ;
                //ump.insert(std::pair<unsigned long long int, int>(zobKey, eval));

                tempForbCstlL = tempForbCstlL2 ;
                tempForbcstlL = tempForbcstlL2 ;
                tempForbCstlS = tempForbCstlS2 ;
                tempForbcstlS = tempForbcstlS2 ;

                if (eval < minEval){

                    tempVariante = {position, destination} ;
                    tempVariante.insert(tempVariante.end(), tempSuffix.begin(), tempSuffix.end());
                    tempSuffix.clear() ;

                }

                if (depthIncreased){
                    depth -= 1 ;
                }

                enPassant = tempEnPassant ;
                forbcstlS = tempForbcstlS ;
                forbcstlL = tempForbcstlL ;
                forbCstlS = tempForbCstlS ;
                forbCstlL = tempForbCstlL ;
                Undo_move(position,destination,brokeCastleS,brokeCastleL,brokecastleS,brokecastleL,wasCastle, wasPromote,pieceCaptured,CstlL,CstlS,cstlL,cstlS,r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                // std::cin >> nothing ;
                /*if (verbose){
                    coutBoard(r,n,b,q,k,p,R,N,B,Q,K,P) ;
                    std::cout << "undone move in minimax" << std::endl ;
                    std::cin >> nothing ;}*/

                minEval =  std::min(minEval,eval) ;
                beta = std::min(beta,eval) ;
                if ( beta <= alpha ){
                    // if (verbose){
                    // std::cout << "Beta <= alpha : break" << std::endl ;
                    // std::cin >> nothing ;
                    // }
                    break ;
                }
            }
            rootVariant = tempVariante ;
            return minEval ;
    }
}
        


