#include<iostream>
#include <string>
#include <ctime>


using std::cin;
using std::cout;
using std::endl;

int innings[2][9] ={{0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0}};

void introduction(){
    cout<<"Press Enter to Begin!"<<endl;
    cin.ignore();

    cout<<"-------------------------"<<endl;
    cout<<"Welcome to Baseball Simulator!"<<endl;
    cout<<"Home Team - Astros"<<endl;
    cout<<"Away Team - Blue Jays"<<endl;

};


void displayInnings(const int innings[2][9]) {
    // Display the innings array
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < 10; ++j) {
            cout << innings[i][j] << "|";
        }
        
        cout << endl;
        cout << "--------------------" << endl;
    }
    
};/*iterate through the array "innings" and display the score at each element.*/



void finalScore(const int innings[2][9], int &team1Score, int &team2Score){
    for(int i = 0; i < 2;++i){
        for(int j = 0; j<10;++j){
            if(i == 0){
                team1Score += innings[i][j];
            }
            else{
                team2Score += innings[i][j];
            }
        }
    }
};/* calculate the final score of each team by iterating 
    through the top of the innings then the bottom. 
 */

int main(){
    introduction();
    displayInnings(innings);
    int inning = 1, turn = 1, runs, team1Score = 0, team2Score = 0;
    //turn is used to determine if it is the top or bottom inning
    
    std::string team1 = "Astros";
    std::string team2 = "Blue Jays";

    srand(time(NULL)); //provide a random number when using "rand()"

    while(inning != 10){
        if(turn % 2 == 1){
            cout<<"Top of the " << inning << " inning"<<endl;
            runs = rand() % 10;
            innings[0][inning] = runs;
            displayInnings(innings);

        }
        else{
            cout<<"Bottom of the "<< inning<<" inning"<<endl;
            runs = rand() % 10;
            innings[1][inning] = runs;
            displayInnings(innings);      
            inning++;
        }
    turn++;
    }
    finalScore(innings, team1Score, team2Score);
    cout<<team1 <<": "<<team1Score<<"\n"<<team2<<": "<<team2Score<<endl;


    if(team1Score > team2Score){
        cout<<team1<<" wins!"<<endl;
    }
    else{
        cout<<team2<<" wins!"<<endl;
    }
    cout<<team1Score<<" "<<team2Score<<endl;
    return 0;
};
