#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int timer = 0;
int RACE_END = 100;
void moveTortoise(int *);
void moveHare(int *);
void printCurrentPositions(int *, int*);

int main(){
	srand(2016);
	int T_loc = 1, H_loc = 1;

	cout << "ON YOUR MARK, GET SET\n";
	cout << "BANG               !!!!\n";
	cout << "AND THEY'RE OFF    !!!!\n";

	for (;;){
		timer++;
		moveTortoise(&T_loc);
		moveHare(&H_loc);
		printCurrentPositions(&T_loc, &H_loc);
		cout << endl;


		if (T_loc >= RACE_END || H_loc >= RACE_END)
			break;
	}

	if (T_loc >= RACE_END)
		cout << "\nTORTOISE WINS!!! YAY!!!\n";

	else if (H_loc >= RACE_END)
		cout << "Hare wins. Yuch\n";

	cout << "TIME ELAPSED = " << timer << " seconds\n\n";
}

void moveTortoise(int *T_loc){
	int x = rand() % 10 + 1;

	if (x <= 5)
		*T_loc += 3;

	else if (x == 6 || x == 7)
	{
		*T_loc -= 6;

		if (*T_loc < 1)
			*T_loc = 1;
	}

	else
		++*T_loc;
}

void moveHare(int *H_loc){
	int y = rand() % 10 + 1;

	if (y == 1 || y == 2)
		*H_loc = *H_loc + 0;

	else if (y == 3 || y == 4)
		*H_loc += 9;

	else if (y == 5)
	{
		*H_loc -= 12;

		if (*H_loc < 1)
			*H_loc = 1;
	}

	else if (y >= 6 && y <= 8)
		++*H_loc;

	else
	{
		*H_loc -= 2;

		if (*H_loc < 1)
			*H_loc = 1;
	}
}

void printCurrentPositions(int *T_loc, int *H_loc){
	cout << timer << ":";

	if (*T_loc > *H_loc)
	{
		for (int i = 1; i < *H_loc; i++){
			cout << " ";
		}
		cout << "H";

		if (*T_loc > RACE_END)
		{
			for (int i = 1; i < RACE_END - *H_loc; i++)
				cout << " ";

			cout << "T";
		}

		else
		{
			for (int i = 1; i < *T_loc - *H_loc; i++)
				cout << " ";

			cout << "T";
		}
	}

	else if (*T_loc < *H_loc)
	{
		for (int i = 1; i < *T_loc; i++){
			cout << " ";
		}
		cout << "T";

		if (*H_loc > RACE_END)
		{
			for (int i = 1; i < RACE_END - *T_loc; i++)
				cout << " ";

			cout << "H";
		}

		else
		{
			for (int i = 1; i < *H_loc - *T_loc; i++)
				cout << " ";

			cout << "H";
		}
	}

	else{
		for (int i = 1; i < *T_loc; i++){
			cout << " ";
		}
		cout << "OUCH!!!";
	}
}
