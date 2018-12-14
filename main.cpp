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

    for(int i = 0; i<1; i++){

    int maxReward=0;

    Qlearn.Initialize();
    Qlearn.currentState=Qlearn.ChooseAction(0);
    Qlearn.UpdateReward(0,Qlearn.currentState,0,1); //Update reward of choosen action.
    Qlearn.prevState=0;


    for(int i=0; i<Qlearn.rSize-2;i++){
        points=(std::rand()%20)*100;
        times=100; //std::rand()%100+10;
        switch (Qlearn.currentState) {
        case 0:
            times=1;
            break;
        case 1:
            times=std::rand()%10+10;
            break;
        case 2:
            times=std::rand()%10+10;
            break;
        case 3:
            times=std::rand()%10+50;
            break;
        case 4:
            times=std::rand()%10+30;
            break;
        case 5:
            times=std::rand()%10+10;
            break;
        case 6:
            times=std::rand()%10+20;
            break;
        case 7:
            times=std::rand()%10+1;
            break;
        case 8:
            times=std::rand()%10+60;
            break;
        case 9:
            times=std::rand()%10+100;
            break;
        case 10:
            times=std::rand()%10+120;
            break;
        case 11:
            times=std::rand()%10+3;
            break;

        default:
            times=0;
            break;
        }
        Qlearn.prevState=Qlearn.currentState;
        //std::cout << "current state:  " << Qlearn.currentState << std::endl;
        Qlearn.UpdateReward(Qlearn.currentState,Qlearn.prevState,points, times);
        Qlearn.currentState=Qlearn.ChooseAction(Qlearn.currentState);
        maxReward+=Qlearn.rewardV;

        Qlearn.PrintR();
    }
    myfile.open ("Qlearn.csv",std::ofstream::app);
    myfile << maxReward;
    myfile << ",";
    myfile.close();




    std::cout << "maxReward" << maxReward << std::endl;
    Qlearn.Run();
    Qlearn.PrintRoute();
    }
}
