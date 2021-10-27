#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;


       
  int knapSack(int W, int wt[], int val[], int n) 
{ 
  
    
    if (n == 0 || W == 0) 
        return 0; 
  
   
    if (wt[n-1] > W) 
        return knapSack(W, wt, val, n - 1); 
  
   
    else
        return max(val[n-1] + knapSack(W - wt[n-1],  wt, val, n - 1),
                            knapSack(W, wt, val, n - 1)); 
} 
    

int main() {
	
int val[] = { 10, 40, 30, 50 }; 
int wt[] = { 5, 4, 6, 3 }; 
int W = 10; 
int n = 4;
cout<<knapSack(W, wt, val, n);
	

}