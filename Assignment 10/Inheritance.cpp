#include <iostream>
using namespace std;

class students
{
    int rollno;

public:
    students(int a) : rollno(a) {}
    int getRollno() const { return rollno; }
};

class test : virtual protected students
{
    int phy, chem, maths;

public:
    test(int r, int a, int b, int c) : students(r), phy(a), chem(b), maths(c) {}
    int getPhy() { return phy; }
    int getChem() { return chem; }
    int getMaths() { return maths; }
};

class sports : virtual protected students
{
    int spa_score;
    char spa_grade;

public:
    sports(int r, int a, char b) : students(r), spa_score(a), spa_grade(b) {}
    int getSpaScore() { return spa_score; }
    char getSpaGrade() { return spa_grade; }
};

class result : public test, public sports
{
    int final_score;
    char final_grade;

public:
    result(int r, int p, int c, int m, int s, char g)
        : students(r), test(r, p, c, m), sports(r, s, g),final_score(0), final_grade('F') {}

    void calculate_result()
    {
        float avg = (getPhy() + getChem() + getMaths()) / 3.0f;
        final_score = ((avg + getSpaScore()) / 2);

        if (final_score > 80)
            final_grade = 'A';
        else if (final_score > 60)
            final_grade = 'B';
        else if (final_score > 40)
            final_grade = 'C';
        else
            final_grade = 'D';
    }

    void display_result()
    {
        cout << "RESULT: " << endl;
        cout << "1. Phy Marks = " << getPhy() << endl;
        cout << "2. Chem Marks = " << getChem() << endl;
        cout << "3. Maths Marks = " << getMaths() << endl;
        cout << "SPA Score = " << getSpaScore() << endl;
        cout << "SPA Grade = " << getSpaGrade() << endl;
        cout << "FINAL SCORE = " << final_score << endl;
        cout << "FINAL GRADE = " << final_grade << endl;
    }
};

#include <iostream>
using namespace std;

int main()
{
    int choice, roll, phy, chem, maths, spa_score;
    char spa_grade;

    cout << "Enter student roll number: ";
    cin >> roll;
    cout << "Enter Physics, Chemistry, and Maths marks: ";
    cin >> phy >> chem >> maths;
    cout << "Enter SPA score: ";
    cin >> spa_score;
    cout << "Enter SPA grade: ";
    cin >> spa_grade;


    result R1(roll, phy, chem, maths, spa_score, spa_grade);
    R1.calculate_result();
    R1.display_result();

    return 0;
}
