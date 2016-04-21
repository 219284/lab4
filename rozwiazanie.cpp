#include <stdio.h>

#include <stdio.h> 
#include <iostream> 
#include <string.h>
#include <cstdlib>

bool selection(int n,int k);
void numbertoword(int i);
using namespace std; 

int main(int argc, char *argv[])
{
int n = atoi(argv[1]);
	while(n<0||n>999999)
	{
		cout << "Liczba ma być w zakresie od 0 do 999999. Wprowadź ponownie liczbę.";
		cin>>n;
	}

cout << "Twoja liczba: " << n << " ";
numbertoword(n);
cout << endl;

for (int i=1, iloczyn=n;iloczyn<1000000;i++,iloczyn=n*i)
{
	if (n==0) cout << "Dowolna liczba spełnia warunek";
	if (n==0)	break;
	selection(iloczyn,i);
}
}

bool selection(int n, int k)
{
	int d=1;
	for (int i=0;i<6;i++)
	{
		if (((n/d)%10)!=0&&((n/d)%10)!=1)
		{
			return false;
		}
		d=d*10;
	}
			cout << "Znaleziono liczbę: " << n << " ";
			numbertoword(n);
			cout << endl << "Szukane k: " << k << " ";
			numbertoword(k);
			cout << endl << endl;
			return true;	
}

void numbertoword(int n)
{
int temp=n;
int d=1;

string Jednosci[]=	{"","jeden ", "dwa ", "trzy ","cztery ", "pieć ", "sześć ", "siedem ", "osiem ", "dziewieć "};
string Dziesiatki[]=	{"","dziesieć ", "dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ", "dziewiećdziesiąt "};
string Setki[]=	{"","sto ", "dwieście ", "trzysta ", "czterysta ", "pięćset ", "sześćset ", "siedemset ", "osiemset ", "dziewiećset "};
string Nascie[]=	{ "dziesieć ", "jedenaście ", "dwanaście ", "trzynaście ", "czternaście ", "piętnaście ", "szesnaście ", "siedemnaście ", "osiemnaście ", "dziewiętnaście "};
string Tysiace[] = {"","tysiąc ","tysiące ","tysięcy "};

if (n==0) cout << "zero";
else
{
int cyfry[6];
for (int i=0;i<6;i++)
{
	cyfry[i]=0;
}

for(int i=5; i>-1;i--)
{
	cyfry[i]=(n/d)%10;
	d=d*10;
}
for (int i= 0; i<2;i++)
{
	if (cyfry[0+3*i]!=0)cout << Setki[cyfry[0+3*i]];	
	if (cyfry[0+3*i+1]==1) cout << Nascie[cyfry[0+3*i+2]];
	if (i==1&&cyfry[0+3*i+1]!=1) cout << Dziesiatki[cyfry[0+3*i+1]] << Jednosci[cyfry[0+3*i+2]];
	if (i==0&&(cyfry[i]==0&&cyfry[0+i+1]==0&&cyfry[0+i+2]==1)) cout << Tysiace[i+1];
	if (i==0&&cyfry[i]==0&&cyfry[0+i+1]==0&&cyfry[0+i+2]>1&&cyfry[0+3*i+2]>4) cout << Tysiace[i+2];
	if (i==0&&(cyfry[i]>0||cyfry[0+i+1]>0)) cout << Tysiace[i+3];
	if (i==0&&cyfry[i]==0&&cyfry[0+i+1]==0&&cyfry[i+2]==0)  cout << Tysiace[i];
}
}
}
