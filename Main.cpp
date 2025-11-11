#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void assignSentryRoles(vector<bool>& sentries) {
    srand(time(0));
    for (size_t i = 0; i < sentries.size(); ++i) {
        sentries[i] = rand() % 2; // 0 = lying, 1 = truthful
    }
}

int main() {
    const int numSentries = 5;
    vector<bool> sentries(numSentries);
    assignSentryRoles(sentries);

    vector<string> questions = {
        "Is 2+2=4?",
        "Is the sky green?",
        // Add more questions!
    };
    vector<bool> correctAnswers = { true, false };

    cout << "Welcome to the Truth or Lie Labyrinth Game!\n";
    // TODO: Game loop will go here
}
