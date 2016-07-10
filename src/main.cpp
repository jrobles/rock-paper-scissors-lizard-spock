#include<iostream>
#include<map>

using namespace std;

int computer(int size) 
{
	return rand() % size + 1;
}

void battle(map<int,string> options,int player,int computer)
{
	cout << "Player choose: " << options[player] << endl;
	cout << "Computer choose: " << options[computer] << endl;
}

int main()
{
	int option;

	map<int,string> options;
	options[1] = "Rock";
	options[2] = "Paper";
	options[3] = "Scissors";
	options[4] = "Lizard";
	options[5] = "Spock";

	for (map<int, string>::iterator it = options.begin(); it != options.end(); it++ ) {
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "0\texit" << endl;

	do
	{
		cout << "choose an option: ";
		cin >> option;
		if (option != 0){
			battle(options,option,computer(options.size()));
		}
	} while (option != 0);

	return 0;
}
