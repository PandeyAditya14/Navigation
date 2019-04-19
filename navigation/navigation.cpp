// navigation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

using namespace std;

double matrix[11][11];


vector <location> campus;
vector <roads> graph;


pair<bool,int> findLoc(string nm) {
	pair<bool, int> res;
	int flag = -1;
	int count = 0;
	for (auto i = campus.begin(); i != campus.end(); ++i, count++)
	{
		if (i->name == nm)
		{
			flag++;
			break;
		}
	}
	if (flag != -1) {
		res.first = true;
		res.second = count;
	}
	else {
		res.first = false;
		res.second = -1;
	}
	return res;

}

void createCampus(fstream& file) {
	string line,name;
	double lat, lon;
	while (getline(file, line)) {
		istringstream ss(line);
		ss >> name >> lat >> lon;
		location temp(name, lat, lon);
		campus.push_back(temp);
		}	
	//for (auto i = campus.begin(); i != campus.end(); ++i)
		//cout << " " << i->name << " " << i->latitude << " " << i->longitude << endl;
}



void createGraph(fstream& file) {
	string line, loc1, loc2;
	pair<bool, int> loca1, loca2;
	while (getline(file, line)) {
		istringstream ss(line);
		ss >> loc1 >> loc2;
		cout << loc1 << " " << loc2 <<endl;
		loca1 = findLoc(loc1);
		loca2 = findLoc(loc2);
		location temp1 = campus[loca1.second];
		location temp2 = campus[loca2.second];
		roads tempr(temp1, temp2);
		if (loca1.first&&loca2.first) {
			matrix[loca1.second][loca2.second] = matrix[loca1.second][loca2.second] = tempr.len;
		}
		graph.push_back(tempr);
		//for (auto i = graph.begin(); i != graph.end(); ++i)
		//	i->display();
	}
}

int main()
{   
	  fstream f1("location.txt");
      fstream f2("roads.txt"); 
	  for (int i = 0; i < 11; i++) {
		  for (int j = 0; j < 11; j++) {
			  matrix[i][j] = 0;//daczx
		  }
	  }
	  createCampus(f1);
	  createGraph(f2);
	  for (int i = 0; i < 11; i++) {
		  for (int j = 0; j < 11; j++) {
			  cout<<matrix[i][j]<<"\t\t";
		  }
		  cout << "\n";
	  }
	  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
