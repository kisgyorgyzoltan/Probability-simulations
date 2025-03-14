#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>


using namespace std;

#define iteracio 1000000
#define number_of_threads 16
#define egyenesekkozti_tavolsagok 1
#define tu_hossz 0.5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long long global_osszes_metszet_szama = 0;
double global_pi = 0;

void *szimulacio(void (*arg) ){

    random_device rd;

    mt19937_64 gen(rd());

    uniform_real_distribution<double> dist(0,1);
    uniform_real_distribution<double> dist2(0,M_PI/2);

    double x,y,szog;
    double t,T;
    long long osszes_metszet_szama = 0;
    for(long long i=1;i<=iteracio;i++){
        y= dist(gen);
        szog= dist2(gen);
        t = abs(0.5*sin(szog)*tu_hossz);
        
        T = min(abs(0-y),abs(1-y));

        if(t>=T){
            osszes_metszet_szama++;
        }
    }

   
    pthread_mutex_lock(&mutex);

    global_osszes_metszet_szama += osszes_metszet_szama;

    pthread_mutex_unlock(&mutex);

    return NULL;

}


int main(){

     long long it = iteracio * number_of_threads;
    cout<< "thread_count = "<<number_of_threads<<endl;

    double tmp_pi = 0;
    int j=1;
    while(true){

        pthread_t *threads = new pthread_t[number_of_threads];

        for(int i=0;i<number_of_threads;i++){
            pthread_create(&threads[i],NULL,szimulacio,NULL);
        }

        for(int i=0;i<number_of_threads;i++){
            pthread_join(threads[i],NULL);
        }
        double pi = (2*tu_hossz*it*j)/(global_osszes_metszet_szama*egyenesekkozti_tavolsagok);
        cout << "it:" << it * j  <<" -> pi = "<<fixed<<setprecision(6)<<pi<<endl;
        // if((int)(pi*10000)==31415)
        //     break;
        
        
        j++;
    }
    return 0;
}