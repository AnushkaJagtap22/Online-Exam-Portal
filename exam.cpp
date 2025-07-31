#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for toupper

using namespace std;

struct Question {
    string question, optA, optB, optC, optD;
    char correctOpt;
};

class ExamPortal {
    vector<Question> questionBank;
    int score = 0;

public:
    void addQuestion() {
        Question q;
        cin.ignore(); // flush input buffer
        cout << "Enter Question: ";
        getline(cin, q.question);
        cout << "Enter option A: ";
        getline(cin, q.optA);
        cout << "Enter option B: ";
        getline(cin, q.optB);
        cout << "Enter option C: ";
        getline(cin, q.optC);
        cout << "Enter option D: ";
        getline(cin, q.optD);
        cout << "Enter correct option (A/B/C/D): ";
        cin >> q.correctOpt;
        q.correctOpt = toupper(q.correctOpt);

        questionBank.push_back(q);
        cout << "Question added successfully!\n";
    }

    void takeExam() {
        score = 0;
        char ans;

        for (int i = 0; i < questionBank.size(); i++) {
            cout << "\nQ" << i + 1 << ": " << questionBank[i].question << endl;
            cout << "A. " << questionBank[i].optA << endl;
            cout << "B. " << questionBank[i].optB << endl;
            cout << "C. " << questionBank[i].optC << endl;
            cout << "D. " << questionBank[i].optD << endl;
            cout << "Enter your answer (A/B/C/D): ";
            cin >> ans;

            if (toupper(ans) == questionBank[i].correctOpt)
                score++;
        }

        cout << "\nExam Completed!\n";
        cout << "Your Score: " << score << " / " << questionBank.size() << endl;
    }

    void adminPanel() {
        string user, pass;
        cout << "Enter Admin Username: ";
        cin >> user;
        cout << "Enter Admin Password: ";
        cin >> pass;

        if (user == "admin" && pass == "admin123") {
            int ch;
            do {
                cout << "\n--- Admin Panel ---\n";
                cout << "1. Add Question\n2. Logout\nEnter your choice: ";
                cin >> ch;
                if (ch == 1)
                    addQuestion();
            } while (ch != 2);
        } else {
            cout << "Invalid credentials!\n";
        }
    }

    void studentPanel() {
        string name, pass;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Student Password: ";
        cin >> pass;

        cout << "\nWelcome " << name << "!\n";
        int ch;
        do {
            cout << "\n1. Take Exam\n2. Logout\nEnter your choice: ";
            cin >> ch;
            if (ch == 1)
                takeExam();
        } while (ch != 2);
    }
};

int main() {
    ExamPortal ep;
    int choice;

    do {
        cout << "\n=== Online Exam Portal ===\n";
        cout << "1. Admin Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ep.adminPanel();
                break;
            case 2:
                ep.studentPanel();
                break;
            case 3:
                cout << "Thank you for using the Exam Portal!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
