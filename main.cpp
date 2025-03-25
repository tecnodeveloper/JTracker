#include <iostream>
#include<vector>
#include<string>
#include "structs.h"
#include<chrono>
#include <iomanip>


using namespace std;


int main() {
	// Get the current time
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm local_time;
	localtime_s(&local_time, &now_time);

	// Display the current time
	cout << "Current time: " << put_time(&local_time, "%Y-%m-%d %H:%M:%S") << endl;


	vector<pair<string, int>> dailyScores;
	int score{};
	int accessories{};
	string respond;


		cout << "_______Tracking your progress_______ \n";
		do {
			cout << "Have you done Squat, Bench or Pull Ups ? y/n: "; cin >> respond;
			if (respond[0] == 'y') { score += 3; }
			else if (respond[0] == 'n') { cout << "You decided to skip compounds today I see \n"; }
			else { cout << "Please enter a valid response: "; }
		} while (respond[0] != 'y' && respond[0] != 'n');


		do {
			cout << "Have you done Romanian/Deadlift, Overhead Press or Rows ? y/n: "; cin >> respond;
			if (respond[0] == 'y') { score += 2; }
			else if (respond[0] == 'n') { cout << "You decided to skip the other compounds \n"; }
			else { cout << "Please enter a valid response \n"; }
		} while (respond[0] != 'y' && respond[0] != 'n');


		do {
			cout << "Did you train abs today ? y/n: "; cin >> respond;
			if (respond[0] == 'y') { score += 2; }
			else if (respond[0] == 'n') { cout << "Abs are not made only in the kitchen brother! \n"; }
			else { cout << "Please enter a valid response \n"; }
		} while (respond[0] != 'y' && respond[0] != 'n');


		do {
			cout << "Have you done cardio ? y/n: "; cin >> respond;
			if (respond[0] == 'y') { score += 3; }
			else if (respond[0] == 'n') { cout << "David Goggins runs everyday but you don't !? \n"; }
			else { cout << "Please enter a valid response \n"; }
		} while (respond[0] != 'y' && respond[0] != 'n');


		while (true) {
			cout << "How many accessory exercises have you done?: ";
			cin >> accessories;
			if (cin.fail()) {
				cin.clear(); // clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				cout << "PLEASE ENTER A VALID NUMBER\n";
			}
			else {
				score += accessories;
				break;
			}
		}

		cout << "Points scored: " << score << '\n'<<'\n';


        ExercisePersonal person;

		cout << "_______Personal Information_______ \n";
		cout << "Enter your name: "; cin >> person.name;
		cout << "Enter your country: "; cin >> person.country;
		cout << "Enter your age: "; cin >> person.age;
		cout << "Enter your weight(kg): "; cin >> person.weight; cout << '\n';

		cout << "Name: " << person.name << endl;
		cout << "Country: " << person.country << endl;
		cout << "Age: " << person.age << endl;
		cout << "Weight: " << person.weight << "kg" << endl; person.points = score;
		cout << "Points: " << person.points << endl;

		dailyScores.push_back(make_pair(person.name, score)); // experimental , Need database to store the scores

   ExercisePersonal *p = &person;
   cout << "You are representing athelete of " << p->country << endl<< endl;
	

		return main();
}



