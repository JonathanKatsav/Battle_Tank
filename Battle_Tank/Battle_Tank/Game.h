#pragma once

#include "utils.h"
#include "Menu.h"
#include "Board.h"
#include "ShellManager.h"



class Game {
	Menu menu;

	static constexpr int ESC = 27;
	static constexpr int sleepDuration = 300;

	int totalTime = 0;
	bool shouldExit = false; // Flag to check if the game should exit
	bool shouldQuit = false; // Flag to check if the game should quit

	bool pausingGameMenu(Board& board);
	void handleKeyPress(Tank& player1, Tank& player2, Board& board, bool& shouldExit);
	void exitGameMenu();
	void showInstructionsMenu();
	void deathMenu(int playerWon, int playerLost);
	/*void manageLife(Tank& player);*/
public:

	void startingMenu();

	void run() {
		startingMenu();
	}

	void startGame(std::string boardFilesName);
	int getUserInput();
	// Function to validate user input for the starting menu
	bool validateUserInput(int input) {
		return input == 1 || input == 6 || input == 8 || input == 9;
	}
	void runGameLoop(std::string boardFileName, Tank& player1, Tank& player2, Board& board);
	void deathAnimation(Tank& player);
	void checkCollsionsWithPlayer(Tank& player, ShellManager& shellManager);
	bool checkPressP(Tank& player, char key);
};

