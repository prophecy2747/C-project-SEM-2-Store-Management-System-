#include<stdio.h>
#include<string.h>

int membership(int);
void customer(char c_name[], char items[],int cost[], int stock[] ) {
    int bal,ch,i=0,bill = 0;
    char b;
    printf("Welcome to our store");
    printf("\nEnter the Amount in your e-wallet: ");
    scanf("%d",&bal);
    do {
        printf("\n1. View the Items in our Store \n2. Shop Items in our Store \n3. View your Balance in your e-Wallet");
        printf("\nEnter what you want to do: ");
        scanf(" %c",&ch);
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


void employee(char name[], char items[][30], int cost[], int stock[])
{
    printf("\n=============EMPLOYEE=============\n");
    int passcode;

    // printf("%s\n", name);
    // for(i = 0; i<10; i++) {printf("%s ",items[i]);}
    // printf("\n");
    // for(i = 0; i < 10; i++){printf("%d ", stock[i]);}
    // printf("\n");
    // for(i = 0; i < 10; i++){printf("%d ", cost[i]);}

    printf("Enter the employee passcode: ");
    scanf("%i", &passcode);
    if(passcode != 1234 ){printf("\nIncorrect Passcode!");return;}
    
    int choice;
    char ch='y';

    printf("Welcome %s to the employee menu, ", name);
    do{
            printf("what would you like to do?\n(1)Update stock\n(2)Update cost\n(3)View Items\n>> ");
            scanf("%d", &choice);

            char returnCheck = 'y';
            int itemID,i;

            switch(choice)
            {
                case 1: printf("Update stock\n");
                        do{
                            printf("Which stock item would you like to change(-1 to exit)\n>>Enter Item ID: ");scanf("%d",&itemID);
                                if(itemID == -1 ){break;}  // -1 TO EXIT OUT OF THE LOOP
                                if(itemID > 10 ){continue;}
                                
                                    printf("\nSeletect Item; %s \nAvailable Stock; %d",items[ itemID ],stock[ itemID ]);
                                    printf("\nWhat is the new stock amount for this item? ");scanf("%i",&stock[itemID]);
                                    printf("\nSTOCK HAS BEEN UPDATED \nItem; %s \nNew Stock; %d",items[ itemID ],stock[ itemID ]);

                            printf("\nDo you wish to update stock for anything else?(y/n) ");scanf(" %c",&returnCheck);printf("\n");
                        }while(returnCheck == 'Y' || returnCheck == 'y');
                        break;
                
                case 2: printf("Update cost\n");
                        do{
                            printf("Which stock item would you like to change(-1 to exit)\n>>Enter Item ID: ");scanf("%d",&itemID);
                                if(itemID == -1 ){break;}
                                if(itemID > 10 ){continue;}
                                
                                    printf("\nSeletect Item; %s \nCurrent Price; %d",items[ itemID ],cost[ itemID ]);
                                    printf("\nWhat is the new price for this item? ");scanf("%i",&cost[itemID]);
                                    printf("\nCOST HAS BEEN UPDATED \nItem; %s \nNew Price; %d",items[ itemID ],cost[ itemID ]);

                            printf("\nDo you wish to update stock for anything else?(y/n) ");scanf(" %c",&returnCheck);printf("\n");
                        }while(returnCheck == 'Y' || returnCheck == 'y');
                        break;

               /* case 3: printf("View Items\n");
                        printf("\nID\tItems\t\t Stock\t\t Cost");
                        for( int i = 0 ; i < 10 ; i++ ) {printf("\n%d.\t%s\t\t %d\t\t %d",i,items[i],stock[i],cost[i]);}
                        break; */
                default:printf("wrong choice\n");break;
            }

        printf("\nDo you want to go back to employee menu?(y/n) ");scanf(" %c",&ch);printf("\n");
    }while(ch == 'Y' || ch == 'y');

}





int main()
{
	char items[10]={'Apples','Chips','Pepsi','Chocolate','Boost','Nutella','Toothpaste','Surf Excel','Biscuits','Ketchup'};
	char whilemain='y';
	char user_name[20];
	int cost[10]={'50','20','25','10','60','100','20','70','15','10',},stock[10]={'50','50','50','50','50','50','50','50','50','50',};
	
	while(whilemain=='y'||whilemain=='Y')
	    {
	    	printf("Enter your name");
	        gets(user_name);
	        
	        int loop1=0;
	        
	        while(loop1==0)
	        {
	        	printf("Enter c/C for Customers\nEnter e/E for Employees\n");
	        	char choice;
				scanf(" %c", &choice);
	        	
	        	if(choice=='c'||choice=='C')
	        	{
	        		customer(user_name,items,cost,stock);
					loop1=1;
				}
				else if(choice=='e'||choice=='E')
				{
					employee(user_name,items,cost,stock);
					loop1=1;
				}
				else
				{
					printf("Invalid input, try again");
				}
			}
			
			printf("Do you want to go back the main page? (y/n)");
			scanf(" %c", whilemain);
		}
		
	printf("Thank you for Shopping with us?");
	return 0;
	    
}

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
