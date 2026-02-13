#include "stdio.h"
#include "../../libraries/types.h"

Natural f(Natural x)
{
    if (x == 0)
    {
        return 0;
    }

    if (x == 1)
    {
        return 2;
    }

    return (f(x-1) + (1<<x));
}

int main()
{
    for (Natural n = 0; n < 10; n++)
    {
        printf("f(%hu) = %hu\n", n, f(n));
    }

    return 0;
}
