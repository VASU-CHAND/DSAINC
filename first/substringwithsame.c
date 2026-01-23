#include<stdio.h>
int main(){
char arr[7]= {'a' , 'b' , 'c' , 'a' , 'c' , 'd' , 'a' };
int count =0;
for (int i= 0; i<7; i++){
int end =i;
for ( end ; end<7; end++){
    if(arr[i]==arr[end]){
count ++;
}
}
}
count-=7;
printf("%d", count);
return 0;
}