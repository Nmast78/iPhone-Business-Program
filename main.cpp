#include <iostream>

char space[3][3] = {{'1' ,  '2' , '3'}, {'4' , '5' , '6'}, {'7' , '8' , '9'}};
int row;
int column;
int choice;
bool tie = false;
char token = 'x';
std::string player1;
std::string player2;

void functionOne() {

    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    std::cout << "   |   |   " << std::endl;

}

void functionTwo() {

    if(token == 'x') {
        std::cout << player1 << " please enter a number: ";
        std::cin >> choice;
    }
    else if(token == 'o') {
        std::cout << player2 << " please enter a number: ";
        std::cin >> choice;
    }

    switch(choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;

        default: 
            std::cout << "Code entered is invalid!" << std::endl;
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = 'x';
        token = 'o';
    }
    else if(token == 'o' && space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = 'o';
        token = 'x';
    }
    else {
        std::cout << "That is not an empty space! \n";
        functionTwo();
    }

    functionOne();

}

bool decideWinner() {
    for(int i = 0; i < 3; i++) {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[2][i] == space[0][i]) {
            return true;
        }
    }

    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    
    std::cout << "TIC-TAC-TOE \n\n";
    std::cout << "Enter player 1 name: ";
    std::cin >> player1;
    std::cout << std::endl;

    std::cout << "Enter player 2 name: ";
    std::cin >> player2;
    std::cout << std::endl;

    std::cout << player1 << " will go first.";
    std::cout << std::endl;
    
    while(!decideWinner()) {
        functionOne();
        functionTwo();
        decideWinner();
    }

    if(token == 'x' && tie == false) {
        std::cout << player2 << " wins!";
    }
    else if(token == 'o' && tie == false) {
        std::cout << player1 << " wins!";
    }
    else {
        std::cout << "Its a draw!" << std::endl;
    }
}