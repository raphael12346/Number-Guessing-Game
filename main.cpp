#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

void delay(int sec);
void clearScreen();
void clearLine();
void displayAiGuessing();

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int playerNumber, playerGuess;
    int aiNumber, aiGuess, start = 1, end = 10, remainingNumbers = end;
    int round = 1;

    cout << "Welcome to the Number Guessing Game!" << endl;
    delay(1);
    cout << "Think of a number between " << start << " and " << end << ". The AI and you will take turns guessing it." << endl;
    delay(1);
    cout << endl << "Enter your Number: ";
    cin >> playerNumber;

    aiNumber = rand() % remainingNumbers + start; //Generates AI's random number from 1 to 100

    do
    {
        cout << endl << "Round " << round << endl;
        round++;

        //PLAYER'S TURN
        cout << endl << "-----> Your Turn <-----" << endl;
        cout << "Take a Guess: ";
        cin >> playerGuess;
        delay(1);
        if(playerGuess == aiNumber)
        {
            cout << "Congratulations! You guessed the number " << aiNumber << "!!!" << endl;
            break;
        }
        else if(playerGuess < aiNumber)
        {
            cout << "Try a higher number next time!" << endl;
        }
        else
        {
            cout << "Try a lower number next time!" << endl;
        }

        //AI'S TURN -----------------------------------------------------------------------------
        cout << endl << "<----- AI's Turn ----->" << endl;
        displayAiGuessing();
        cout << "AI's Guess: ";
        if(remainingNumbers > 0)
        {
            aiGuess = rand() % remainingNumbers + start;
        }
        else
            aiGuess = start;
        cout << aiGuess << endl;
        if(aiGuess == playerNumber)
        {
            cout << "You lose! The AI guessed your number " << playerNumber << "!!!" << endl;
            break;
        }
        else if(aiGuess < playerNumber)
        {
            cout << "Try a higher number next time!" << endl;
            start = aiGuess + 1;
            remainingNumbers = end - start;
        }
        else
        {
            cout << "Try a lower number next time!" << endl;
            end = aiGuess - 1;
            remainingNumbers = end - start;
        }
        // ------------------------------------------------------------------------------------------------
        //cout << start << " - " << end << endl;
        delay(1);
    }while(playerGuess != aiNumber || aiGuess != playerNumber);

    cout << endl << "Do you want to try again? (Y/N) ";
    char choice;
    cin >> choice;
    if(choice == 'y' || choice == 'Y') {
        clearScreen();
        delay(1);
        return main();
    }
}

void clearLine()
{
    cout.flush(); // Flush the output buffer to ensure immediate display
    cout << "\r\033[K"; // Use escape sequences to move the cursor up and erase the line
}

void clearScreen()
{
    cout << "\033[2J\033[H"; // ANSI escape code to clear the screen
}

void delay(int sec)
{
    this_thread::sleep_for(chrono::seconds(sec));
}

void displayAiGuessing()
{
    //delay(1);
    cout << "AI is Guessing";
    delay(1);
    cout << " .";
    delay(1);
    cout << " .";
    delay(1);
    cout << " .";
    delay(1);
    clearLine();
}
