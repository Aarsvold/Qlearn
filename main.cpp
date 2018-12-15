#include <QCoreApplication>
#include "qlearn.h"
#include <time.h>
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));

    std::ofstream myfile;
    myfile.open("Qlearn.csv", std::ofstream::out | std::ofstream::trunc);
    myfile.close();

    int points;
    double times;
    Qlearning Qlearn;

    for(int i = 0; i<300; i++){

    int maxReward=0;
    int marblesC=0;
    int marbles=0;

    Qlearn.Initialize();
    Qlearn.currentState=Qlearn.ChooseAction(0);
    std::cout << Qlearn.currentState << std::endl;
    Qlearn.prevState=0;
    Qlearn.UpdateReward(Qlearn.currentState,Qlearn.prevState,0,1); //Update reward of choosen action.
    Qlearn.prevState=Qlearn.currentState;


    for(int i=0; i<Qlearn.rSize-2;i++){
        if(marblesC<=20)
        {
            marbles = std::rand()%3;
            marblesC+=marbles;
            if(marblesC>20)
            {
                marbles=marbles-(marblesC-20);
                marblesC=marblesC-marbles;
            }
            points = marbles*100;
        }
        else
            points=0;
        std::cout << "marbles" << marbles << std::endl;
        std::cout << "marblesC" << marblesC << std::endl;
        std::cout << "points" << points << std::endl;

        Qlearn.currentState=Qlearn.ChooseAction(Qlearn.currentState);
       switch (Qlearn.currentState) {
        case 0:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=23;
                break;
            case 2:
                times=63;
                break;
            case 3:
                times=53;
                break;
            case 4:
                times=12;
                break;
            case 5:
                times=76;
                break;
            case 6:
                times=12;
                break;
            case 7:
                times=11;
                break;
            case 8:
                times=17;
                break;
            case 9:
                times=30;
                break;
            case 10:
                times=15;
                break;
            case 11:
                times=29;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 1:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=1;
                break;
            case 2:
                times=10;
                break;
            case 3:
                times=30;
                break;
            case 4:
                times=48;
                break;
            case 5:
                times=61;
                break;
            case 6:
                times=27;
                break;
            case 7:
                times=17;
                break;
            case 8:
                times=43;
                break;
            case 9:
                times=12;
                break;
            case 10:
                times=19;
                break;
            case 11:
                times=17;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 2:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=41;
                break;
            case 2:
                times=1;
                break;
            case 3:
                times=23;
                break;
            case 4:
                times=51;
                break;
            case 5:
                times=15;
                break;
            case 6:
                times=19;
                break;
            case 7:
                times=42;
                break;
            case 8:
                times=49;
                break;
            case 9:
                times=14;
                break;
            case 10:
                times=12;
                break;
            case 11:
                times=41;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 3:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=54;
                break;
            case 2:
                times=32;
                break;
            case 3:
                times=1;
                break;
            case 4:
                times=31;
                break;
            case 5:
                times=34;
                break;
            case 6:
                times=43;
                break;
            case 7:
                times=39;
                break;
            case 8:
                times=28;
                break;
            case 9:
                times=20;
                break;
            case 10:
                times=53;
                break;
            case 11:
                times=13;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 4:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=42;
                break;
            case 2:
                times=12;
                break;
            case 3:
                times=32;
                break;
            case 4:
                times=1;
                break;
            case 5:
                times=12;
                break;
            case 6:
                times=32;
                break;
            case 7:
                times=53;
                break;
            case 8:
                times=21;
                break;
            case 9:
                times=32;
                break;
            case 10:
                times=18;
                break;
            case 11:
                times=28;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 5:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=12;
                break;
            case 2:
                times=27;
                break;
            case 3:
                times=16;
                break;
            case 4:
                times=15;
                break;
            case 5:
                times=1;
                break;
            case 6:
                times=65;
                break;
            case 7:
                times=30;
                break;
            case 8:
                times=10;
                break;
            case 9:
                times=6;
                break;
            case 10:
                times=2;
                break;
            case 11:
                times=74;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 6:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=32;
                break;
            case 2:
                times=12;
                break;
            case 3:
                times=18;
                break;
            case 4:
                times=29;
                break;
            case 5:
                times=20;
                break;
            case 6:
                times=1;
                break;
            case 7:
                times=91;
                break;
            case 8:
                times=42;
                break;
            case 9:
                times=19;
                break;
            case 10:
                times=29;
                break;
            case 11:
                times=28;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 7:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=21;
                break;
            case 2:
                times=35;
                break;
            case 3:
                times=31;
                break;
            case 4:
                times=10;
                break;
            case 5:
                times=28;
                break;
            case 6:
                times=26;
                break;
            case 7:
                times=1;
                break;
            case 8:
                times=24;
                break;
            case 9:
                times=13;
                break;
            case 10:
                times=20;
                break;
            case 11:
                times=27;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 8:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=18;
                break;
            case 2:
                times=17;
                break;
            case 3:
                times=20;
                break;
            case 4:
                times=27;
                break;
            case 5:
                times=28;
                break;
            case 6:
                times=26;
                break;
            case 7:
                times=28;
                break;
            case 8:
                times=1;
                break;
            case 9:
                times=50;
                break;
            case 10:
                times=38;
                break;
            case 11:
                times=26;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 9:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=15;
                break;
            case 2:
                times=16;
                break;
            case 3:
                times=13;
                break;
            case 4:
                times=34;
                break;
            case 5:
                times=23;
                break;
            case 6:
                times=21;
                break;
            case 7:
                times=31;
                break;
            case 8:
                times=41;
                break;
            case 9:
                times=1;
                break;
            case 10:
                times=31;
                break;
            case 11:
                times=22;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 10:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=11;
                break;
            case 2:
                times=55;
                break;
            case 3:
                times=33;
                break;
            case 4:
                times=22;
                break;
            case 5:
                times=31;
                break;
            case 6:
                times=44;
                break;
            case 7:
                times=41;
                break;
            case 8:
                times=49;
                break;
            case 9:
                times=29;
                break;
            case 10:
                times=1;
                break;
            case 11:
                times=4;
                break;

            default:
                times=0;
                break;
            }
            break;
        case 11:
           switch (Qlearn.prevState) {
            case 0:
                times=1;
                break;
            case 1:
                times=50;
                break;
            case 2:
                times=48;
                break;
            case 3:
                times=57;
                break;
            case 4:
                times=50;
                break;
            case 5:
                times=46;
                break;
            case 6:
                times=30;
                break;
            case 7:
                times=48;
                break;
            case 8:
                times=46;
                break;
            case 9:
                times=46;
                break;
            case 10:
                times=40;
                break;
            case 11:
                times=1;
                break;

            default:
                times=0;
                break;
            }
            break;

        default:
            times=0;
            break;
        }
        std::cout << "times:  " << times << std::endl;
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
