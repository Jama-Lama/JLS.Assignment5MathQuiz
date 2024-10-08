//Assignment 5 - Math Quiz
//James-Lee Spaulding

//Include and Namespace statments
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	//Save path for QuizQuestions.txt and QuizResults.txt in program memory
	string quizQuestionsFilepath = "C:\\Temp\\QuizQuestions.txt";
	string quizResultsFilepath = "C:\\Temp\\QuizResults.txt";

	//Create space for questions in program memory
	vector<string> questions;

	//Initialize the random number generator
	srand(time(NULL));
	int randomNumber;

	//Save Questions to Vector in program
	int numQuestions = 0;
	string returnLine;
	ifstream ifs(quizQuestionsFilepath);
	while (getline(ifs, returnLine)) {
		questions.push_back(returnLine);
		numQuestions++;
	}	
	ifs.close();

	//Begin Outputting Questions (and other text) and Saving Input Answers
	cout << "Welcome to the Math Quiz!\n";
	ofstream ofs(quizResultsFilepath);
	for (int i = 0; i < 3; i++) {
		randomNumber = rand() % numQuestions;
		cout << "\nQuestion " << (i + 1) << ": " << questions.at(randomNumber) << " = " << "\nEnter your answer: ";
		cin >> returnLine;
		ofs << questions.at(randomNumber) << " = " << returnLine << "\n";
	}
	ofs.close();

	//Hold Program Open and Return 0 (Allow Verificaiton of all Output)
	(void)_getch();
	return 0;
}