//
// Created by Spencer Maslen on 2016-12-02.
//


//Altered from D2l C implementation
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


void convolve(float x[], int N, float h[], int M, float y[], int P)
{  int n, m;  /*  Make sure the output buffer is the right size: P = N + M - 1  */
    if (P != (N + M - 1)) {
        cout << "Output signal vector is the wrong size" << endl;
        cout << "It is " << P << " but should be " << (N+M-1) << endl;
        cout << "Aborting convolution" << endl;
        return;
    }
    /*  Clear the output buffer y[] to all zero values  */
    for (n = 0; n < P; n++)
        y[n] = 0.0;  /*  Do the convolution  */
    /*  Outer loop:  process each input value x[n] in turn  */
    for (n = 0; n < N; n++)
    {    /*  Inner loop:  process x[n] with each sample of h[]  */
        for (m = 0; m < M; m++)
            y[n+m] += x[n] * h[m];
    }
}

