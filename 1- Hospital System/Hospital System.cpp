#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <ctype.h>
#include <climits>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <functional>
#include <iterator>
#include <sstream>

#define long long ll;
#define long double ld;


using namespace std;

struct patient
{
	bool isurgent{};
	string name{};
	int sp{};
	string prnturgnt()
	{
		if (isurgent)
			return "urgent";
		else
			return "regular";
	}
};

struct spech
{
	deque<patient> patients;
	int id;
	void addpatient(const patient p)
	{
		if (patients.size() < 5)
		{
			if (p.isurgent)
				patients.push_front(p);
			else
				patients.push_back(p);

			cout << "Added!\n\n" << endl;
		}
		else {
			cout << "Sorry, We can not accept more patients right now.\n\n";
		}
	}
	void getpatient()
	{
		if (!patients.empty())
		{
			cout << patients[0].name << " please go and see the doctor\n";
			//cout << (patients.front()).name << " please go and see the doctor\n";

			//cout << patients[0].name << ' ' << patients[0].prnturgnt() << endl;
			patients.pop_front();
		}
		else
			cout << "There is no Patients in this specialization right now.\n";
	}
	void printall() {
		for (int i = 0; i < patients.size(); i++) {
			cout << patients[i].name << ' ' << patients[i].prnturgnt() << endl;
		}
	}
};

unsigned main()
{
	cout << "*************************************\n";
	cout << "*********** W E L C O M E ***********\n";
	cout << "*************************************\n\n";

	vector<spech> spys(20);
	int choice{};
	while (true)
	{
		cout << "Enter Ur Choice:\n";
		cout << "1) Add New Patient\n";
		cout << "2) Print all Patients\n";
		cout << "3) Get the next Patient\n";
		cout << "\nEnter 0 to exit...\n\n";
		cin >> choice;
		if (choice == 0){

			break;
		}
		else if (choice == 1) {
			patient tempp;
			cout << "Enter Specialization, Name, Statis: ";
			cin >> tempp.sp >> tempp.name >> tempp.isurgent;
			spys[tempp.sp - 1].addpatient(tempp);
			continue;
		}
		else if (choice == 2)
		{
			cout << "***************************\n";
			bool ch = false;
			for (int i = 0; i < 20; i++) {
				if (!spys[i].patients.empty()) {
					cout << "There is " << spys[i].patients.size() << " in specialization " << i + 1 << '\n';
					spys[i].printall();
					ch = true;
				}
			}
			if (ch == false)
			{
				cout << "There is No patients in the whole Hospital.\n";
			}
			cout << "\n\n";
			continue;
		}
		else if (choice == 3) {
			int i{};
			cout << "Enter Specialization: ";
			cin >> i;
			spys[i - 1].getpatient();
			continue;
		}
		
	}
	cout << "\nThanks for using our application XD\n";
}
