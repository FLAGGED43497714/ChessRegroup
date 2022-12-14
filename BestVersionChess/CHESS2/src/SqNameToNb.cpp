#include "SqNameToNb.h"


#include <iostream>
#include <string>

int SquareNameToNb(std::string SquareName){
    int result (0) ;

    char charNb = SquareName[1] ;

    int nb = charNb - '0' ;

    result += (nb-1) * 8 ;

    switch (SquareName[0]) {
    case 'a' :
        result += 7 ;
        break  ;

    case 'b' :
        result += 6 ;
        break  ;

    case 'c' :
        result += 5 ;
        break  ;

    case 'd' :
        result += 4 ;
        break  ;

    case 'e' :
        result += 3 ;
        break  ;

    case 'f' :
        result += 2 ;
        break  ;

    case 'g' :
        result += 1 ;
        break  ;

    case 'h' :
        break  ;
    }

    return result ;
}


std::string SquareNbtoName(int SquareNb){
    std::string result ("") ;

    switch (SquareNb%8) {
        case -1 :
            result += "hashed" ;
            break ;
        case 0 :
            result += "h" ;
            break  ;
        case 1 :
            result += "g" ;
            break  ;
        case 2 :
            result += "f" ;
            break  ;
        case 3 :
            result += "e" ;
            break  ;
        case 4 :
            result += "d" ;
            break  ;
        case 5 :
            result += "c" ;
            break  ;
        case 6 :
            result += "b" ;
            break  ;
        case 7 :
            result += "a" ;
            break  ;
    }
    switch (SquareNb/8) {
        case 0 :
            result += "1" ;
            break  ;
        case 1 :
            result += "2" ;
            break  ;
        case 2 :
            result += "3" ;
            break  ;
        case 3 :
            result += "4" ;
            break  ;
        case 4 :
            result += "5" ;
            break  ;
        case 5 :
            result += "6" ;
            break  ;
        case 6 :
            result += "7" ;
            break  ;
        case 7 :
            result += "8" ;
            break  ;
        }
        return result ;
    }



