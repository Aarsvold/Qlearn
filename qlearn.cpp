#include "qlearn.h"


Qlearn::Qlearn()
{

}

int Qlearn::getRandomAction(){
    int action;
    bool choiceIsValid = false;
    //printRtemp();

    do {
        //Get a random value between 0 and rSize.
        action = rand()%rSize;
        //std::cout << action << std::endl;
        if(RTemp[currentState][action] > -1){
            choiceIsValid = true;
        }
    } while(choiceIsValid == false);
    for(int i = 0; i <= (rSize - 1); i++){ //fill temp matrix with "-1" to avoid selectning it again.
            RTemp[currentState][i] = -1;
        }


//std::cout << action << std::endl;
    return action;
}

void Qlearn::chooseAction(int initialState){
    int possibleAction;
    currentState=initialState;

    possibleAction = getRandomAction();

    if(R[currentState][possibleAction] >= 0){
        R[currentState][possibleAction] = reward(possibleAction); //Update reward of choosen action.
        //std::cout << reward(possibleAction) << std::endl;
        currentState = possibleAction;
    }

}

void Qlearn::episode(){
//Reset the temp array to a new episode.
    for(int i = 0; i <= (rSize - 1); i++){
        for(int j = 0; j <= (rSize - 1); j++){
            RTemp[i][j] = R[i][j];
        }
    }
}



void Qlearn::initialize(){

    srand((unsigned)time(NULL));

    for(int i = 0; i <= (rSize - 1); i++){
        for(int j = 0; j <= (rSize - 1); j++){
            Q[i][j] = 0;
        }
    }
}

int Qlearn::maximum(int state, bool returnIndexOnly, bool temp){
// if returnIndexOnly = true, a Q matrix index is returned.
// if returnIndexOnly = false, a Q matrix element is returned.

    int winner;
    bool foundNewWinner;
    bool done = false;

    winner = 0;
if(!temp){
    do {
        foundNewWinner = false;
        for(int i = 0; i <= (rSize - 1); i++){
            if((i < winner) || (i > winner)){     //Avoid self-comparison.
                if(R[state][i] > R[state][winner]){
                    winner = i;
                    foundNewWinner = true;
                }
            }
        } // i

        if(foundNewWinner == false){
            done = true;
        }

    } while(done = false);
}
else{
    do {
        foundNewWinner = false;
        for(int i = 0; i <= (rSize - 1); i++){
            if((i < winner) || (i > winner)){     //Avoid self-comparison.
                if(RTemp[state][i] > RTemp[state][winner]){
                    winner = i;
                    foundNewWinner = true;
                }
            }
        } // i

        if(foundNewWinner == false){
            done = true;
        }

    } while(done = false);
}
    //std::cout << "R" << R[state][winner] << std::endl;

    if(returnIndexOnly == true){
        return winner;
    }else{
        return R[state][winner];
    }
}

int Qlearn::reward(int action){
    //Get reward
    return static_cast<int>((((RTemp[currentState][action]+rand()%10)) + (gamma * maximum(action, false, false)))/2);
}

void Qlearn::iterate(int ite){
    initialize();
    const int iterations = ite;

    for(int j = 0; j <= (iterations - 1); j++){
        episode(); // reset for new run
        for(int i = 0; i <= (6 - 1); i++){
           chooseAction(initialStates[i]);
        } // i
    }
}
void Qlearn::printRtemp(){ //print the temperary matrix of points.
    std::cout << "RTemp" << std::endl;
    for(int i = 0; i <= (rSize - 1); i++){
        for(int j = 0; j <= (rSize - 1); j++){
            std::cout << std::setw(5) << RTemp[i][j];
            if(j < rSize - 1){
                std::cout << ",";
            }
        } // j
        std::cout << "\n";
    } // i
    std::cout << "\n";
}

void Qlearn::printroute(){ //Print the most optimal route, based on past experience.
    episode();
    currentState=initialStates[0];
    std::cout << "Optimal path:  " << std::endl;
    for(int i=0; i<rSize;i++){
        //printRtemp();
        //std::cout << "hej" << std::endl;
        newState = maximum(currentState, true,true);
        for(int i = 0; i <= (rSize - 1); i++){
                RTemp[i][newState] = -1;
            }
        currentState = newState;
        std::cout << currentState << ", ";
    }
    std::cout << std::endl;

}

void Qlearn::printR(){
    //Print out R matrix.
    for(int i = 0; i <= (rSize - 1); i++){
        for(int j = 0; j <= (rSize - 1); j++){
            std::cout << std::setw(5) << R[i][j];
            if(j < rSize - 1){
                std::cout << ",";
            }
        } // j
        std::cout << "\n";
    } // i
    std::cout << "\n";
} // j


