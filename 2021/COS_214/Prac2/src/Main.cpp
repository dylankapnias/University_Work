#include "../inc/ArsenalFactory.h"
#include "../inc/ChelseaFactory.h"
#include "../inc/LiverpoolFactory.h"
#include "../inc/AttackPlayStyle.h"
#include "../inc/DefensivePlayStyle.h"
#include "../inc/PossesionPlayStyle.h"
#include "../inc/SoccerPlayer.h"
#include <iostream>
#include <string>

using namespace std;

/*void expandArr(Merchandise** m, int cap, int num) {
    Merchandise** temp = new Merchandise*[cap];

    for (int i = 0; i < num; i++) {
        temp[i] = m[i]->clone();
    }

    for (int i = 0; i < num; i++) {
        cout << temp[i]->getDescription() << endl;
    }

    for (int i = 0; i < num; i++) {
        delete m[i];
    }
    delete [] m;

    for (int i = 0; i < num; i++) {
        temp[i]->getDescription();
    }

    m = temp;

    for (int i = 0; i < num; i++) {
        m[i]->getDescription();
    }  
}*/

/**
 * 
 * Function to test the Merchandise class and the Abstract Factory
 * 
 * **********************************************************************/
void merchFunc() {
    cout << "Merchandise creation starting now!" << endl << endl;

    // const vars for the program
    const int numFactories = 3;
    const int merchCap = 100;

    // other vars
    int type;
    int club;
    string size;
    bool inf;
    int amount;
    int stop;

    MerchandiseFactory* factories[numFactories];
    factories[0] = new ChelseaFactory();
    factories[1] = new ArsenalFactory();
    factories[2] = new LiverpoolFactory();

    Merchandise** merch = new Merchandise*[merchCap];
    int numMerch = 0;
    
    while (true) {
        type = 0;
        cout << "Choose the type of merchandise you want to create: Ball=1, Shirt=2 > ";
        cin >> type;

        club = 0;
        cout << "Choose the club whose merchandise should be created: Chelsea=1, Arsenal=2, Liverpool=3 > ";
        cin >> club;

        size = "";
        inf = true;
        switch (type) {
            case 1:        
                char inS;
                cout << "Should the ball(s) be inflated? (y/n) > ";
                cin >> inS;
                inf = (inS == 'y') ? true : false;
                break;

            case 2:
                cout << "Choose the size of the shirt(s) to be created > ";
                cin >> size;
                
            default:
                break;
        }

        amount = 0;
        cout << "How many merchandise items should be created? > ";
        cin >> amount;
        //numMerch = numMerch + amount;
        /*if (numMerch + amount > merchCap){
            merchCap = merchCap * 2;
            expandArr(merch, merchCap, numMerch);
            for (int i = 0; i < numMerch; i++) {
                merch[i]->getDescription();
            }
        }*/

        for (int i = 0; i < amount; i++) {
            switch (club) {
                case 1:
                    merch[numMerch] = (type == 1) ? static_cast<Merchandise*>(factories[0]->createSoccerBall(inf)) : static_cast<Merchandise*>(factories[0]->createShirt(size));
                    numMerch++;
                    break;

                case 2:
                    merch[numMerch] = (type == 1) ?  static_cast<Merchandise*>(factories[1]->createSoccerBall(inf)) : static_cast<Merchandise*>(factories[1]->createShirt(size));
                    numMerch++;
                    break;

                case 3:
                    merch[numMerch] = (type == 1) ?  static_cast<Merchandise*>(factories[2]->createSoccerBall(inf)) : static_cast<Merchandise*>(factories[2]->createShirt(size));
                    numMerch++;
                    break;

                default:
                    break;
            }
        }

        stop = 0;
        cout << endl << "Enter 1 to create more items or 0 to stop > ";
        cin >> stop;
        cout << endl;

        if (stop == 0) {
            break;
        } else {
            continue;
        }
    }

    // Cleaning up memory
    for (int i = 0; i < numMerch; i++) {
		delete merch[i];
	}
	delete [] merch;

    for (int i = 0; i < numFactories; i++) {
		delete factories[i];
	}

    cout << endl << "Merchandise creation ending now!" <<  endl;
}

/**
 * 
 * Function to test the SoccerPlayer class and the state and strategy
 * 
 * **********************************************************************/
void playerFunc() {
    cout << "Player state starting now!" << endl << endl;

    // Constant variables
    const int numStyles = 3;

    PlayStyle** styles = new PlayStyle*[numStyles];
    styles[0] = new AttackPlayStyle();
    styles[1] = new DefensivePlayStyle();
    styles[2] = new PossesionPlayStyle();

    SoccerPlayer* player = new SoccerPlayer("Dyl", styles[0]);
    player->play();
    player->commitFoul();

    player->setStyle(styles[1]);
    player->play();
    player->commitFoul();

    player->setStyle(styles[2]);
    player->play();

    for (int i = 0; i < numStyles; i++)
    {
        delete styles[i];
    }
    delete [] styles;    

    delete player;

    cout << endl << "Player state ending now!" << endl;
}

/**
 * 
 * Main function
 * 
 * **********************************************************************/
int main() {

    //merchFunc();

    playerFunc();    

    return 0;
}