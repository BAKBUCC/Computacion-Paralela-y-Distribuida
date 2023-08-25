#include <chrono>
#include <iostream>
#include <sstream>
#include <ctime>

#define MAX 10000 //el tamanio del array

using std::cout;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::system_clock;

int main() {
    double(*A)[MAX] = new double[MAX][MAX];
    double* x = new double[MAX];
    double* y = new double[MAX];



    /*Initialize A and x, assign y = 0*/
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            A[i][j] = 1.0;
    for (int i = 0; i < MAX; i++)
        x[i] = 1.0;
    for (int i = 0; i < MAX; i++)
        y[i] = 0.0;


    auto millisec_start_epoch = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    /*First pair of loops*/
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];
    auto millisec_end_epoch = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    auto t1 = millisec_end_epoch - millisec_start_epoch;

    cout << "first loop: " << t1 << "ns" << endl;

    /*Assign y = 0*/
    for (int i = 0; i < MAX; i++)
        y[i] = 0.0;

    auto millisec_start_epoch1 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    /*Second pair of loops*/
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];
    auto millisec_end_epoch1 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    auto t2 = millisec_end_epoch1 - millisec_start_epoch1;

    cout << "second loop: " << t2 << "ns" << endl;

    delete[] A;
    delete[] x;
    delete[] y;
}
