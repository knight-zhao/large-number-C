#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	 /**
 	 代码思想如下：
 	   使用数据结构：数组（模拟栈）
	   首先通过计算将输入的小数通过转换变成整数，便于存放与模拟栈中计算
	   幂的计算通过直接幂计算实现（因为个数还不到十位数）

    */
void zero(int a[]);  //用来将计算中间过程需要使用的模拟栈初始化为全0
void compute(float num_float ,int mi);//用来计算的函数
void main(){  //进行输入的管理，结束之后连续两个回车即可。
    float num_float[10]={0};
    int mi[10]={0};
    int i=0,j=0;
    char ch;
    while(scanf("%f %d",&num_float[i],&mi[i])){
      ch=getchar();
      ch=getchar();
      if(ch=='\n') break;
      ungetc(ch,stdin);
      i++;
    }
    while(j<=i){
        compute(num_float[j],mi[j]);
        j++;
    }
}
void compute(float num_float ,int mi){
	/**
	首段代码实现的是数据的简单处理
	包括：将输入的小数通过计算改变成整数
          并且将小数点为数统计出来
          并且计算出来小数点后的个数（易知，小数点后位数的幂就是最终结果小数点后的个数）
          将计算的乘数入栈，单次结果栈res_once，最终结果res_final，乘数栈mul
	*/
//	 float num_float=0;
//	 int mi=0;//小数点后的个数
	 int m=0;//标记幂

	 int num_temp=0;
	 int count=0;

	 int mul[5]={0} ;
	 int res_once[125]={0};
	 int res_once_mul[125]={0};
	 int res_final[125]={0};
	 int once=0;
	 int mult=0;
	 int add=0;
	int i=0;
	int k=0;
 	int j=0;
 	int c=0;
	int mul_max_index=4;
	int res_final_max_index=4;
	int res_once_max_index=0;
	int tail=0;
//	 scanf("%f %d",&num_float,&mi);
 	 m=mi;
	 num_temp=(int) num_float;
	 while(num_temp>0){
	 	count++;
	 	num_temp/=10;
	 }
	 mi=m*(5-count);
	 while(count<5){
	 	num_float*=10;
	 	count++;
	 }
	 num_temp=(int) num_float;
	while(i<5){
		res_final[i]=mul[i]=num_temp%10;
		i++;
		num_temp/=10;
	}
	/**
	第二段即计算部分
	*/
	while(m-1>0){
	    i=0;
		while(i<=mul_max_index){
            zero(res_once);
			j=0;
			mult=0;
		    while(j<=res_final_max_index){
		 	    once=res_final[j]*mul[i]+mult;
		 	    add=once%10;
		 	    mult=once/10;
		 	    res_once[i+j]=add;
 	    		j++;
			}
			if(mult!=0){
				res_once_max_index=i+j;
				res_once[res_once_max_index]=mult;
			}
			else    res_once_max_index=i+j-1;

			c=0;
			mult=0;
			while(c<=res_once_max_index){
				add=res_once_mul[c]+res_once[c]+mult;
				res_once_mul[c]=add%10;
				mult=add/10;
				c++;
			}
			if(mult!=0){
				res_once_max_index++;
				res_once_mul[res_once_max_index]=mult;
			}
			i++;
		}
		mult=0;
		c=0;
		while(c<=res_once_max_index){
			res_final[c]=res_once_mul[c];
  			c++;
		}
		res_final_max_index=res_once_max_index;
        zero(res_once_mul);
		m--;
	}
	if(res_final_max_index>mi) c=res_final_max_index;
	else c=mi;
	while((c>=mi) && (res_final[c]==0)) c--;
	while(res_final[tail]==0) tail++;
	if(mi==0){
    	while(c>=0){
		    printf("%d",res_final[c]);
		    c--;
	    }
	    return ;
	}
	while(c>=mi){
		printf("%d",res_final[c]);
		c--;
	}
	printf(".");
	while(c>=tail){
		printf("%d",res_final[c]);
		c--;
	}
	printf("\n");
}
void zero(int a[]){
    int i=0;
    for(;i<125;i++) a[i]=0;
}
