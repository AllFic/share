#include<stdio.h>

void output_shelf(unsigned long long int shelf)
{
    int i;
    unsigned long long int output[8],tmp;
    for(i=7;i>=0;i--)   //��²�檺��X�覡�A�C�����̥k�䨺���A�˱Կ�X
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
        while(shift<8)  //�ˬd�O�_�b�[�W
        {
            tmp=255ull<<(8ull*shift);   //�ɶq�קK���P���A���ȡA�ҥH�����Φ� unsigned long long
            tmp&=shelf; //��� "shift" ���Ѫ��s�����X��
            tmp>>=(8ull*shift);
            if(tmp==num)break;  //����^���ˬd�O�_�۵�
            shift+=1;
        }
        if(shift<8) //�]��break�A�[�W��shift���ѴN�O�n�䪺�s��
        {
            bound=(int)shift;   //�ɶq�קK���Psize������A�ҥHfor�̭���bound
            /*��n�����ѥk�䨺�ǮѰO���_��*/
            tmp=0;
            for(i=0;i<bound;i++)
            {
                tmp<<=8;
                tmp|=255;
            }
            tmp=tmp&shelf;
            /*���������A�}�l����*/
            shelf>>=8ull*(i+1);     //��k�䨺�Ǯ��k�s
            shelf<<=8ull*(i+1);     //�ťX��m
            shelf|=tmp<<8ull;       //��O���_�Ӫ��ѩ�i�h
            shelf|=num;     //��n�ݪ��ѩ�^�̥k��
        }
        else    //�[�W�S���A������̥k��
        {
            shelf<<=8;
            shelf|=num;
        }
        //�p�G�ndebug�A��²��N�O�b�o���C�@�����Ѭ[�L�X��
    }
    output_shelf(shelf);    //��Ѭ[�L�X��
    return 0;
}
