#pragma once
//类的声明写在头文件，实现写在源文件
class User{
	private:
		int age;
		char *name;
	
	public:
		void setAge(int age);
		int getAge();
		void setName(char *name);
		char* getName();

};
