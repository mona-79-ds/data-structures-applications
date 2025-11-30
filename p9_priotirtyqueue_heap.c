#include <stdio.h>
#include <stdlib.h>
void heapify(int a[], int n)
{
    int i, k, v,flag=0, j;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = a[k];
        while (!flag && 2*k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if(a[j]<a[j+1])
                    j = j + 1;
            }
            if (v >= a[j])
                flag=1;
            else
            {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
        flag=0;
    }
}

int main()
{
    int n,a[10],i,ch;
    for(;;)
    {
        printf("\n 1. Create heap");
        printf("\n2. Extract max");
        printf("\n3. exit");
        printf("\n Read choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n Read no. of elements:\n");
                    scanf("%d",&n);
                    printf("\n Read elements:\n");
                    for(i=1;i<=n;i++)
                        scanf("%d",&a[i]);
                    heapify(a,n);
                    printf("\n Elements after constructing heap-\n");
                    for(i=1;i<=n;i++)
                        printf("%d\t",a[i]);
                    break;
            case 2: if(n>=1)
                    {
                        printf("\n Key deleted is %d",a[1]);
                        a[1]=a[n];
                        n=n-1;
                        heapify(a,n);
                        printf("\n Heap after deleting- \n");
                        for(i=1;i<=n;i++)
                            printf("%d\t",a[i]);
                    }
                    else
                        printf("\n No element to delete");
                    break;
            default: exit(0);
        }
    }
    return 0;
}
