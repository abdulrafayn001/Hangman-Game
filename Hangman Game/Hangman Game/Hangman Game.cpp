#include<iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int size = 70, score = 0;
	char dictionary[] = "birds,dog,cat,lion,elephent,bear,giraffe,tiger,horse,snake,fish,hippopotamus,monkey,wolf,kangaroo,owls,fox,goat,hen,chicken,salad,sandwich,bread,steak,rice,pizza,burger,eggs,cheese,apple,milk,cookie,cake,coffe,dates,fish,noodles,yougurt,milkshake,jelly,pen,marker,pencil,eraser,tape,ruler,glue,stapler,files,scissor,calculator,sticky,pins,highlighter,whiteboard,afghanistan,cuba,denmark,egypt,france,india,iceland,iran,iraq,ireland,italy,japan,pakistan,korea,bangladesh";
	int indices[70] = { 0 };
	char x = '\0', c = '\0';
	int lives = 0, range = 0, min = 0, max = 0, index = 0, startingIndex = 0, sizeOfWord = 0;
	bool isWin = false, isFound;

	//Save Starting of Words Indices
	int i = 0, l = 0;
	while (dictionary[i] != '\0')
	{
		if (i == 0)
		{
			indices[l] = i;
			l++;
		}
		if (dictionary[i] == ',')
		{
			indices[l] = i + 1;
			l++;
		}
		i++;
	}
	cout << "\t\t\t======================================================" << endl;
	cout << "\t\t\t|                HANGMAN SEARCH GAME                 |" << endl;
	cout << "\t\t\t======================================================" << endl;
	cout << "\t\t\t                      WELCOME                         " << endl;
	cout << "\t\t\t======================================================" << endl;
	cout << "\t\t\t                    |  MENU  |                        " << endl;
	cout << "\t\t\t======================================================" << endl << endl;
	int choice = 0;
	do
	{
		cout << "\t\t\t\t     Enter 1 to Start the Game." << endl;
		cout << "\t\t\t\t     Enter 2 to Exit." << endl;
		cout << "\t\t\t\t     Choice : ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			cout << "\t\t\t======================================================" << endl;
			cout << "\t\t\t                    GAME STARTTED                     " << endl;
			cout << "\t\t\t======================================================" << endl;
			cout << "\t\t\t                     CATEGORIES                       " << endl;
			cout << "\t\t\t======================================================" << endl << endl;
			do
			{
				cout << "\t\t\t\t     Enter A/a for Animals." << endl;
				cout << "\t\t\t\t     Enter F/f for Foods." << endl;
				cout << "\t\t\t\t     Enter S/s for Stationary." << endl;
				cout << "\t\t\t\t     EnterC/c for Country." << endl;
				cout << "\t\t\t\t     Enter R/r for Random Category." << endl;
				cout << "\t\t\t\t     Choice: ";
				cin >> x;
			} while (!(x == 'A' || x == 'a' || x == 'F' || x == 'f' || x == 's' || x == 'S' || x == 'C' || x == 'c' || x == 'R' || x == 'r'));

			//Generate Random Index 
			if (x == 'A' || x == 'a')
			{
				max = 19;
				min = 0;
				range = max - min + 1;
				index = rand() % range + min;
			}
			else
			if (x == 'F' || x == 'f')
			{
				max = 39;
				min = 19;
				range = max - min + 1;
				index = rand() % range + min;
			}
			else
			if (x == 's' || x == 'S')
			{
				max = 54;
				min = 40;
				range = max - min + 1;
				index = rand() % range + min;
			}
			else
			if (x == 'C' || x == 'c')
			{
				max = 69;
				min = 55;
				range = max - min + 1;
				index = rand() % range + min;
			}
			else
			if (x == 'R' || x == 'r')
			{
				max = 69;
				min = 0;
				range = max - min + 1;
				index = rand() % range + min;
			}
			i = 0;
			char word[50] = { '\0' };
			startingIndex = indices[index];//10
			//Store Random Word in Separate character array 
			while (dictionary[startingIndex] != ',')
			{
				word[i] = dictionary[startingIndex];
				startingIndex++;
				i++;
				if (dictionary[startingIndex] == '\0')
				{
					break;
				}
			}
			cout << endl << endl << word << endl << endl;
			sizeOfWord = i;
			char tmp[50] = { '\0' };
			
			for (i = 0; i < sizeOfWord; i++)
			{
				tmp[i] = '-';
			}
			cout << endl;
			lives = 15;
			cout << "\t\t\t\t     Enter a character of Word to Guess." << endl;
			cout << "\t\t\t\t     Lives : " << lives << endl;
			do
			{
				cout << endl;
				isWin = false;
				i = 0;
				cout << "\t\t\t\t     ";
				while (tmp[i] != '\0')
				{
					cout << tmp[i] << " ";
					i++;
				}
				cout << endl;
				cout << "\t\t\t\t     Character of Word : ";
				cin >> c;

				//Find Character in Word
				i = 0;
				while (word[i] != '\0')
				{
					if (word[i] == c && tmp[i] != c)
					{
						isFound = true;
						break;
					}
					else
					{
						isFound = false;
					}
					i++;
				}
				if (isFound == true)
				{
					i = 0;
					while (word[i] != '\0')
					{
						if (word[i] == c)
						{
							tmp[i] = word[i];
							sizeOfWord--;
						}
						i++;
					}
				}
				else
				{
					lives--;
					cout << "\t\t\t\t     Lives Left : " << lives << endl;
				}
				if (sizeOfWord == 0)
				{
					isWin = true;
					cout << "\t\t\t\t     ";
					cout << word;
					break;
				}
			} while (lives > 0);

			if (isWin == true)
			{
				score++;
				cout << endl;
				cout << "\t\t\t\t     YOU WIN !" << endl << endl;
				cout << "\t\t\t\t     Score: " << score << endl << endl;
				char R;
				do
				{
					cout << endl;
					cout << "\t\t\t\t     Do You Want to play game again (Y/y ,N/n) : ";
					cin >> R;
					if (R == 'Y' || R == 'y')
					{
						isWin = false;
						isFound = false;
						break;
					}
					if (R == 'N' || R == 'n')
					{
						cout << "\t\t\t\t     Score: " << score << endl << endl;
						cout << "\t\t\t======================================================" << endl;
						cout << "\t\t\t                       GAME END                       " << endl;
						cout << "\t\t\t======================================================" << endl;
						return 0;
					}
					else
					{
						cout << "\t\t\t\t     Wrong Choice!" << endl;
					}
				} while (true);
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t     COMPUTER WINS! " << endl;
				cout << "\t\t\t\t     YOU ARE FAILED TO GUESS THE WORD ! " <<  endl;
				cout << "\t\t\t\t     Score: " << score << endl << endl;
				char R;
				do
				{
					cout << "\t\t\t\t     Do You Want to play game again (Y y , N n) : ";
					cin >> R;
					if (R == 'Y' || R == 'y')
					{
						isWin = false;
						isFound = false;
						break;
					}
					if (R == 'N' || R == 'n')
					{
						cout << "\t\t\t\t     Score: " << score << endl << endl;
						cout << "\t\t\t======================================================" << endl;
						cout << "\t\t\t                       GAME END                       " << endl;
						cout << "\t\t\t======================================================" << endl;
						return 0;
					}
					else
					{
						cout << "\t\t\t\t     Wrong Choice no such Coice exists!" << endl;
					}
				} while (true);
			}
		}
		if (choice == 2)
		{
			cout << "\t\t\t\t     Score: " << score << endl << endl;
			cout << "\t\t\t======================================================" << endl;
			cout << "\t\t\t                    GAME FINISHED                     " << endl;
			cout << "\t\t\t======================================================" << endl;
			return 0;
		}
	} while (true);
}