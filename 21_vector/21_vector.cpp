#include <iostream>
#include <vector>
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
	
};
class Railway {
	vector<Train>trains;
public:
	Railway():trains(){}
	Railway(Train t):trains(){}
	

	void addTrain(Train t) {
		trains.push_back(t);
		trains.push_back(t);
		trains.push_back(t);
	}

};


int main()
{











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


