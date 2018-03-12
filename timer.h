//
// Created by Alumno on 12/03/2018.
//

#ifndef CONCURRENCY_TIMER_H
#define CONCURRENCY_TIMER_H
#include<ctime>
#include <iostream>

class timer {

public:
    void begin();
    void end();
    void show();

private:
    clock_t inicio;
    clock_t fin;
};



#endif //CONCURRENCY_TIMER_H
