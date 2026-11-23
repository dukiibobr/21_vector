#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include<ifstream>
using namespace std;

//void printVector(vector<int> v,vector<int> v2) {
//	cout << "vector 1: ";
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "vector 2: ";
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//}



struct Time {
	int h, m, s;
};

class Train {
	int num;
	Time departure;
	string destination;
public:

	Train():num(0),departure(),destination("-"){}
	Train(int n,Time t,string de):num(n),departure(t),destination(de){}
	
	void print()const {
		cout << "num: " << num << endl;
		cout << "departure: " << departure.h<<"/"<<departure.m<<"/"<<departure.s<< endl;
		cout << "destination: " << destination << endl;
		cout << endl;
	}

	friend ostream& operator<<(ostream& out, const Train& t) {
		out << t.num << " ";
		out << t.departure.h << " ";
		out<<t.departure.m << " ";
		out<<t.departure.s << " ";
		out << t.destination << " ";

		return out;
	}

	friend istream& operator>>(istream& in,  Train& t) {
		in >> t.num;

		in >> t.departure.h;
		in >> t.departure.m;
		in >> t.departure.s;

		in >> t.destination;
		return in;
	}

	int getNum()const {
		return num;
	}
	string getDestination()const {
		return destination;
	}
	Time getDeparture()const {
		return departure;
	}

	void setDeparture(Time t) {
		departure = t;
	}

	int getTimeInSeconds()const {
		return departure.h * 3600 + departure.m * 60 + departure.s;
	}
};

class Railway {
	vector<Train>trains;
public:
	Railway() :trains() {}
	Railway(const vector<Train>& t) :trains(t) {}


	void addTrain(Train t) {
		trains.push_back(t);
	}

	void printAll()const {
		for (const auto& item : trains) {
			cout << item << endl;
		}
	}

	void printNum(int num)const {
		for (const auto& item : trains)
		{
			if (item.getNum() == num)
			{
				cout << item;
				return;
			}
		}
		cout << "train not found" << endl;
	}

	void printDeparture(Time dep)const {
		for (const auto& item : trains)
		{
			Time t = item.getDeparture();
			if (t.h == dep.h and t.m == dep.m and t.s == dep.s)
			{
				cout << item;
				return;
			}
		}
		cout << "departure not found" << endl;
	}

	void printDestination(string dest)const {
		for (const auto& item : trains)
		{
			if (item.getDestination() == dest)
			{
				cout << item;
				return;
			}
		}
		cout << "destination not found" << endl;
	}


	void changeTime(int num) {
		for (auto& item : trains)
		{
			if (item.getNum() == num)
			{
				Time t;
				cin >> t.h >> t.m >> t.s;
				item.setDeparture(t);
				return;
			}
		}
		cout << "train not found" << endl;
	}


	void sortByTime() {
		for (int i = 0; i < trains.size(); i++)
		{
			for (int j = 0; j < trains.size() - i - 1; j++)
			{
				if (trains[j].getTimeInSeconds() > trains[j + 1].getTimeInSeconds())
				{
					swap(trains[j], trains[j + 1]);
				}
			}
		}
	}

		
	void saveToFile()
	{
		ofstream out("trainsData.txt");
		for (const auto& item:trains)
		{
			out << item << endl;
		}
		out.close();
	}

	void readFromFile()
	{
		ifstream in("trainsData.txt");

		if (!in.is_open())
		{
			cout << "file not found" << endl;
			return;
		}
		trains.clear();

		Train t;
		cout << "num/time/destination" << endl;
		while (in >> t)
			trains.push_back(t);

		in.close();
	}

};


int main()
{

	Train t(1, { 2,3,40 }, "Kyiv");
	Train t1(2, { 7,3,40 }, "Lviv");
	Train t2(3, { 5,3,40 }, "Lviv");

	vector<Train>v = { t,t1,t2 };
	Railway r(v);
	//r.addTrain(t1);
	//r.printAll();
	//r.printDeparture({2,3,40});
	//r.printDestination("Lviv");
	//r.printNum(2);
	//r.changeTime(2);
	//r.printAll();
	//r.sortByTime();
	//r.printAll();
	r.saveToFile();
	r.readFromFile();
	r.printAll();





//	vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
//	vector<int>v2 = { 10,11,12,13,14 };
//
////	for (int i = 0; i < v.size(); i++)
////	{
////		cout << v[i] << " ";
////	}
////	cout << endl;
////
////
////	v[0] = 55;
////
////	for (int i = 0; i < v.size(); i++)
////	{
////		cout << v[i] << " ";
////	}
////
////
////	cout << endl;
////	v[0] = 55;
////	for (auto item : v) {
////		cout << item << " ";
////		//item = 0;
////}
////	cout << endl;
////
////
////
////	int a = 5;
////	auto b = 6;
////	auto c = 3.33;
////	float d = 1.25;
////
////	auto p="o";
//
//	//v.begin();
//	/*printVector(v, v2);
//	v.erase(v.begin()+2);
//	printVector(v, v2);
//	v.erase(v.end()-1);
//	printVector(v, v2);*/
//
//	cout << "size: " << v.size() << endl;
//	cout << "capacity: " << v.capacity() << endl;
//
//	printVector(v, v2);
//
//	v.erase(v.begin(),v.end()-4);
//	printVector(v, v2);
//
//
//	//v.insert(v.begin(), 55);
//	//printVector(v, v2);
//	//v.insert(v.end(), { 7,8,9,10 });
//	//printVector(v, v2);
//	//v.insert(v.begin()+2,5,44);
//	//cout << "size: " << v.size() << endl;
//	//cout << "capacity: " << v.capacity() << endl;
//	//printVector(v, v2);
//	//v.insert(v.end(),v2.begin()+1,v2.end()-2);
//	//printVector(v, v2);
//
//	//v.push_back(100);
//	//printVector(v, v2);
//
//	//v.pop_back();
//	//printVector(v, v2);
//
//
//	//v.swap(v2);
//	printVector(v, v2);
//
//	cout << "show first el: " << v.front() << endl;
//	cout << "show last el: " << v.back() << endl;
//
//	v.resize(70);
//	printVector(v, v2);
//	v.shrink_to_fit();
//	cout << "size: " << v.size() << endl;
//	cout << "capacity: " << v.capacity() << endl;
//
//	v.resize(7);
//	printVector(v, v2);
//
//
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i]==7)
//			v.insert(v.begin() + i+1,7);
//	}
//	printVector(v, v2);

}


