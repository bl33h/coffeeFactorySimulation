/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: CoffeeFactorySimulation
@version: I
Creation: 06/09/2022
Last modification: 09/09/2022
------------------------------------------------------------------------------*/
// Imports
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <math.h>
#include <errno.h>
#include <sys/wait.h>
#include <cstdint>
#include <sstream>
#include <fstream>

// Namespace
using namespace std;

// --- Mutex lock ---
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Counter
int counter;

// --- Structure for the coffee control ---
struct coffeeControl{
    int coffeeByToaster = 0;
    int coffeeInStorage = 0;
    int coffeeContainer = 0;
};

// --- First toaster method ---
void *toaster(void *coffeeBags)
{
    coffeeControl *coffeeStructure = (coffeeControl*) coffeeBags; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"The first toaster has produced: 1 toasted coffee pound."<<endl;
    coffeeStructure->coffeeByToaster += 1;
    // *Mutex Unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Second toaster method ---
void *toaster2(void *coffeeBags)
{
    coffeeControl *coffeeStructure = (coffeeControl*) coffeeBags; // *Structure call
    // *Mutex loc*
    pthread_mutex_lock(&lock);
    cout<<"The second toaster has produced: 1 toasted coffee pound."<<endl;
    coffeeStructure->coffeeByToaster += 1;
    // *Mutex unlock*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Baler method ---
void *baler(void *coffeeBags)
{
    coffeeControl *coffeeStructure = (coffeeControl*) coffeeBags; // *Structure call
    // *Mutex lock*
    pthread_mutex_lock(&lock);
    cout<<"Baler has produced: 1 coffee bag of 1 pound."<<endl;
    coffeeStructure->coffeeInStorage += 1;
    cout<<"Coffee pounds in storage: "<<coffeeStructure->coffeeInStorage<<endl;
    // *Mutex onluck*
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return NULL;
}

// --- Main method ---
int main()
{
    double worker;
    bool coffee = false; // *Boolean for the total coffee pounds
    coffeeControl coffeeFactory;
    pthread_t tid[2];
    pthread_attr_t attr;
    cout<<"The coffee production has just started!..."<<endl;
    // *While cycle*
    while(coffee == false){
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
        worker = pthread_create(&tid[0],&attr,toaster2,(void *)&coffeeFactory);
        worker = pthread_join(tid[0],NULL);
        // *First condition*
        if(coffeeFactory.coffeeInStorage == 395)
        {
            coffeeFactory.coffeeByToaster -= 4;
            coffeeFactory.coffeeInStorage = 399;
            coffee = true;
        }
        //*Second condition*
        if((coffeeFactory.coffeeByToaster % 5 == 0)||(coffeeFactory.coffeeByToaster== 5))
        {
            coffeeFactory.coffeeByToaster -= 1;
            cout<<"Coffee pounds in container (silo): "<<coffeeFactory.coffeeByToaster<<endl;
            worker = pthread_create(&tid[2],&attr,baler,(void *)&coffeeFactory);
            worker = pthread_join(tid[2],NULL);
        }
        worker = pthread_create(&tid[1],&attr,toaster,(void *)&coffeeFactory);
        worker = pthread_join(tid[1],NULL);
        sleep(1);
        //*Third condition*
        if(coffeeFactory.coffeeInStorage == 395)
        {
            coffeeFactory.coffeeByToaster -= 4;
            coffeeFactory.coffeeInStorage = 400; // *Final value*
            coffee = true;
        }
        //*Fourth condition*
        if((coffeeFactory.coffeeByToaster % 5 == 0)||(coffeeFactory.coffeeByToaster== 5))
        {
            coffeeFactory.coffeeByToaster -=1;
            cout<<"Coffee pounds in container (silo): "<<coffeeFactory.coffeeByToaster<<endl;
            worker = pthread_create(&tid[2],&attr,baler,(void *)&coffeeFactory);
            worker = pthread_join(tid[2],NULL);
        }
    }
    // *Final print*
    cout<<"Coffee pounds in container (silo): 0"<<endl;
    cout<<"Coffee pounds in storage: 400"<<endl;
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return 0;
}