#include<stdio.h>
int main(){
	int n = 0,number,max = 0,j,i,valu,posi,choice,array[100];
	int flag = 0,temp;
	do{
		printf("+--------------------------------------------------------MENU---------------------------------------------------------+\n");
		printf("|1.  Nhap so luong phan tu va gia tri tung phan tu trong mang                                                         |\n");
		printf("|2.  In ra cac gia tri phan tu trong mang                                                                             |\n");
		printf("|3.  In cac so la so hoan hao trong mang                                                                              |\n");
		printf("|4.  Tim gia tri lon nhat trong mang                                                                                  |\n");
		printf("|5.  Them moi mot phan tu vao dau mang                                                                                |\n");
		printf("|6.  Xoa phan tu tai mot vi tri cu the                                                                                |\n");
		printf("|7.  Sap xep mang theo thu tu giam dan                                                                                |\n");
		printf("|8.  Tim kiem va hien thi vi tri cua mot phan tu                                                                      |\n");
		printf("|9.  In sao cho toan bo so chan dung truoc, so le dung sau nhung khong lam thay doi thu tu cac so chan le ban dau     |\n");
		printf("|10. sap xep mang theo thu tu nguoc lai                                                                               |\n");
		printf("+---------------------------------------------------------------------------------------------------------------------+\n");
		printf("moi ban nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				while(1){
					printf("moi ban nhap so luong phan tu cua mang: ");
					scanf("%d",&n);
				if(n <= 0 || n > 100){
					printf("loi moi ban nhap lai!!!");
					}
				break;
				}
				for(int i = 0; i < n; i++){
					printf("moi ban nhap gia tri cua tung phan tu array[%d] = ",i);
					scanf("%d",&array[i]);
				}
				printf("\n");
				break;
		case 2:
			if(n == 0){
				printf("moi ban nhap luong phan tu va gia tri tung phan tu trong mang truoc!!!");
				break;
			}
			for(int i = 0; i < n; i++){
				printf("array[%d] = %d\n",i,array[i]);
			}
			printf("\n");
			break;
		case 4:
			if(n == 0){
				printf("moi ban nhap luong phan tu va gia tri tung phan tu trong mang truoc!!!");
				break;
			}
			max = array[0];
			for(int i = 0; i < n; i++){
				if(array[i] > max){
					max = array[i];
				}
			}
			printf("so lon nhat trong mang la: %d",max);
			printf("\n");
			break;
		case 5:
			if(n == 0){
				printf("moi ban nhap luong phan tu va gia tri tung phan tu trong mang truoc!!!");
				break;
			}
			printf("moi ban nhap gia tri muon them vao dau: ");
			scanf("%d",&valu);
			n++;
			for(int i = n - 1; i > 0; i--){
				array[i] = array[i-1];
			}
			array[0] = valu;
			printf("\n");
			break;
		case 6:
			if(n == 0){
				printf("moi ban nhap luong phan tu va gia tri tung phan tu trong mang truoc!!!");
				break;
			}
			printf("moi ban chon vi tri muon xoa: ");
			scanf("%d",&posi);
			for(int i = posi; i < n; i++){
				array[i] = array[i+1];
			}
			n--;
			printf("\n");
			break;
		case 8:
			if(n == 0){
				printf("moi ban nhap luong phan tu va gia tri tung phan tu trong mang truoc!!!");
				break;
			}
			printf("nhap so ma ban muon tim: ");
			scanf("%d",&number);
			for(int i = 0; i < n; i++){
				if(array[i] == number){
					flag = 1;
					printf("so %d tai array[%d] \n",number,i);
				}
			}
			if(flag == 0){
				printf("khong tim thay so!!!");
			}
			printf("\n");
			break;
		default:
			printf("loi moi ban nhap lai!!!\n");
			break;
		}
	}while(1);
	return 0;
}
