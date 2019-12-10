#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int *servis,*gelisz,*bitisz,*process,*ortatam,*ortabek;

void tablo(int,int);
void gotoxy(int,int);
void tablodoldur(int);
int gelissorgu(int);
void ayni(int);
void aynidegil(int);

int main() {
	
	int prossa=0,i;
				
	printf("Kac proses var?\n");
	scanf("%d",&prossa);
	system("cls");
	
	servis = (int *)malloc (prossa * sizeof(int));  
	gelisz = (int *)malloc (prossa * sizeof(int));  
	bitisz = (int *)malloc (prossa * sizeof(int));
	process= (int *)malloc (prossa * sizeof(int));
	ortatam= (int *)malloc (prossa * sizeof(int));
	ortabek= (int *)malloc (prossa * sizeof(int));
	
	for(i=0;i<prossa;i++){
		process[i]=i+1;
	}
	
	tablo(prossa,0);
	tablodoldur(prossa);
		
	if(gelissorgu(prossa)==1){
		ayni(prossa);
		tablo(prossa,1);
	}
	else{
		aynidegil(prossa);
		tablo(prossa,1);
	}
	
	return 0;
}

void tablo(int n,int k){
	if(k==1){
		gotoxy(15*n,0);
	}
	printf("          |  Servis  |  Gelis Zamani  |\n");
	if(k==1){
		gotoxy(15*n,1);
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
	
	int i;
	int indis=2;
	for(i=1;i<=n;i++){		
			
	if(k==1){
	gotoxy(15*n,indis);	
	}	
	printf("    P     |          |                |\n");
	
	gotoxy(5,indis);

	if(k==1){
	gotoxy(15*n+5,indis);	
	}
	printf("%d\n",i);
	if(k==1){
		gotoxy(31+((n-1)*15),indis);
		printf("%d",servis[i-1]);
		gotoxy(44+((n-1)*15),indis);
		printf("%d",gelisz[i-1]);
	}
	indis++;
	
	}
	
	if(k==1){
	gotoxy(15*n,i+1);	
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
}

void tablodoldur(int n){
	
	
	int i,indis=2;
	for(i=0;i<n;i++){
		gotoxy(15,indis);
		scanf("%d",&servis[i]);
		
		gotoxy(29,indis);
		scanf("%d",&gelisz[i]);
		indis++;
	}
}

int gelissorgu(int n){
	
	int i;
	for(i=1;i<n;i++){
		if(gelisz[i-1]!=gelisz[i]){
			return -1;
		}
	}
	return 1;
	
	//1 ise ayný zaman -1 ise farklý zaman
}

void ayni(int n){
	
	system("cls");
	
	int i;
	int indis=0;
	int indis2=7;
	int indis3=13;
	float sonuctamam=0;
	gotoxy(((n*13/2)-5),0);
	printf("Gant Diyagrami\n");
	
	for(i=0;i<n;i++){
		printf("-------------");
	}
	printf("\n");
	for(i=1;i<=n;i++){
	gotoxy(indis,2);
	printf("|     P      |");
	gotoxy(indis2,2);
	printf("%d",i);
	indis2+=13;
	indis+=13;
	}
	printf("\n");
	
	bitisz[0]=0;
	
	for(i=0;i<n;i++){
		printf("-------------");
		
	}
	
	bitisz[0]=servis[0]+gelisz[0];
	for(i=1;i<n;i++){
		bitisz[i]=bitisz[i-1]+servis[i];
	}
	
	gotoxy(0,3);
	printf("%d",gelisz[0]);
	for(i=0;i<n;i++){
	gotoxy(indis3,3);
	printf("%d",bitisz[i]);
	indis3+=13;	
	}
	
	printf("\n\n\n* Ortalama Tamamlanma Suresi\n");
	printf("(");
	for(i=0;i<n;i++){
		sonuctamam+=bitisz[i];
		printf("+%d",bitisz[i]);
	}
	sonuctamam/=n;
	
	printf(")/%d = %0.2f ",n,sonuctamam);
	
	sonuctamam=0;
	printf("\n\n\n* Ortalama Bekleme Suresi\n");
	printf("(0");
	
	
	for(i=0;i<n-1;i++){
		sonuctamam+=bitisz[i];
		printf("+%d",bitisz[i]);
	}	
	sonuctamam/=n;
	printf(")/%d = %0.2f ",n,sonuctamam);
	
	
	
}

void aynidegil(int n){

	system("cls");

	int i,j,gcc;
	int indis=0;
	int indis2=7;
	int indis3=13;
	float sonuctamam=0;	
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(gelisz[i]>gelisz[j]){
			gcc=gelisz[i];
			gelisz[i]=gelisz[j];
			gelisz[j]=gcc;
			
			gcc=servis[i];
			servis[i]=servis[j];
			servis[j]=gcc;
			
			gcc=process[i];
			process[i]=process[j];
			process[j]=gcc;
	
			}
		}
	}
	
	
	///////////////////////////
	
	
	
	
	gotoxy(((n*13/2)-5),0);
	printf("Gant Diyagrami\n");
	
	for(i=0;i<n;i++){
		printf("-------------");
	}
	printf("\n");
	for(i=1;i<=n;i++){
	gotoxy(indis,2);
	printf("|     P      |");
	gotoxy(indis2,2);
	printf("%d",process[i-1]);
	indis2+=13;
	indis+=13;
	}
	printf("\n");
	
	bitisz[0]=0;
	
	for(i=0;i<n;i++){
		printf("-------------");
		
	}
	
	bitisz[0]=servis[0]+gelisz[0];
	for(i=1;i<n;i++){
		bitisz[i]=bitisz[i-1]+servis[i];
	}
	
	gotoxy(0,3);
	printf("%d",gelisz[0]);
	for(i=0;i<n;i++){
	gotoxy(indis3,3);
	printf("%d",bitisz[i]);
	indis3+=13;	
	}
	
	for(i=0;i<n;i++){
		ortatam[i]=bitisz[i]-gelisz[i];
		ortabek[i]=ortatam[i]-servis[i];
	}
	
	printf("\n\n\n* Ortalama Tamamlanma Suresi\n");
	printf("(");
	for(i=0;i<n;i++){
		sonuctamam+=ortatam[i];
		printf("+%d",ortatam[i]);
	}
	sonuctamam/=n;
	printf(")/%d = %0.2f ",n,sonuctamam);
	
	sonuctamam=0;
	
	printf("\n\n\n* Ortalama Bekleme Suresi\n");
	printf("(0");
	
	
	for(i=0;i<n;i++){
		sonuctamam+=ortabek[i];
		printf("+%d",ortabek[i]);
	}	
	sonuctamam/=n;
	printf(")/%d = %0.2f ",n,sonuctamam);
	

}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
