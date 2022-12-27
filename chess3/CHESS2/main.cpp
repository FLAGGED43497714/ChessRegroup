#include "Game.h"
#include "initBoard.h"
#include "MakeMove.h"
#include "LegalMoves.h"
#include "coutBoard.h"
#include "BitwiseFunction.h"
#include "SqNameToNb.h"
#include "Eval.h"
#include "MouseControl.h"

#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <windows.h>
#include <chrono>





int main()
{  

    char whiteHumanCHAR ;
    bool whiteHuman ;
    bool goodInput = false ; 
    while (!goodInput){
        std::cout << "white Human ? [y,n]" << std::endl ; 
        std::cin >> whiteHumanCHAR ;
        std::cin.ignore() ; 
        if (whiteHumanCHAR == 'y'){
            whiteHuman = 1 ;
            goodInput = true ; 
        } 
        if (whiteHumanCHAR == 'n'){
            whiteHuman = 0 ;
            goodInput = true ; 
        }
    }

    Game(3,11,5,7,whiteHuman) ;

    return 0;
}
