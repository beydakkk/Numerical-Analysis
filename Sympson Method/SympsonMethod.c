#include <stdio.h>
#include<stdlib.h>
#define MAX 100

float ustalma(float taban,float ust){
	
	int i;
	float sonuc=1;
	
	for(i=0;i<ust;i++){
		sonuc = sonuc*taban;
	}
	return sonuc;
	}

int main(){
	
	printf("SIMPSON YONTEMI\n\n");
	
	int i,j,n,ara;
	float katsayi[MAX],x1,x2,h;
	float S=0,k_tek=0,k_cift=0,S1=0,S2=0;
	
	
	printf("fonksiyonunuz kacinci dereceden?\n");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		if(i==0){
			printf("sabit sayiyi giriniz:\n",i);
			scanf("%f",&katsayi[i]);
		}
		else{
			printf(" x^%d elemaninin katsayisini giriniz:\n",i);
			scanf("%f",&katsayi[i]);
		}
	}
	
	printf("incelemek istediginiz araligin baslangicini giriniz:");
	scanf("%f",&x1);
	printf("incelemek istediginiz araligin bitisini giriniz:");
	scanf("%f",&x2);
	printf("aralik sayisini giriniz:\n");
	printf("!!aralik sayisi cift olmalidir!!\n");
	scanf("%d",&ara);
	
	if(x2>0 && x1<0){
		h=(0-x1)/ara;
		for(i=0;i<=n;i++){
			S1+= ustalma(0,i)*katsayi[i]+ustalma(x1,i)*-katsayi[i];
		}
		for(i=1;i<ara;i++){
			for(j=0;j<=n;j++){
				if(i%2==0) k_cift+=ustalma(x1+i*h,j)*-katsayi[j];
				else k_tek+=ustalma(x1+i*h,j)*-katsayi[j];
			}
			S1+= k_tek*4 + k_cift*2;
			k_tek=0;
			k_cift=0;
		}
		S1*= h/3;
		
		h=x2/ara;
		for(i=0;i<=n;i++){
			S2+= ustalma(0,i)*katsayi[i]+ustalma(x2,i)*katsayi[i];
		}
		for(i=1;i<ara;i++){
			for(j=0;j<=n;j++){
				if(i%2==0) k_cift+=ustalma(i*h,j)*katsayi[j];
				else k_tek+=ustalma(i*h,j)*katsayi[j];
			}
			S2+=k_tek*4+k_cift*2;
			k_tek=0;
			k_cift=0;
		}
		S2*= h/3;
		S=S1+S2;
	}
	
	else if(x2>=0 && x1>=0) {

		h=(x2-x1)/ara;
		for(i=0;i<=n;i++){
			S+= ustalma(x1,i)*katsayi[i]+ustalma(x2,i)*katsayi[i];
		}
		for(i=1;i<ara;i++){
			for(j=0;j<=n;j++){
				if(i%2==0) k_cift+=ustalma(x1+i*h,j)*katsayi[j];
				else k_tek+=ustalma(x1+i*h,j)*katsayi[j];
			}
			S+=k_tek*4+k_cift*2;
			k_tek=0;
			k_cift=0;
		}
		S*= h/3;
	}
	
	else{
		h=(x2-x1)/ara;
		for(i=0;i<=n;i++){
			S+= ustalma(x1,i)*katsayi[i]+ustalma(x2,i)*katsayi[i];
		}
		for(i=1;i<ara;i++){
			for(j=0;j<=n;j++){
				if(i%2==0) k_cift+=ustalma(x1+i*h,j)*katsayi[j];
				else k_tek+=ustalma(x1+i*h,j)*katsayi[j];
			}
			S+=k_tek*4+k_cift*2;
			k_tek=0;
			k_cift=0;
		}
		S*= h/3;
		
		
	}
	
	printf("%f",S);
	
	return 0;
}
