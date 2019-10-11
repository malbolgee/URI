/*
    @autor: Malbolge;
    @data: 08/10/2019;
    @nome: Nem Tudo é Greve Versão Hard;
*/

#include <stdio.h>

#define MOD 1000000007

int countWays(int);
  
int main() 
{

    int n;
    scanf("%d", &n);
    printf("%d\n", countWays(n)); 
    return 0;

} 

int countWays(int n) 
{ 

    int i;
    int ans[n + 1]; 
    ans[0] = 1; ans[1] = 1; ans[2] = 2;
    for (i = 3; i <= n; i++)  
        ans[i] = (((ans[i - 1] + ans[i - 2]) % MOD + ans[i - 3]) % MOD) % MOD;
      
    return ans[n];

} 