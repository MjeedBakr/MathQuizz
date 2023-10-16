#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

enum enQuestionsLevel {Easy = 1, Medium = 2, Hard = 3, MixLvl = 4};
enum enOperation {Add = 1, Sub = 2, Mult = 3, Div = 4, Mod = 5, Mix = 6};

struct strQuestionInfo
{
    short questionNumber;
    short firstNumber;
    short secondNumber;
    short rightAnswer;
    short userAnswer;
    enOperation operationType;
};

struct strGameInfo
{
    strQuestionInfo questionInfo[50];
    short numberOfQuestions;
    enOperation operationType;
    enQuestionsLevel questionsLevel;
    short wrongAnswers = 0;
    short rightAnswers = 0;
    string finalResult;
    char playAgain;
};

void newLine(short numberOfLines)
{
    for (int i = 0; i < numberOfLines; i++)
        cout << "\n";
}

short randomNumber(int from, int to)
{
    short randNum = rand() % (to - from + 1) + from;
    return randNum;
}

short getRandomNumber(enQuestionsLevel questionLevel)
{
    enQuestionsLevel randomLevel = (enQuestionsLevel)randomNumber(1, 3);
    switch (questionLevel)
    {
    case Easy:
         return randomNumber(1, 10);
    case Medium:
         return randomNumber(11, 100);
    case Hard:
         return randomNumber(101, 200);
    case MixLvl:
         return getRandomNumber(randomLevel);
    default:
        break;
    }

    return -1;
}

string getOperationSymbol(enOperation operation)
{
    switch (operation)
    {
    case Add:
        return "Addition +";
    case Sub:
        return "Subtract -";
    case Mult:
        return "Multiply *";
    case Div:
        return "Divide /";
    case Mod:
        return "Modulo %";
    case Mix:
        return "Mix";
        break;
    default:
        break;
    }
}

string getQuestionLevel(enQuestionsLevel questionLvl)
{
    switch (questionLvl)
    {
    case Easy:
        return "Easy";
    case Medium:
        return "Mid";
    case Hard:
        return "Hard";
    case MixLvl:
        return "Mix";
    default:
        break;
    }
}

short doOperation(enOperation &opType, short firstNum, short secondNum)
{
    enOperation randomOperation = (enOperation)randomNumber(1, 5);
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
        opType = randomOperation;
        return doOperation(opType, firstNum, secondNum);
    default:
        break;
    }
}

void validateAnswer(strGameInfo& gameInfo, strQuestionInfo& questionInfo)
{
    if (questionInfo.rightAnswer == questionInfo.userAnswer)
    {
        system("color 2F");
        cout << "Right Answer :-)";
        gameInfo.rightAnswers++;
    }
    else
    {
        cout << "\a";
        system("color 4F");
        cout << "Wrong Answer :-(\n";
        cout << "The right ansewr is: " << questionInfo.rightAnswer;
        gameInfo.wrongAnswers++;
    }
}

void questionCard(strGameInfo& gameInfo, strQuestionInfo& questionInfo)
{
    cout << "Question [" << questionInfo.questionNumber << "/" << gameInfo.numberOfQuestions << "]";
    newLine(2);

    questionInfo.firstNumber = getRandomNumber(gameInfo.questionsLevel);
    questionInfo.secondNumber = getRandomNumber(gameInfo.questionsLevel);

    questionInfo.operationType = gameInfo.operationType;

    questionInfo.rightAnswer = doOperation(questionInfo.operationType, questionInfo.firstNumber, questionInfo.secondNumber);
    
    cout << questionInfo.firstNumber;
    newLine(1);
    cout << questionInfo.secondNumber << "  " << getOperationSymbol(questionInfo.operationType);
    newLine(1);
    cout << "-------------\n";
    cin >> questionInfo.userAnswer;
    
    validateAnswer(gameInfo, questionInfo);



}

void allQuesionsCards(strGameInfo &gameInfo)
{
    for (int i = 0; i < gameInfo.numberOfQuestions; i++)
    {
        gameInfo.questionInfo[i].questionNumber = i + 1;
        questionCard(gameInfo, gameInfo.questionInfo[i]);
        newLine(4);
    }
}

void resetGame()
{
    system("cls");
    system("color 0F");
}

void endGameCard(strGameInfo gameInfo)
{
    cout << "----------------------------------";
    newLine(2);
    cout << " Final Results is " << gameInfo.finalResult;
    newLine(2);
    cout << "----------------------------------";

    newLine(2);

    cout << "Number of Questions    : " << gameInfo.numberOfQuestions;
    newLine(1);
    cout << "Questions Level        : " << getQuestionLevel(gameInfo.questionsLevel);
    newLine(1);
    cout << "OpType                 : " << getOperationSymbol(gameInfo.operationType);
    newLine(1);
    cout << "Number of Right Answers: " << gameInfo.rightAnswers;
    newLine(1);
    cout << "Number of Wrong Answers: " << gameInfo.wrongAnswers;
    newLine(2);
    cout << "----------------------------------";

    newLine(2);


}

void startGame()
{
    strGameInfo gameInfo;

    cout << "How many questions do you want to answer? ";
    cin >> gameInfo.numberOfQuestions;

    cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
    short choice;
    cin >> choice;
    gameInfo.questionsLevel = (enQuestionsLevel)choice;

    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mod, [6] Mix ? ";
    cin >> choice;
    gameInfo.operationType = (enOperation)choice;

    newLine(2);

    allQuesionsCards(gameInfo);

    if (gameInfo.rightAnswers > gameInfo.wrongAnswers)
    {
        system("color 2F");
        gameInfo.finalResult = "Success  :-)";
    }
    else
    {
        cout << "\a";
        system("color 4F");
        gameInfo.finalResult = "Fail  :-(";
    }

    endGameCard(gameInfo);

    cout << "Do you want to play again? Y/N? ";
    cin >> gameInfo.playAgain;

    if (gameInfo.playAgain == 'y' || gameInfo.playAgain == 'Y')
    {
        resetGame();
        startGame();
    }
    else
    {
        cout << "Ending the game.............";
        newLine(3);
    }




}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    startGame();




}


