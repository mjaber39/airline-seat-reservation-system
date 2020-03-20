#include <iostream>
#include <vector>
using namespace std;

//Display AVAILABLE seats
void displaySeats(vector<vector<int> > seats) {

	for (int i = 0; i < seats.size(); i++) {

		cout << (char)('A' + i) << " ";
		for (int j = 0; j < seats[i].size(); j++) {

			if (seats[i][j]) {
				cout << seats[i][j] << " ";
			}
			else {
				cout << "X" << " ";
			}
		}
		if (i == 1) {
			cout << endl << endl << "\t" << "AISLE";
		}
		cout << endl << endl;
	}
}

//Display MENU to the user
void displayMenu() {
	cout << "\t ***MENU*** \t" << endl;
	cout << "1. Reserve a seat of choice." << endl;
	cout << "2. Reserve a window seat." << endl;
	cout << "3. Reserve an aisle seat." << endl;
	cout << "4. Reserve a seat (any available)" << endl;
	cout << "5. Withdraw reservation" << endl;
	cout << "6. Update reservation" << endl;
	cout << "7. Display available seats" << endl;
	cout << "\nEnter your choice: ";
}

//Reserve a seat of CHOICE
void reserveSeatOfChoice(vector<vector<int> > &seats) {
	int col;
	char row;
	char choice = 'y';

	while (choice == 'y') {

		cout << "Enter row A/B/C/D (capital)" << endl;
		cin >> row;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Enter seat number (1-100)" << endl;
		cin >> col;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (row >= 'A' && row <= 'D' && col >= 1 && col <= 100) {

			if (seats[row - 'A'][col - 1]) {
				seats[row - 'A'][col - 1] = 0;
				cout << "Congratulations, your seat is booked at " << (char)row << col << endl << endl;
				displaySeats(seats);
				return;
			}
			else {
				cout << "Sorry, seat already booked. Try again.(y/n) " << endl;
			}
		}
		else {
			cout << "Invalid. Try again(y/n)";
		}
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

//Reserve a WINDOW seat
void reserveWindowSeat(vector<vector<int> > &seats) {
	// Check in row A
	for (int j = 0; j < 100; j++) {
		if (seats['A' - 'A'][j]) {
			seats['A' - 'A'][j] = 0;
			cout << "Congratulations, your seat is booked at " << (char)'A' << j + 1 << endl;
			displaySeats(seats);
			return;
		}
	}

	// Check in row D
	for (int j = 0; j < 100; j++) {
		if (seats['D' - 'A'][j]) {
			seats['D' - 'A'][j] = 0;
			cout << "Congratulations, your seat is booked at " << (char)'D' << j + 1 << endl;
			displaySeats(seats);
			return;
		}
	}

	cout << "Sorry. All Window seats are booked.";

}

//Reserve an AISLE seat
void reserveAisleSeat(vector<vector<int> > &seats) {

	// Check in row B
	for (int j = 0; j < 100; j++) {
		if (seats['B' - 'A'][j]) {
			seats['B' - 'A'][j] = 0;
			cout << "Congratulations, your seat is booked at " << (char)'B' << j + 1 << endl;
			displaySeats(seats);
			return;
		}
	}

	// Check in row C
	for (int j = 0; j < 100; j++) {
		if (seats['C' - 'A'][j]) {
			seats['C' - 'A'][j] = 0;
			cout << "Congratulations, your seat is booked at " << (char)'C' << j + 1 << endl;
			displaySeats(seats);
			return;
		}
	}

	cout << "Sorry. All Aisle seats are already booked.";
}

// Researve ANY seat
void reserveAnySeat(vector<vector<int> > &seats)
{
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 100; j++) {

			if (seats[i][j]) {
				seats[i][j] = 0;
				cout << "Congratulations, your seat is booked at " << (char)('A' + i) << j + 1 << endl;
				displaySeats(seats);
				return;
			}
		}

	}
	cout << "Sorry. All seats are already booked.";
}

//Withdraw reservation
void withdraw(vector<vector<int> > &seats) {
	int col;
	char row;
	char choice = 'y';

	while (choice == 'y') {
		cout << "Enter row A/B/C/D (capital)" << endl;
		cin >> row;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter seat number (1-100)" << endl;
		cin >> col;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (row >= 'A' && row <= 'D' && col >= 1 && col <= 100) {
			if (seats[row - 'A'][col - 1] == 0) {
				seats[row - 'A'][col - 1] = col;
				cout << "Seat withdrawn." << endl;
				displaySeats(seats);
				return;
			}
			else {
				cout << "This seat is not reserved. Try again?(y/n) ";
			}
		}
		else {
			cout << "Invalid. Try again(y/n) ";
		}
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

//Update reservation
void update(vector<vector<int> > &seats) {

	cout << "First withdraw the previous reservation. " << endl;
	withdraw(seats);
	cout << "Enter the new Seat of your choice. " << endl;
	reserveSeatOfChoice(seats);
}

int main() {

	vector<vector<int> > seats(4, vector<int>(100));

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 100; j++) {
			seats[i][j] = j + 1;
		}

	}

	char ch = 'y';
	while (ch == 'y') {

		int choice;
		system("cls");
		displayMenu();
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice) {
		case 1:
			reserveSeatOfChoice(seats);
			break;

		case 2:
			reserveWindowSeat(seats);
			break;

		case 3:
			reserveAisleSeat(seats);
			break;

		case 4:
			reserveAnySeat(seats);
			break;

		case 5:
			withdraw(seats);
			break;

		case 6:
			update(seats);
			break;

		case 7:
			displaySeats(seats);
			break;

		default:
			cout << "Invalid choice." << endl;
		}
		cout << "Continue? (y/n) ";
		cin >> ch;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Thank you." << endl;
}