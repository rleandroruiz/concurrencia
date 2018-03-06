#include <iostream>
#include <thread>
#include <ctime>


void sleep( int s){
    clock_t begin;
    begin = clock();
    double elapsed_secs=0;

    while(elapsed_secs < s){
        elapsed_secs = double(clock() - begin) / CLOCKS_PER_SEC;
    }
}

void hola(){

    for(int i = 0; i< 5; i++) {
        std::cout << "Hola " << i << std::endl;
        sleep(2);
    }
}


int main() {
    std::thread hilo(hola);
    hilo.detach();

    for(int i = 0; i< 10; i++){

        std::cout << "Chau " << i << std::endl;
        sleep(1);
    }


    return 0;
}