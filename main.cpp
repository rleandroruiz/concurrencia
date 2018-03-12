#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <mutex>
#include "timer.h"
#include "msg_queue.h"


//#include <condition_variable>

using namespace std;

mutex pantalla;
//condition_variable mut;

typedef struct{
    int inicio;
    int fin;
} par;

msg_queue<par> mensaje;

void tarea(int inicio, int fin);

void sleep(int s) {
    clock_t begin;
    begin = clock();
    double elapsed_secs = 0;

    while (elapsed_secs < s) {
        elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;
    }
}


void tarea();


bool esPrimo(unsigned int num) {
    for (unsigned int i = 2; i <= (num / 2); i++)
        if (num % i == 0)
            return false;

    return true;
}

#define CANT_HILOS 8
#define INTERVALO 500

int main() {
    thread *h[CANT_HILOS];
    timer tiempo;
    par dato;
    unsigned int inicio = 2;
    unsigned int fin = 300000;
    unsigned int intervalo = (fin - inicio) / CANT_HILOS;

    //lock_guard<mutex> lk(pantalla);


    for (int j = 0; j < CANT_HILOS; j++) {
        h[j] = new thread (tarea);
    }
    for(int i = 0; i < CANT_HILOS; i = i + INTERVALO){
        dato.inicio = i;
        dato.inicio = i + INTERVALO - 1;
        mensaje.enqueue(dato);
    }

    tiempo.begin();
    for (auto &actual : h)
        actual->join();
    //mut.notify_one();
    tiempo.end();

    tiempo.show();

    return 0;
}

void tarea() {
    par dato;


    dato = mensaje.dequeue();

    //unique_lock<mutex> lk(pantalla);


    for (int i = dato.inicio; i < dato.fin; i++)
        if (esPrimo(i)) {
            pantalla.lock();
            std::cout << i << std::endl;
            pantalla.unlock();
        }
}