#include"list.h"

/************************************
函数功能： 三方登录开奖
入参：彩票链头节点，历史链头节点
返回值：是否登录成功
************************************/
void open_ticket(USER_NODE *p,ABT_NODE *q,HT_NODE *r)
{
	ABT_NODE *abt=q;
	HT_NODE *ht=r;
	USER_NODE *user=p;
	if(abt==NULL||ht==NULL||user==NULL)
		{
			printf("error head in sign_in\n");
			exit(-1);
		}

	
			int num=0;
			char ch=' ';
			printf("ticket是否却认开奖(是--Y):");
			scanf(" %c",&ch);
			if(ch!='Y')
				{
					return;
				}
			
					while(abt->next!=NULL)
						{   
							abt=abt->next;
							if(abt->abt.open==0)
							{
								break;
							}
						}

			
					if(abt->abt.open!=0)
						{
							system("clear");
							printf("尚未发布新的彩票，不能开奖!\n");
							return;
						}
				
			while(1)
				{
					system("clear");
					printf("彩票期号\t彩票单价\t奖池金额\n");
					printf("%d\t\t%.2f元\t\t%.2f元\n",abt->abt.issue,abt->abt.p_money,abt->abt.money);

					char ch=' ';
					printf("ticket是否手动开奖? y/n\n");
					scanf(" %c",&ch);

					if(ch=='n')
						{
							srand((unsigned int) time (NULL) );
							num=rand()%100000;
							printf("本期彩票的中奖号码(五个数):%d\n",num);
							
							if(num<10000||num>99999)
								{
									printf("输入号码不合法，请重新输入!\n");
								}
							else 
								{	
									abt->abt.num=num;
									abt->abt.open=1;
									break;
								}
						}
					else if(ch=='y')
						{
							printf("ticket请输入本期彩票的中奖号码(五个数):");
							scanf("%d",&num);

							if(num<10000||num>99999)
								{
									printf("输入号码不合法，请重新输入!\n");
								}
							else 
								{	
									abt->abt.num=num;
									abt->abt.open=1;
									break;
								}
						}
						else 
							{
								while(getchar()!='\n');
								printf("输入有误，请重新输入!\n");
								continue;
							}
					}					
				ht=r->next;
			    int	sum=0;
				while(ht!=NULL)
					{	
  						if(ht->ht.open==0&&ht->ht.buy_num==num)
								{		
									sum+=ht->ht.times;
									ht->ht.win=1;
								}
							ht=ht->next;

					}//计算中了多少注

					//system("clear");

	
				printf("ID\tNAME\tT_ID\tISSUE\tOPEN_N\tBUY_N\tTIMES\tOPEN\tWIN\tBONUS\tBALANCE\n");
				ht=r->next;
				while(ht!=NULL)
					{	
  						if(ht->ht.open==0)
								{		
									ht->ht.open_num=num;
									ht->ht.open=1;
									if(ht->ht.open_num==ht->ht.buy_num)
									{
										ht->ht.money=0.8*(1000+ht->ht.times*abt->abt.p_money)*(ht->ht.times*1.0/sum);
										ht->ht.re_money+=ht->ht.money;
										abt->abt.money-=ht->ht.money;
											while(user->next!=NULL)
												{
													user=user->next;
													if(user->user.id==ht->ht.id)
														{
																user->user.money=ht->ht.re_money;
																break;
														}
													
												}
									}
									printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%.2f\t%.2f"
																			,ht->ht.id
																			,ht->ht.name
																			,ht->ht.t_id
																			,ht->ht.issue
																			,ht->ht.open_num
																			,ht->ht.buy_num
																			,ht->ht.times
																			,ht->ht.open>0?"是":"否"
																			,ht->ht.win>0?"是":"否"
																			,ht->ht.money
																			,ht->ht.re_money);
												printf("\n");
								}
							ht=ht->next;

					}
								
}
/************************************
函数功能： 三方登录查看历史彩票
入参：彩票链头节点
返回值：是否登录成功
************************************/
void view_all_ticket(ABT_NODE *q)
{
	ABT_NODE *abt=q;
	if(abt==NULL)
		{
			printf("error head in sign_in\n");
			exit(-1);
		}

		system("clear");

	printf("ISSUE\tPRICE\tOPE_N\tOPEN\tBALACE\n");
		abt=q->next;
		while(abt!=NULL)
			{
				printf("%d\t%.2f\t%d\t%s\t%.2f\n"
												,abt->abt.issue
												,abt->abt.p_money
												,abt->abt.num
												,abt->abt.open>0?"是":"否"
												,abt->abt.money);
				abt=abt->next;
			}
}


/************************************
函数功能： 三方登录
入参：彩票链头节点，历史链头节点
返回值：是否登录成功
************************************/
int ticket_sign_in(USER_NODE *p,ABT_NODE *q,HT_NODE *r)
{
	ABT_NODE *abt=q;
	HT_NODE *ht=r;
	USER_NODE *user=p;
	if(abt==NULL||ht==NULL||user==NULL)
		{
			printf("error head in sign_in\n");
			exit(-1);
		}
	system("clear");

	while(1)
	{
		system("cat ./view/notary_menu.txt");
		int sw=-1;
		printf("ticket请输入选项-->:");
		scanf("%d",&sw);
		if(sw==1)
			{
				open_ticket(p,q,r);
			}
		else if(sw==2)
			{		
				view_all_ticket(q);
			}
		else if(sw==0)
			{
				system("clear");
				return 0;
			}
		else 
			{
				system("clear");
				printf("输入有误，请重新输入!\n");
			}
		while(getchar()!='\n');
	}
	return 0;
	
}
