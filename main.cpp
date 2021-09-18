/* ADVANTAGES/DISADVANTAGES ARRAY

*/
#include "commands.h";
#include "profiles.h";


int questions() {
    int questionAmmount = 0; // ammount of questions
    int choice = 0; // picking the command description
    int answer = 0; // Links to the correct description
    while (questionAmmount < 5 || questionAmmount > 30) {
        std::cout << "how many questions would you like? 5-30:"; // PROMPTING USER FOR THE NUMBER OF QUESTIONS +2
        std::cin >> questionAmmount;
        if (questionAmmount < 5 || questionAmmount > 30) {
            std::cout << "not valid number";
        }
    }
    Node<std::string, std::string>* pCur1 = NULL;
    for (int i = 0; questionAmmount > i; i++) { // int i used for GENERATING CORRECT NUMBER OF QUESTIONS +5

        // Initialize list
        CommandList<std::string, std::string> myList;
        pCur1 = myList.getPHead();
        // Generate a command from the command linked list
        std::cout << pCur1->getCommand();
        
        
        // Generate the description and 2 other random ones, assign answer +8

        std::cin >> choice;
        if (choice == answer) { // VERIFYING ANSWER +3
            // UPDATING PLAYER POINTS +2
            std::cout << "CORRECT!";
        }
        else {
            std::cout << "Incorrect...";
        }
    }


};

int Menu() {
    std::cout << "1. Play Rules" << std::endl;
    std::cout << "2. Play Game" << std::endl;
    std::cout << "3. Load Previos Game" << std::endl;
    std::cout << "4. Add Command" << std::endl;
    std::cout << "5. Remove Command" << std::endl;
    std::cout << "6. Exit" << std::endl;

    int choice = 0;
    std::cin >> choice;

    std::string newCommand = "";
    switch (choice)
    {
    case (1):

            // If 1, print rules, return main menu
        break;
    case (2):
            questions();
            // If 2, begin questions()
        break;
    case (3):
            std::cout << "What is your username?" << std::endl;
            //print stored points
            questions();

            // If 3, ask for profile name, print stored points from last game, now begin questions()
        break;
    case (4):
            std::cout << "Input new command..." << std::endl;
            // If 4, ask for a new command, input into the linked list of commands, reject if duplicate
        break;
    case (5):
            std::cout << "Which command would you like to delete?" << std::endl;

            //DELETE COMMAND
            // If 5, ask for a command to delete, delete from linked list if exists.
        break;
    case (6):

            // If 6, copy linked list to commands.csv
        break;
    default:
        break;
    }
   // MAIN MENU REQUIRMENT +5
}

int main() {
    Menu();

   // Each profile should be saved to profiles.csv


   // I MUST LIST 1 ADVANTAGE AND 1 DISADVANTAGE TO USING LINKED LIST FOR MY DATA STRUCTURE INVOLED WITH STORING THE COMMANDS AND DESCRIPTIONS IN THIS ASSINGMENT
   // I MUST LIST 1 ADVANTAGE AND 1 DISADVANTAGE TO USING AN ARRAY FOR MY DATA STRUCTURE FOR STORING PROFILES IN THIS ASSIGNMENT

    return 0;
}