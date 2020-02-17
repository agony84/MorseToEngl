/*Author: John Kear
 * Version: v1.0
 * Date: 2/17/2020
 *
 * Comments:
 * This program deciphers a morse code message into the english alphabet.
 * A space between words must be indicated with seven dots.
 * Each sequence of morse code must be separated by a space.
 *
 */
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;

const int ARRAY_SIZE = 38;

int main(){

	//arrays for both letters, numbers and corresponding signals
	char alpha [ARRAY_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.',' '};
	string morse [ARRAY_SIZE] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","......."};
	string input;
	bool found = false;
	char * token;
	string decoded;
	//get input string
	cout << "Enter your code: " <<endl;
	getline(cin, input);
	//compare each string element
	cout << "You entered: " << input << endl;
	token = strtok((char*)input.c_str(), " ");
	while(token != nullptr)
	{

		for(int i = 0; i < ARRAY_SIZE; i++){
			if(token == morse[i]){

				decoded += alpha[i];
				found = true;
			}//end if
		}//end for
		if(!found){
			cout << "Your code contains invalid sequence." << endl;
			cout << "Exiting now..." << endl;
			return 1;
		}

		token = strtok(nullptr, " ");
		found = false;

	}//end while

	cout << "Your decoded message is: " << decoded << endl;

	return 0;
}
