#include <iostream>
#include <string>

int ans;													// Player input
int const num = 9; 
char choices[num] = {'1','2','3','4','5','6','7','8','9'};	// Choices on screen
char place[num] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };	// What is printed on the slots at the table. "X", "O", or " ".
bool taken[num];											// Checks if the slots are taken or not
int counter = 0;											// Used to check whose turn it is
bool checkInvalid = false;									// Used in invalidCheck() to see if a slot is already taken or not

int currentPlayer = 1;
int winner = 0;
bool game = true;
int slotCounter = 0;

void playerChoice(int num); 
void print();

void winnerP1Check();
void winnerP2Check();

void gameReset();
void p1Win();
void p2Win();
void invalidChoice(bool check);
void draw();


int main() {

	bool exit = false;
	int res;
	//	Uses a doWhile to make sure the program runs ones atleast and that the user stays in the program until they chose to end
	do {
		std::cout << "Would you like to play Tic Tac Toe? \n1. Yes \n2. No" << std::endl;
		std::cin >> res;
		std::cout << std::endl;
		
		switch (res)
		{
		case 1:
			gameReset();
			game = true;
			break;
		case 2:
			game = false;
			exit = true;
			return 0;
			break;
		default:
			break;
		
		}
		while (game == true) {
			counter++;
			print();
			if (counter % 2 == 0) {
				currentPlayer = 2;
				std::cout << "Player 2's turn" << std::endl;
			}
			else {
				currentPlayer = 1;
				std::cout << "Player 1's turn" << std::endl;
			}
			std::cin >> ans;
			
			playerChoice(ans);
			winnerP1Check();
			winnerP2Check();
			
			draw();
		} 
	} while (exit == false);

	return 0;
	
}

// Prints out the table and the available choices
// Uses system("cls") to clean the screen so it is printed at the top
void print(){
	
	system("cls");
	std::cout << "        |       |       \n";	 
	std::cout << "    " << place[0] << "   |   "<<place[1]<<"   |   "<<place[2]<<"   \n";
	std::cout << "        |       |       \n";	
	std::cout << " -----------------------\n";	 
	std::cout << "        |       |       \n";
	std::cout << "    " << place[3] << "   |   " << place[4] << "   |   " << place[5] << "   \n";
	std::cout << "        |       |       \n";
	std::cout << " -----------------------\n";
	std::cout << "        |       |       \n";
	std::cout << "    " << place[6] << "   |   " << place[7] << "   |   " << place[8] << "   \n";
	std::cout << "        |       |       \n";
	std::cout << std::endl;
	
	for (int i = 0; i < num; i++) {
		if (i % 3 == 0) {
			std::cout << "\n\n";
		}
		std::cout << "  " << choices[i] << "  ";
	}
	std::cout << std::endl;

	/// Function used to check if the spot is taken or not
	///	Boolean is set in playerChoice()
	invalidChoice(checkInvalid);
}

//	Resets the table and the player choices for the next game
void gameReset() {
	counter = 0;
	for (int i = 0; i < 9; i++) {
		place[i] = ' ';
		taken[i] = false;
	}
	choices[0] = '1';
	choices[1] = '2';
	choices[2] = '3';
	choices[3] = '4';
	choices[4] = '5';
	choices[5] = '6';
	choices[6] = '7';
	choices[7] = '8';
	choices[8] = '9';
	system("cls");
}

// Places an X or O based on place[] based off of who is the current player.
// since the array starts at 0 the players input needs to be changed to: ans - 1
// When the player takes a spot the bool array for that spot is turned to true
// That bool array is then checked to see if the players choice is already taken
// If it is taken it turns the bool checkInvalid to true which is used in the function invalidChoice();
void playerChoice(int num) {
	int r = num - 1;
	if (taken[r] == true) {
		checkInvalid = true;
		counter - 1;
		return;
	}
	else {
		checkInvalid = false;
	}

	taken[r] = true;
	
	if (currentPlayer == 1) {
		place[r] = 'X';
	}
	else if (currentPlayer == 2) {
		place[r] = 'O';
	}
	choices[r] = ' ';

	if (taken[r] == false) {
		place[r] = ' ';
	}
}

// A list of if statements checking if X or O are 3 in a row
void winnerP1Check() {		
	// Horisontalt
	if (place[0] == 'X' && place[1] == 'X' && place[2] == 'X') {
		print();
		p1Win();
		game = false;
	}
	if (place[3] == 'X' && place[4] == 'X' && place[5] == 'X') {
		print();
		p1Win();
		game = false;
	}
	if (place[6] == 'X' && place[7] == 'X' && place[8] == 'X') {
		print();
		p1Win();
		game = false;
	}	  

	// Vertikalt
	if (place[0] == 'X' && place[3] == 'X' && place[6] == 'X') {
		print();
		p1Win();
		game = false;
	}
	if (place[1] == 'X' && place[4] == 'X' && place[7] == 'X') {
		print();
		p1Win();
		game = false;
	}
	if (place[2] == 'X' && place[5] == 'X' && place[8] == 'X') {
		print();
		p1Win();
		game = false;
	}

	// Diagonalt
	if (place[6] == 'X' && place[4] == 'X' && place[2] == 'X') {
		print();
		p1Win();
		game = false;
	}
	if (place[0] == 'X' && place[4] == 'X' && place[8] == 'X') {
		print();
		p1Win();
		game = false;
	}
}
void winnerP2Check() {		
	// Horisontalt
	if (place[0] == 'O' && place[1] == 'O' && place[2] == 'O') {
		print();
		p2Win();
		game = false;
	}
	if (place[3] == 'O' && place[4] == 'O' && place[5] == 'O') {
		print();
		p2Win();
		game = false;
	}
	if (place[6] == 'O' && place[7] == 'O' && place[8] == 'O') {
		print();
		p2Win();
		game = false;
	}

	// Vertikalt
	if (place[0] == 'O' && place[3] == 'O' && place[6] == 'O') {
		print();
		p2Win();
		game = false;
	}
	if (place[1] == 'O' && place[4] == 'O' && place[7] == 'O') {
		print();
		p2Win();
		game = false;
	}
	if (place[2] == 'O' && place[5] == 'O' && place[8] == 'O') {
		print();
		p2Win();
		game = false;
	}

	// Diagonalt
	if (place[6] == 'O' && place[4] == 'O' && place[2] == 'O') {
		print();
		p2Win();
		game = false;
	}
	if (place[0] == 'O' && place[4] == 'O' && place[8] == 'O') {
		print();
		p1Win();
		game = false;
	}

	//return;
}

// Prints out who the winner is and ends the game, used in 
// winnerP1Check(); and winnerP2Check();
void p1Win() {
	winner = 1;
	game = false;
	std::cout << "\nPlayer 1 wins\n" << std::endl;
}
void p2Win() {
	winner = 2;
	game = false;
	std::cout << "\nPlayer 2 wins\n" << std::endl;
}

// Uses a for loop as a counter to how many slots are taken based 
// wether the taken[] bool at that slot is true or not
// If the counter reaches nine it ends the game and says it is a draw
void draw() {
	slotCounter = 0;
	for (int i = 0; i < 9; i++) {
		if (taken[i] == true) {
			slotCounter++;
		}
	}
	if (slotCounter % 9 == 0 && winner == 0) {
		game = false;
		print();
		std::cout << "Thats a draw";
	}
}

// Prints out wether the move is invalid or not
void invalidChoice(bool check) {
	if (check == true) {
		std::cout << "Invalid choice. Turn skipped to next player" << std::endl;
		check = false;
	}
}