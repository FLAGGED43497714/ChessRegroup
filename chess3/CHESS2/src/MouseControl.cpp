#include "MouseControl.h"

#include <Windows.h>
#include <string>
#include <iostream>
#include <unistd.h>

int x,y ;

void ClicSquare(int square){

    x = ( 7 - square%8 ) * 56 + 234 ;
    y = ( 7 - square/8 ) * 56 + 200 ;

    SetCursorPos(x,y) ;

    INPUT Inputs[2] = {0};

    Inputs[0].type = INPUT_MOUSE;
    Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;


    Inputs[1].type = INPUT_MOUSE;
    Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, Inputs, sizeof(INPUT));

}

void RightClicSquare(int square){

    x = ( 7 - square%8 ) * 56 + 234 ;
    y = ( 7 - square/8 ) * 56 + 200 ;

    SetCursorPos(x,y) ;

    INPUT Inputs[2] = {0};

    Inputs[0].type = INPUT_MOUSE;
    Inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;


    Inputs[1].type = INPUT_MOUSE;
    Inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

    SendInput(2, Inputs, sizeof(INPUT));
    // sleep(0.1) ;

}
