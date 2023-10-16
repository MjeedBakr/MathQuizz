#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

enum enQuestionsLevel {Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum enOperation {Add = 1, Sub = 2, Mult = 3, Div = 4, Mod = 5, Mix = 6};

struct strQuestionInfo
{
    short questionNumber;
    short firstNumber;
    short secondNumber;
    short rightAnswer;

};

struct strGameInfo
{
    strQuestionInfo questionInfo[50];
    short numberOfQuestions;
    enOperation operationType;
    enQuestionsLevel questionsLevel;
    short wrongAnswers;
    short rightAnswers;
    bool playAgain = false;
};

void newLine(short numberOfLines)
{
    for (int i = 1; i < numberOfLines; i++)
        cout << "\n";
}

short randomNumber(int from, int to)
{
    short randNum = rand() % (to - from + 1) + from;
    return randNum;
}

short getRandomNumber(enQuestionsLevel questionLevel, short& number)
{
    enQuestionsLevel randomLevel = (enQuestionsLevel)randomNumber(1, 3);
    switch (questionLevel)
    {
    case Easy:
        number = randomNumber(1, 10);
        break;
    case Medium:
        break;
        number = randomNumber(11, 100);
    case Hard:
        number = randomNumber(101, 200);
        break;
    case Mix:
        getRandomNumber(randomLevel, number);
        break;
    default:
        break;
    }
}

short doOperation(enOperation opType, short& firstNum, short& secondNum)
{
    enOperation randomOperaions = (enOperation)randomNumber(1, 5);
    switch (opType)
    {
    case Add:
        return firstNum + secondNum;
    case Sub:
        return firstNum - secondNum;
    case Mult:
        return firstNum * secondNum;
    case Div:
        return firstNum / secondNum;
    case Mod:
        return firstNum % secondNum;
    case Mix:
        return doOperation(randomOperaions, firstNum, secondNum);
    default:
        break;
    }
}

void questionCard(strGameInfo& gameInfo, strQuestionInfo& questionInfo)
{
    cout << "Question [" << questionInfo.questionNumber << "/" << gameInfo.numberOfQuestions << "]";
    newLine(3);

    
}

void allQuesionsCards(strGameInfo gameInfo)
{
    for (int i = 0; i < gameInfo.numberOfQuestions; i++)
    {
        gameInfo.questionInfo[i].questionNumber = i + 1;
        questionCard(gameInfo, gameInfo.questionInfo[i]);
    }
}

void startGame()
{
    strGameInfo gameInfo;

    cout << "How many questions do you want to answer? ";
    cin >> gameInfo.numberOfQuestions;

    cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
    short choice;
    cin >> choice;
    gameInfo.questionsLevel = (enQuestionsLevel)choice;

    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?";
    cin >> choice;
    gameInfo.operationType = (enOperation)choice;


}
int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));




}


