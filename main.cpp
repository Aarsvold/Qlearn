#include <QCoreApplication>
#include "qlearn.h"
#include <time.h>
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //srand(time(0));

    std::ofstream myfile;
    myfile.open("Qlearn.csv", std::ofstream::out | std::ofstream::trunc);
    myfile.close();

    int points;
    double times;
    Qlearning Qlearn;

    for(int i = 0; i<1000; i++){

    int maxReward=0;

    Qlearn.Initialize();
    Qlearn.currentState=Qlearn.ChooseAction(0);
    std::cout << Qlearn.currentState << std::endl;
    Qlearn.prevState=0;
    Qlearn.UpdateReward(Qlearn.currentState,Qlearn.prevState,0,1); //Update reward of choosen action.
    Qlearn.prevState=Qlearn.currentState;


    for(int i=0; i<Qlearn.rSize-2;i++){
        /*points=(std::rand()%(missingM+1);
        std::cout << "marbles" << points << std::endl;
        missingM=missingM-points;
        std::cout << "missingM" << missingM << std::endl;
        points=points*1000; */
        switch (Qlearn.currentState) {
        case 0:
            points=0;
            times=1;
            break;
        case 1:
            times=16;
            points=1000;
            break;
        case 2:
            times=10;
            points=1000;
            break;
        case 3:
            times=30;
            points=1000;
            break;
        case 4:
            times=48;
            points=1000;
            break;
        case 5:
            times=61;
            points=1000;
            break;
        case 6:
            times=27;
            points=1000;
            break;
        case 7:
            times=17;
            points=1000;
            break;
        case 8:
            times=43;
            points=1000;
            break;
        case 9:
            times=12;
            points=1000;
            break;
        case 10:
            times=19;
            points=1000;
            break;
        case 11:
            times=17;
            points=1000;
            break;

        default:
            times=0;
            break;
        }
        //std::cout << "current state:  " << Qlearn.currentState << std::endl;
        Qlearn.currentState=Qlearn.ChooseAction(Qlearn.currentState);
        Qlearn.UpdateReward(Qlearn.currentState,Qlearn.prevState,points, times);
        Qlearn.prevState=Qlearn.currentState;
        maxReward+=Qlearn.rewardV;

        Qlearn.PrintR();
    }
    myfile.open ("Qlearn.csv",std::ofstream::app);
    myfile << maxReward;
    myfile << ",";
    myfile.close();




    std::cout << "maxReward" << maxReward << std::endl;
    Qlearn.Run();
    //Qlearn.PrintRoute();
    }
    std::cout << Qlearn.numRand << std::endl;
}
