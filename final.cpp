#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define min(x,y) (x>y?y:x)
using namespace std;
int minCount(char *S,char *T)
{
    int sl=strlen(S);
    int tl=strlen(T);
    int d[sl+1][tl+1]={0};
    for(int i=1;i<=sl;i++){
        d[i][0] = i;
    }
    for(int j=1;j<=tl;j++){
        d[0][j]=j;
    }
    for(int i=1;i<=sl;i++)
    {
        for(int j=1;j<=tl;j++)
        {
            if(S[i-1]==T[j-1])
            {
                d[i][j]=d[i-1][j-1];
            }
			else
            {
                d[i][j]=min(min(d[i-1][j]+1,d[i][j-1]+1),d[i-1][j-1]+1);
            }
        }
    }
    return d[sl][tl];
}
int main()
{
	
	int n;
	printf("请输入测试个数："); 
	scanf("%d",&n); 
    char S[2001], T[2001];
    while(n--){
    printf("请输入源字符串："); 
    scanf("%s",S);
    printf("请输入目标字符串："); 
    scanf("%s",T);
    printf("最小操作数为：%d\n",minCount(S,T));
    }
    return 0;
}




