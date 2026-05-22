#include<iostream>
#include<bits/stdc++.h>
#include <ctime> // is used in C++ to work with time and date functions.
#include<iomanip> // It helps control:decimal points,spacing,alignment,width,formatting

using namespace std;

int score = 0;

void Brain_Ops(){

    int num1 = rand() % 100 + 1;

    // preventing num1 / num2 where num2 = 0
    int num2 = rand() % 100 + 1;
    
    // this will give user either +/- at random 
    int operation = rand() % 4;

    float Bot_answer;

    // user answer
    float Your_answer;

    // due to this answer will come upto only 2 decimal points
    cout << fixed << setprecision(2);

    if(operation == 0){
        cout << " " << num1 << " " << "+" << " " << num2 << endl;
        cout << "Enter your answer : ";
        cin >> Your_answer;

        Bot_answer = num1 + num2;
        if(Your_answer == Bot_answer){
            cout << "\n [✓] Correct [✓]\n";
            score++;
        }
        else{
            cout << "\nWrong [X]\n";
            cout << "Correct answer : " << Bot_answer << endl;
        }
    }
    else if(operation == 1){
        cout << " " << num1 << " " << "-" << " " << num2 << endl;
        cout << "Enter your answer : ";
        cin >> Your_answer;

        Bot_answer = num1 - num2;
        if(Your_answer == Bot_answer){
            cout << "\n [✓] Correct [✓]\n";
            score++;
        }
        else{
            cout << "\nWrong [X]\n";
            cout << "Correct answer : " << Bot_answer << endl;
        }
    }
    else if(operation == 2){
        cout << " " << num1 << " " << "*" << " " << num2 << endl;
        cout << "Enter your answer : ";
        cin >> Your_answer;

        Bot_answer = num1 * num2;
        if(Your_answer == Bot_answer){
            cout << "\n [✓] Correct [✓]\n";
            score++;
        }
        else{
            cout << "\nWrong [X]\n";
        }
    }
    else if(operation == 3){
        cout << " " << num1 << " " << "/" << " " << num2 << endl;
        cout << "Enter your answer : ";
        cin >> Your_answer;

        Bot_answer = (float)num1 / num2;
        if(Your_answer == Bot_answer){
            cout << "\n [✓] Correct [✓]\n";
            score++;
        }
        else{
            cout << "\nWrong [X]\n";
        }
    }
}

void rock_paper_scissor(){
    // user choice
    string user_choice;

    // taking random numbers from 0 - 9 and then divide by 3 to get 0 1 2
    int bot = rand()%3;

    // input from the user
    cout << "\n choose (rock/paper/scissor) : ";
    cin >> user_choice;

    // any uppercase letter to lower case convertor
    transform(user_choice.begin(),user_choice.end(),user_choice.begin(), :: tolower);

    // putting random choice of bot into a string 
    string botchoice;

    // when the remainder of bot is 0 , i placed 0 means rock simarly 1 means paper and 2  means sissor
    if(bot == 0){
        botchoice = "rock"; 
    }
    else if(bot == 1){
        botchoice = "paper"; 
    }
    else if(bot == 2){
        botchoice = "scissor"; 
    }

    cout << "bot choice = " << botchoice <<endl;

    // comparing botchoice to userchoice
    if(user_choice == botchoice){
        cout << "\nDraw\n";
    }
    else if((botchoice == "rock" && user_choice == "paper") || (botchoice == "paper" && user_choice == "scissor") || (botchoice == "scissor" && user_choice == "rock") ){
        cout << "\nYou wins\n";
        score++;
    }
    else{
        cout << "\nBot wins\n";
    }
}

void Toss(){
    int toss = rand() % 2;

    string userchoice;
    cout << "Enter your outcome (Head/Tail) : ";
    cin >> userchoice;

    transform(userchoice.begin(),userchoice.end(),userchoice.begin(), :: tolower);

    string outcome;

    if(toss == 0){
        outcome = "head";
    }
    else{
        outcome = "tail";
    }

    cout << "Result = " << outcome << endl;

    if(outcome == userchoice){
        cout << "\nYou won the toss\n";
        score++;
    }
    else{
        cout << "\nYou lose the toss\n";
    }
}


// interface of the game
void game(){
    
    bool run = true;

    while(run){
        // start Menu...
        cout << "\n🎮 WELCOME 🎮\n" << "\nARE YOU READYY... (YES/NO) : ";
        string ready;
        cin >> ready;

        // for any type of entry like YES,Yes, YEs ,No,NO,nO to their lowercase
        transform(ready.begin(),ready.end(),ready.begin(), :: tolower);

        if(ready == "yes"){

            cout << "\nWhich game you wanna play??\n";
            cout << "\n1.Brain 🧠 Ops\n";
            cout << "\n2.Rock Paper & Sissor\n";
            cout << "\n3.Toss\n";

            int choice;

            // user which game he/she wanna play
            cout <<  "\nchoose : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                Brain_Ops();
                break;
            case 2:
                rock_paper_scissor();
                break;
            case 3:
                Toss();
                break;
            
            default:
                cout << "\nINVALID CHOICE...! 👀\n";
                break;
            }


        }

        // exit
        else if(ready == "no"){
            cout << "\nGooodd Byeee😭😭😭...\n";
            run = false;
        }

        // invalid choice
        else{
            cout << "\nINVALID CHOICE...! 👀\n";
        }
    }
}

int main(){
    srand(time(0));
    game();
    cout << "\nFinal Score : " << score;

    return 0;
}