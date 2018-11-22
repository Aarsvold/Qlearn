#ifndef QLEARN_H
#define QLEARN_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <string.h>

class Qlearn
{
public:
    Qlearn();
    void episode();
    void chooseAction(int initialState);
    int getRandomAction();
    void initialize();
    int maximum(int state, bool returnIndexOnly, bool temp);
    int reward(int action);
    void getReward(int action);
    void printRtemp();
    void printroute();
    void printR();
    void iterate(int iterations);


    int initialStates[6] = {1, 3, 5, 2, 4, 0};
    int Q[6][6];
    int R[6][6] =  {{-1, 0, 0, 0, 0, 0},
                    {0, -1, 0, 0, 0, 0},
                    {0, 0, -1, 0, 0, 0},
                    {0, 0, 0, -1, 0, 0},
                    {0, 0, 0, 0, -1, 0},
                    {0, 0, 0, 0, 0, -1}};

    int currentState;
private:
    //const int qSize = 6;
    const double gamma = 0.8;
    int newState;
    int rSize=6;
    int RTemp[6][6];
};

#endif // QLEARN_H
