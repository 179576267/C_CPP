#include"User.h"
#include<iostream>
using namespace std;

int main(){
	User u;
	char name[] = "wzf";
	u.setName(name);
	u.setAge(20);
	
	cout << u.getAge() << endl;
	cout << u.getName() << endl;

}
