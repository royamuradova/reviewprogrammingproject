#include <iostream>
#include <random>
#include <string>

using namespace std;

/*
Rock-Paper-Scissors Game
---------------------------------
This program allows a user to play Rock-Paper-Scissors against the computer.
The user inputs their choice: "rock", "paper", or "scissors". The computer 
randomly selects one of these choices. The program determines the winner 
of each round, updates the score, and continues until the user decides to quit.

How it works:
1. The user is prompted to enter their choice.
2. The computer generates a random choice.
3. The winner of the round is determined.
4. Scores are updated based on the winner.
5. The game continues in a loop until the user enters "quit".
6. The final winner is displayed based on total scores.
*/

// Function prototypes
string getPlayerChoice();
string getComputerChoice();
string determineWinner(string player, string computer);
void updateScores(string winner, int &playerScore, int &computerScore);
void displayFinalWinner(int playerScore, int computerScore);

int main() {
    int playerScore = 0, computerScore = 0;
    string playerChoice, computerChoice, winner;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    while (true) {
        playerChoice = getPlayerChoice();

        if (playerChoice == "quit") {
            break; // Exit game loop
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        winner = determineWinner(playerChoice, computerChoice);
        updateScores(winner, playerScore, computerScore);

        cout << "Current Score - You: " << playerScore << " | Computer: " << computerScore << endl;
    }

    displayFinalWinner(playerScore, computerScore);
    return 0;
}

// Function to get the player's choice
// Input: None (user is prompted to enter a choice)
// Preconditions: User must enter "rock", "paper", "scissors", or "quit" (case insensitive)
// Postconditions: Returns a valid user choice as a lowercase string
string getPlayerChoice() {
    string choice;
    while (true) {
        cout << "Enter rock, paper, scissors, or quit: ";
        cin >> choice;

        // Convert input to lowercase for consistency
        for (char &c : choice) {
            c = tolower(c);
        }

        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
            return choice;
        } else {
            cout << "Invalid input! Please enter rock, paper, scissors, or quit." << endl;
        }
    }
}

// Function to get a random computer choice
// Input: None
// Preconditions: None
// Postconditions: Returns "rock", "paper", or "scissors" as a randomly chosen string
string getComputerChoice() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 3);

    int randomNum = dist(gen);
    if (randomNum == 1) return "rock";
    if (randomNum == 2) return "paper";
    return "scissors";
}

// Function to determine the winner
// Input: Player's choice and computer's choice as strings
// Preconditions: Both inputs must be "rock", "paper", or "scissors"
// Postconditions: Returns "player" if player wins, "computer" if computer wins, and "draw" if it's a tie
string determineWinner(string player, string computer) {
    if (player == computer) {
        cout << "It's a draw!" << endl;
        return "draw";
    }

    if ((player == "rock" && computer == "scissors") ||
        (player == "scissors" && computer == "paper") ||
        (player == "paper" && computer == "rock")) {
        cout << "You win this round!" << endl;
        return "player";
    } else {
        cout << "Computer wins this round!" << endl;
        return "computer";
    }
}

// Function to update the score based on the round winner
// Input: The winner as a string, and references to player and computer scores
// Preconditions: winner must be either "player", "computer", or "draw"
// Postconditions: Updates the score by incrementing the appropriate player's count
void updateScores(string winner, int &playerScore, int &computerScore) {
    if (winner == "player") {
        playerScore++;
    } else if (winner == "computer") {
        computerScore++;
    }
}

// Function to display the final winner at the end of the game
// Input: Player's total score and computer's total score
// Preconditions: None
// Postconditions: Displays the final score and announces the tournament winner
void displayFinalWinner(int playerScore, int computerScore) {
    cout << "\nFinal Score - You: " << playerScore << " | Computer: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Congratulations! You won the tournament!" << endl;
    } else if (computerScore > playerScore) {
        cout << "Computer wins the tournament! Better luck next time!" << endl;
    } else {
        cout << "The tournament ended in a draw!" << endl;
    }
}
