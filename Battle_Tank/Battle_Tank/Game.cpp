#include "Game.h"

void Game::runGameLoop(std::string boardFilesName, Tank& player1, Tank& player2, Board& board) {
    bool isBoardValid;
    int gamesPlayed = 0;

    if (!shouldQuit) {
        ShellManager shellManager(board);
        isBoardValid = board.load(boardFilesName, player1, player2);
        if (!isBoardValid) {
            menu.showInvalidBoardMessage(boardFilesName);
        }
        board.print();

        while (!shouldExit) {

            handleKeyPress(player1,player2, board, shouldExit);

            player1.draw();
            player2.draw();

            /*
            here we will add the shoots creation and draw
            */
            Sleep(sleepDuration);
            /*
            here we will add the shoots erase and move
            */

            /*checkCollsionsWithPlayer(player1, shellManager);
            checkCollsionsWithPlayer(player2, shellManager);*/

            // Erase and move players
            player1.eraseAndMovePlayer(player1);
            player2.eraseAndMovePlayer(player2);

            //checkCollsionsWithPlayer(player1, shellManager);
            //checkCollsionsWithPlayer(player2, shellManager);
        }
    }
};

void Game::startingMenu() {
    bool exitMenu = false;

    while (!exitMenu) {
        clearConsole();
        menu.startingMenu();

        int userInput = getUserInput();


        clearConsole();
        switch (userInput) {
        case 1: {
            Board board;

            startGame("BT_screen.screen");

            break;
        }
        case 6:
            Menu::useEmojis = !Menu::useEmojis;
            break;
        case 7:
            Menu::useColor = !Menu::useColor;
            break;
        case 8:
            showInstructionsMenu();
            // Continue the loop after showing instructions
            break;
        case 9:
            exitGameMenu();
            exitMenu = true; // Set exitMenu to true to exit the loop
            break;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
            Sleep(2000);
            break;
        }
    }
}

void Game::deathAnimation(Tank& player) {
    int playerX = player.getX();
    int playerY = player.getY();
    gotoxy(playerX - 5, playerY - 1);
    printToScreen(playerX, playerY, explosionChar);
    Sleep(3 * 70);
}

void Game::checkCollsionsWithPlayer(Tank& player, ShellManager& shellManager) {
    // Check if a shell moved into a player position
    if (shellManager.checkCollisionWithPlayer(player)) {
        deathAnimation(player);
        clearConsole();
        if (player.getPlayerNum() == First)
            menu.deathMenu(Second, First);
        else
            menu.deathMenu(First, Second);
        _getch();
        shouldExit = true;
        startingMenu();
    }
}

void Game::startGame(std::string boardFileName) {
    ShowConsoleCursor(false);
    Board board;

    Tank player1(&board);
    player1.setPlayerNum(First);
    player1.setKeys("edqasw");
    player1.setNumKeys();

    Tank player2(&board);
    player2.setPlayerNum(Second);
    player2.setKeys("olujki");
    player2.setNumKeys();


    //Time timer;

    shouldExit = false;  // Set exit flag to false at the start
    shouldQuit = false;
    runGameLoop(boardFileName, player1, player2, board);
}

int Game::getUserInput() {
    int i = 0;
    int userInput = 0;

    while (!validateUserInput(userInput)) {
        gotoxy(25, 16 + i);
        std::cout << "Please enter a valid option: ";
        std::cin >> userInput;

        i++;
    }

    return userInput;
}

// Private functions
// Starts the game: sets up board, player, and runs the game loop
bool Game::pausingGameMenu(Board& board) {
    clearConsole();
    menu.pausingGameMenu();

    if (_getch() == ESC) {
        clearConsole();
        board.print();
        return true;
    }
    else
        return false;
}

void Game::handleKeyPress(Tank& player1, Tank& player2, Board& board, bool& shouldExit) {
    if (_kbhit()) {
        char key = _getch();
        if (key == ESC) {

            if (!pausingGameMenu(board))
                shouldExit = true;
            else {
                shouldExit = false;
            }
        }
        else if (checkPressP(player1, key))
			player1.keyPressed(key);
		else if (checkPressP(player2, key))
			player2.keyPressed(key);
    }
}

void Game::exitGameMenu() {
    shouldExit = true;
    clearConsole();
    menu.exitGameMenu();
    _getch();
    clearConsole();
}

void Game::showInstructionsMenu() {
    menu.showInstructionsMenu();
    _getch();
    clearConsole();
    startingMenu();
}

void Game::deathMenu(int playerWon, int playerLost) {
    clearConsole();
    menu.deathMenu(playerWon, playerLost);
    _getch();
    shouldExit = true;
    startingMenu();
}

bool Game::checkPressP(Tank& player, char key) {
	size_t size = player.getNumKeys();
    for (size_t i = 0; i < size; i++) {
        if (std::tolower(key) == player.getkeys(i)) {
            player.setCurrentKey(key);
            return true;
        }
    }
        return false;
}


//void Game::manageLife(Tank& player) {
//
//    if (player.getObjectLife() == 0) {
//        shouldExit = false;
//        if (player.Number == 1) {
//            deathMenu(1, 2);
//        }
//        else {
//            deathMenu(2, 1);
//        }
//        
//    }
//}