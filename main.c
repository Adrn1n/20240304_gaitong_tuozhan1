#include <stdio.h>
#include <stdlib.h>

#define n 10
#define N 50000
#define disp_width 254
#define len (disp_width - 4)

int toss_coins(int number_coins)
{
    int tosses = 0;
    for (int i = 0; i < number_coins; i++)
        tosses += (rand() % 2);
    return tosses;
}

int main()
{
    FILE *fp = fopen("./result.txt", "w");
    if (fp)
    {
        int head[N] = {0}, cnt[n + 1] = {0};
        for (int *p = head; p - head < N; p++)
            *p = toss_coins(n);
        for (int *p = head; p - head < N; p++)
            cnt[*p]++;
        int head_cnt = 0;
        for (int *p = cnt; head_cnt < n; p++)
        {
            double d = (double)N / len;
            int val = (int)(*p / d);
            head_cnt = (int)(p - cnt);
            if (head_cnt < 10)
                printf(" %d: ", head_cnt), fprintf(fp, " %d: ", head_cnt);
            else
                printf("%d: ", head_cnt), fprintf(fp, "%d: ", head_cnt);
            for (int i = 0; i < val - 1; i++)
                printf(" "), fprintf(fp, " ");
            printf("*\n\n"), fprintf(fp, "*\n\n");
        }
    }
    else
        printf("FILE OPEN ERROR!\n");
    return 0;
}
