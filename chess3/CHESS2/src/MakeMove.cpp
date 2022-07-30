#include "MakeMove.h"
#include "coutBoard.h"
#include <iostream>
#include <unistd.h>
#include <vector>



/*void isEnPassant(std::pair<int,int>& lastMove, unsigned long long int & enPassant, unsigned long long int & P,
                 bool whiteJstPlayed){

    bool updated (false) ;

    if ((P>>lastMove.second)&1){
        if ((whiteJstPlayed) && (24 <= lastMove.second <= 31)){
            int enPassantIdx = lastMove.second - 8 ;
            enPassant = 1 ;
            enPassant <<= enPassantIdx ;
            updated = true ;
        }

        if ((!whiteJstPlayed) && (32 <= lastMove.second <= 39)){
            int enPassantIdx = lastMove.second + 8 ;
            enPassant = 1 ;
            enPassant <<= enPassantIdx ;
            updated = true ;
        }
    }

    if (!updated) {
        enPassant = 0 ;
    }
}*/

void Do_move(int pos, int dest, bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        bool & brokeCastleS, bool & brokeCastleL, bool & brokecastleS, bool & brokecastleL,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,unsigned long long int & R,
        unsigned long long int & N,unsigned long long int & B,unsigned long long int & Q,unsigned long long int & K,
        unsigned long long int & P, unsigned long long int & enPassant, unsigned long long int & forbCstlS,
        unsigned long long int & forbCstlL, unsigned long long int & forbcstlS, unsigned long long int & forbcstlL,
        bool & wasCastle, bool & wasPromote, int & pieceCaptured){

    //piece captured : aucune - rnbqkpRNBQKP
    //int : 0 - 1-2-3-4-5-6-7-8-9-10-11-12

    enPassant = 0 ;
    forbCstlS = 0 ;
    forbCstlL = 0 ;
    forbcstlS = 0 ;
    forbcstlL = 0 ;

    std::string nothing ;


    unsigned long long int posInt (1) ;
    unsigned long long int destInt (1) ;

    posInt <<= pos ;
    destInt <<= dest ;

    //enlever la pièce sur capture

    if (r>>dest&1){
        r -= destInt ;
        pieceCaptured = 1 ;

    } else {

    if (n>>dest&1){
        n -= destInt ;
        pieceCaptured = 2 ;

    } else {

    if (b>>dest&1){
        b -= destInt ;
        pieceCaptured = 3 ;

    } else {

    if (q>>dest&1){
        q -= destInt ;
        pieceCaptured = 4 ;

    } else {

    if (k>>dest&1){
        k -= destInt ;
        pieceCaptured = 5 ;

    } else {

    if (p>>dest&1){
        p -= destInt ;
        pieceCaptured = 6 ;

    } else {

    if (R>>dest&1){
        R -= destInt ;
        pieceCaptured = 7 ;

    } else {

    if (N>>dest&1){
        N -= destInt ;
        pieceCaptured = 8 ;

    } else {

    if (B>>dest&1){
        B -= destInt ;
        pieceCaptured = 9 ;

    } else {

    if (Q>>dest&1){
        Q -= destInt ;
        pieceCaptured = 10 ;

    } else {

    if (K>>dest&1){
        K -= destInt ;
        pieceCaptured = 11 ;

    } else {

    if (P>>dest&1){
        P -= destInt ;
        pieceCaptured = 12 ;
    }

    else { //en passant
        if (( dest == pos + 7 ) && (P>>pos&1)){ //prise avant droit
            destInt = 1 ;
            destInt <<= pos-1 ; //à droite de 1
            p -= destInt ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos + 9 ) && (P>>pos&1)){
            destInt = 1 ;
            destInt <<= pos+1 ;
            p -= destInt ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos - 7 ) && (p>>pos&1)){
            destInt = 1 ;
            destInt <<= pos+1 ;
            P -= destInt ;
            destInt = 1 ;
            destInt <<= dest ;
        } else {

        if (( dest == pos - 9 ) && (p>>pos&1)){
            destInt = 1 ;
            destInt <<= pos-1 ;
            P -= destInt ;
            destInt = 1 ;
            destInt <<= dest ;
        }}}}
    }

    }}}}}}}}}}}

    //promotion
    if ((pos/8 == 6)&&(P>>pos&1)){
        wasPromote = true ;
        P -= posInt ;
        Q += destInt ;
    } else {

    if ((pos/8 == 1)&&(p>>pos&1)){
        wasPromote = true ;
        p -= posInt ;
        q += destInt ;
    } else {


    //castle
    if ((pos==3)&&(dest==1)&&(K>>pos&1)&&(R&1)&&CstlS){ //white short

        wasCastle = true ;
        forbCstlS = 12 ;
        K = K - posInt + destInt ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 0 ;
        destInt <<= 2 ;


        R = R - posInt + destInt ;

        //CstlS = false ;

    } else {

    if ((pos==3)&&(dest==5)&&(K>>pos&1)&&(R>>7&1)&&CstlL){ //white long
        wasCastle = true ;
        forbCstlL = 24 ;
        K = K - posInt + destInt ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 7 ;
        destInt <<= 4 ;
        R = R - posInt + destInt ;

        //CstlL = false ;

    } else {

    if ((pos==59)&&(dest==57)&&(k>>pos&1)&&(r>>56&1)&&cstlS){ //black short
        wasCastle = true ;
        forbcstlS = 864691128455135232 ;
        k = k - posInt + destInt ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 56 ;
        destInt <<= 58 ;
        r = r - posInt + destInt ;

        //cstlS = false ;

    } else {

    if ((pos==59)&&(dest==61)&&(k>>pos&1)&&(r>>63&1)&&cstlL){ //black long
        wasCastle = true ;
        forbcstlL = 1729382256910270464 ;
        k = k - posInt + destInt ;
        posInt = 1 ;
        destInt = 1 ;
        posInt <<= 63 ;
        destInt <<= 60 ;
        r = r - posInt + destInt ;

        //cstlL = false ;

    } else {


    if (r>>pos&1){
        if(pos == 56){
            brokecastleS = cstlS ;
            cstlS = false ;
        }
        if(pos == 63){
            brokecastleL = cstlL ;
            cstlL = false ;
        }
        r -= posInt ;
        r += destInt ;

    } else {

    if (n>>pos&1){
        n -= posInt ;
        n += destInt ;

    } else {

    if (b>>pos&1){
        b -= posInt ;
        b += destInt ;

    } else {

    if (q>>pos&1){
        q -= posInt ;
        q += destInt ;

    } else {

    if (k>>pos&1){

        k -= posInt ;
        k += destInt ;

        brokecastleL = cstlL ;
        brokecastleS = cstlS ;

        cstlL = false ;
        cstlS = false ;

    } else {

    if (p>>pos&1){
        p -= posInt ;
        p += destInt ;

        if (dest == pos-16){
            enPassant = 1 ;
            enPassant <<=(pos-8) ;

        }

    } else {

    if (R>>pos&1){
        R -= posInt ;
        R += destInt ;

        if(pos == 0){
            brokeCastleS = CstlS ;
            CstlS = false ;
        }
        if(pos == 7){
            brokeCastleL = CstlL ;
            CstlL = false ;
        }

    } else {

    if (N>>pos&1){
        N -= posInt ;
        N += destInt ;

    } else {

    if (B>>pos&1){
        B -= posInt ;
        B += destInt ;

    } else {

    if (Q>>pos&1){
        Q -= posInt ;
        Q += destInt ;

    } else {

    if (K>>pos&1){
        K -= posInt ;
        K += destInt ;

        brokeCastleL = CstlL ;
        brokeCastleS = CstlS ;

        CstlL = false ;
        CstlS = false ;

    } else {

    if (P>>pos&1){
        P -= posInt ;
        P += destInt ;

        if (dest == pos+16){
            enPassant = 1 ;
            enPassant <<=(pos+8) ;
        }
    }

    }}}}}}}}}}}}}}}}}
}

void Undo_move(int wasPos, int wasDest, bool brokeCastleS, bool brokeCastleL, bool brokecastleS, bool brokecastleL,
        bool wasCastle, bool wasPromote, int pieceCaptured,
        bool & CstlL, bool & CstlS, bool & cstlL, bool & cstlS,
        unsigned long long int & r,unsigned long long int & n,unsigned long long int & b,
        unsigned long long int & q,unsigned long long int & k,unsigned long long int & p,
        unsigned long long int & R,unsigned long long int & N,unsigned long long int & B,
        unsigned long long int & Q,unsigned long long int & K,unsigned long long int & P){

    std::string nothing ;



    //piece captured : aucune - rnbqkpRNBQKP
    //int : 0 - 1-2-3-4-5-6-7-8-9-10-11-12

    if (brokeCastleL){
        CstlL = true ;
        //std::cout << "CL" << std::endl ;

    }

    if (brokecastleL){
        cstlL = true ;

        //std::cout << "cL" << std::endl ;


    }

    if (brokeCastleS){
        CstlS = true ;
        //std::cout << "CS" << std::endl ;

    }

    if (brokecastleS){
        cstlS = true ;
        //std::cout << "cS" << std::endl ;

    }

    unsigned long long int wasDestInt (1) ;
    unsigned long long int wasPosInt (1) ;
    unsigned long long int temPassant (1) ;


    if (wasPromote){

        //std::cout << "in promote, " << std::endl ;
        //std::cin >> nothing ;

        wasDestInt = wasDestInt <<= wasDest ;
        wasPosInt = wasPosInt <<= wasPos ;

        if (wasDest/8 == 7){
            Q -= wasDestInt ;
            P += wasPosInt ;
        } else {

        if (wasDest/8 == 0){
            q -= wasDestInt ;
            p += wasPosInt ;
        }}

    } else {

    if (wasCastle){

        if (wasDest == 1){

            wasDestInt <<= 1;
            wasPosInt <<= 3;



            K = K - wasDestInt + wasPosInt ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 2;
            //wasPosInt <<= 0;



            R = R - wasDestInt + wasPosInt ;


        } else {
        if (wasDest == 5){

            wasDestInt <<= 5;
            wasPosInt <<= 3;

            K = K - wasDestInt + wasPosInt ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 4;
            wasPosInt <<= 7;

            R = R - wasDestInt + wasPosInt ;

        } else {

        if (wasDest == 57){

            wasDestInt <<= 57;
            wasPosInt <<= 59;

            k = k - wasDestInt + wasPosInt ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 58;
            wasPosInt <<= 56;

            r = r - wasDestInt + wasPosInt ;

        } else {
        if (wasDest == 61){

            wasDestInt <<= 61;
            wasPosInt <<= 59;

            k = k - wasDestInt + wasPosInt ;

            wasDestInt = 1 ;
            wasPosInt = 1 ;

            wasDestInt <<= 60;
            wasPosInt <<= 63;

            r = r - wasDestInt + wasPosInt ;

        }}}}}

        else {


    wasDestInt = wasDestInt <<= wasDest ;
    wasPosInt = wasPosInt <<= wasPos ;

    //std::cout << "destint = " << std::endl ;
    //coutBitSet(wasDestInt) ;

    //std::cout << "posint = " << std::endl ;
    //coutBitSet(wasPosInt) ;



    /*std::cout << "wasDestInt = " << std::endl;
    coutBitSet(wasDestInt) ;
    std::cout << "wasPosInt = " << std::endl;
    coutBitSet(wasPosInt) ;*/

    if (r>>wasDest&1){
        r = r - wasDestInt + wasPosInt ;
    } else {

    if (n>>wasDest&1){
        n = n - wasDestInt + wasPosInt ;
    } else {

    if (b>>wasDest&1){
        b = b - wasDestInt + wasPosInt ;
    } else {

    if (q>>wasDest&1){
        q = q - wasDestInt + wasPosInt ;
    } else {

    if (k>>wasDest&1){
        k = k - wasDestInt + wasPosInt ;
    } else {

    if (p>>wasDest&1){

        if ((wasDest == wasPos-7) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos+1) ;
            P+=temPassant ;


        }
        if ((wasDest == wasPos-9) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos-1) ;
            P+=temPassant ;

        }
        p = p - wasDestInt + wasPosInt ;
    } else {

    if (R>>wasDest&1){
        R = R - wasDestInt + wasPosInt ;
    } else {

    if (N>>wasDest&1){
        N = N - wasDestInt + wasPosInt ;
    } else {

    if (B>>wasDest&1){
        B = B - wasDestInt + wasPosInt ;
    } else {

    if (Q>>wasDest&1){
        //std::cout << "queen in dest " << std::endl ;
        //std::cin >> nothing ;
        Q = Q - wasDestInt + wasPosInt ;
    } else {

    if (K>>wasDest&1){
        K = K - wasDestInt + wasPosInt ;
    } else {

    if (P>>wasDest&1){
        P = P - wasDestInt + wasPosInt ;
        if ((wasDest == wasPos+7) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos-1) ;
            p+=temPassant ;

        }
        if ((wasDest == wasPos+9) && (pieceCaptured == 0)){ // enPassant
            temPassant <<= (wasPos+1) ;
            p+=temPassant ;

        }
    }


    }}}}}}}}}}}}}

    if (pieceCaptured != 0){
        //std::cout << "In Undo_move, pieceCaptured = " << pieceCaptured << std::endl ;
        switch(pieceCaptured){
            case 1 :
                r += wasDestInt ;
                break ;
            case 2 :
                n += wasDestInt ;
                break ;
            case 3 :
                b += wasDestInt ;
                break ;
            case 4 :
                q += wasDestInt ;
                break ;
            case 5 :
                k += wasDestInt ;
                break ;
            case 6 :
                p += wasDestInt ;
                break ;
            case 7 :
                R += wasDestInt ;
                break ;
            case 8 :
                N += wasDestInt ;
                break ;
            case 9 :
                B += wasDestInt ;
                break ;
            case 10 :
                Q += wasDestInt ;
                break ;
            case 11 :
                K += wasDestInt ;
                break ;
            case 12 :
                P += wasDestInt ;
                break ;
        }
    }
}
