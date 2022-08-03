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

    // int square1, square2, exitnb ;
    // exitnb = system("C:/Users/balth/anaconda3/python.exe ./findDiff.py");

    // square1 = exitnb/64 ;
    // square2 = exitnb%64 ; 

    // for (int i = 0 ; i < 64 ; i++){
    //     RightClicSquare(i) ;
    //     sleep(0.5) ;
    // }


    // std::cout << "python exited " << square1 << " " << square2 << std::endl;
    //std::cout << color << std::endl ;
    //sleep(7) ;   
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

    Game(3,5,4,5,whiteHuman) ;

    
    // unsigned long long int p27 = reverseULL(PawnSqTbW10) ; 
    // std::cout << p27 << std::endl;
    // coutBitSet(28710448241246208) ; 


    // std::cout << "ended" << std::endl ; 
    


    return 0;
}
