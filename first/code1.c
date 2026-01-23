#include<stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int revrse(int array[], int n , int k){

for( int i=0; i<n; i+=3){
    int st=i;
    int end =k +i -1;
    if (end > n)
    {
        break;
    }
    else{
            swap(&array[st], &array[end]);
            st++;
            end--;
            if(st>end){
                break; 
}
   }
}
}
int main()
{   int k; 
    printf("enter the value of k (grouping length): \n");
    scanf("%d", &k);
    int n=9;
    int array []= {1,2,3,4,5,6,7,8,9};
    revrse(array, n, k);
      for(int i=0; i<n; i++){
    printf("%d ", array[i]);
   }
    return 0;
}