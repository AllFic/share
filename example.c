#include<stdio.h>

void output_shelf(unsigned long long int shelf)
{
    int i;
    unsigned long long int output[8],tmp;
    for(i=7;i>=0;i--)   //最簡單的輸出方式，每次拿最右邊那本，倒敘輸出
    {
        tmp=255;
        tmp&=shelf;
        output[i]=tmp;
        shelf>>=8;
    }
    for(i=0;i<7;i++)printf("%llu ",output[i]);
    printf("%llu\n",output[i]);
}

int main()
{
    int i,bound;
    unsigned long long int shelf=0,num,tmp,check,shift;
    while(scanf("%lld",&num)!=EOF)
    {
        shift=0;
        while(shift<8)  //檢查是否在架上
        {
            tmp=255ull<<(8ull*shift);   //盡量避免不同型態的值，所以全部用成 unsigned long long
            tmp&=shelf; //把第 "shift" 本書的編號拿出來
            tmp>>=(8ull*shift);
            if(tmp==num)break;  //移位回來檢查是否相等
            shift+=1;
        }
        if(shift<8) //因為break，架上第shift本書就是要找的編號
        {
            bound=(int)shift;   //盡量避免不同size的比較，所以for裡面用bound
            /*把要拿的書右邊那些書記錄起來*/
            tmp=0;
            for(i=0;i<bound;i++)
            {
                tmp<<=8;
                tmp|=255;
            }
            tmp=tmp&shelf;
            /*紀錄完畢，開始移動*/
            shelf>>=8ull*(i+1);     //把右邊那些書歸零
            shelf<<=8ull*(i+1);     //空出位置
            shelf|=tmp<<8ull;       //把記錄起來的書放進去
            shelf|=num;     //把要看的書放回最右邊
        }
        else    //架上沒有，直接塞最右邊
        {
            shelf<<=8;
            shelf|=num;
        }
        //如果要debug，最簡單就是在這邊把每一輪的書架印出來
    }
    output_shelf(shelf);    //把書架印出來
    return 0;
}
