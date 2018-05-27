#define True 1
#define False 0

int cmp(const void *a, const void *b);
void findThreeSum(int* nums, int** answers, int rememberValue, int numsSize, int *returnSize);

int** threeSum(int* nums, int numsSize, int* returnSize) {
    
    int **answers;
    int total;
    
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    findThreeSum(nums, answers, False, numsSize, &total);
    answers = (int**)malloc(total * sizeof(int*));
    findThreeSum(nums, answers, True, numsSize, &total);
    
    /*check result
    for (i=0; i<total; i++) {
        for (j = 0; j < 3; j ++) {
            printf("%d ", answers[i][j]);
        }printf("\n");
    }*/
    
    *returnSize = total;
    return answers;
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void findThreeSum(int* nums, int** answers, int rememberValue, int numsSize, int *returnSize) {
    
    int i, j, k, twoSum, fixedVal, total; 
    
    for (i = 0, total = 0; i < numsSize; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        } 
        
        j = i + 1;
        k = numsSize - 1;
        
        while(j < k) {
            twoSum = nums[j] + nums[k];
            fixedVal = 0 - nums[i];
            if (fixedVal < twoSum) {
                --k;
            } else if (fixedVal == twoSum) {
                if (rememberValue == 1) {
                    answers[total] = (int*)malloc(3 * sizeof(int));
                    answers[total][0] = nums[i];
                    answers[total][1] = nums[j];
                    answers[total][2] = nums[k];
                }
                ++total;
                while (nums[j+1] == nums[j]) {
                    ++j;
                }
                ++j;
            } else if (fixedVal > twoSum) {
                ++j;
            }
        }
    }
    *returnSize = total;
}