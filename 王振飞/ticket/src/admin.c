#include"list.h"

/************************************
函数功能：admin的查看购菜记录
入参：历史购彩记录头节点
返回值：整型
************************************/
int view_ticket(HT_NODE *head)
{
	HT_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in view_ticket!\n");
				exit(-1);
			}
	system("clear");
	printf("ID\tNAME\tT_ID\tISSUE\tOPEN_N\tBUY_N\tOPEN\tWIN\tBONUS\n");
	p=p->next;
	while(p!=NULL)
		{
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%.2f\n",p->ht.id
							 								,p->ht.name
															,p->ht.t_id
															,p->ht.issue
															,p->ht.open_num
															,p->ht.buy_num
															,p->ht.open>0?"是":"否"
															,p->ht.win>0?"是":"否"
															,p->ht.money);
			p=p->next;

		}

	return 0;

}


/***********************************
函数功能：查找上期彩票的奖池余额和期号
入参：彩票链头节点
返回值：无
************************************/
void  old_abt_search(ABT_NODE *head,int *issue)
{
		ABT_NODE *p=head;
			if(p==NULL)
			{
				printf("error head in old_abt_search!\n");
				exit(-1);
			}


		int k=0;
		p=head->next;
		while(p!=NULL)
			{
				k++;
				if(p->abt.issue>*issue)
					{
						*issue=p->abt.issue;
					}
				p=p->next;
			}
}
/***********************************
函数功能：管理员发行彩票
入参：彩票链头节点
返回值：无
************************************/
void issue_ticket(ABT_NODE *head)
{
	ABT_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in issue_ticket!\n");
				exit(-1);
			}

	char ch=' ';
	printf("admin是否确定发行彩票(是-->Y):");
	scanf(" %c",&ch);
		if(ch!='Y')
			{
				system("clear");
				return;
			}

	float pice=0.0f;
	int issue=0,*p_issue=NULL;
		p_issue=&issue;
	old_abt_search(p,p_issue);

		p=head->next;
		while(p!=NULL)
			{
				if(p->abt.open==0)
					{
						system("clear");
						printf("上期彩票尚未开奖，不能发行新彩票！\n");
						return;
					}
				p=p->next;
			}
		
	while(1)
	{		
		printf("admin请输入本期彩票单价:");
		scanf("%f",&pice);
		if(pice==0.0)
		{
			printf("输入有误，请重新输入!\n");
			while(getchar()!='\n');
		}
		else break;
	}

	ABT_NODE *newnode=(ABT_NODE *) malloc (sizeof(ABT_NODE));
		
		assert(newnode!=NULL);
		newnode->abt.money=1000;
		newnode->abt.p_money=pice;
		newnode->abt.issue=issue+10;
		newnode->abt.num=-1;
		newnode->abt.open=0;


		newnode->next=head->next;
		head->next=newnode;
		
		system("clear");
		printf("**********发行彩票成功**********\n");
		printf("彩票期号\t彩票单价\t奖池金额\n");
		printf("%d\t\t%.2f元\t\t%.2f元\n",newnode->abt.issue,pice,newnode->abt.money);
}

/***********************************
函数功能：admin搜索彩民ID
入参：用户链头节点
返回值：无
************************************/
void search_userid(USER_NODE *head)
{
	USER_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in search_userid!\n");
				exit(-1);
			}

	printf("请输入用户ID：");
	while(1)
	{
			int id=-1;	
			scanf("%d",&id);
			p=head->next;
			while(p!=NULL)
				{
					if(p->user.id==id)
						break;
					p=p->next;
				}
				
		if(p!=NULL&&p->user.id==id)
			break;
		else 
			{
				printf("无此用户，请重新输入用户ID：");
				while(getchar()!='\n');
			}
	}


	system("clear");
	printf("==========================\n");
	printf("ID\t姓名\t密码\t余额\n");
	printf("%d\t%s\t%s\t%.2f\n",p->user.id
								,p->user.name
								,p->user.pwd
								,p->user.money);


	char pwd[pwd_len]={},pwd1[pwd_len]={};
	while(1)
	{
		char ch=' ';
		printf("admin是否修改客户密码(Y/N):");
		scanf(" %c",&ch);

		if(ch=='Y')
			{
				printf("请输入新密码：");	
				scanf("%s",pwd);
				printf("请再次输入新密码：");
				scanf("%s",pwd1);
				{
					if(strcmp(pwd,pwd1)==0)
						{	
							system("clear");
							strcpy(p->user.pwd,pwd);		
							printf("！密码修改成功！\n");
							return;
						}
					else printf("密码不一致，请重新输入！\n");
				}
			}
		else if(ch=='N')
			return;
		else 
			{
				printf("输入有误，请重新输入！！！\n");
			}
		while(getchar()!='\n');
	}
}
/***********************************
函数功能：搜索特定用户余额区间
入参：用户链头节点
返回值：无
************************************/
void money_block(USER_NODE *head)
{
	USER_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in issue_ticket!\n");
				exit(-1);
			}
	while(1)			
		{
			printf("admin请输入搜索区间(用空格分开):");
			float	down=-2.0f,up=-3.0f;
			scanf("%f %f",&down,&up);
			if(up<down)
				{
					printf("输入不合法，请重新输入\n");
					while(getchar()!='\n');
				}
			else 
			{
				p=p->next;
				system("clear");
				printf("==================================\n");
				printf("ID\t姓名\t余额\n");
				while(p!=NULL)
					{
						if((p->user.money<up+1)&&(p->user.money>down-1))
							printf("%d\t%s\t%.2f\n",p->user.id
													,p->user.name
													,p->user.money);

						p=p->next;
					}
				return;
			}
		}
	

}

/***********************************
函数功能：admin依据id,余额排序查看
入参：用户链头节点
返回值：无
************************************/
void view_all(USER_NODE  *head,int num)
{
	USER_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in issue_ticket!\n");
				exit(-1);
			}


	int j=0,i=0,id=-1,k=0;
	char name[name_len]={},pwd[pwd_len]={};
	float money=0.0;
	
	p=head->next;
	while(p!=NULL)
		{
			k++;
			p=p->next;
		}


#if 0
		p=head->next;
		printf("==================================\n");
		printf("ID\t姓名\t余额\n");
		while(p!=NULL)
			{
				printf("%d\t%s\t%.2f\n",p->user.id
										,p->user.name
										,p->user.money);
				p=p->next;

			}
#endif


	if(num==1)
	{
		for(i=0;i<k-1;i++)
			{
				p=head->next;
				for(j=0;j<k-1-i;j++)
					{		
						if((p->user.id)>(p->next->user.id))
							{
								id=p->user.id;
								p->user.id=p->next->user.id;
								p->next->user.id=id;

								money=p->user.money;
								p->user.money=p->next->user.money;
								p->next->user.money=money;

								strcpy(name,p->user.name);
								strcpy(p->user.name,p->next->user.name);
								strcpy(p->next->user.name,name);

								strcpy(pwd,p->user.pwd);
								strcpy(p->user.pwd,p->next->user.pwd);
								strcpy(p->next->user.pwd,pwd);
				    		}
						p=p->next;
		     		}
				}
		}
		
		else 
		{
			for(i=0;i<k-1;i++)
				{
					p=head->next;
					for(j=0;j<k-1-i;j++)
						{		
							if((p->user.money)>(p->next->user.money))
								{
									id=p->user.id;
									p->user.id=p->next->user.id;
									p->next->user.id=id;

									money=p->user.money;
									p->user.money=p->next->user.money;
									p->next->user.money=money;

									strcpy(name,p->user.name);
									strcpy(p->user.name,p->next->user.name);
									strcpy(p->next->user.name,name);

									strcpy(pwd,p->user.pwd);
									strcpy(p->user.pwd,p->next->user.pwd);
									strcpy(p->next->user.pwd,pwd);
				    			}
							p=p->next;
		     			}
					}
			}

		p=head->next;
		system("clear");
		printf("==================================\n");
		printf("ID\t姓名\t余额\n");
		while(p!=NULL)
			{
				printf("%d\t%s\t%.2f\n",p->user.id
										,p->user.name
										,p->user.money);
				p=p->next;

			}
			
		
	

}	
/***********************************
函数功能：admin查看用户
入参：用户链头节点
返回值：无
************************************/
void view_user(USER_NODE  *head)
{
	USER_NODE *p=head;
		if(p==NULL)
			{
				printf("error head in issue_ticket!\n");
				exit(-1);
			}
	system("clear");		

	while(1)
		{
			int sw=-1;
			system("cat ./view/ticket_admin_view.txt");
			printf("请输入选项-->");
			scanf("%d",&sw);

				switch(sw)
					{
						case 0: 
							{	
								system("clear");
								return;
							}
						case 1:
							{
								system("clear");
								search_userid(head);
								break;
							}
						case 2:
							{
								system("clear");
								money_block(head);
								break;
							}
						case 3:
							{	
								system("clear");
								view_all(head,1);
								break;
							}
						case 4:
							{
								system("clear");
								view_all(head,2);
								break;
							}
					}

			while(getchar()!='\n');
		}

}

/***********************************
函数功能：admin 查看申请充值
入参：充值链头节点
返回值：无
************************************/
void view_all_charge(CHARGE_NODE *t)
{
	CHARGE_NODE *charge=t;
	if(t==NULL)
		{
			printf("error head in admin!\n");
			exit(-1);
		}
	printf("ID\tNAME\tSUCCESS\tPROCESS\tMONEY\n");
	
		while(charge->next!=NULL)
			{
				charge=charge->next;
				printf("%d\t%s\t%s\t%s\t%.2f\n"
											,charge->charge.id
											,charge->charge.name
											,charge->charge.state>0?"是":"否"
											,charge->charge.process>0?"是":"否"
											,charge->charge.money);

			}
}
/***********************************
函数功能：查看申请充值
入参：用户链头节点，充值链头节点
返回值：无
************************************/
void apply_charge(USER_NODE *p,CHARGE_NODE *t)
{
	USER_NODE *user=p;
	CHARGE_NODE *charge=t;
	if(p==NULL||t==NULL)
		{
			printf("error head in admin!\n");
			exit(-1);
		}

	while(charge->next!=NULL)
		{
				char check=' ';
				charge=charge->next;
				if(charge->charge.process==0)
					{
						printf("ID\tNAME\tSUCCESS\tPROCESS\tMONEY\n");
						printf("%d\t%s\t%s\t%s\t%.2f\n"
												  ,charge->charge.id
												  ,charge->charge.name
												  ,charge->charge.state>0?"是":"否"
												  ,charge->charge.process>0?"是":"否"
												  ,charge->charge.money);
						printf("是否同意充值(y/else):");
						scanf(" %c",&check);
						if(check=='y')
							{
								user=p;
								while(user->next!=NULL)
									{
										user=user->next;
										if(user->user.id==charge->charge.id)
											{
													user->user.money+=charge->charge.money;
													charge->charge.state=1;
													charge->charge.process=1;
													printf("申请已同意！\n");
													printf("*********************************\n");
													break;
											}
									}

							}
						else
							{
								printf("申请不同意！\n");
								printf("*********************************\n");
								charge->charge.state=0;
								charge->charge.process=1;
								while(getchar()!='\n');
							}
					}
		}
}

/***********************************
函数功能：管理员登录
入参：用户链头节点，彩票链头节点，历史链头节点
返回值：整型
************************************/
int admin_sign_in(USER_NODE *p,ABT_NODE *q,HT_NODE *r,CHARGE_NODE *t)
{
	if(p==NULL||q==NULL||r==NULL||t==NULL)
		{
			printf("error head in admin!\n");
			exit(-1);
		}
	system("clear");


		while(1)
			{	
				int sw=-1;
				system("cat ./view/ticket_admin.txt");
				printf("admin请输入选项-->");
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
								issue_ticket(q);
								break;
							}
						case 2:
							{
								system("clear");
								view_user(p);
								break;
							}
						case 3: 
							{
								system("clear");
								int vi=view_ticket(r);
									if(vi==0)
										break;
							}
						case 4:
							{
								system("clear");
									apply_charge(p,t);
								break;
							}
						case 5:
							{
								system("clear");
									view_all_charge(t);
								break;
							}
					  default:
					  	{
							system("clear");
							printf("输入有误，请重新输入！\n");
						}
					}
				while(getchar()!='\n');
			}
}
