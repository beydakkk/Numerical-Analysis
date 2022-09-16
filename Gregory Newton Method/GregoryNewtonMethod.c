#include <stdio.h>
#include<stdlib.h>
#define MAX 100

float fact(float n){
	if(n==1) return 1;
	else return n*fact(n-1);
}
	
float ustalma(float taban,float ust)
{
	int i;
	float sonuc=1;
		
	for(i=0;i<ust;i++){
		sonuc = sonuc*taban;
	}
	return sonuc;	}

int main(){
	
	int i,j,n;
	float h,nokta[MAX];
	float deger[MAX],fark[MAX];
	float x,fx,tmp=1;
	
	printf("Nokta sayisini giriniz : \n");
	scanf("%d",&n);
	printf("\n");
	
	printf("noktalar arasindaki farki giriniz:");
	scanf("%f",&h);
	
	printf("X0 noktasini giriniz:");
	scanf("%f",&nokta[0]);
	
	for(i=1;i<n;i++){
		nokta[i]=nokta[0]+h*i;
	}
	
	printf("noktalar icin verilen degerleri giriniz\n\n");
	
	for(i=0;i<n;i++){
		printf("x%d = %f icin deger --> ",i,nokta[i]);
		scanf("%f",&deger[i]);
		printf("\n");
	}
	
	printf("Hesaplatmak istediginiz noktayi giriniz : ");
	scanf("%f",&x);
	
	for(i=0;i<n-1;i++){
		fark[i]=deger[i+1]-deger[i];
	}
	i=0;
	fx=deger[0];
	
	while(fark[0]!=0){
		for(j=0;j<=i;j++){
			tmp*=(x-nokta[j]);
		}
		
		tmp*=fark[0];
		
		tmp/=fact(i+1);
		
		if(h!=1) tmp/=ustalma(h,i+1);
		
		fx+=tmp;
		
		for(j=0;j<(n-i-2);j++){
			fark[j]=fark[j+1]-fark[j];
		}
		tmp=1;
		i++;
	}
	printf("%f icin Gregory Newton enterpolasyonuyla hesaplanan deger ----> %f",x,fx);
	
	return 0;
}
