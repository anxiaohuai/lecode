#include <stdio.h>
#include <stdlib.h>
#define N 1024
char* f(char s[][N],int len){
    char* res = (char*) malloc(sizeof(char)*(len+1));
    for(int i = 0;i<len;++i){
        res[i] = s[i][0];
    }
    res[len] = '\0';
    return res;
}
int main(){
    char s[][N] = {"mango","apple","orange","banana","pineapple"};
    printf("%s\n",f(s,sizeof(s)/sizeof(s[0])));
    return 0;
}