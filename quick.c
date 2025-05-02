#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

//swapping the numbers
void swap(int *x,int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void generate_random(int a[],int n)
{
    int i;
    srand(time(0));
    for(i = 0;i < n;i++)
    a[i] = rand() % 1000;
}

int partition(int a[100],int l;int h)
{
    int i = l,j = h + 1,p = 1;
    do{
        do{
            i = i + 1;
        }while(a[i]<a[p]);
        do{
            j = j - 1;
        }while(a[j]>a[p]);
        swap(&a[i],&a[j]);
    }while(i <=  j);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

int quicksort(int a[10],int m,int n)
{
    int s;
    if(m<n+1)
    {
        s = partition(a,m,n);
        quicksort(a,m,s-1);
        quicksort(a,s+1,n);
        return a;
    }
}

int main()
{
    int a[10000],i,ch,n;
    struct timeval t;
    double start,end;
    FILE *fp;
    while (1)
    {
        printf("\nEnter the type of operation as follows:\n");
        printf("1.Randomly generate numbers and quicksort\n");
        printf("2.Enter the number of values to be generated and sorted");
        switch(ch)
        {
            case 1:
            fp = fopen("quicksort.txt","w");
            for(i = 10000;i < 100000;i = i + 5000)
            {
                generate_random(a,i);
                gettimeofday(&t,NULL);
                start = t.tv_sec+(t.tv_usec/1000000.0);
                quicksort(a,0,i - 1);
                gettimeofday(&t,NULL);
                end = t.tv_sec+(t.tv_usec/1000000.0);
                int tt = end-start;
                printf("%d\t%lf\n",i,tt);
                fprintf(fp,"%d\t%lf\n",i,tt);
            }
            fclose(fp);
            break;

            case 2:
            printf("\nEnter the number of values to be generated\n");
            scanf("%d",&i);
            generate_random(a,i);
            gettimeofday(&t,NULL);
            start = t.tv_sec+(t.tv_usec/1000000.0);
            quicksort(a,0,i-1);
            gettimeofday(&t,NULL);
            end = t.tv_sec+(t.tv_usec/1000000.0);
            int tt = end - start;
            printf("Number of array elements: %d \t Time taken = %f\n",i,tt);
            printf("The sortred array is\n");
            for(n = 0;n < i;n++)
            printf("%d\t",a[n]);
            printf("\n");
            break;

            default:printf(""Invalid choice");
                exit(0);
        }
    }
        return 0;

}

