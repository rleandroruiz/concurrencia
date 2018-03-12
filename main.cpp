#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <mutex>

using namespace std;

mutex pantalla;


void tarea(int inicio, int fin);


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



    for (int j = 0; j < CANT_HILOS; j++) {
        h.emplace_back(tarea, inicio + intervalo * j, inicio + intervalo * (j + 1) - 1);
    }

    for (auto &actual : h)
        actual.join();

    return 0;
}

void tarea(int inicio, int fin) {

    for (int i = inicio; i < fin; i++)
        if (esPrimo(i)) {
            pantalla.lock();
            std::cout << i << std::endl;
            pantalla.unlock();
        }
}