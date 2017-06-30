#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define name_len 20
#define pwd_len  20 

typedef struct 
{
	int id;//用户ID
	char name[name_len];
	char pwd[pwd_len];
	float money;//用户余额

}USER;//彩民信息结构体

typedef struct user_node
{
	USER user;
	struct user_node *next;
}USER_NODE;//彩民链表


typedef struct
{
	float money;//奖池金额
	float p_money;//彩票单价
	int   issue;//彩票期号
	int   num;//中奖号码
	int  open;//是否开奖
}ABT;//发行彩票结构体


typedef struct abt_node
{	
	ABT abt;
	struct abt_node *next;
}ABT_NODE;//发行彩票链表


typedef struct 
{
	int id;//用户id
	char name[name_len];//用户姓名
	int   t_id;// 彩票ID
	int issue;//发行期号
	int open_num;//开奖号码
	int buy_num;// 购买号码
	int times;//购买注数
	int open;//是否开奖
	int win; //是否中奖
	float money;//中奖金额
	float re_money;//帐户余额
}HT;//历史购票结构体

typedef struct ht_node
{
	HT ht;
	struct ht_node *next;
}HT_NODE;//历史购票链表


typedef struct
{
	int id;//用户ID
	char name[name_len];//用户姓名
	int state;//充值状态
	int process;//受理状态
	float money;//充值金额
}CHARGE;

typedef struct charge_node
{
	CHARGE charge;
	struct charge_node *next;
}CHARGE_NODE;//充值链




