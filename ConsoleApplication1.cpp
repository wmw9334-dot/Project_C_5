#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3};
           //stone = ÕÃ— , paper = Ê—ﬁ… ,scissors = „ﬁ’
enum enWinner { player = 1, computer = 2, draw = 3 };

struct stround{
	short arr = 0;
	short player = 0;
	short computer = 0;
	short winner = 0;
	string winnerwonname = "";

};

struct stGamEover{
	short gameround = 0;
	short playerwon = 0;
	short computerwon = 0;
	short drawwon = 0;
	short finalwinner = 0;
	string finalwinnername = "";
};

int enrand(int from, int To) {
	int n = rand() % (To - from + 1) + from;
	return n;
}

int Computer() {
	return enrand(1,3);
}

int players() {
	int play;

	do{
		cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors : ";
		cin >> play;

	} while (play < 1 || play > 3);

	return play;
}

int readarr() {
	int n;
	do{
	cout << "How Many Rounds 1 to 10 ?\n";
	cin >> n;

	} while (n < 1 || n > 10);

	return n;
}

string Winnername(short num) {
	string name[3] = { "Player", "Computer", "Draw" };
	return name[num - 1];
}

enWinner FinaLwinner(int play,int computer) {
	
	if(play > computer) {

		return enWinner::player;
	}

	else if (computer > play) {

		return enWinner::computer;
	}
	
	else {
		return enWinner::draw;
	}
	
}

string ChoiceName(short Choice){  //ÊŸÌ› Â  ÕÊÌ· —ﬁ„ «Œ Ì«— «··«⁄» «Ê «·ﬂ„»ÌÊ — ›Ì ﬂ· ÃÊ·… «·Ï ‰’ ·⁄—÷Â ⁄·Ï «·„” Œœ„
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

enWinner whowontheround(int computer, int play) {

	if (computer == play) {
		return enWinner::draw;
	}

	else if ((play == enGameChoice::Stone && computer == enGameChoice::Scissors) ||
		(play == enGameChoice::Paper && computer == enGameChoice::Stone) ||
		(play == enGameChoice::Scissors && computer == enGameChoice::Paper)
		) {
		return enWinner::player;

	}
	else {
		return enWinner::computer;

	}
}

void clor(enWinner won) {

	switch (won) {
	case enWinner::player: 
		 system("color 1F");
		 break;

	case enWinner::computer: 
		 system("color 4F");
		cout << "\a";
		break;

	case enWinner::draw:
		 system("color 6F");
		 break;

	default:
		break;
	}
}

void myplaygame(stround sround){

		cout << "\n______________________________Round [" << sround.arr << "]___________________\n\n";

		cout << "Pleyer chice : " << ChoiceName(sround.player);

		cout << "\nComputer chice : ";
		cout << ChoiceName(sround.computer);

		cout << "\nRound Winner : [" << sround.winnerwonname << "]";
		cout << "\n________________________________________\n\n";

		clor(whowontheround(sround.computer, sround.player));
}

string tist(short num){

	for (int n = 1;n <= num;n++) {
		cout << "\t";
	}
	return "";
}

stGamEover fullgameover(int arr, int player,int computer,int draw) {
	stGamEover gameover;

	gameover.gameround = arr;
	gameover.playerwon = player;
	gameover.computerwon = computer;
	gameover.drawwon = draw;
	gameover.finalwinner = FinaLwinner(gameover.playerwon, gameover.computerwon);
	gameover.finalwinnername = Winnername(gameover.finalwinner);

	return gameover;
}

void GameOver(stGamEover gameover){
	cout << endl;
	cout << tist(3) << "________________________________________\n\n";
	cout << tist(3) << "+++ Game Over +++\n";
	cout << tist(3) << "________________________________________\n\n";
	cout << tist(3) << "_____________ [Game Results] ___________\n\n";

	cout << tist(3) << "Game Results : " << gameover.gameround << endl;
	cout << tist(3) << "Player won times : " << gameover.playerwon << endl;
	cout << tist(3) << "Computer won times : " << gameover.computerwon << endl;
	cout << tist(3) << "Draw times : " << gameover.drawwon << endl;
	cout << tist(3) << "Final Winner : [" << gameover.finalwinnername << "]\n";
	cout << tist(3) << "________________________________________\n";
}

stGamEover playgame(int arr) {
	stround sround;
	stGamEover game;

	int gameplayer = 0, gamecomputer = 0, gamedraw = 0;

	for (int n = 1; n <= arr;n++) {
		cout << "\nRound [" << n << "] begins : \n\n";

		sround.arr = n;
		sround.player = players();
		sround.computer = Computer();
		sround.winner = whowontheround(sround.computer, sround.player);
		sround.winnerwonname = Winnername(sround.winner);

		if (sround.winner == enWinner::player)
			gameplayer++;
		else if (sround.winner == enWinner::computer)
			gamecomputer++;
		else
			gamedraw++;

		myplaygame(sround);

	}

	return fullgameover(arr, gameplayer, gamecomputer, gamedraw);
}

void rewrite(){
	system("cls");
	system("color 0F");
}

void print() {
	string n = "";
	do
	{
		rewrite();
		stGamEover result = playgame(readarr());
		GameOver(result);

		cout << "\n\nDo you want to play again ? [Y/N] : ";
		cin >> n;
	} while (n == "Y" || n == "y");
}

int main(){
	srand((unsigned)time(NULL));

	print();


	 cout << "\n\n";
}