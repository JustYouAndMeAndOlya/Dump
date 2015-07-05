#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
float MAS[100][100];
float SUM[100];
float HAR[100];
int read()
{	
	int z=0;
	ifstream fff("read.txt");
	fff>>z;
	if (z<=0)
	{
		cout<<"Net razmera";
	}
	else
	{
		for (int i =0;i<z;i++)
			for(int u =0;u<z;u++)
			fff>>MAS[i][u];
	}
	return z;
}

void write(int razmer)
{
	ofstream fff("write.txt");
	for (int i =0;i<razmer;i++)
	{
			if(i!=0)
				fff<<endl;
			for(int x =0;x<razmer;x++)
			{
			fff<<MAS[i][x]<<" ";
		
			}
	}
}
float NORMA(int razmer)
{	float RESULT=0;
	for (int i =0;i<5;i++)
	{
			for(int u =0;u<5;u++)
			{
				SUM[i]=SUM[i]+MAS[i][u];
			}
			RESULT=SUM[0];
			for (int p=1;p<5;p++)
				if (RESULT<SUM[p])
					RESULT=SUM[p];

	}
	cout<<endl<<"CYMMbI STOJI6U,OB "<<endl;
for (int i=0;i<5;i++)
	cout<<SUM[i]<<" ";
	return RESULT;
}
void DEFINITION(int razmer)
{
	for (int i=0;i<razmer;i++)
	{
		HAR[i]=0;
		for(int u =0;u<razmer;u++)
				if(u%2!=0&&MAS[u][i]<0)
				{
					HAR[i]=HAR[i]+MAS[u][i];
				}
	}
	for (int i=0;i<razmer;i++)
		cout<<HAR[i]<<" ";
	cout<<endl;
	for (int i=0;i<razmer-1;i++)
	{
		if (HAR[i]<HAR[i+1])
		{
			swap(HAR[i],HAR[i+1]);
				for(int u =0;u<razmer;u++)
				{
					cout<<MAS[u][i]<<" <-> "<<MAS[u][i+1]<<endl;
					swap(MAS[u][i],MAS[u][i+1]);
				}
		}
	
	}
	for (int q=0;q<razmer;q++)
	{
		cout<<endl;
				for(int u =0;u<razmer;u++)
					cout<<MAS[q][u]<<" ";
	}


}
void main()
{
	float SHOW;
	int razmer;
	razmer=read();
	for (int i =0;i<razmer;i++)
	{
		cout<<endl;
			for(int u =0;u<razmer;u++)
			cout<<MAS[i][u]<<" ";
	}
	cout<<endl<<endl;
	//SHOW=NORMA(razmer);
//	cout<<endl<<"HOPMA_MATPUU,bI = "<<SHOW<<endl;
	//write(5);
	DEFINITION(razmer);
	system ("pause");
}