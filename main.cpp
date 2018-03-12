#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <mutex>
//#include <condition_variable>

using namespace std;

mutex pantalla;
//condition_variable mut;

void tarea(int inicio, int fin);

void sleep(int s) {
    clock_t begin;
    begin = clock();
    double elapsed_secs = 0;

    while (elapsed_secs < s) {
        elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;
    }
}

void hola() {

    for (int i = 0; i < 5; i++) {
        std::cout << "Hola " << i << std::endl;
        sleep(2);
    }
}


bool esPrimo(unsigned int num) {
    for (unsigned int i = 2; i <= (num / 2); i++)
        if (num % i == 0)
            return false;


    return true;
}

#define CANT_HILOS 30

int main() {
    vector<thread> h;
    unsigned int inicio = 2;
    unsigned int fin = 300000;
    unsigned int intervalo = (fin - inicio) / CANT_HILOS;

    //lock_guard<mutex> lk(pantalla);

    for (int j = 0; j < CANT_HILOS; j++) {
        h.emplace_back(tarea, inicio + intervalo * j, inicio + intervalo * (j + 1) - 1);
    }
    for (auto &actual : h)
        actual.join();
    //mut.notify_one();


    return 0;
}

void tarea(int inicio, int fin) {
    //unique_lock<mutex> lk(pantalla);

    for (int i = inicio; i < fin; i++)
        if (esPrimo(i)) {
            pantalla.lock();
            std::cout << i << std::endl;
            pantalla.unlock();
        }
}