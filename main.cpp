#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <time.h>
#include "definitions.h"
#include "Trainer.h"

using namespace std;

int main()
{
    Trainer t;
    cout << "OK" << endl;
    t.set_data(or_gate);
    cout << t.learn(10000, false) << endl;
    
    // let's see how well we predict
    cout << t.prediction() << endl;;

    return 0;
}

