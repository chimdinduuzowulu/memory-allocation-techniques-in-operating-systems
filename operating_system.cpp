#include<iostream>
using namespace std;
void first();
void best();
void worst();
void task2();
int main()
{
	char menu;
	cout<<"1. first-fit\n2. Best Fit\n3. Worst Fit\n4.TASK TWO\n";
	cout<<"enter the allocation algorithm you will like to use.\n";
	cin>>menu;
	switch(menu)
	{
		case '1':
			first();
			break;
		case '2':
			best();
			break;
		case '3':
			worst();
			break;
		case '4':
			task2();
			break;
		default:
		cout<<"there is no option with that number...";
	}	
	return 0;
}
//	...............using FIRST-FIT.............
void first()
{
	int cap,num=0,psize[num],hole[num];
	int process[num],noexec[num];
	int frag[num];
	cout<<"what is the memory capacity...";
	cin>>cap;
	cout<<"how many processes are you to run?";
	cin>>num;
//	assigning an equal sizes to the holes by calculation
	int allocationsize=cap/num;
//	allocating the sizes to the holes
	for (int i=1;i<=num;i++)
	{
		hole[i]=allocationsize;
	}
//	asking for the sizes of the processes to run..
	for(int i=1;i<=num;i++)
	{
		cout<<"enter the size of the process... "<<i<<"\n";
		cin>>psize[i];
	}
//	checking if the process can run by comparing the alloacted size on the holes and the psize
	for(int i=1;i<=num;i++)
	{
		if(psize[i]<=hole[i] )
		{
//			check if it works and set the p[i] to 1 as true and calculate the internal fragentation by subtracting the two
			process[i]=1;
			frag[i]=hole[i]-psize[i];
		}
//		if it cant find a sufficient hole then it cant run and set it to zero
		else
		{
			process[i]=0;
		}
	}
//	listing out the ones that got executed.....
	cout<<"the list of all the processes that got executed and their internal fragmentations:\n";
	cout<<"PROCESS		SIZE		INTERNAL FRAGMENTATION\n";
	for(int i=1;i<=num;i++)
	{
		if(process[i]==1)
		{
			cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
			cout<<"|"<<i<<"|"<<"		"<<"|"<<psize[i]<<"|"<<"		"<<"|"<<frag[i]<<"|"<<"\n";
			cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
		}
	}
//	list of all the processes that did not execute...
	cout<<"the list of all the processes that didnt execute..\n";
	cout<<"PROCESS		SIZE\n";
	for(int i=1;i<=num;i++)
		{
			if(process[i]==0)
			{ cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
				cout<<i<<"|"<<"		"<<"|"<<psize[i]<<"|"<<"\n";
				cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
			}
		}
}
//	..........for BEST-FIT ALGORITHM........finds d smallest hole big enough to fit it
void best()
{	int cap,num=0,psize[num],hole[num];
	int process[num],noexec[num],minresult;
	int frag,hold=0,result,flag[num];
	cout<<"what is the memory capacity...";
	cin>>cap;
	cout<<"how many processes are you to run?";
	cin>>num;
//	assigning an varrying sizes to the holes by calculation
	int allocationsize=cap/num;
//	allocating the sizes to the holes
	for (int i=1;i<=num;i++)
	{
//		randomly assigning the others then subtracting the others from the cap as the size of the last frame
		if(i==num)
		{
			hole[i]=cap-hold;
			break;
		}
	hole[i]=allocationsize;
	hold+=allocationsize;
	allocationsize+=5;	
	}
//	asking for the sizes of processes.....
	for(int i=1;i<=num;i++)
	{
		cout<<"enter the size of the process... "<<i<<"\n";
		cin>>psize[i];
//		initializing the process executions to false first...
		process[i]=0;
	}
for(int i=1;i<=num;i++)
{
	int	min=hole[0];
	for(int i=1;i<=4;i++)
	{
		if (hole[i]<min && hole[i]>=psize[i])
		{
			flag[i]=1;
		}
	}
	if(flag[i]=1)
	{continue;
	}
}
//	printing out the executed ones....
cout<<"PROCESS		SIZE		INTERNAL FRAGMENTATION\n";
for (int i=1;i<=num;i++)
{
	if(flag[i]==1)
	{
		int x=i;
		frag=hole[i]-psize[i];
		if(frag<0)
		{cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
		cout<<"|"<<x<<"|"<<" didnt execute with size of "<<"|"<<psize[i]<<"|"<<"	no internal fragmentation "<<"\n";
		cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
		}
		else
		{
			cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
			cout<<"|"<<x<<"|"<<"		"<<"|"<<psize[i]<<"|"<<"		"<<"|"<<frag<<"|"<<"\n";
			cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
		}
	}
}
}
//	the worst fit algorithm...................
void worst()
{
	int cap,num=0,psize[num],hole[num];
	int process[num],noexec[num],minresult;
	int frag[num],hold=0,result,flag[num];
	cout<<"what is the memory capacity...";
	cin>>cap;
	cout<<"how many processes are you to run?";
	cin>>num;
//	assigning an varrying sizes to the holes by calculation
	int allocationsize=cap/num;
//	allocating the sizes to the holes
	for (int i=1;i<=num;i++)
	{
//		randomly assigning the others then subtracting the others from the cap as the size of the last frame
		if(i==num)
		{
			hole[i]=cap-hold;
			break;
		}
	hole[i]=allocationsize;
	hold+=allocationsize;
	allocationsize+=5;	
	}
//	asking for the sizes of processes.....
	for(int i=1;i<=num;i++)
	{
		cout<<"enter the size of the process... "<<i<<"\n";
		cin>>psize[i];
//		initializing the process executions to false first...
		process[i]=0;
	}
for(int i=1;i<=num;i++)
{
	int	max=hole[0];
	for(int j=1;j<=num;j++)
	{
		if (hole[j]>max && hole[j]<=psize[i])
		{
			flag[i]=1;
		}
	}
	if(flag[i]=1){continue;}
}
//	printing out the executed ones....
cout<<"PROCESS		SIZE		INTERNAL FRAGMENTATION\n";
for (int i=1;i<=num;i++)
{
	if(flag[i]==1)
	{
		int x=i;
		cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
		cout<<"|"<<x<<"|"<<"		"<<"|"<<psize[i]<<"|"<<"		"<<"|"<<hole[i]-psize[i]<<"|"<<"\n";
		cout<<"__"<<"__"<<"		"<<"__"<<"__"<<"		"<<"__"<<"__"<<"\n";
	}
}
}
void task2(){
	int memory=0.125;
//	converting from mega byte to kilo byte
	memory=0.125*1024;
	int page_size,nos_frame;
	page_size=nos_frame=4;
	double process_size=100000;
//	converting the process size from byte to kilo byte...
	process_size=100000/1024;
	int nos_pages= process_size/page_size;
	cout<<nos_frame;
	int availablemem[128];
	int free_frame[25];
	int partion =memory/nos_frame;																																																																																																																																																											
// displaying the free frame list before allocation.....
cout<<"\nbefore allocation the free frame lists are....:"<<endl;
for (int i=0;i<25;i++)
{
	free_frame[i] = i*5;
	cout<<"FRAME "<<"|"<<free_frame[i]<<"|"<<endl;
}
//	after alloaction the free frames......
 cout<<"after allocaiton the only free frames......\n";
 for (int j=0;j<25;j+=5)
{
	if(j!=(j+5)){
		cout<<"FRAME "<<"|"<<free_frame[j]<<"|"<<endl;
	}
    free_frame[j]=j+10;	
}
float PTE=(float)(1048576.00/32000.00);
cout<<"the maximium number of the page table entries is..(2^20)/(2^25) in bits...="<<PTE<<" bits"<<endl;
}
	
	
	
	
	
