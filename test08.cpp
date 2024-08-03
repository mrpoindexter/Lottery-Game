#include<iostream>
#include<iomanip>
#include<time.h>
#include <cstdlib> 
using namespace std;

struct employees {
	string name;
	int id;
	int count;
};

employees e[10];

void input()
{

	e[0].name = "Rahim Bhai";
	e[0].id = 0;

	e[1].name = "Sumaia Apu";
	e[1].id = 1;

	e[2].name = "Ahnaf Bro";
	e[2].id = 2;

	e[3].name = "Swapna Apu";
	e[3].id = 3;

	e[4].name = "Shahid Bhai";
	e[4].id = 4;

	e[5].name = "Asma Madam";
	e[5].id = 5;

	e[6].name = "Kaniz Apu";
	e[6].id = 6;

	e[7].name = "Ishrat Apu";
	e[7].id = 7;

	e[8].name = "Jamir Bhai";
	e[8].id = 8;

	e[9].name = "Nasima Apu";
	e[9].id = 9;

}

void Lottery(int winnings)
{
	srand(time(0));

	for (int j = 0; j < winnings; j++)
	{
		int x = rand() % 10;

		for (int i = 0; i < 10; i++)
		{
			if (e[i].id == x)
			{
				e[i].count++;
			}
		}
	}
}

void output()
{
	int max = 0;
	string winner;

	cout << "Employee Name" << setw(25) << "No. of times won" << endl << endl;

	for (int k = 0; k < 10; k++)
	{

		cout << e[k].name << setw(10) << " | " << setw(10) << setw(10) << e[k].count << endl;

		if (e[k].count > max)
		{
			max = e[k].count;
			winner = e[k].name;
		}
	}

	cout << endl << endl << "Winner: " << winner << endl;
	cout << "Total no. of times won: " << max << endl;
}

int main()
{
	input();
	Lottery(1000);
	output();

	system("pause>0");
	return 0;
}