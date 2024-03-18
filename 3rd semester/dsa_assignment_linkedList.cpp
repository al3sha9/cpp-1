#include <iostream>
using namespace std;

struct Agent {
    string codename;
    Agent* next;
    
    Agent(string alias) : codename(alias), next(nullptr) {}
};

class CovertTeam {
private:
    Agent* head;
    int teamSize;

public:
    CovertTeam() : head(nullptr), teamSize(0) {}

    void recruit(string alias) {
        Agent* newAgent = new Agent(alias);
        if (head == nullptr) {
            head = newAgent;
        } else {
            Agent* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newAgent;
        }
        teamSize++;
    }

    string courier(int evasionFactor) {
        Agent* current = head;
        Agent* previous = nullptr;

        while (current->next != nullptr) {
            current = current->next;
        }

        while (teamSize > 1) {
            for (int i = 0; i < evasionFactor; i++) {
                previous = current;
                current = current->next != nullptr ? current->next : head;
            }
            previous->next = current->next;
            Agent* temp = current;
            current = current->next != nullptr ? current->next : head;
            delete temp;
            teamSize--;
        }

        return current->codename;
    }
};

int main() {
    int operatives, evasion;
    cout << "Enter the number of operatives: ";
    cin >> operatives;
    cout << "Enter the evasion factor: ";
    cin >> evasion;

    CovertTeam teamAlpha;
    for (int i = 0; i < operatives; i++) {
        string alias;
        cout << "Enter the alias of agent " << i + 1 << ": ";
        cin >> alias;
        teamAlpha.recruit(alias);
    }

    string courier = teamAlpha.courier(evasion);
    cout << "The designated courier of sensitive intel is " << courier << endl;

    return 0;
}
