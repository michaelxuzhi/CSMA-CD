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
	cout<<"��ʼ�˱ܲ���!"<<endl;
	if(i<=10)
	MAX=TwoPowerK(i)-1;
	if(i>10)
	{
		cout<<"�ش���������10,��10��ֹ��"<<endl;
		MAX=TwoPowerK(10)-1;
	}
	cout<<"�������Χ��"<<"0��"<<MAX<<endl;
	r=GetRand(0,MAX);
	cout<<"�õ��������rΪ��"<<r<<endl;
	BackTime=r*CONTENTION_PERIOD;
	cout<<"�˱�ʱ��Ϊ��"<<"51.2*"<<r<<"="<<BackTime<<"΢��"<<endl;
	Sleep(200);
	cout<<"�˱���ɣ���ʼ�ش�!"<<endl;
	cout<<endl;
	return 0;
}
void main()
{
	cout<<"***�ض϶������˱�ָ���㷨��ʾ***"<<endl;
	int k=0;
	int p;
	cout<<"ÿ�δ��ͷ�����ײ�ĸ���Ϊp%��������p��ֵ����ΧΪ0��100֮�����������";
	cin>>p;
	cout<<endl;
	while(1)
	{
		if(GetRand(1,100)<=p)
		{
			k++;
			if(k<=16)
			{
				cout<<"***������ײ��"<<"׼�����е�"<<k<<"���ش���***"<<endl;
				Resend(k);
				continue;
			}
			if(k>16)
			{
				cout<<"�ش�16����δ�ɹ���������֡����߲㱨�棡"<<endl;
				break;
			}
		}
		if(GetRand(1,100)>p)
		{
			cout<<"����δ������ײ�����ͳɹ��������ش�"<<k<<"�Ρ�"<<endl;
			break;
		}
	}
}
