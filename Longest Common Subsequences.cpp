#include<iostream>
#include<string.h>
using namespace std;
int LCS(char *a,char *b,int i,int j)
{
    //BASE CASE
    if(a[i]=='\0' || b[j]=='\0')
        return 0;
    //RECURSIVE CASE
    int len=0;
    if(a[i]==b[j])
    {
        len++;
        len=len+LCS(a,b,i+1,j+1);
        return len;
    }
    else
    {
        int op1=LCS(a,b,i+1,j);
        int op2=LCS(a,b,i,j+1);
        return max(op1,op2);
    }
}
int TopDown(char *a,char *b,int i,int j,int dp[][100])
{
    //BASE CASE
    if(a[i]=='\0' || b[j]=='\0')
    {
        dp[i][j]=0;
        return 0;
    }
    //RECURSIVE CASE
    int len=0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(a[i]==b[j])
    {
        len++;
        len=len+TopDown(a,b,i+1,j+1,dp);
        dp[i][j]=len;
        return len;
    }
    else
    {
        int op1=TopDown(a,b,i+1,j,dp);
        int op2=TopDown(a,b,i,j+1,dp);
        int ans=max(op1,op2);
        dp[i][j]=ans;
        return ans;
    }
}
int BottomUp(char *a,char *b)
{
    //INITALISATION
    int dp[100][100]={0};
    for(int i=1;i<=strlen(a);i++)
    {
        for(int j=1;j<=strlen(b);j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<=strlen(a);i++)
    {
        for(int j=0;j<=strlen(b);j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int n=dp[strlen(a)][strlen(b)];
    char ans[10];
    int i=strlen(a);
    int j=strlen(b);
    int k=dp[i][j]-1;
    ans[k+1]=NULL;
    while(true)
    {
        if(k<0)
            break;
        if(a[i-1]==b[j-1])
        {
            ans[k]=a[i-1];
            i--;
            j--;
            k--;
            continue;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
                continue;
            }
            else
            {
                j--;
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return dp[strlen(a)][strlen(b)];
}
int main()
{
    char a[]="coddingblockss";
	char b[]="codppqwertblocks";
	int dp[100][100];
	for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
	cout<<BottomUp(a,b)<<endl;
	cout<<TopDown(a,b,0,0,dp)<<endl;
	cout<<LCS(a,b,0,0)<<endl;
	return 0;
}
