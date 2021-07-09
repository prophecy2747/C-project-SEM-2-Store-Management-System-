#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void employee(char name[], char items[][30], int stock[], int cost[])
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

                case 3: printf("View Items\n");
                        printf("\nID\tItems\t\t Stock\t\t Cost");
                        for( int i = 0 ; i < 10 ; i++ ) {printf("\n%d.\t%s\t\t %d\t\t %d",i,items[i],stock[i],cost[i]);}
                        break;
                default:printf("wrong choice\n");break;
            }

        printf("\nDo you want to go back to employee menu?(y/n) ");scanf(" %c",&ch);printf("\n");
    }while(ch == 'Y' || ch == 'y');

}





int main()
{
	char items[][30]={"Apples","Chips","Pepsi","Chocolate","Boost","Nutella","Toothpaste","Surf Excel","Biscuits","Ketchup"};
	char whilemain='y';
	char cust_name[20];
	int cost[10]={180,20,25,30,75,360,45,144,50,30},stock[10]={10,8,15,5,5,15,15,15,15,15};
	
    strcpy(cust_name,"Username");
    employee(cust_name,items,stock,cost);

}

