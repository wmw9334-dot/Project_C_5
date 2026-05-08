#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

enum enLevel{Easy = 1, Med = 2, Hard = 3, Mix = 4};

enum enSignal {Add = 1,Sub = 2, Mul = 3, Div = 4};

struct stRound {

    int LeveLentry1 = 0;
    int LeveLentry2 = 0;
    int sigalentry = 0;
    char sigal1234 = 0;
};

int enrand(int from, int To) {
    int n = rand() % (To - from + 1) + from;
    return n;
}

int ouestion() {
    int num;

    do{
        cout << "How Many Ouestions do you want to answer ? ";
        cin >> num;

    } while(num <= 0);

    return num;
}

int Level() {
    int num;

    do {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> num;

    } while (num <= 0 || num > 4);

    return num;
}

int MixLevel(int num){

    if (num == enLevel::Mix) 
        return enrand(1, 3);

    else
        return num;
}

int levelentry1(int num) {

    switch (num) {
    case enLevel::Easy:
        return enrand(1, 10);

    case enLevel::Med:
        return enrand(10, 50);

    case enLevel::Hard:
        return enrand(50, 100);
    }
}

int levelentry2(int num) {

    switch (num) {
    case enLevel::Easy:
        return enrand(1, 10);

    case enLevel::Med:
        return enrand(10, 50);

    case enLevel::Hard:
        return enrand(50, 100);
    }
}

int ReadSignal() {

    int num;

    do {
        cout << "Enter Questions Level [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> num;

    } while (num <= 0 || num > 5);

    return num;
}

int MixSignal(int num){
    if (num == 5)
        return enrand(1, 4);
    else
        return num;
}

int SigalEntry(int num,int S1,int S2) {

    switch (num) {
        case enSignal::Add:
            return S1 + S2;

        case enSignal::Sub:
            return S1 - S2;

        case enSignal::Mul:
            return S1 * S2;

        case enSignal::Div:
            return S1 / S2;
    }
}

char Sigal1234(int num) {
    char sigal[4] = {'+','-','*','/'};
    return sigal[num - 1];
}

int read() {
    int N;
    cin >> N;
    return N;
}

void VS(int play,int compute, stRound rounds) {

    if (play == compute) {
        cout << "Right Answer :-)";
        system("color 2F");
    }
    else {
        cout << "Worng Answer :-(\a";
         system("color 4F");
         cout << "\nThe right answer is: " << rounds.sigalentry;
    }
}

void printRound(stRound rounds,int &Reads) {

    cout << rounds.LeveLentry1 << endl;
    cout << rounds.sigal1234 << endl;
    cout << rounds.LeveLentry2 << endl;
    cout << "________________\n";
    Reads = read();

    VS(Reads,rounds.sigalentry,rounds);
    cout << "\n";
}

string QuestionLevel(int num){
    string arr[4] = { "Easy","Med","Hard","Mix"};
    return arr[num - 1];
    }

string Readsignal(int num){
    string arr[5] = { "Add","Sub","Mul","Div","Mix" };
    return arr[num - 1];
}

void gameOver(int Right, int Wrong){

    if(Right >= Wrong){
        cout << "\n\n\t\t\t\tFinal Resutls is PASS :-)";
         system("color 2F");
    }
    else {
        cout << "\n\n\t\t\t\tFinal Resutls is FAIL :-(\a";
         system("color 4F");
    }

}

string Text(int number) {

    for (int n = 1;n <= number;n++) {
        return "\t\t\t\t";
    }
}

int printGameOver(short arrnum,int Right, int Wrong,int Level,int readsignal){
    cout << Text(3) <<"_____________________________";
    cout << endl;
     gameOver(Right, Wrong);
     cout << endl;
    cout << Text(3) << "_____________________________\n";
    cout << endl;
    cout << Text(3) << "Number of Questions:     " << arrnum << endl;
    cout << Text(3) << "Questions Level:        " << QuestionLevel(Level) << endl;
    cout << Text(3) << "OpType:                 " << Readsignal(readsignal) << endl;
    cout << Text(3) << "Number of Right Answers: " << Right << endl;
    cout << Text(3) << "Number of Wrong Answers: " << Wrong << endl;
    cout << Text(3) << "_____________________________\n";

    return 0;
}

void Results(){
    system("color 0F");
    system("cls");
}

int play(int num) {
    stRound rounds;

    int Reads;
    int L = Level();
    int RS = ReadSignal();

    int Right = 0, Wrong = 0;

    for(int n = 1;n <= num;n++){
        cout << "\n\nQuestion [" << n << "/" << num << "]\n\n";
        int mixL = MixLevel(L);
        int mixRS = MixSignal(RS);

        rounds.LeveLentry1 = levelentry1(mixL);
        rounds.LeveLentry2 = levelentry2(mixL);
        rounds.sigal1234 = Sigal1234(mixRS);
        rounds.sigalentry = SigalEntry(mixRS, rounds.LeveLentry1, rounds.LeveLentry2);

         printRound(rounds,Reads);

         if(rounds.sigalentry == Reads){
             Right++;
         }
         else{
             Wrong++;
         }
    }
    return printGameOver(num,Right, Wrong,L,RS);
}

void print() {
    char OR;

    do{
        Results();
        play(ouestion());

        cout << "\nDo you want to play the game ? [Y/N] ";
        cin >> OR;

    } while (OR == 'y' || OR == 'Y');

}

int main(){
    srand((unsigned)time(NULL));

    print();

}