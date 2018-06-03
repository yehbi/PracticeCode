#include <stdlib.h>
#include <string.h>
int cmp(const void *p,const void *q)
{
    int a=*((int*)p),b=*((int*)q);
    if(a!=b) return a>b?1:-1;
    return 0;

}
int** threeSum(int* nums, int numsSize, int* returnSize);
int main()
{
    int arr[6]={-1, 0, 1, 2, -1, -4};
    int i,j,fix;
    int tmp;


    for(i=0;i<6;i++)
    printf("%d",arr[i]);

    int returnSize=0;
    int** sol=threeSum(arr, 6, &returnSize);
    printf("\nreturnSize=%d\n",returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d %d %d\n",sol[i][0],sol[i][1],sol[i][2]);
    }
    return 0;
}
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int i=0,j=0,fix;
    int target;
    *returnSize=0;
int **sol;
//malloc很佔時間，所以整個algo要做兩次,第一次算出malloc的size
    /*int **sol=(int**)malloc(100000*sizeof(int*));
    for(i=0;i<100000;i++)
        sol[i]=(int*)malloc(3*sizeof(int));*/


    qsort(nums,numsSize,sizeof(int),cmp);
//        for(i=0;i<numsSize;i++)
 //   printf("%d",nums[i]);

    for(fix=0;fix<numsSize;fix++)
    {
        if(nums[fix]>0) break;//避免 TLE
        if(fix>0 && nums[fix]==nums[fix-1])//避免TLE
            continue;
        target= 0-nums[fix];
        i=fix+1;
        j=numsSize-1;

        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {


                *returnSize=*returnSize+1;
                while(i<j&&nums[i]==nums[i+1])
                    i++;
                while(i<j&&nums[j]==nums[j-1])
                    j--;
                i++;j--;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;

        }
    }
    sol=(int**)malloc(*returnSize*sizeof(int*));
    for(i=0;i<*returnSize;i++)
        sol[i]=(int*)malloc(3*sizeof(int));
    *returnSize=0;
    for(fix=0;fix<numsSize;fix++)
    {
        if(nums[fix]>0) break;
        if(fix>0 && nums[fix]==nums[fix-1])
            continue;
        target= 0-nums[fix];
        i=fix+1;
        j=numsSize-1;

        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {

                sol[*returnSize][0]=nums[fix];
                sol[*returnSize][1]=nums[i];
                sol[*returnSize][2]=nums[j];
                *returnSize=*returnSize+1;
                while(i<j&&nums[i]==nums[i+1])
                    i++;
                while(i<j&&nums[j]==nums[j-1])
                    j--;
                i++;j--;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;

        }
    }
    //printf("returnSize=%d\n",returnSize);
    return sol;
}
