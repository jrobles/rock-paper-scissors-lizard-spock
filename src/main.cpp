#include<iostream>
#include<map>

using namespace std;

int computerOption(int size); 
void battle(map<int,string> options,int player,int computer);

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

	// Loop through the options map and print out the options menu.
	for (map<int, string>::iterator it = options.begin(); it != options.end(); it++ ) {
		cout << it->first << "\t" << it->second << endl;
	}

	// Print out the option to exit the game.
	cout << "0\texit" << endl;

	do
	{
		cout << "Choose an option: ";
		cin >> playerOption;
		if (playerOption != 0){ // meh
			battle(options,playerOption,computerOption(options.size()));
		}
	} while (playerOption != 0);

	return 0;
}

// Used to randomly select a number from 1 - the number of options.
int computerOption(int size) 
{
	return rand() % size + 1;
}

// Used to initiate the player vs. computer match.
void battle(map<int,string> options,int player,int computer)
{

	cout << "Player choose: " << options[player] << endl;
	cout << "Computer choose: " << options[computer] << endl;


	cout << "The winner is: Me" << endl; 
}
