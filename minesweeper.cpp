#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <ctime>
#include <cctype>
#include <limits>

using namespace std;
class gameBoard;
int gamePoint1, gamePoint2, gamePoint3;
int main();
void game();
void numberChoice(gameBoard, int);
void pause(int);
int X = 0, Y = 5;
enum LEVEL {EASY, MODERATE, HARD};
LEVEL sLevel = EASY;
void levelChoice();

void gotoxy(int x, int y)
{
    COORD  c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void shuffle(int values[], int);
void shuffle(int values[], int size)
{
    srand((int)time(NULL));
    for (int i = 0; i < (size * 20); i++)
    {
        int randvalue1 = (rand() % size) + 0;
        int randvalue2 = (rand() % size) + 0;

        int temp = values[randvalue1];
        values[randvalue1] = values[randvalue2];
        values[randvalue2] = temp;
    }
}

class gameBoard
{
protected:
    int num[10];
    char gnum[10];
    char outNum[10];
public:
    void getData(int get[], int ran)
    {
        for(int i=0; i<=ran; i++)
        {
            num[i] = get[i];
        }
        for(int i=0; i<=9; i++)
        {
            gnum[i] = '0' + num[i];
        }
    }

    void randNumGen(int numSelect, int count = 0)
    {
		char gnumSelect = '0' + numSelect;
		if(sLevel == EASY)
        {
            if(count == 0)
            {
                int min = 9, max = 0;
                int range = (min - max);
                int *values = new int[range];
                for(int i=0; i<=range; i++)
                {
                    values[i] = min - i;
                }
                shuffle(values,range + 1);
                for(int i=0; i<=9; i++)
                {
                    outNum[i] = '0' + values[i];
                    //cout << outNum[i] << endl;
                    gotoxy(28, 2);
                    cout << "MINE-SAFE NUMBER BONUS: " << "[" << outNum[6] << "] [" << outNum[7] << "] [" << outNum[8] << "] [" << outNum[9] << "]" << endl;
                }
                if(gnumSelect == outNum[0])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint1 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint1++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint1 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
            else
            {
                if(gnumSelect == outNum[0])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint1 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint1++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint1 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
        }

        if(sLevel == MODERATE)
        {
            if(count == 0)
            {
                int min = 9, max = 0;
                int range = (min - max);
                int *values = new int[range];
                for(int i=0; i<=range; i++)
                {
                    values[i] = min - i;
                }
                shuffle(values,range + 1);
                for(int i=0; i<=9; i++)
                {
                    outNum[i] = '0' + values[i];
                    //cout << outNum[i] << endl;
                    gotoxy(28, 2);
                    cout << "MINE-SAFE NUMBER BONUS: " << "[" << outNum[6] << "] [" << outNum[7] << "] [" << outNum[8] << "] [" << outNum[9] << "]" << endl;
                }
                if(gnumSelect == outNum[0] || gnumSelect == outNum[1])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint2 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint2++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint2 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
            else
            {
                if(gnumSelect == outNum[0] || gnumSelect == outNum[1])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint2 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint2++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint2 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
        }

        if(sLevel == HARD)
        {
            if(count == 0)
            {
                int min = 9, max = 0;
                int range = (min - max);
                int *values = new int[range];
                for(int i=0; i<=range; i++)
                {
                    values[i] = min - i;
                }
                shuffle(values,range + 1);
                for(int i=0; i<=9; i++)
                {
                    outNum[i] = '0' + values[i];
                    //cout << outNum[i] << endl;
                    gotoxy(28, 2);
                    cout << "MINE-SAFE NUMBER BONUS: " << "[" << outNum[8] << "] [" << outNum[9] << "]" << endl;
                }
                if(gnumSelect == outNum[0] || gnumSelect == outNum[1] || gnumSelect == outNum[2] || gnumSelect == outNum[3])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint3 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint3++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint3 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
            else
            {
                if(gnumSelect == outNum[0] || gnumSelect == outNum[1] || gnumSelect == outNum[2] || gnumSelect == outNum[3])
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = 'X';
                            gotoxy(27, 3);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 4);
                            cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 5);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 6);
                            cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 7);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 8);
                            cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                            gotoxy(27, 9);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 10);
                            cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                            gotoxy(27, 11);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 12);
                            cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 13);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 14);
                            cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 15);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 16);
                            cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                            gotoxy(27, 17);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 18);
                            cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                            gotoxy(27, 19);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 20);
                            cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                            gotoxy(27, 21);
                            cout << "-----------------------------------------" << endl;
                            gotoxy(27, 22);
                            cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                            gotoxy(27, 23);
                            cout << "-----------------------------------------" << endl;
                            pause(3);
                            system("cls");
                            gotoxy(42, 10);
                            cout << "GAME OVER" << endl;
                            gamePoint3 = 0;
                            pause(3);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<=9; i++)
                    {
                        if(gnumSelect == gnum[i])
                        {
                            gnum[i] = '*';
                            gamePoint3++;
                        }
                    }
                    gotoxy(27, 3);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 4);
                    cout << "| " << gnum[1] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[0] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 5);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 6);
                    cout << "| " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[9] << " | " << gnum[2] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 7);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 8);
                    cout << "| " << gnum[4] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[2] << " | " << endl;
                    gotoxy(27, 9);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 10);
                    cout << "| " << gnum[1] << " | " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[5] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[2] << " | " << gnum[7] << " | " << endl;
                    gotoxy(27, 11);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 12);
                    cout << "| " << gnum[4] << " | " << gnum[4] << " | " << gnum[1] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[7] << " | " << gnum[6] << " | " << gnum[0] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 13);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 14);
                    cout << "| " << gnum[9] << " | " << gnum[0] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[9] << " | " << gnum[5] << " | " << gnum[0] << " | " << gnum[2] << " | " << gnum[2] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 15);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 16);
                    cout << "| " << gnum[4] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[1] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[5] << " | " << gnum[9] << " | " << gnum[8] << " | " << endl;
                    gotoxy(27, 17);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 18);
                    cout << "| " << gnum[8] << " | " << gnum[2] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[1] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[1] << " | " << gnum[6] << " | " << gnum[0] << " | " << endl;
                    gotoxy(27, 19);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 20);
                    cout << "| " << gnum[3] << " | " << gnum[3] << " | " << gnum[0] << " | " << gnum[8] << " | " << gnum[8] << " | " << gnum[2] << " | " << gnum[6] << " | " << gnum[6] << " | " << gnum[1] << " | " << gnum[1] << " | " << endl;
                    gotoxy(27, 21);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(27, 22);
                    cout << "| " << gnum[3] << " | " << gnum[0] << " | " << gnum[3] << " | " << gnum[9] << " | " << gnum[8] << " | " << gnum[6] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[7] << " | " << gnum[6] << " | " << endl;
                    gotoxy(27, 23);
                    cout << "-----------------------------------------" << endl;
                    gotoxy(40, 24);
                    cout << "TOTAL POINT: " << gamePoint3 << endl;
                    count++;
                    numberChoice(*this, count);
                }
            }
        }
    }
    void displayBoard()
    {
        system("cls");
        gotoxy(27, 3);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 4);
        cout << "| " << num[1] << " | " << num[8] << " | " << num[6] << " | " << num[8] << " | " << num[1] << " | " << num[2] << " | " << num[6] << " | " << num[2] << " | " << num[0] << " | " << num[2] << " | " << endl;
        gotoxy(27, 5);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 6);
        cout << "| " << num[7] << " | " << num[1] << " | " << num[1] << " | " << num[1] << " | " << num[1] << " | " << num[8] << " | " << num[8] << " | " << num[9] << " | " << num[2] << " | " << num[8] << " | " << endl;
        gotoxy(27, 7);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 8);
        cout << "| " << num[4] << " | " << num[9] << " | " << num[8] << " | " << num[1] << " | " << num[7] << " | " << num[5] << " | " << num[2] << " | " << num[2] << " | " << num[6] << " | " << num[2] << " | " << endl;
        gotoxy(27, 9);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 10);
        cout << "| " << num[1] << " | " << num[4] << " | " << num[4] << " | " << num[1] << " | " << num[7] << " | " << num[5] << " | " << num[8] << " | " << num[6] << " | " << num[2] << " | " << num[7] << " | " << endl;
        gotoxy(27, 11);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 12);
        cout << "| " << num[4] << " | " << num[4] << " | " << num[1] << " | " << num[9] << " | " << num[5] << " | " << num[0] << " | " << num[7] << " | " << num[6] << " | " << num[0] << " | " << num[6] << " | " << endl;
        gotoxy(27, 13);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 14);
        cout << "| " << num[9] << " | " << num[0] << " | " << num[9] << " | " << num[9] << " | " << num[9] << " | " << num[5] << " | " << num[0] << " | " << num[2] << " | " << num[2] << " | " << num[6] << " | " << endl;
        gotoxy(27, 15);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 16);
        cout << "| " << num[4] << " | " << num[7] << " | " << num[1] << " | " << num[1] << " | " << num[5] << " | " << num[5] << " | " << num[5] << " | " << num[5] << " | " << num[9] << " | " << num[8] << " | " << endl;
        gotoxy(27, 17);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 18);
        cout << "| " << num[8] << " | " << num[2] << " | " << num[3] << " | " << num[9] << " | " << num[1] << " | " << num[7] << " | " << num[7] << " | " << num[1] << " | " << num[6] << " | " << num[0] << " | " << endl;
        gotoxy(27, 19);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 20);
        cout << "| " << num[3] << " | " << num[3] << " | " << num[0] << " | " << num[8] << " | " << num[8] << " | " << num[2] << " | " << num[6] << " | " << num[6] << " | " << num[1] << " | " << num[1] << " | " << endl;
        gotoxy(27, 21);
        cout << "-----------------------------------------" << endl;
        gotoxy(27, 22);
        cout << "| " << num[3] << " | " << num[0] << " | " << num[3] << " | " << num[9] << " | " << num[8] << " | " << num[6] << " | " << num[7] << " | " << num[7] << " | " << num[7] << " | " << num[6] << " | " << endl;
        gotoxy(27, 23);
        cout << "-----------------------------------------" << endl;
    }
};

int main()
{
    system("color F2");
    Y = 5;
    char choice;
    while(1)
    {
		gotoxy(36, 4);
		cout << "1. START GAME" << endl;
		gotoxy(36, 5);
		cout << "2. INSTRUCTIONS" << endl;
		gotoxy(36, 6);
		cout << "3. LEVEL" << endl;
		gotoxy(36, 7);
        cout << "4. EXIT " << endl;
        gotoxy(34, 9);
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case '1':
            game();
            break;
        case '2':
        	system("cls");
        	gotoxy(22, 4);
        	cout << "-> The player will be shown numbers from 0 to 9." << endl;
        	gotoxy(22, 5);
        	cout << "-> You can reveal only one number at a time. " << endl;
        	gotoxy(22, 6);
        	cout << "-> '*' means the number you've revealed doesn't contain mines." << endl;
        	gotoxy(22, 7);
        	cout << "-> 'X' means you've hit the mine and that's the end of the game." << endl;
        	gotoxy(22, 9);
        	cout << "Press any key to continue ... ";
        	getche();
        	system("cls");
            break;
        case '3':
            levelChoice();
            break;
        case '4':
            exit(0);
            break;
        default:
            gotoxy(37, 11);
            cout << "Invalid choice!" << endl;
            pause(2);
            system("cls");
            break;
        }
    }
    return 0;
}


void game()
{
    gameBoard start;
    int minimum = 0, maximum = 9;
    int r = (maximum - minimum);
    int *val = new int[r];
    for (int i = 0; i <= r; i++)
    {
        val[i] = minimum + i;
    }
    shuffle(val, r + 1);
    start.getData(val, r);
    start.displayBoard();
    int count = 0;
    numberChoice(start, count);
}

void numberChoice(gameBoard start, int count = 0)
{
	int numSelect = 0;
	if(sLevel == EASY)
    {
        gotoxy(33, 1);
        cout << "LEVEL -- EASY || AVOID 1 MINE(S)" << endl;
        if(gamePoint1 == 9)
        {
            pause(3);
            system("cls");
            gotoxy(30, 5);
            cout << "Bravo! You have avoided all the mines." << endl;
            gotoxy(22, 7);
            cout << "You will be prompted to Star Menu with a few seconds ..." << endl;
            pause(4);
            gamePoint1 = 0;
            system("cls");
            main();
        }
    }

    if(sLevel == MODERATE)
    {
        gotoxy(32, 1);
        cout << "LEVEL -- MODERATE || AVOID 2 MINE(S)" << endl;
        if(gamePoint2 == 8)
        {
            pause(3);
            system("cls");
            gotoxy(30, 5);
            cout << "Bravo! You have avoided all the mines." << endl;
            gotoxy(22, 7);
            cout << "You will be prompted to Star Menu with a few seconds ..." << endl;
            pause(4);
            gamePoint2 = 0;
            system("cls");
            main();
        }
    }

    if(sLevel == HARD)
    {
        gotoxy(33, 1);
        cout << "LEVEL -- HARD || AVOID 4 MINE(S)" << endl;
        if(gamePoint3 == 6)
        {
            pause(3);
            system("cls");
            gotoxy(30, 5);
            cout << "Bravo! You have avoided all the mines." << endl;
            gotoxy(22, 7);
            cout << "You will be prompted to Star Menu with a few seconds ..." << endl;
            pause(4);
            gamePoint3 = 0;
            system("cls");
            main();
        }
    }
    gotoxy(X, Y);
    while (cout << "Enter a number: " && !(cin >> numSelect) || cin.peek() != '\n')
	{
		gotoxy(X, Y);
		cout << "Oops! Invalid Input!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Y++;
	}
	Y++;
    start.randNumGen(numSelect, count);
}


void pause(int inNum) //In order to pause
{
    int iCurrentTime = 0;
    int iElapsedTime = 0;
    iCurrentTime = time(NULL);
    do{
        iElapsedTime = time(NULL);
      } while((iElapsedTime - iCurrentTime) < inNum);
}

void levelChoice()
{
    char choice;
    while(1)
    {
        system("cls");
        gotoxy(36, 3);
        cout << "THE LEVEL OF HARDSHIP: " << endl;
        gotoxy(32, 5);
        cout << "1. EASY = Contains 1 mines (Default)" << endl;
        gotoxy(32, 6);
        cout << "2. MODERATE = Contains 2 mines" << endl;
        gotoxy(32, 7);
        cout << "3. HARD = Contains 4 mines" << endl;
        gotoxy(36, 9);
        cout << "Pick a level: ";
        cin >> choice;
        switch(choice)
        {
        case '1':
            sLevel = EASY;
            gotoxy(31, 11);
            cout << "You have selected EASY level." << endl;
            gotoxy(33, 12);
            cout << "Now, START the game!" << endl;
            pause(3);
            system("cls");
            main();
            break;
        case '2':
            sLevel = MODERATE;
            gotoxy(31, 11);
            cout << "You have selected MODERATE level." << endl;
            gotoxy(33, 12);
            cout << "Now, START the game!" << endl;
            pause(3);
            system("cls");
            main();
            break;
        case '3':
            sLevel = HARD;
            gotoxy(31, 11);
            cout << "You have selected HARD level." << endl;
            gotoxy(33, 12);
            cout << "Now, START the game!" << endl;
            pause(3);
            system("cls");
            main();
            break;
        default:
            gotoxy(36, 11);
            cout << "Invalid choice!" << endl;
            pause(2);
            break;
        }
    }
}
