#include <iostream>
using namespace std;

class StudentRecord {
private:
    float quiz1, quiz2;
    float midtermScore;
    float finalExamScore;
    float weightedAverage;
    char letterGrade;

    void validateQuizzes(float x1, float x2) {
        if (x1 >= 0 && x1 <= 10) {
            quiz1 = x1;
        } else {
            cout << "Invalid Quiz 1 grade. It must be between 0 and 10." << endl;
            quiz1 = 0; 
        }

        if (x2 >= 0 && x2 <= 10) {
            quiz2 = x2;
        } else {
            cout << "Invalid Quiz 2 grade. It must be between 0 and 10." << endl;
            quiz2 = 0;
        }
    }

    void validateMidtermAndFinal(float m, float f) {
        if (m >= 0 && m <= 100) {
            midtermScore = m;
        } else {
            cout << "Invalid Midterm grade. It must be between 0 and 100." << endl;
            midtermScore = 0;
        }

        if (f >= 0 && f <= 100) {
            finalExamScore = f;
        } else {
            cout << "Invalid Final Exam grade. It must be between 0 and 100." << endl;
            finalExamScore = 0;
        }
    }

public:
    StudentRecord() : quiz1(0), quiz2(0), midtermScore(0), finalExamScore(0) {
        cout << "Object has been created." << endl;
    }

    StudentRecord(float q1, float q2, float midterm, float finalExam) {
        validateQuizzes(q1, q2);
        validateMidtermAndFinal(midterm, finalExam);
    }

    ~StudentRecord() {
        cout << "Object has been destroyed." << endl;
    }

    void setQuiz1(float q1) {
        if (q1 >= 0 && q1 <= 10) {
            quiz1 = q1;
        } else {
            cout << "Invalid Quiz 1 grade. It must be between 0 and 10." << endl;
        }
    }

    void setQuiz2(float q2) {
        if (q2 >= 0 && q2 <= 10) {
            quiz2 = q2;
        } else {
            cout << "Invalid Quiz 2 grade. It must be between 0 and 10." << endl;
        }
    }

    void setMidtermScore(float midterm) {
        if (midterm >= 0 && midterm <= 100) {
            midtermScore = midterm;
        } else {
            cout << "Invalid Midterm grade. It must be between 0 and 100." << endl;
        }
    }

    void setFinalExamScore(float finalExam) {
        if (finalExam >= 0 && finalExam <= 100) {
            finalExamScore = finalExam;
        } else {
            cout << "Invalid Final Exam grade. It must be between 0 and 100." << endl;
        }
    }

    float getQuiz1() const { return quiz1; }
    float getQuiz2() const { return quiz2; }
    float getMidtermScore() const { return midtermScore; }
    float getFinalExamScore() const { return finalExamScore; }
    float getWeightedAverage() const { return weightedAverage; }
    char getLetterGrade() const { return letterGrade; }

    void calculateWeightedAverage() {
        float quizPercentage = ((quiz1 + quiz2) / 20.0) * 100;
        weightedAverage = (quizPercentage * 0.25) + (midtermScore * 0.25) + (finalExamScore * 0.5);
    }

    void calculateLetterGrade() {
        if (weightedAverage >= 90)
            letterGrade = 'A';
        else if (weightedAverage >= 80)
            letterGrade = 'B';
        else if (weightedAverage >= 70)
            letterGrade = 'C';
        else if (weightedAverage >= 60)
            letterGrade = 'D';
        else
            letterGrade = 'F';
    }

    void displayRecord() const {
        cout << "Quiz 1 Score: " << quiz1 << "/10" << endl;
        cout << "Quiz 2 Score: " << quiz2 << "/10" << endl;
        cout << "Midterm Exam Score: " << midtermScore << "/100" << endl;
        cout << "Final Exam Score: " << finalExamScore << "/100" << endl;
        cout << "Weighted Average: " << weightedAverage << "%" << endl;
        cout << "Final Letter Grade: " << letterGrade << endl;
    }
};

int main() {
    StudentRecord student1;
    student1.setQuiz1(8.5);
    student1.setQuiz2(9.0);
    student1.setMidtermScore(78);
    student1.setFinalExamScore(85);
    student1.calculateWeightedAverage();
    student1.calculateLetterGrade();
    cout << "Student 1 Record:" << endl;
    student1.displayRecord();
    cout << endl;

    StudentRecord student2(9.5, 10, 85, 92);
    student2.calculateWeightedAverage();
    student2.calculateLetterGrade();
    cout << "Student 2 Record:" << endl;
    student2.displayRecord();

    return 0;
}
