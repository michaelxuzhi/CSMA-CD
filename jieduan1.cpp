#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
#define CONTENTION_PERIOD 51.20
int GetRand(int min,int max)
{
	SYSTEMTIME t;
	GetSystemTime(&t);
	srand(t.wMilliseconds);
	int r=rand()%(max-min+1)+min;
	return r;
}

int TwoPowerK(int k)
{
	int a=2;
	int f=1;
	while(k--)
	{
		f*=a;	
	}
	return f;
} 

int Resend(int i)
{
	int r,MAX;
	double BackTime;
	cout<<"开始退避操作!"<<endl;
	if(i<=10)
	MAX=TwoPowerK(i)-1;
	if(i>10)
	{
		cout<<"重传次数超过10,从10截止。"<<endl;
		MAX=TwoPowerK(10)-1;
	}
	cout<<"随机数范围："<<"0到"<<MAX<<endl;
	r=GetRand(0,MAX);
	cout<<"得到的随机数r为："<<r<<endl;
	BackTime=r*CONTENTION_PERIOD;
	cout<<"退避时间为："<<"51.2*"<<r<<"="<<BackTime<<"微秒"<<endl;
	Sleep(200);
	cout<<"退避完成，开始重传!"<<endl;
	cout<<endl;
	return 0;
}
void main()
{
	cout<<"***截断二进制退避指数算法演示***"<<endl;
	int k=0;
	int p;
	cout<<"每次传送发生碰撞的概率为p%，请输入p的值（范围为0到100之间的整数）：";
	cin>>p;
	cout<<endl;
	while(1)
	{
		if(GetRand(1,100)<=p)
		{
			k++;
			if(k<=16)
			{
				cout<<"***发生碰撞！"<<"准备进行第"<<k<<"次重传！***"<<endl;
				Resend(k);
				continue;
			}
			if(k>16)
			{
				cout<<"重传16次仍未成功，丢弃本帧，向高层报告！"<<endl;
				break;
			}
		}
		if(GetRand(1,100)>p)
		{
			cout<<"本次未发生碰撞，传送成功！！共重传"<<k<<"次。"<<endl;
			break;
		}
	}
}
