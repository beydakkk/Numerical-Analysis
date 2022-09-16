#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

	float ustalma(float taban,float ust)
	{
		int i;
		float sonuc=1;
		
		for(i=0;i<ust;i++){
			sonuc = sonuc*taban;
		}
		return sonuc;
	}

int main(){
	
	int i,j,katsayi[MAX],turev_katsayi[MAX],n;
	float a,b,hata,mutlak_hata=1;
	float fa=0,fa_turev=0,x;
	int iterasyon=0;
	
	printf("NEWTON RAPHSON YONTEMI\n\n");
	
	printf("fonksiyonunuz kacinci dereceden?\n");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		if(i==0){
			printf("sabit sayiyi giriniz:\n",i);
			scanf("%d",&katsayi[i]);
		}
		else{
			printf(" x^%d elemaninin katsayisini giriniz:\n",i);
			scanf("%d",&katsayi[i]);
		}
	}
	
	printf("fonksiyonun turevini giriniz\n");
	for(i=0;i<=n-1;i++){
		if(i==0){
			printf("sabit sayiyi giriniz:\n",i);
			scanf("%d",&turev_katsayi[i]);
		}
		else{
			printf(" x^%d elemaninin katsayisini giriniz:\n",i);
			scanf("%d",&turev_katsayi[i]);
		}
	}
	
	printf("incelemek istediginiz araligin baslangicini giriniz:");
	scanf("%f",&a);
	printf("incelemek istediginiz araligin bitisini giriniz:");
	scanf("%f",&b);
	
	printf("islemlerinizde tolere edilebilecek hata degerini giriniz:");
	scanf("%f",&hata);
	
	while(mutlak_hata > hata){
		
		for(i=0;i<=n;i++){
			 fa+= ustalma(a,i)*katsayi[i];
		} 
		for(j=0;j<=n-1;j++){
			fa_turev+= ustalma(a,j)*turev_katsayi[j];
		} 
		x= a - (fa/fa_turev);
		
		mutlak_hata = fabs(x-a);
		
	//	printf("mutlak:%f fa:%f turev:%f x:%f",mutlak_hata,fa,fa_turev,x);
		fa=0;
		fa_turev=0;
		a = x ;
		iterasyon += 1;
		
	}
	
	printf("iterasyon sayisi:%d yaklasik kok:%f",iterasyon,x);
	
	return 0;
}
