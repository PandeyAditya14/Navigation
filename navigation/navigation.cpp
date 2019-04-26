// navigation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

using namespace std;

graph g(11, 14);

class number : public exception {
public :
	const char* what() {
		return "The value entered shiuld be a number";
	}
};

class valid : public exception {
public:
	const char* what() {
		return "The value should be in range 1-11";
	}
};

class same : public exception {
public:
	const char* what() {
		return "Both points can't be same";
	}
};

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
	campus.pop_back();
	//for (auto i = campus.begin(); i != campus.end(); ++i)
		//cout << " " << i->name << " " << i->latitude << " " << i->longitude << endl;
}



void createRoads(fstream& file) {
	string line, loc1, loc2;
	pair<bool, int> loca1, loca2;
	while (getline(file, line)) {
		istringstream ss(line);
		ss >> loc1 >> loc2;
		//cout << loc1 << " " << loc2 <<endl;
		loca1 = findLoc(loc1);
		//cout << loca1.second<<endl;
        loca2 = findLoc(loc2);
		//cout << loca2.second << endl;
		location temp1 = campus[loca1.second];
		//cout << temp1.name << endl;
		location temp2 = campus[loca2.second];
		//cout << temp2.name << endl;
		roads tempr(temp1, temp2);
		//tempr.display();
		if (loca1.first&&loca2.first) {
			matrix[loca1.second][loca2.second] = tempr.len;
			g.addedge(loca1.second, loca2.second, tempr.len);
			}
		croads.push_back(tempr);
		}
	//for (auto i = croads.begin(); i != croads.end(); ++i)
		//i->display();
}
void dispCampus() {
	int i = 0;
	std::vector<location>::iterator it=campus.begin();
	for (it; it < campus.end(); it++, i++)
		cout << i+1 << ". " << it->name << endl;

}

int main()
{   
	cout << "--------------------------------WELCOME TO KLETECH NAV--------------------------------------\n";
	  fstream f1("location.txt");
      fstream f2("roads.txt"); 
	  for (int i = 0; i < 11; i++) {
		  for (int j = 0; j < 11; j++) {
			  matrix[i][j] = 0;//daczx
		  }
	  }
	  createCampus(f1);
	  createRoads(f2);
	/*for (int i = 0; i < 11; i++) {
		  for (int j = 0; j < 11; j++) {
			  cout<<matrix[i][j]<<"\t\t";
		  }
		  cout << "\n";
	  }*/
	  g.kruskalMST();
	 /*g.caller(0, 2);
	  while (!final.empty()) {
		  cout << " <- " << campus[final.top()].name;
		  final.pop();
	  }
	  */

	  int start, dest;
	  int flag = 0;
	  int choice = 0;
	  vector<int> loctemp;
	  roads temp;
	  std::vector<int>::iterator it2;
	  number num;
	  valid val;
	  same sm;
	  while (flag != -1) {
		  cout <<"\n-------------------------Enter Your Choice------------------------------ \n1.View The list of landmarks Around campus"
			   <<"\n2.Find th shortest route between 2 points in campus"
			   <<"\n3.Distance between two Points on campus"
			   <<"\n4.Coordinates of any given point on campus"
			   <<"\n0.EXIT\n:";
		  cin >> choice;
		  try

		  {
			  switch (choice) {
			  case 1: dispCampus();
				  break;
			  case 2: dispCampus();
				  cout << "Enter your start and destination:\n";
				  cin >> start >> dest;
				  if (start < 1 || start > 11)
					  throw val;
				  else if (dest < 1 || dest > 11)
					  throw val;
				  else if (start == dest)
					  throw sm;
				  start--;
				  dest--;
				  g.caller(start, dest);
				  while (!final.empty()) {
					  loctemp.push_back(final.top());
					  final.pop();
				  }
				  it2 = loctemp.begin();
				  for (it2; it2 < loctemp.end(); it2++)
					  cout << campus[*it2].name << " <-----| ";
				  break;
			  case 3: dispCampus();
				  cout << "Enter your Point A and Point B:\n";
				  cin >> start >> dest;
				  if (start < 1 || start > 11)
					  throw val;
				  else if (dest < 1 || dest > 11)
					  throw val;
				  else if (start == dest)
					  throw sm;
				  temp.setdata(campus[--start], campus[--dest]);
				  cout << "Distance between point entered is" << temp.length()*1000 << " m " << endl;
				  break;
			  case 4: dispCampus();
				  cout << "Enter your desired loc\n";
				  cin >> start;
				  if (start < 1 || start > 11)
					  throw val;
				  start--;
				  campus[start].display();
				  break;
			  case 0:cout << "YOU WANT TO EXIT (YES-1/NO-0)????\n";
				  cin >> start;
				  if (start)
					  flag = -1;
				  break;
			  default:
				  cout << "ENTER A VALID CHOICE !!!!!!\n";
			  }
		  }
		  
		  catch (valid s) {
			  cout << s.what() << endl;
		  }
		  catch (same s) {
			  cout << s.what() << endl;
		  }catch (...) {
			  cout <<"An error occured" << endl;
		  }
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
