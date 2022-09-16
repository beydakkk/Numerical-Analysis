#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
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
	
	int n,i,katsayi[MAX],iterasyon=0;
	float x1,x2,hata,c,fark,mutlak_hata=1;
	float sonuc1=0,sonuc2=0,fc=0;
	// x1 araligin baslangic, x2 bitis degeri
	
	printf("BISECTION YONTEMI\n\n");
	
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
	
	printf("incelemek istediginiz araligin baslangicini giriniz:");
	scanf("%f",&x1);
	printf("incelemek istediginiz araligin bitisini giriniz:");
	scanf("%f",&x2);
	
	printf("islemlerinizde tolere edilebilecek hata degerini giriniz:");
	scanf("%f",&hata);
	
	
	
	while(mutlak_hata > hata){
		for(i=0;i<=n;i++){
		 sonuc1+= ustalma(x1,i)*katsayi[i];
		}
		for(i=0;i<=n;i++){
			 sonuc2+= ustalma(x2,i)*katsayi[i];
		}
		c=(x1+x2)/2;
		
		for(i=0;i<=n;i++){
			fc += ustalma(c,i)*katsayi[i];
		}
	iterasyon += 1;
		if(sonuc1*fc>0){
			x1=c;
		}	
		else {
			x2=c;
		}
			
	//	printf("sonuc1:%f sonuc2:%f fc:%f x1:%f x2:%f c:%f\n",sonuc1,sonuc2,fc,x1,x2,c);
	
	sonuc1=0;
	sonuc2=0;
	fc=0;
	
		if(x2-x1 <0){
			mutlak_hata= x1-x2 ;
		}
		else mutlak_hata= x2-x1 ;
	}
	
	printf("iterasyon sayisi:%d yaklasik kok:%f ",iterasyon,c);
	

	
	return 0;
}
