#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <algorithm>
#define precision 6 
#define LINE_MAX 1024
using namespace std;

struct node
{
    int bustime,arrive,priority,id;
    struct node *next;
};


void scheduling_method();
void display(struct node *header);
struct node* readfromfile(struct  node *head);
struct node * createnode(int con1, int con2, int con3,int con4);
struct node * insert(struct node *header,int con1,int con2, int con3,int con4);
int size(struct node *header);
void firstcomefirstserve(struct node *header,int processes);
void nonpsjf(struct node *header,int processes);
void nonpreemtivepr(struct node *header,int processes);
void sortinglist( struct node *header);
void sortingbyst(struct node *header);
void sortingbypr(struct node *header);
void sortingid(struct node *header);
void showresult(struct node *header,int processes,string y);
void exit(struct node *header,int processes,string n);
string tostring(int x);
string tostdouble(double x);

int main() {
	
	struct node *head=NULL;
	head=readfromfile(head);
	int p=size(head);
    int choice;
    while(true){
	 cout<<"\n\n 1) Scheduling Method";
	 cout<<"\n 2) Preemptive Mode";
	 cout<<"\n 3) Non-preemptive Mode";
	 cout<<"\n 4) show Result";
	 cout<<"\n 5) End Program";
	 cout<<"\n choose simulation method \n";
	cin>>choice;

	 
	switch(choice){
		
		
		case 1:
			scheduling_method();
			break;
			
			
		case 2:
				cout<<".......";
			break;
			
			
		case 3:
			int u;
			cout<<"\n\n\n 1)Shortest Job First";
			cout<<"\n 2)Priority first";
			cout<<"\n choose the type of non-preemtive \n";
			cin>>u;
			switch(u)
				switch(u)
			{
					case 1:
						nonpsjf(head,p);
						break;
					case 2:
							nonpsjf(head,p);
						break;
			}
			break;
			
			
		case 4:
				int k;
			cout<<"\n\n\n 1)First Come First Serve";
			cout<<"\n 2)non-preemptive Shortest Job First";
			cout<<"\n 3)non-preemtive Priority first";
			cout<<"\n choose the type scheduling you want to display \n";
			cin>>k;
			switch(k)
				switch(k)
			{				
					case 1:
						firstcomefirstserve(head,p);						
						break;				
					case 2:					
						nonpsjf(head,p);												
						break;
					case 3:												
						nonpreemtivepr(head,p);
						break;
			}
			break;
			
			
		case 5:
				return 0;
			break;
	}
}
}
	
void scheduling_method(){
	struct node *head=NULL;
	head=readfromfile(head);
	int c;
	int p=size(head);
	cout<<"\n 1) First Come,First Served Scheduling";
	cout<<"\n 2) Shortest-Job-First Scheduling";
	cout<<"\n 3) Priority Scheduling";
	cout<<"\n 4) Round-Robin Scheduling";
	cout<<"\n choose scheduling method\n";
	cin>>c;
		switch(c){
		case 1:
			firstcomefirstserve(head,p);
			break;
		case 2:
			{
			
			int u;
			cout<<"\n\n\n 1)preemptive";
			cout<<"\n 2)non-preemptive";
			cout<<"\n choose the type of SJFS \n";
			cin>>u;
			switch(u)
			{
				
					case 1:
						{
						cout<<"......";
						}
						
						break;
					case 2:
						{
						
							nonpsjf(head,p);
						}
						
						break;
			}
		}
			    break;
		case 3:
				int w;
			cout<<"\n\n\n 1)preemptive";
			cout<<"\n 2)non-preemptive";
			cout<<"\n choose the type of SJFS \n";
			cin>>w;
				switch(w){
				
					case 1:
						cout<<".......";
						break;
					case 2:
						{
							nonpreemtivepr(head,p);	
						}
				
						break;
					}
			break;
		case 4:
				cout<<".......";
			break;
		case 5:
				cout<<".......";
			break;
	}
	

}
struct node * readfromfile(struct node *head){
	FILE *fp;
	int i=1;
    char line[LINE_MAX];
     unsigned int num[4];

    if ((fp = fopen("input.txt", "r")) == NULL)
        return 0;
    while (fgets(line, LINE_MAX, fp) != NULL) {
    	num[3]=i;
        sscanf(line,"%d:%d:%d\n",&num[0],&num[1],&num[2]);
      head =  insert(head,num[0],num[1],num[2],num[3]);
      i++;
}
	
fclose(fp);
	return head;
	
}
struct node * createnode(int con1, int con2, int con3,int con4)
{
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(node));
	temp->bustime=con1;
	temp->arrive=con2;
	temp->priority=con3;
	temp->id=con4;
	temp->next=NULL;
	return temp;
}
struct node * insert(struct node *header,int con1,int con2, int con3,int con4)
{
	struct node * temp=(createnode(con1,con2,con3,con4));
	struct node * findback;
	if(header==NULL)
		{
			header=temp;
			return header;
		}
	findback=header;
	while(findback->next!=NULL)
		findback=findback->next;
	findback->next=temp;
	return header;
}


int size(struct node *header)
{
	int x=0;
	while(header!=NULL)
	{
		x++;
		header=header->next;
	}
	return x;	
}
void firstcomefirstserve(struct node *header,int processes)
{
	struct node *temp=header;
	sortinglist(temp);
	string x="First Come First Serve";
	int comtime=0,waitingtime=0,totalwait,arriva,bust,n;
	for(int i=0;i<processes;i++)
	{
		comtime+=temp->bustime;
		waitingtime=comtime-temp->arrive-temp->bustime ;
		temp->bustime=waitingtime;
		temp=temp->next;
	}
   
		showresult(header,processes,x);
		exit(header,processes,x);
}
void nonpsjf(struct node *header,int processes){
	node *temp=header;
	sortinglist(temp);
	string x="Non-Preemptive Shortest Job First";
    int firstjob,comtime=0,wait,tt=0;
    sortingbyst(temp->next); 
		for(int i=0;i<processes;i++){
			comtime+=temp->bustime;
			wait=comtime-temp->arrive-temp->bustime;
			temp->bustime=wait;
			temp=temp->next;
		}
			
	showresult(header,processes,x);
	exit(header,processes,x);
}

void nonpreemtivepr(struct node *header,int processes){
	node *temp=header;
	sortinglist(header);
	string x="Non-Preemptive Shortest Job First";
    int firstjob,comtime=0,wait,tt=0;
    sortingbypr(temp->next); 
		for(int i=0;i<processes;i++){
			comtime+=temp->bustime;
			wait=comtime-temp->arrive-temp->bustime;
			temp->bustime=wait;
			temp=temp->next;
		}
			
	showresult(header,processes,x);
	exit(header,processes,x);
}
void sortingbyst(struct node *header){
	struct node *end,*p,*q;
	int tempbt,tempat,tempid,temppt;
	for(end=NULL;end!=header->next;end=p)
	{
		for(p=header;p->next!=end; p=p->next){
		
		q=p->next;
		if(p->bustime > q->bustime)
		{
		tempat=p->arrive;
		p->arrive=q->arrive;
		q->arrive=tempat;
		
		tempbt=p->bustime;
		p->bustime=q->bustime;
		q->bustime=tempbt;
		
		tempid=p->id;
		p->id=q->id;
		q->id=tempid;
		
		temppt=p->priority;
		p->priority=q->priority;
		q->priority=temppt;
		}
	}
}
}


void sortingbypr(struct node *header){
	struct node *end,*p,*q;
	int tempbt,tempat,tempid,temppt;
	for(end=NULL;end!=header->next;end=p)
	{
		for(p=header;p->next!=end; p=p->next){
		
		q=p->next;
		if(p->priority > q->priority)
		{
		tempat=p->arrive;
		p->arrive=q->arrive;
		q->arrive=tempat;
		
		tempbt=p->bustime;
		p->bustime=q->bustime;
		q->bustime=tempbt;
		
		tempid=p->id;
		p->id=q->id;
		q->id=tempid;
		
		temppt=p->priority;
		p->priority=q->priority;
		q->priority=temppt;
		}
	}
}
}
void sortingid(struct node *header){
		struct node *end,*p,*q;
	int tempbt,tempat,tempid,temppt;
	for(end=NULL;end!=header->next;end=p)
	{
		for(p=header;p->next!=end; p=p->next){
		
		q=p->next;
		if(p->id > q->id)
		{
		tempat=p->arrive;
		p->arrive=q->arrive;
		q->arrive=tempat;
		
		tempbt=p->bustime;
		p->bustime=q->bustime;
		q->bustime=tempbt;
		
		tempid=p->id;
		p->id=q->id;
		q->id=tempid;
		
		temppt=p->priority;
		p->priority=q->priority;
		q->priority=temppt;
		}
	}
}
}
void sortinglist(struct node *header){
	struct node *end,*p,*q;
	int tempbt,tempat,tempid,temppt;
	for(end=NULL;end!=header->next;end=p)
	{
		for(p=header;p->next!=end; p=p->next){
		
		q=p->next;
		if(p->arrive > q->arrive)
		{
		tempat=p->arrive;
		p->arrive=q->arrive;
		q->arrive=tempat;
		
		tempbt=p->bustime;
		p->bustime=q->bustime;
		q->bustime=tempbt;
		
		tempid=p->id;
		p->id=q->id;
		q->id=tempid;
		
		temppt=p->priority;
		p->priority=q->priority;
		q->priority=temppt;
		}
	}
}
} 
void exit(struct node *header,int processes,string n)
{
	ofstream file;
	file.open("output.txt");
	file<<" Scheduling method:"<<n<<endl;
   	file<<" Process waiting times:"<<endl;
   		sortingid(header);
   			int totalwt=0;
   			float aw,tt;
		   for(int i=0;i<processes;i++)
		   {	
		   		totalwt+=header->bustime;
		    	file<< "\n P"<<(header->id)<<": "<<header->bustime<<endl;
		    	header=header->next;
			}
		tt=totalwt;
		aw=tt/processes;
	file<<"average waiting time: "<<aw<<endl;
	file.close();
}
void showresult(struct node *header,int processes,string y)
{
		cout<<"\n\n\n Scheduling method:"<<y;
   		cout<<"\n Process waiting times:";
   		sortingid(header);
   			int totalwt=0;
   			float aw,tt;
		   for(int i=0;i<processes;i++)
		   {	
		   		totalwt+=header->bustime;
		    	cout<< "\n P"<<(header->id)<<": "<<header->bustime;
		    	header=header->next;
			}
		tt=totalwt;
		aw=tt/processes;
	cout<<"\n average waiting time: "<<aw;
}
string tostring(int n){

{
    if (n == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (n>0)
    {
        temp+=n%10+48;
        n/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
}
string tostdouble(double f){
	double ff;
	scanf("%f",&f);
	ff = f;
	char str[30];
	int a,b,c,k,l=0,m,i=0,j;
	

	if(f<0.0)
	{
		
		str[i++]='-';
		f*=-1;
	}
	
	a=f;	
	f-=a;
	k = precision;
	
	
	while(k>-1)
	{
		l = pow(10,k);
		m = a/l;
		if(m>0)
		{
			break;
		}
	k--;
	}


	
	for(l=k+1;l>0;l--)
	{
		b = pow(10,l-1);
		c = a/b;
		str[i++]=c+48;
		a%=b;
	}
	str[i++] = '.';
	for(l=0;l<precision;l++)
	{
		f*=10.0;
		b = f;
		str[i++]=b+48;
		f-=b;
	}

	str[i]='\0';
return str;
}

