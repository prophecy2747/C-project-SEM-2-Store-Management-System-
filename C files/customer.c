#include <stdio.h>
#include <stdlib.h>

void customer(char rcname[], int stock[], int cost[], char *items[]) {
    int bal,ch,i=0,bill = 0;
    char b;
    printf("Welcome to our store Mr/Mrs. %s",rcname);
    printf("\nEnter the Amount in your e-wallet: ");
    scanf("%d",&bal);
    do {
        printf("\n1. View the Items in our Store \n2. Shop Items in our Store \n3. View your Balance in your e-Wallet");
        printf("\nEnter what you want to do: ");
        scanf("%d",&ch);
        if (ch==1) {
            while (i<2) {
                printf("\n %d. %s = %d",i+1,items[i],cost[i]);
                i++;
            }
        }
        else if (ch==3) {
            printf("\n\nYour Current Balance in your e-Wallet is: %d",bal);
        }
        else if (ch==2) {
            char j = 'y';
            while (j=='y' || j=='Y') {
                i=0;
                while (i<2){
                    printf("\n %d. %s = %d",i+1,items[i],cost[i]);
                    i++;
                }
                int chi,ni,l = 0;
                printf("\nSelect any items: ");
                scanf ("%d",&chi);
                printf("\nEnter the Number of items: ");
                scanf ("%d",&ni);
                while (stock[chi-1]<ni){
                        printf("\n\nInsufficient Stocks!!!!");
                        printf("\nDecrease the Number of items: ");
                        scanf ("%d",&ni);
                }
                stock[chi] -= ni;
                bill += (cost[chi-1])*ni;
                printf("\n\nDo you want to Add more Items to your Cart : ");
                scanf (" %c",&j);
            }
            int loops=0,loopp = 0;
            char s,p;
            while (loops == 0) {
                printf("\nPress s or S to Scan Items: ");
                scanf(" %c",&s);
                if (s=='s' || s=='S') {
                    printf("\nYour cart has been successfully scanned!!");
                    printf("\n\nYour Bill amount: $%d",bill);
                    //bill = membership(bill)
                    printf("\nYour total Bill amount after Discounts: $%d",bill);
                    loops=1;
                }
                else {
                    printf("\nError!!! Try again!!!");
                }
            }
            while (loopp == 0 ){
                printf("\nPress p or P to Pay the bill: ");
                scanf(" %c",&p);
                if (p=='p' || p=='P') {
                    printf("\nYou have been Redirected to the Payments Page!!!");
                    char payvar;
                    if (bal<bill) {
                        payvar = 'n';
                    }
                    else {
                        printf("\n\nDo you want to continue: ");
                        scanf(" %c",&payvar);
                    }
                    if (payvar == 'y' || payvar == 'Y'){
                        printf("\nPayment completed successfully!!");
                        bal-=bill;
                        printf("\nThanks For Shopping with us!!!!!");
                        printf("\nYour Current Balance in your e-Wallet : %d",bal);
                        loopp=1;
                    }
                    else {
                        if (payvar == 'n' || payvar == 'N'){
                            printf("\nOops!! You have Insufficient Balance!!");
                            printf("\nPayment Failed!!!");
                            loopp = 1;
                        }
                        else {
                            printf("\nPayment Failed!!! \nTry again!!!");
                            loopp=0;
                        }
                    }
                }
                else {
                    printf("\nError!!! Try again!!!");
                }
            }
        }
        printf("\n\nDo you want to Enter the Shop again???  : ");
        scanf(" %c",&b);
    }
    while (b == 'y' || b == 'Y');
    
}

 
int main() {
    char *ptr[2];
    ptr[0] = (char *)malloc(10*sizeof(char));
    ptr[1] = (char *)malloc(10*sizeof(char));
    int stock[2] = {10,20}, cost[2] = {100,200};
    ptr[0] = "Apples";
    ptr[1] = "Oranges";
    
    char name[100] = "SAM";
    customer(name,stock,cost,ptr);
    
}
