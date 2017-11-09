#include "../header.h"

class Teacher{
	private:
		char *name;
		
	public :
		//静态计数器
		static int total;
		
		Teacher(char *n){
			this->name = n;
			cout << "teacher"<<endl;
		}
		
		char * getName(){
			return name;
		}

		void setName(char *n){
			this->name = n;
		}

		//static
		
		static void sCount(){
			total ++;
		}

		void count(){
			total ++;
		}
		~Teacher(){cout << "~teacher"<<endl;}
		
};

//静态属性初始化赋值，然后才能调用
int Teacher::total = 9;

int main(){
	Teacher::total++;
	//直接通过类名访问
	Teacher::sCount();
	Teacher t("123");
	t.count();
	t.sCount();
	cout << Teacher::total << endl;
	
}
