#include <stdio.h>
#include <stdarg.h>

double my_sum(const char* format, ...)
{
    va_list fp;
    va_start(fp, format);
    double sum = 0;
    
    while(*format)
    {
        if (*format == 'd')
        {
            sum += va_arg(fp, int); 
        }
        else if (*format == 'f')
        {
            sum += va_arg(fp, double);
        }

        format++;
    }

    va_end(fp);
    return sum;
}

int main()
{
    double res;

    res = my_sum("%d %d %d %f", 32, 60, 54, 35.2);
    printf("%f", res);

    return 0;
    
}