#include<iostream>
#include<string.h>
using namespace std;
void x_at_end(char *str,int i,int n)
{
    //BASE CASE
    if(str[i]==NULL)
    {
        cout<<str;
        return;
    }
    //RECURSIVE CASE
    if(str[i]=='x')
    {
        for(int j=i;str[j]!=NULL;j++)
        {
            str[j]=str[j+1];
        }
        str[n-1]='x';
    }
    x_at_end(str,i+1,n);
}
int main()
{
    char str[100];
    cin.getline(str,100);
    int n=strlen(str);
    x_at_end(str,0,n);
    return 0;
}
