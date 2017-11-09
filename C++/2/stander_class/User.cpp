
#include"User.h"

void User::setAge(int age){
	this->age = age;
}

int User::getAge(){
	return this->age;
}

void User::setName(char *name){
	this->name = name;	
}

char * User::getName(){
	return this->name;
}
