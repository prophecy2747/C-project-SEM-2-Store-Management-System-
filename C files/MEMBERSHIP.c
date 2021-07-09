#include <stdio.h>

int membership(int);
int main()
{
    int bill;
    bill=membership(bill);
}

/*membership alloting part*/

int membership(int bill_amount)
{
    if(bill_amount>3000)
    {
        printf("dear customer, you will come under PLATINUM membership");
        bill_amount-=bill_amount*(0.25);
    }
    else if(bill_amount>2000)
    {
        printf("dear customer, you will come under GOLD membership");
        bill_amount-=bill_amount*(0.15);
    }
    else if(bill_amount>1000)
    {
        printf("dear customer, you will come under SILVER membership");
        bill_amount-=bill_amount*(0.05);
    }
    else if(bill_amount>500)
    {
        printf("dear customer, you will come under BRONZE membership");
        bill_amount-=bill_amount*(0.025);
    }
    else
    {
        printf("dear customer, You will not come under any membership scheme");
    }
    return bill_amount;
}
