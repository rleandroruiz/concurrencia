//
// Created by Alumno on 12/03/2018.
//
#include<ctime>
#ifndef CONCURRENCY_TIMER_H
#define CONCURRENCY_TIMER_H


class timer {

public:
    clock_t inicio;
    clock_t fin;
    float show();
};


#endif //CONCURRENCY_TIMER_H
