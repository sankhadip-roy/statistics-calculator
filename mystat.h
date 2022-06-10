float mean(int m, float x[10])
{
    int i;
    float sum = 0, average;
    for (i = 0; i < m; i++)
        sum = sum + x[i];
    average = sum / (float)m;
    return average;
}

int mode(int r, float x[10])
{
    int i, j, b[10] = {0}, sum = 0, t, k = 0, c = 1, max = 0, mode1;
    for (i = 0; i < r - 1; i++)
    {
        mode1 = 0;
        for (j = i + 1; j < r; j++)
        {
            if (x[i] == x[j])
                mode1++;
        }
        if ((mode1 > max) && (mode1 != 0))
        {
            k = 0;
            max = mode1;
            b[k] = x[i];
            k++;
        }
        else if (mode1 == max)
        {
            b[k] = x[i];
            k++;
        }
    }
    for (i = 0; i < r; i++)
    {
        if (x[i] == b[i])
            c++;
    }
    if (c == r){
        printf("\nThere is no mode");
        return 0;
    }
    else
    {
        printf("\nMode\t= ");
        for (i = 0; i < k; i++)
            printf("%d ", b[i]);
    }
    printf("\n");
}

float median(int n, float a[10])
{
    float temp = 0, med;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    if (n % 2 == 0)
        med = (a[(n / 2) - 1] + a[(n / 2)]) / 2.0;
    else
        med = a[(n / 2)];
    return med;
}

float variance(int m, float x[10])
{
    int i;
    float var, sum = 0;
    for (i = 0; i < m; i++)
        sum = sum + pow((x[i] - mean(m, x)), 2);
    var = sum / (float)m;
    return var;
}