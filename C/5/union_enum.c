//联合体（共用体）
//不同类型的变量共占用一段内存（相互覆盖），联合变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小 = 最大的成员所占的字节数
//同穿一条裤子
union MyValue{
	
	int x;
	int y;
	double z; 
};

//枚举
//固定的数据
//梅举的值默认是int值，从0开始 Mon = 0, Tue = 1, ...., Sun = 6
enum Day{
	Mon,
	Tue,
	Wen,
	Thu,
	Fri,
	Sat,
	Sun
};

void main(){
	union MyValue d1;
	d1.x = 90;
	d1.y = 100;
	d1.z = 45.23; // 只有z有值,最后一个赋值的才有值
	printf("x = %d, y = %d, z = %lf\n", d1.x, d1.y, d1.z);

	enum Day d = Mon;
	printf("%#x, %d\n", &d, d);
	
	int i = 0;	
	//梅举的地址不是连续的
	enum Day *p = &d;
	for(; i < 7; i++){
		printf("%#x, %d\n", p, *p);
		p++;
	}

	
}


