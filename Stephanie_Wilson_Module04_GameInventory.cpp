// Stephanie Wilson IN200
// Module 04 
// Chapter 3 Assignment

#include <iostream>
#include <string>
#include <chrono>  // used for sleep
#include <thread>  // used for sleep
#include <cstdlib> // used to generate random numbers
#include <ctime>   // used to generate random numbers

using namespace std;

int main() {
  const int MAX_GAMES = 15;    // number of items in array
  
  // create array and use collection initializer to add values
  string gameInventory[MAX_GAMES] = {"Need for Speed", "World of Warcraft",
     "Half-Life 2", "Overlord"};  
     
  int numGames = 4;      // current number of games
  string mystr;          // to store user input
  string newGame;
  bool gameFound = false;
  
  cout << "Welcome to Your Game Station!\n\n";
  
  // choose random Game
  srand(static_cast<unsigned int>(time(0)));  // seed random generator
  int random = (rand() % numGames); // generate random index from number of games in array
  string gameOfDay = gameInventory[random];
  
  cout << "The Game of the Day is " << gameOfDay << ". Have you played it? Y or N?  ";
  this_thread::sleep_for(chrono::milliseconds(500));   //pause 500 milliseconds
  getline(cin, mystr);
  if (mystr == "Y" || mystr == "y") {
    cout << "\nThat's awesome! It's a great game!\n";
  } else {
    cout << "\nToo bad! You should try it out today!\n";
    }
  
  this_thread::sleep_for(chrono::milliseconds(500));   //pause 500 milliseconds
  cout << "\n\nSearching for the game, 'Half-Life 2'...\n";
  this_thread::sleep_for(chrono::milliseconds(1000));    //pause 1 second
  
  // iterate through array and look for Half-Life 2
  for (int i = 0; i < numGames; i++) {         
    if (gameInventory[i] == "Half-Life 2"){
      gameFound = true;
    }
  }
  
  // display result of searching for Half-Life 2
  if (gameFound == true) {
    cout << "\nYes! Half-Life 2 is in the game inventory!\n";
  } else {
    cout << "\nSorry, the inventory does not have Half-Life 2.\n";
    }
  
  this_thread::sleep_for(chrono::milliseconds(1000));     //pause 1 second
  cout << "\n\nWould you like to add another game? Y or N?  ";
  getline(cin, mystr);
  
  // loop through adding new game to inventory and displaying results as long as user answers yes
  while (mystr == "Y" || mystr == "y") {
    this_thread::sleep_for(chrono::milliseconds(500));     //pause 500 milliseconds
    cout << "\nEnter the name of the game you would like to add: ";
    getline(cin, mystr);
    newGame = mystr;
    this_thread::sleep_for(chrono::milliseconds(500));    //pause 500 milliseconds
    cout << "\nThank you. You entered " << newGame << ".\n";
    gameInventory[numGames++] = newGame;   // add new game to gameInventory array
    this_thread::sleep_for(chrono::milliseconds(1000));   //pause 1 second
    cout << "\nList of games in inventory now:\n\n";
    
    // iterate through games listed in the array
    for (int i = 0; i < numGames; i++) {          
          cout << i + 1 << ". " << gameInventory[i] << endl; // display numbered list of games in inventory array
    }
    
    this_thread::sleep_for(chrono::milliseconds(1000));    //pause 1 second
    cout << "\n\nWould you like to add another game? Y or N?  ";
    getline(cin, mystr);
  }
  
  this_thread::sleep_for(chrono::milliseconds(500));      //pause 500 milliseconds
  cout << "\n\nGoodbye. Check back tomorrow for another Game of the Day.";
  
  return 0;
  
}