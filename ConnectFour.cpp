#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |W|\n\
          |O|\n\
          |W|\n\
          | |\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

int playersChoice;
string playerOne, playerTwo, colorSelection, playAgain;
string gameGrid[7][6] = {{" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "}, {" ", " ", " ", " ", " ", " "},};
bool wantsToPlay = true;
bool checkwinp1 = false;
bool checkwinp2 = false;
bool selectionValid = false;
bool gameInProgress = false;
bool P1validPlay = false;
bool P2validPlay = false;

//Beginning Prompt Message, Sets Colored Piece To Player One or Two
void startMessage() {
	
	cout << "Welcome To Connect Four" << endl;
    //cout << "\033[1;30m" << s11 << "\033[0m\n"; BLACK TEXT
    //cout << "\033[1;31m" << s11 << "\033[0m\n"; RED TEXT
    cout << "Player One Do You Want To Be Red, or Black?" << endl << "Type 'red' or 'black'" << endl;
        cin >> colorSelection;
        if (colorSelection == "red") {
            playerOne = "\033[1;31mO\033[0m";
            playerTwo = "\033[1;30mO\033[0m";
            selectionValid = true;
        } else {
            playerOne = "\033[1;30mO\033[0m";    
            playerTwo = "\033[1;31mO\033[0m";
            selectionValid = true;
        }
    cout << "Good Luck!" << endl << endl << endl;
}

//Creates Board
void generateBoard() {
    cout << "      1       2       3       4       5       6       7    " << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][0] << "   |   " << gameGrid[1][0]  << "   |   " << gameGrid[2][0] << "   |   " << gameGrid[3][0] << "   |   " << gameGrid[4][0] << "   |   " << gameGrid[5][0] << "   |   " << gameGrid[6][0] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][1] << "   |   " << gameGrid[1][1]  << "   |   " << gameGrid[2][1] << "   |   " << gameGrid[3][1] << "   |   " << gameGrid[4][1]<< "   |   " << gameGrid[5][1] << "   |   " << gameGrid[6][1] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][2] << "   |   " << gameGrid[1][2]  << "   |   " << gameGrid[2][2] << "   |   " << gameGrid[3][2] << "   |   " << gameGrid[4][2] << "   |   " << gameGrid[5][2] << "   |   " << gameGrid[6][2] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][3] << "   |   " << gameGrid[1][3]  << "   |   " << gameGrid[2][3] << "   |   " << gameGrid[3][3] << "   |   " << gameGrid[4][3] << "   |   " << gameGrid[5][3] << "   |   " << gameGrid[6][3] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][4] << "   |   " << gameGrid[1][4]  << "   |   " << gameGrid[2][4] << "   |   " << gameGrid[3][4] << "   |   " << gameGrid[4][4] << "   |   " << gameGrid[5][4] << "   |   " << gameGrid[6][4] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "  |   " << gameGrid[0][5] << "   |   " << gameGrid[1][5]  << "   |   " << gameGrid[2][5] << "   |   " << gameGrid[3][5] << "   |   " << gameGrid[4][5] << "   |   " << gameGrid[5][5] << "   |   " << gameGrid[6][5] << "   |" << endl;
    cout << "  |       |       |       |       |       |       |       |" << endl;
    cout << "   ________________________________________________________" << endl << endl;
}

//Check If Player One Has Won
int checkWinP1() {
	//check horizontal win
	int counter = 0;
	for (int row = 0; row < 7; row++) {
		for (int i = 0; i < 7; i++) {
			if (gameGrid[i][row] == playerOne) {
				counter++;
			} else {
				counter = 0;
			}
			if (counter >=4) {
				cout << "Player One Has Won!" << endl;
				checkwinp1 = true;
				return 0;
			}
		}
	}
	return 0;
}

//Check If Player Two Has Won
int checkWinP2() {
	//check horizontal win
	int counter = 0;
	for (int row = 0; row < 7; row++) {
		for (int i = 0; i < 7; i++) {
			if (gameGrid[i][row] == playerTwo) {
				counter++;
			} else {
				counter = 0;
			}
			if (counter >=4) {
				cout << "Player Two Has Won!" << endl;
				checkwinp2 = true;
				return 0;
			}
		}
	}
	return 0;
}

//Placing The Pieces
void promptChoices() {
	gameInProgress = true;
	while (gameInProgress == true) {
		while (P1validPlay == false) {
			cout << "Player One Pick A Column" << endl;
			cin >> playersChoice;
			playersChoice = playersChoice - 1;
			for(int i = 5; i >=0; i--) {
				if(gameGrid[playersChoice][i] == " ") {
					gameGrid[playersChoice][i] = playerOne;
					P1validPlay = true;
					break;
				}
			}
			if (gameGrid[playersChoice][0] != " ") {
				cout << "This Column Is Full! Chooe Another :/" << endl;
				P1validPlay = false;
			} 
		}
		checkWinP1();
		if (checkwinp1 == true) {
			generateBoard();
			gameInProgress = false;
			break;
		}
		generateBoard();
		while (P2validPlay == false) {
			cout << "Player Two Pick A Column" << endl;
			cin >> playersChoice;
			playersChoice = playersChoice - 1;
			for(int i = 5; i >=0; i--) {
				if(gameGrid[playersChoice][i] == " ") {
				gameGrid[playersChoice][i] = playerTwo;
				P2validPlay = true;
				break;
				}
			}
			if (gameGrid[playersChoice][0] != " ") {
				cout << "This Column Is Full! Choose Another :/" << endl;
				P2validPlay = false;
			}
		}
		checkWinP2();
		if (checkwinp2 == true) {
			generateBoard();
			gameInProgress = false;
			break;
		}
		generateBoard();
		P1validPlay = false;
		P2validPlay = false;
	}
}

//Rocket Animation
void endAnimation() {
	sleep(1);
	for (int i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
		printf("%s", rocket);
		int j = 300000;
		for (int i = 0; i < 60; i ++) {
			usleep(j); // move faster and faster,
			j = (int)(j * 0.95); // so sleep less each time
			printf("\n"); // move rocket a line upward
		}
}
int main() {
		startMessage();
		generateBoard();
		promptChoices();
		cout << "Congradulations" << endl;
		endAnimation();
	
	
return 0;    
}
