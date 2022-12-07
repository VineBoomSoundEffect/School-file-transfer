//A c++ program supposed to help me study french vocabulary tests.
//Feel free to use it anyhow you desire
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

//for randomization
#include <stdlib.h>
#include <ctime>
using namespace std;

struct Word{
	char ro[255];
	char fr[255];
};

void read(Word word[200], int &n, char file[255]){
	ifstream f(file);
	int i = 0;
	while(f.get(word[i].fr, 255)){
		f.get();
		f.get(word[i].ro, 255);
		f.get();
		i++;
	}
	n = i;
}
void shuffle(Word word[200], int n){
	srand((int)time(NULL));
	int r1, r2;
	Word aux;
	for(int i=0;i<600;i++){
		r1 = rand()%n;
		r2 = rand()%n;
		aux = word[r1];
		word[r1] = word[r2];
		word[r2] = aux;
	}
}
void actual_stuff(Word word[200], int n){
	int score = 0;
	char input[255];
	for(int i=0;i<n;i++){
		cout << word[i].ro << ": ";
		cin.get(input, 255);
		cin.get();
		if(!strcmp(input, "exit")) break;
		if(strcmp(word[i].fr, input))
			cout << word[i].fr << "\n";
		else{
			score++;
		}
	}
	cout << "YOUR SCORE: " << score << "/" << n << "\n";
}
int main(int argc, char ** argv){
	char again;
	Word word[200];
	int n;
	if(!argv[1]){
		char fileInput[255];
		cout << "Enter input file: ";
		cin.get(fileInput, 255);
		cin.get();
		read(word, n, fileInput);
	}
	else read(word, n, argv[1]);
	again = 'y';
	while(again != 'n'){
		shuffle(word, n);
		actual_stuff(word, n);
		cout << "Again?(y/n)";
		again = getch();
		cout << "\n\n";
	}
	return 0;
}
