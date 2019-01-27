#include <iostream>
//This is needed for generating a random number
#include <ctime>
using namespace std;

int main() {
	//Introducing the program 
	system("Title Skynet HK-Aerial Software");
	cout << "Skynet HK-Aerial Software" << endl;
	cout << "Generating Random enemy location on an 8x8 grid...." << endl;

	//Variables
	int searchGridHighNumber = 64; 
	int searchGridLowNumber = 1;
	//Number of target location predictions it took to find the enemy
	int targetLocationPrediction = 0;
	int targetLocationPredictionCounter = 0;
	//Generating a random number from 1 - 64
	srand(time(0));
	int enemyLocation = rand() % 64 + 1;
	cout << "The enemy is located at location #" << enemyLocation << " on an 8x8 grid with 64 sectors.\n" << endl;
	//Is target found / destroyed 
	bool isTargetFound = false;

	cout << "Initializing Skynet HK-Aerial Software......" << endl; 

	// This loop will run until the enemy is found
	while (isTargetFound == false) {

		//Software selecting target location prediction in flyover hunt for enemy. (Thank you for this Mr. Hinton!)
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; //Binary search Algorithm  
		// Increases with each iteration 
		targetLocationPredictionCounter++;
		cout << "====================================================================================" << endl;
		

		//If the number the computer guessed is higher than the enemy position, this function will run
		if (targetLocationPrediction > enemyLocation) {
			cout << "Skynet HK-Aerial Radar sending out ping #" << targetLocationPredictionCounter << ":" << endl;
			// New high number guess
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
		}
		//If the number the computer guessed is lower than the enemy position, this function will run
		else if (targetLocationPrediction < enemyLocation) {
			cout << "Skynet HK-Aerial Radar sending out ping #" << targetLocationPredictionCounter << ":" << endl;
			// New low number guess
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
			cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
		}
		// If the number the compuer guessed is the enemy's location, this function will run
		else if (targetLocationPrediction == enemyLocation) {
			cout << "Enemy was hiding at location #" << enemyLocation << endl;
			cout << "Target was found at location #" << targetLocationPrediction << endl;
			cout << "Skynet HK-Aerial Software took " << targetLocationPredictionCounter << " predictions to find the enemy location on a grid size of 8x8" << endl;
			//Stops the while loop
			isTargetFound = true;
		}
	}
	system("pause");
	return 0; 
}