//
// Created by Alumno on 12/03/2018.
//

#include "timer.h"

void timer::begin(){
    inicio = clock();
}

void timer::end(){
    fin = clock();
}

void timer::show(){
    std::cout << "El tiempo es: " << fin - inicio << std::endl;
}
