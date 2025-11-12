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
        "Is the sky green?"
        "Is Ahmed left handed?",
        "Does Anthony have a dog?"
        // Add more questions!
    };
    vector<bool> correctAnswers = { true, false, true, false };

    cout << "Welcome to the Truth or Lie Labyrinth Game!\n";

    int score = 0;
    for (int questionsAsked = 0; questionsAsked < 5; ++questionsAsked) {
        int sentryChoice;
        cout << "\nChoose a sentry to question (1-" << numSentries << "): ";
        cin >> sentryChoice;
        if (sentryChoice < 1 || sentryChoice > numSentries) {
            cout << "Invalid sentry. Try again.";
            continue;
        }
        sentryChoice--;

        int questionIdx = rand() % questions.size();
        cout << "Question: " << questions[questionIdx] << endl;

        bool answer = sentries[sentryChoice] ? correctAnswers[questionIdx] : !correctAnswers[questionIdx];
        cout << "Sentry's answer: " << (answer ? "Yes" : "No") << endl;

        string guess;
        cout << "Is the sentry telling the truth? (yes/no): ";
        cin >> guess;

        bool userGuessTruth = (guess == "yes");
        if (userGuessTruth == sentries[sentryChoice]) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong!\n";
        }
    }

    cout << "\nGame over. You correctly identified " << score << " sentry roles out of 5.\n";
}
