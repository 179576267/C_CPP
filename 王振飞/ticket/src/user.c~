#include"list.h"

/*******************************************
函数功能：修改用户密码
入参：用户结构体，用户链头节点
返回值：整型
********************************************/
int mend(USER *p_user,USER_NODE *head)
{
	char pwd[pwd_len]={},pwd1[pwd_len]={};
	if(p_user==NULL||head==NULL)
		{
			printf("error head in mend!\n");
			exit(-1);
		}
	while(1)
		{
			printf("请输入原密码:");
			scanf("%s",pwd1);
			if(strcmp(pwd1,p_user->pwd)==0)
				{
					printf("请输入新密码(5-10):");
					scanf("%s",pwd);
					printf("请再次输入新密码:");
					scanf("%s",pwd1);
						
						if(strcmp(pwd1,pwd)==0&&(strlen(pwd)>4||strlen(pwd)<11))
							{
								strcpy(p_user->pwd,pwd);
								break;
							}
						else printf("新密码不一致，或者不合法，请重新输入!\n");
				}
			else printf("密码不正确，请重新输入!\n");
		}

	return 1;

}
/*******************************************
函数功能：删除用户
入参：用户结构体，用户链头节点
返回值：整型
**********************************************/
int delete(USER *p_user,USER_NODE *head)
{
	USER_NODE *p=head,*save=NULL;
	if(p==NULL||p_user==NULL)
		{
			printf("error head in delete!\n");
			return 0;
		}
//	printf("deletehead=%p\n",head);
	while(p->next->user.id!=p_user->id)
		{

			p=p->next;
		}

	save=p->next;
	p->next=p->next->next;
	free(save);

	return 1;
}
/*******************************************
函数功能：用户登录成功后 购买彩票
入参：用户链头节点，彩票链头节点，历史记录链头节点
返回值：无
********************************************/
void buy_ticket(ABT_NODE *q,HT_NODE *r,USER *p_user)
{
	system("clear");
	ABT_NODE *abt=q;
	HT_NODE *ht=r;
	if(p_user==NULL||abt==NULL||ht==NULL)
			{
				printf("error head lottery!\n");
				exit(-1);
			}
	while(abt->next!=NULL)
		{
			abt=abt->next;
			if(abt->abt.open==0)
				break;
		}

	if(abt->abt.open==0)
		{
			printf("发布期号\t彩票单价\t奖池金额\n");
			printf("%d\t\t%.2f\t\t%.2f\n"
										,abt->abt.issue
										,abt->abt.p_money
										,abt->abt.money);
		
				
						int num=0;
						int t_id=0;
						int times=-1;
				while(1)
					{
						printf("%s###请输入购买号码：",p_user->name);
						scanf("%d",&num);

						if(num<10000||num>99999)
							{
								printf("输入有误，请重新输入！\n");
								while(getchar()!='\n');
							}
						else break;
					}

				while(1)
					{
						printf("%s###请选择购买注数(0-5注)：",p_user->name);
						scanf("%d",&times);

						if(times<0||times>5)
							{
								printf("输入有误，请重新输入！\n");
								while(getchar()!='\n');
							}
						else 
							{
								if(p_user->money<abt->abt.p_money*times)
									{
										printf("余额不足，请先充值!\n");
										return;
									}
								else p_user->money-=abt->abt.p_money*times;



								HT_NODE *newnode=(HT_NODE *) malloc (sizeof(HT_NODE));
									newnode->ht.id=p_user->id;
									strcpy(newnode->ht.name,p_user->name);

										while(ht->next!=NULL)
											{
												ht=ht->next;
												if(ht->ht.t_id>t_id)
													t_id=ht->ht.t_id;
											}

									newnode->ht.t_id=t_id+1;
									newnode->ht.issue=abt->abt.issue;
									newnode->ht.open_num=-1;
									newnode->ht.buy_num=num;
									newnode->ht.times=times;
									newnode->ht.open=0;
									newnode->ht.win=0;
									newnode->ht.money=0;
									newnode->ht.re_money=p_user->money;

									abt->abt.money+=times*abt->abt.p_money;
								
									newnode->next=r->next;
									r->next=newnode;
								printf("恭喜购买成功，祝您中奖!\n");
								break;
							}
					}
			}

		else 
		{
			printf("尚未发布新彩票，请等待!\n");
		}
	

}
/*******************************************
函数功能：用户查看购票记录
入参：历史记录链头节点，当前登录用户
返回值：无
********************************************/
void view_myself(HT_NODE *r,USER *p_user)
{
	HT_NODE *ht=r;
	if(p_user==NULL||ht==NULL)
			{
				printf("error head lottery!\n");
				exit(-1);
			}



				printf("ID\tNAME\tT_ID\tISSUE\tOPEN_N\tBUY_N\tTIMES\tOPEN\tWIN\tBONUS\tBALANCE\n");
				ht=r->next;
				while(ht!=NULL)
					{	
						if(p_user->id==ht->ht.id)
						{
							printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%.2f\t%.2f\n"
															,ht->ht.id
															,ht->ht.name
															,ht->ht.t_id
															,ht->ht.issue
															,ht->ht.open_num
															,ht	->ht.buy_num
															,ht->ht.times
															,ht->ht.open>0? "是":"否"
															,ht->ht.win>0? "是":"否"
															,ht->ht.money
															,ht->ht.re_money);
						}
						ht=ht->next;
					}
}
/*******************************************
函数功能：用户查看充值记录
入参：充值链头节点
返回值：无
********************************************/
void charge_view(CHARGE_NODE *head,USER *p_user)
{
	CHARGE_NODE *charge=head;
	if(charge==NULL)
			{
				printf("error head lottery!\n");
				exit(-1);
			}

	printf("ID\tNAME\tSUCCESS\tPROCESS\tMONEY\n");
	while(charge->next!=NULL)
		{
			charge=charge->next;
			if(p_user->id==charge->charge.id)
			{
				printf("%d\t%s\t%s\t%s\t%.2f\n"
										,charge->charge.id
										,charge->charge.name
										,charge->charge.state>0? "是":"否"
										,charge->charge.process>0? "是":"否"
										,charge->charge.money);
			}
		}
}
/*******************************************
函数功能：用户登录成功后的权限
入参：用户链头节点，彩票链头节点，历史记录链头节点
返回值：整型
********************************************/
int user_sign_in(USER_NODE *p,ABT_NODE *q,HT_NODE *r,USER *p_user,CHARGE_NODE *t)
{
	USER_NODE *user=p;
	ABT_NODE *abt=q;
	HT_NODE *ht=r;
	CHARGE_NODE *charge=t;
	if(user==NULL||abt==NULL||ht==NULL||charge==NULL)
			{
				printf("error head lottery!\n");
				exit(-1);
			}
	system("clear");
	printf("(  (  (  (  (  用户名密码正确  )  )  )  )  )\n");
	
//	printf("LOTTERYhead=%p\n",p);
	
	while(1)
		{
			int sw=-1;
			system("cat ./view/ticket_user.txt");
			printf("%s##请输入选项-->",p_user->name);
			scanf("%d",&sw);

			switch(sw)
				{
					case 0: 
						{
							system("clear");
							return 0;
						}
					case 1: 
						{
							system("clear");
							printf("ID\t姓名\t密码\t帐户余额\n");
							printf("%d\t%s\t%s\t%.2f\n",p_user->id
														,p_user->name
														,"****"
														,p_user->money);
							break;

						}
					case 2:
						{
							buy_ticket(q,r,p_user);
							break;

						}
					case 3:
						{	
							float money=-1.0f;
							while(1)
								{
									srand((unsigned int) time (NULL) );
									printf("请输入充值金额(0-1000元):");
									scanf("%f",&money);
									int check=rand()%10000,check_user=0;
									printf("验证码为:%d\n",check);
									printf("请输入验证码-->");
									scanf("%d",&check_user);
									if(check!=check_user)
										{
											printf("验证码错误，请重新选择!\n");
											while(getchar()!='\n');
										}
									else if(money<0||money>1000)
										{
											printf("输入金额不合法，请重新输入\n");
											while(getchar()!='\n');
										}
									else break;
								}

								system("clear");

								CHARGE_NODE *newnode=(CHARGE_NODE *) malloc (sizeof(CHARGE_NODE));
									
									assert(newnode!=NULL);
									newnode->charge.id=p_user->id;
									strcpy(newnode->charge.name,p_user->name);
									newnode->charge.state=0;
									newnode->charge.process=0;
									newnode->charge.money=money;

									newnode->next=charge->next;
									charge->next=newnode;

								printf("充值申请已提交，请联系管理员!\n");
								
								break;
						}

					case 4:
						{
							system("clear");
							charge_view(charge,p_user);
							break;
						}
					case 5:
						{
							int m=mend(p_user,p);
								system("clear");
								if(m==1) printf("修改密码成功!\n");
								else printf("修改密码失败!\n");
							break;
						}
					case 6:
						{
							system("clear");
							view_myself(r,p_user);
							break;
						}
					case 7:
						{
							char ch=' ';
							printf("是否确认注销帐户(Y/N):");
								scanf(" %c",&ch);
							if(ch=='Y'&&getchar()=='\n')
								{
									int de=delete(p_user,p);
									system("clear");
									if(de==1) printf("删除帐户成功!\n");
									return 0;
								}	
							else if(ch=='N') 
								{
										system("clear");
										break;
								}
							else
								{
										system("clear");
										printf("输入不合法!\n");	
										break;
								}
						}
					default:
						{
							system("clear");
							printf("输入不合法，请重新输入\n");
							break;
						}
				}
				while(getchar()!='\n');
		}
}

