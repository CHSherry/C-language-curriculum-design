/*
(1) ����Ա����

    �������ÿ�����������ɡ�4����ѡ�𰸡���׼�𰸵���Ϣ��
	�ɽ���������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

    ����ܣ�ָ����Ŀ������Ŀ�ܷ֣������Ծ�
	���Ծ�������ļ��������������һ���ļ���

	�û��������û���Ϣ������ӡ�ɾ�����޸ġ���ѯ�����桢����Ȳ�����

	�û������������ָ���û���ͳ�������Ծ���ܴ������Լ�ÿ�����õ��ܷ֡�
*/

//admin.cpp created time 2016-1-3 17:58:13

#include "all.h"

int sign_in() {

	system("mode con cols=30 lines=22");
	system("color 3A");

	int i;
	//char name[10]={"admin"},password[10]={"admin"};
	char name[10]={"1"},password[10]={"1"};

	FILE *fp;
	fp=fopen("password","r");

	if(fp==NULL)
		strcpy(password,"admin");
	else{
		fread(password,sizeof(char)*10,1,fp);
		fclose(fp);
	}	

	char get_1[10],get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("       ����Ա��¼����\n\n");
		printf("     ---------------------\n");
		printf("     |��¼��:|           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     | ����: |           |\n");
		printf("     ---------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fflush(stdin);
		goto_pos(16,7);
		scanf("%10s",get_1);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%10s",get_2);
		
		if(strcmp(name,get_1)==0&&strcmp(password,get_2)==0){
			goto_pos(11,17);
			printf("��¼�ɹ�!");
			Sleep(800);
			return 0;
		}else{
			goto_pos(11,17);
			printf("�������\n    ���������� (ʣ�����:%d)",2-i);
			Sleep(1300);
		}
	}
	exit(-1);
}

/*
               ����Ա���ƽ���     admin


               1.�������(��ɾ�Ĳ�)

               2.�����           

               3.�û��˺ż������������

               4.�޸Ĺ���Ա����

               ---------------     

               0.ע����¼
*/

void admin() {

	if(sign_in()==-1)//�����¼ʧ�����˳�
		return ;

	int a;
		
	while (1) {

		system("mode con cols=57 lines=20");
		system("color 47");

		a = move_1(5,menuPrint_2);
		switch (a) {
			//1.
			case 1:question_admin();continue;
			case 2:auto_paper();continue;
			case 3:user_admin();continue;
			case 4:change_admin_password();continue;
			case 6:;continue;
			case 0:
			default:break;
		}
		break;
	}

}

void menuPrint_2(int a) {

	system("cls");
	char name[15]={"menu_2.txt"};

	
	char arr[1500];//����1000��Ϊ����~2333
	memset(arr,0,sizeof(char)*1500);
	FILE *fp;
	fp=fopen(name,"r");

	if(fp==NULL) {
		printf("cannot open %s\n",name);
		exit (0);
	}

	int h=0;
	while(!feof(fp)) {
		fread(arr+h,sizeof(char),1,fp);
		h++;
	}
	printf("%s",arr);

	fclose(fp);

	switch (a) {
		//��ʾ���
		case 1:printLaugh(40,6);break;
		case 2:printLaugh(40,8);break;
		case 3:printLaugh(40,10);break;
		case 4:printLaugh(40,12);break;
		case 5:printLaugh(40,14);break;
		case 0:printLaugh(40,16);break;
		default:break;
	}
	
}

//------------------------------------------

void question_admin() {

	question(); // ->question.cpp

}

void auto_paper() {

	system("mode con cols=30 lines=12");
	system("color 0F");
	
	struct info * head = NULL;
	head=read_info();
	head=head->next;
	struct info * temp = NULL;
	if(head==NULL) {
		printf("��ǰ���Ϊ��!");
		return ;
	}

	fflush(stdin);
	int num,score;
	int i,j,count;
	int *no;

	printf("��������Ŀ��:");
	scanf("%2d",&num);
	no=(int *)malloc(sizeof(int)*num);
	if(no==NULL)
		exit(-1);

	printf("�������ܷ�:");
	scanf("%3d",&score);
	float solo=(float)((score+0.0)/num);
	
	for(i=0,j=0,count=0;i<num;)
	{
		count++;
		if(rand()%2==0)
			if( (temp=find_info_num(head,count))!=NULL&&temp->no!=0 )
				no[i++]=temp->no;
			else
				j++;
		if(j>10000)
			break;
	}

	if(i==num){
		printf("����ɹ�!���ڱ���Ϊ�����ļ�...");
		FILE * fp;
		fp=fopen("paper.txt","w");
		if(fp==NULL) {
			printf("cannot write %s\n","paper.txt");
			exit (0);
		}
		FILE * fq;
		fq=fopen("answer.txt","w");
		if(fq==NULL) {
			printf("cannot write %s\n","answer.txt");
			exit (0);
		}
		for(i=0;i<num;i++){
			temp=find_info_num(head,no[i]);
			fprintf(fp,"%s","���");
			fprintf(fp,"%3d",i+1);
			fprintf(fp,"%s","\n");
			fprintf(fp,"%s",temp->statement);
			fprintf(fp,"%.1f",solo);
			fprintf(fp,"%s","��\n");

			fprintf(fq,"%s","���");
			fprintf(fq,"%3d",i+1);
			fprintf(fq,"%s"," ��ȷ��ѡ����");
			fprintf(fq,"%c",temp->rightAnswer+'A');
			fprintf(fq,"%s","\n");
			for(j=0;j<4;j++){
				fprintf(fq,"%c",j+'A');
				fprintf(fq,"%s",":");
				fprintf(fq,"%s",temp->answers[j]);
			}
			fprintf(fq,"%s","\n");
		}
		fclose(fp);
		fclose(fq);
	}else{
		printf("��Ŀ������������ɳ�������...����ʧ��!\n");
		printf("���ڷ������˵�...");
		Sleep(1500);
	}

}

void user_admin() {

	admin_user();

}

void change_admin_password() {

	system("mode con cols=30 lines=22");
	system("color 3A");

	int i;
	char name[20]={"1"},password[20]={"1"};

	FILE *fp;
	fp=fopen("password","r");

	if(fp==NULL)
		strcpy(password,"admin");
	else{
		fread(password,sizeof(char)*10,1,fp);
		fclose(fp);
	}

	char get_2[10];
	for(i=0;i<3;i++) {
		system("cls");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("      ����Ա�����޸Ľ���\n\n");
		printf("     ---------------------\n");
		printf("     |ԭ����:|           |\n");
		printf("     ---------------------\n");
		printf("\n");
		printf("     ---------------------\n");
		printf("     |������:|           |\n");
		printf("     ---------------------\n");
		printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		goto_pos(16,7);
		printf("%s",password);
		fflush(stdin);
		goto_pos(16,11);
		scanf("%10s",get_2);
		if(strlen(get_2)>6){
			goto_pos(11,17);
			strcpy(password,get_2);
			fp=fopen("password","w");
			fwrite(password,sizeof(char)*10,1,fp);
			fclose(fp);
			printf("�޸ĳɹ�!");
			Sleep(800);
			return ;
		}else{
			goto_pos(9,17);
			printf("������ڼ�\n    ���������� (ʣ�����:%d)",2-i);
			Sleep(1300);
		}
	}
	exit(-1);

}

//------------------------------------------

struct info * find_info_num(struct info * head,int num) {

	struct info * node = head;

	while(node->next!=NULL){
		if(node->next->no==num)
			return node;
		node=node->next;
	}
	return NULL;
}


struct info * find_info_score_num(struct info * head,int lev) {

	struct info * node = head;

	while(node->next!=NULL){
		if(node->next->score==lev)
			return node->next;
		node=node->next;
	}
	return NULL;
}