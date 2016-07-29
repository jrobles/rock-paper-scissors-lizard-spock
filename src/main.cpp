#include<iostream>
#include<map>

using namespace std;

const int width = 80;
const string title = "Rock, Paper, Scissors, Lizzard, Spock";

int computerOption(int size); 
void battle(map<int,string> options,int player,int computer);
void printBorder(string val);
void printHeader(string val);

int main()
{
	int playerOption;
	
	// Map with the available options.
	map<int,string> options;
	options[1] = "Rock";
	options[2] = "Paper";
	options[3] = "Scissors";
	options[4] = "Lizard";
	options[5] = "Spock";

	printHeader(title);

	// Loop through the options map and print out the options menu.
	for (map<int, string>::iterator it = options.begin(); it != options.end(); it++ ) {
		cout << it->first << "\t" << it->second << endl;
	}

	// Print out the option to exit the game.
	cout << "0\texit" << endl;
	printBorder("-");

	do
	{
		cout << "Choose an option: ";
		cin >> playerOption;
		if (playerOption != 0) { // meh
			battle(options,playerOption,computerOption(options.size()));
		}
		printBorder("-");

	} while (playerOption != 0);

	return 0;
}

void printHeader(string val)
{
	printBorder("#");
	cout << val << endl;
	printBorder("#");
}

void printBorder(string val)
{
	for (int i = 1;i <= width;i++) {
		cout << val;
	}
	cout << endl;		
}

// Used to randomly select a number from 1 - the number of options.
int computerOption(int size) 
{
	return rand() % size + 1;
}

// Used to initiate the player vs. computer match.
void battle(map<int,string> options,int player,int computer)
{
	int rules[6][2]; // janky!

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

	// There can only be one!! Or a tie...
	cout << "Player choose: " << options[player] << endl;
	cout << "Computer choose: " << options[computer] << endl;
	if (player == computer)
	{
		cout << "It's a tie!!!" << endl;	
	} else {

	}
}
