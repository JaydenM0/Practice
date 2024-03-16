#include <iostream>
#include <string>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

void introduction(){
    cout<<"Press Enter to begin"<<endl;
    cin.ignore();

    cout<<"-----------------------------"<<endl;
    cout<<"Welcome to Tic-Tac-Toe!"<<endl;
    cout<<"Player 1 - X"<<endl;
    cout<<"Player 2 - O"<<endl;
    cout<<"-----------------------------"<<endl;

}

bool gameOver(bool isWinner){
    //horizontal win
    if (square[1] == square[2] && square[2] == square[3] ||
        square[4] == square[5] && square[5] == square[6] ||
        square[7] == square[8] && square[8] == square[9])  
    {
        return isWinner = true;
    }
    //vertical win
    else if (square[1] == square[4] && square[4] == square[7] ||
        square[2] == square[5] && square[5] == square[8] ||
        square[3] == square[6] && square[6] == square[9])  
    {
        return isWinner = true;
    }
    //diagonal win
    else if (square[1] == square[5] && square[5] == square[9] ||
        square[3] == square[5] && square[5] == square[7])  
    {
        return isWinner = true;
    }
    else{
        return isWinner = false;
    }

}

void displayBoard(const char square[]){
    cout<<"     |     |    "<<endl;
    cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<endl;
    cout<<"-----|-----|-----"<<endl;
    cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<endl;
    cout<<"-----|-----|-----"<<endl;
    cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<endl;
    cout<<"     |     |    "<<endl;

}


int main() {
    introduction();
    bool isWinner = false;
    int choice = 0;
    int turn = 0;

    displayBoard(square);
    while(isWinner == false){
        if(turn % 2 == 0){
            cout<<"Player 1's turn! Enter a Number: "<<endl;
            cin>>choice;
            while(choice <= 0 || choice >= 10 || square[choice] == 'X' || square[choice] == 'O'){
               cout<<"Invalid placement, choose another number: "<<endl;
               cin>>choice;
            } 
                square[choice] = 'X';
                turn++;
            }
         else if(turn % 2 == 1){
            cout<<"Player 2's turn! Enter a Number: "<<endl;
            cin>>choice;
            while((choice <= 0 || choice >= 10) || (square[choice] == 'X' || square[choice] ==  'O')){
               cout<<"Invalid placement, choose another number: "<<endl;
               cin>>choice;
            } 
                square[choice] = 'O';
                turn++;
            }
        displayBoard(square);
        isWinner = gameOver(isWinner);
    }
    if ((turn -1 )  % 2 == 0){
        cout<<"Gamer Over! Player 1 wins!"<<endl;
    }
    else{
        cout<<"Gamer Over! Player 2 wins!"<<endl;
    }
    return 0;
}

