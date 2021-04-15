//
// Created by Dawid on 01.04.2021.
//

#ifndef C___FAD_POCHODNE_MIESZANE_FUNKCJA_H
#define C___FAD_POCHODNE_MIESZANE_FUNKCJA_H

#endif //C___FAD_POCHODNE_MIESZANE_FUNKCJA_H


template <typename T>
T funkcja(const T & x, const T & y){
    T wynik = sin(x*x - 2*(y+1))/exp(-y*y+cos(x*y));
//    T wynik = sin((x*x)/y + 10/(x+34) - (-y)/100)    ;
//    T wynik = (-y)/100    ;
//    T wynik = 10/(x+34)   ;
//    T wynik = x+34   ;
//    T wynik = (x+34) /10  ;
//    T wynik = (x*x)/y    ;
//    T wynik = (x*x)/y + 10/(x+34) - (-y)/100    ;

//    T wynik = exp(sin((x*x)/y + 10/(x+34) - (-y)/100))    ;
//    T wynik = cos(exp(sin((x*x)/y + 10/(x+34) - (-y)/100)))    ;
//    T wynik = x*x - 2*(y+1)   ;
    return wynik;

}