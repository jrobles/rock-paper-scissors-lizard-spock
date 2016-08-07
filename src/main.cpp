#include <iostream>
#include <map>

using namespace std;

const int width = 80;
const string title = "Rock, Paper, Scissors, Lizzard, Spock";

struct competitor {
	int wins;
	int losses;
	int ties;
	int rock;
	int paper;
	int scissors;
	int lizard;
	int spock;
};

int computerHand(int size); 
void battle(map<int,string> options,int playerHand,int computerHand, int rules[2]);
void printBorder(string val);
void printHeader(string val);
void centerString(string val);
void printMenu();
void playGame(competitor *player, competitor *computer);
void clrScrn();

int main()
{
	// Print the main menu 	
	printMenu();

	int menuOption;
	competitor player;
	competitor computer;

	do
	{
		printBorder("-");
		cout << "Choose an option: ";
		cin >> menuOption;
		
		switch(menuOption) {
			case 1:
				cout << "\n- Scissors cuts Paper" << endl;
				cout << "- Paper covers Rock" << endl;
				cout << "- Rock crushes Lizard" << endl;
				cout << "- Lizard poisons Spock" << endl;
				cout << "- Spock smashes Scissors" << endl;
				cout << "- Scissors decapitates Lizard" << endl;
				cout << "- Lizard eats Paper" << endl;
				cout << "- Paper disproves Spock" << endl;
				cout << "- Spock vaporizes Rock" << endl;
				cout << "- (and as it always has) Rock crushes Scissors" << endl;
				break;
			case 2:
				playGame(&player,&computer);
				break;
			case 3:
				centerString("stats.txt updated!");
				break;
			case 4:
				cout << "\nPlayer Wins: " << player.wins << endl;
				cout << "Player Losses: " << player.losses << endl;
				cout << "Player Ties: " << player.ties << endl;

				cout << "\nComputer Wins: " << computer.wins << endl;
				cout << "Computer Losses: " << computer.losses << endl;
				cout << "Computer Ties: " << computer.ties << endl;

				break;	
		}
	} while (menuOption != 5);
	clrScrn();

	return 0;
}

void printMenu()
{
	map<int,string> menu;
	menu[1] = "See the rules of the game";
	menu[2] = "Play against the computer";
	menu[3] = "Update statistics to file stats.txt";
	menu[4] = "Show lifetime statistics";
	menu[5] = "Quit";

	// Print out the fancy program header
	printHeader(title);

	// Loop through the options map and print out the options menu.
	for (map<int, string>::iterator it = menu.begin(); it != menu.end(); it++ ) {
		cout << "[" << it->first << "]" << "\t" << it->second << endl;
	}
}

void playGame(competitor *player, competitor *computer)
{
	// Clear the screen
	clrScrn();

	player->wins += 3;

	// Print out the fancy program header
	printHeader(title);

	int playerHand;
	int rules[6][2]; // janky!

	// Map with the menu options.
	map<int,string> options;
	options[1] = "Rock";
	options[2] = "Paper";
	options[3] = "Scissors";
	options[4] = "Lizard";
	options[5] = "Spock";

	// Define the rules based on the options map
	rules[1][0] = 3; // Rock > Scissors
	rules[1][1] = 5; // Rock > Lizard
	rules[2][0] = 1; // Paper > Rock
	rules[2][1] = 5; // Paper > Spock
	rules[3][0] = 2; // Sissors > Paper
	rules[3][1] = 4; // Scissors > Lizard
	rules[4][0] = 1; // Lizard > Paper
	rules[4][1] = 5; // Lizard > Spock
	rules[5][0] = 1; // Spock > Rock
	rules[5][1] = 3; // Spock > Scissors


	// Loop through the options map and print out the options menu.
	for (map<int, string>::iterator it = options.begin(); it != options.end(); it++ ) {
		cout << "[" << it->first << "]" << "\t" << it->second << endl;
	}

	// Print out the option to exit the game.
	cout << "[0]\tReturn to main menu" << endl;
	printBorder("-");

	do
	{
		cout << "Choose a hand: ";
		cin >> playerHand;
		if (playerHand != 0) { // meh
			battle(options,playerHand,computerHand(options.size()), rules[playerHand]);
		}
		printBorder("-");

	} while (playerHand != 0);

	// Clear the screen
	clrScrn();

	// Print the main menu
	printMenu();
}

// Takes a string and prints it out with padding based on the width CONST.
void centerString(string val)
{
	// Determine how much left padding is needed to center the string
	int padding = (width - val.length()) / 2;

	// Print out the padding
	for (int i = 1;i <= padding;i++)
	{
		cout << " ";
	}
	cout << val << endl;
}

// Prints out the program header
void printHeader(string val)
{
	printBorder("#"); // Print top border
	centerString(val); // Print the title CONST centered.
	printBorder("#"); // Print bottom border
}

// Used to print out any sort of line / border
void printBorder(string val)
{
	for (int i = 1;i <= width;i++) {
		cout << val;
	}
	cout << endl;		
}

// Used to randomly select a number from 1 - the number of options.
int computerHand(int size) 
{
	return rand() % size + 1;
}

// Used to initiate the player vs. computer match.
void battle(map<int,string> options,int playerHand,int computerHand, int rules[2])
{
	bool win = false;

	// There can only be one!! Or a tie...
	cout << "\nPlayer choose: " << options[playerHand] << endl;
	cout << "Computer choose: " << options[computerHand] << "\n" << endl;
	if (playerHand == computerHand)
	{
		centerString("!!! It's a tie !!!");	
	} else {
		for (int i = 0;i <= 1;i++) {
			if (rules[i] == computerHand) {
				win = true;
			}
		}
		if (win) {
			centerString("Player wins!!");	
		} else {
			centerString("Computer wins!!");	
		}
	}
}
 void clrScrn()
{
	cout << "\033[2J\033[1;1H";	 
}
