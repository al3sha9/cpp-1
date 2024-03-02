#include <iostream>
#include <string>
using namespace std;

class Sports {
private:
    string team1Name;
    string team2Name;
    int team1Score;
    int team2Score;

public:
    Sports(const string& name1, const string& name2) {
        team1Name = name1;
        team2Name = name2;
        team1Score = 0;
        team2Score = 0;
    }

    friend void inputScores(Sports& s);
    friend void displayScores(const Sports& s);
};

void inputScores(Sports& s) {
    cout << "Enter score for " << s.team1Name << ": ";
    cin >> s.team1Score;
    cout << "Enter score for " << s.team2Name << ": ";
    cin >> s.team2Score;
}

void displayScores(const Sports& s) {
    cout << "Team " << s.team1Name << " score: " << s.team1Score << endl;
    cout << "Team " << s.team2Name << " score: " << s.team2Score << endl;
}

int main() {
    Sports game("CS Team", "SE Team");
    inputScores(game);
    displayScores(game);

    return 0;
}
