#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char removeNewline(char*);
int scanFileList(char*, char*);
int getCustomerValues(char*, int);
void updateCustomerValues(char*, int, int);
void appendToList(char*, char*);
void appendToNumberList(char*, int);
int membership(int,int);

struct object{
		char o_item[20];
		int o_cost;
		int o_stock;
	} o_details[10];

struct bl {
	int item_no[100];
	int no_item[100];
};	
	
void customer(struct object o_details[10],char name[]) {
    int bal,ch,i=0,bill=0;
    char b;
    struct bl *ptr;
    ptr = (struct bl *) calloc(100,sizeof(struct bl));
    printf("Welcome to our store");
    printf("\nEnter the Amount in your e-wallet: $");
    scanf("%d",&bal);
    do{
        i=0;
        printf("\n1. View the Items in our Store \n2. Shop Items in our Store \n3. View your Balance in your e-Wallet");
        printf("\nEnter what you want to do: \n==>");
        scanf(" %d",&ch);
        if(ch==1){
            while(i<10){
                printf("\n %d. %s = %d",i+1,o_details[i].o_item,o_details[i].o_cost);
                i++;
            }
        }
        else if(ch==3){
            printf("\n\nYour Current Balance in your e-Wallet is: %d",bal);
        }
        else if(ch==2){
            char j='y';
            int k = 0;
 FILE *fptr;//File pointer
            fptr=fopen("stock.txt","w");//opening the file in write mode.

            while(j=='y'||j=='Y'){
                i=0;
                while(i<10){
                    printf("\n %d. %s = %d",i+1,o_details[i].o_item,o_details[i].o_cost);
                    i++;
                }
                int chi,ni,l = 0;
                printf("\nSelect any items: \n==>");
                scanf("%d",&chi);
                ptr->item_no[k] = chi-1;
                printf("\nEnter the Number of items: ");
                scanf(" %d",&ni);
                while(ni>o_details[chi-1].o_stock)
                {
                        printf("\n\nInsufficient Stocks!!!!");
                        printf("\nDecrease the Number of items: \n==>");
                        scanf ("%d",&ni);
                }
                ptr->no_item[k] = ni;
                o_details[chi-1].o_stock -= ni;
                //rewriting the file
                for(i=0;i<9;i++){
                    fprintf(fptr, "%d,", o_details[i].o_stock);
		        }
		        fprintf(fptr,"%d", o_details[9].o_stock);
                fclose(fptr);

                bill += (o_details[chi-1].o_cost)*ni;
                ++k;
                printf("\n\nDo you want to Add more Items to your Cart :\n==>");
                scanf (" %c",&j);
            }
            int loops=0,loopp = 0;
            char s,p;
            while (loops == 0) {
                printf("\nPress s or S to Scan Items: \n==>");
                scanf(" %c",&s);
                if (s=='s' || s=='S') {
                   int yr=0;
                    printf("\nYour cart has been successfully scanned!!\n\n");
                    printf("\n\n");
                    printf("<===============BILL DETAILS==============>\n\n");
                    printf("Name: %s\n\n",name);
                    printf("S.no\t Item Name\t Item cost\t Total No.Items\t Total Cost\n");
                    int m;
					for ( m=0; m<k; m++){
                    yr = (o_details[ptr->item_no[m]].o_cost)*(ptr->no_item[m]);
                	printf("%d.\t %s\t %d\t   %d\t   %d\n",m+1,o_details[ptr->item_no[m]].o_item,o_details[ptr->item_no[m]].o_cost,ptr->no_item[m],yr);
                    //loops=1;
                }

                 printf("\n\nYour Bill amount: $%d",bill);
                    //bill = membership(bill);
                    int visits, pos;
                    pos = scanFileList("namelist.txt",name);
                    if(pos == -1)
                    {   
					    appendToList("namelist.txt", name);
                        appendToNumberList("visitslist.txt", 1);
                        int pos = scanFileList("namelist.txt",name);
                    }
                    visits = getCustomerValues("visitslist.txt", pos);
                    updateCustomerValues("visitslist.txt", pos, visits+1);
                    int payment = membership(bill, visits);
                    printf("\nYour total Bill amount after Discounts: $%d",payment);
                    loops=1;
                }        
                else {
                    printf("\nError!!! Try again!!!");
                }
            }
            while (loopp == 0 ){
                printf("\nPress p or P to Pay the bill: \n==>");
                scanf(" %c",&p);
                if (p=='p' || p=='P') {
                    printf("\nYou have been Redirected to the Payments Page!!!");
                    char payvar;
                    if (bal<bill) {
                        payvar = 'n';
                    }
                    else {
                        printf("\n\nDo you want to continue: \n==>");
                        scanf(" %c",&payvar);
                    }
                    if (payvar == 'y' || payvar == 'Y'){
                        printf("\nPayment completed successfully!!");
                        bal-=bill;
                        printf("\nThanks For Shopping with us!!!!!");
                        printf("\nYour Current Balance in your e-Wallet : $%d",bal);
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
        free(ptr);
        printf("\n\nDo you want to Enter the Shop again???  : ");
        scanf(" %c",&b);
    }
    while(b=='y'||b=='Y');
    
}


void employee(struct object o_details[10])
{
    printf("\n=============EMPLOYEE=============\n");
    int passcode;
    printf("Enter the employee passcode: ");
    scanf("%i",&passcode);
    if(passcode!=1234){printf("\nIncorrect Passcode!");return;}
    
    int choice;
    char ch='y';
    
    do{
            printf("what would you like to do?\n(1)Update stock\n(2)Update cost\n(3)View Items\n>> ");
            scanf("%d",&choice);

            char returnCheck ='y';
            int itemID,i;
            FILE *fp;

            //We are updating the value in the structure and rewriting the file with the change so that it is permanent and does not get reset

            switch(choice)
            {
                case 1: printf("Update stock\n");
                        fp=fopen("stock.txt","w");//opening stock.txt file in write mode to rewrite file
                
                        do{
                            printf("Which stock item would you like to change(-1 to exit)\n>>Enter Item ID: ");scanf("%d",&itemID);
                                if(itemID == -1 ){break;}  // -1 TO EXIT OUT OF THE LOOP
                                if(itemID > 10 ){continue;}
                                
                                    printf("\nSeletect Item; %s \nAvailable Stock; %d",o_details[ itemID-1 ].o_item,o_details[ itemID-1 ].o_stock);
                                    printf("\nWhat is the new stock amount for this item? ");scanf("%i",&o_details[ itemID-1 ].o_stock);
                                    printf("\nSTOCK HAS BEEN UPDATED \nItem; %s \nNew Stock; %d",o_details[ itemID-1 ].o_item,o_details[ itemID-1 ].o_stock);
                                    
                                    //Rewriting file
									for(i=0;i<9;i++){
                                    	fprintf(fp, "%d,", o_details[i].o_stock);
		                            }
		                            fprintf(fp,"%d", o_details[9].o_stock);

                            printf("\nDo you wish to update stock for anything else?(y/n) ");scanf(" %c",&returnCheck);printf("\n");
                        }while(returnCheck == 'Y' || returnCheck == 'y');
                        
                        fclose(fp);
                        
                        break;
                
                case 2: printf("Update cost\n");
                
                        fp=fopen("cost.txt","w");//opening cost.txt file in write mode to rewrite file
                
                        do{
                            printf("Which stock item would you like to change(-1 to exit)\n>>Enter Item ID: ");scanf("%d",&itemID);
                                if(itemID == -1 ){break;}
                                if(itemID > 10 ){continue;}
                                
                                    printf("\nSeletect Item; %s \nCurrent Price; %d",o_details[ itemID-1 ].o_item,o_details[ itemID-1 ].o_cost);
                                    printf("\nWhat is the new price for this item? ");scanf("%i",&o_details[ itemID-1 ].o_cost);
                                    printf("\nCOST HAS BEEN UPDATED \nItem; %s \nNew Price; %d",o_details[ itemID-1 ].o_item,o_details[ itemID-1 ].o_cost);
                                    
                                    //Rewriting file
									for(i=0;i<9;i++){
                                    	fprintf(fp, "%d,", o_details[i].o_cost);
		                            }
		                            fprintf(fp,"%d", o_details[9].o_cost);

                        printf("\nDo you wish to update stock for anything else?(y/n) ");scanf(" %c",&returnCheck);printf("\n");
                        }while(returnCheck == 'Y' || returnCheck == 'y');
                        fclose(fp);
                        break;

               case 3: printf("View Items\n");
                        printf("\nID\tItems\t\t\tStock\t\tCost");
                        int i;
                        for(i = 0 ; i < 10 ; i++ ) {printf("\n%d.\t%s\t\t\t%d\t\t%d",i+1,o_details[i].o_item,o_details[i].o_stock,o_details[i].o_stock);}
                        break;  
                default:printf("wrong choice\n");break;   
            }

        printf("\nDo you want to go back to employee menu?(y/n) ");scanf(" %c",&ch);printf("\n");
    }while(ch == 'Y' || ch == 'y');

}




//Main function
int main()
{
	//Declaring some variables
	char user_name[20];
    char tempchar[256];
    char *token;
    struct object o_details[10];
    
    int i=0;
    
	
	//intializing structure array
    //initalizing items 
	FILE *fp1 ;
	fp1= fopen("items.txt","r");
	char line[100];
	
	while(fgets(line, sizeof(line),fp1)){
		strcpy(tempchar,line);
		strcpy(o_details[i].o_item,tempchar);
		i++;
    }
    fclose(fp1);
    
    
	//initializing cost
    FILE *fp2 ;
    fp2= fopen("cost.txt","r");
    fscanf(fp2,"%s",tempchar);
    token=strtok(tempchar,",");
    i=0;
    
    while(token != NULL){
    	o_details[i].o_cost=atoi(token);
		token=strtok(NULL, ",");
		i++;
	}
    fclose(fp2);
    
    
    //initializing stock
	FILE *fp3 ;
    fp3= fopen("stock.txt","r");
    fscanf(fp3,"%s",tempchar);
    token=strtok(tempchar,",");
    i=0;
    
    while(token != NULL){
		o_details[i].o_stock=atoi(token);
		token=strtok(NULL, ",");
		i++;
	}
	fclose(fp3);
	
	
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
	        		customer(o_details,user_name);
					loop1=1;
				}
				else if(choice=='e'||choice=='E')
				{
					employee(o_details);
					loop1=1;
				}
				else
				{
					printf("Invalid input, try again");
				}
			}
			
			printf("Do you want to go back the main page? (y/n)");
			scanf(" %c",&whilemain);
		}
		
	printf("Thank you for Shopping with us");
	return 0;
	    
}

char removeNewline(char *data)
{
    int length;
        length = strlen(data);
        if( data[length-1] == '\n')
            data[length-1] = 0;
    return *data;
}
int scanFileList(char *filename, char* username)
{
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL ){ printf("file undefinied"); return 0; }
    
    char str[255];int pointerPos = 0;
    int foundPerson = 0;

    while( fgets(str, 255, fp) != NULL )
    {   
        removeNewline(str);

        if(strcmp(str, username) == 0)
        {   
            foundPerson = 1;break;
        }
        else
        {
            // printf("\n>> %s", str);
        }

        pointerPos++;
    }
    fclose(fp);

    if(foundPerson == 0){pointerPos = -1;}
    // printf("\npointer pos: %d", pointerPos);

    return pointerPos;
}
int getCustomerValues(char *filename, int pos)
{
    FILE *fp;
    fp = fopen(filename,"r");
    int pointerPos = 0, value;

    while(fscanf(fp,"%d", &value) == 1){
        // printf("\n>> %d", value);
        if(pointerPos == pos){break;}
        pointerPos++;
    }
    fclose(fp);
    return value;
}
void updateCustomerValues(char * filename, int pos, int newValue)
{
    FILE *fp;
    fp = fopen(filename,"r");
    int pointerPos = 0, value;
    FILE *fptemp;
    fptemp = fopen("temp", "w");

    while(fscanf(fp,"%d", &value) == 1){
        // printf("\n>> %d", value);
        if(pointerPos == pos){fprintf(fptemp, "%d\n", newValue);}
        else{fprintf(fptemp, "%d\n", value);}
        pointerPos++;
    }

    fclose(fptemp);
    fclose(fp);

    remove(filename);
    rename("temp", filename);
}
void appendToList(char *filename, char*value)
{
    FILE *fp;
    fp = fopen(filename,"a");
    fprintf(fp, "%s\n", value);
    fclose(fp);
}
void appendToNumberList(char *filename, int value)
{
    FILE *fp;
    fp = fopen(filename,"a");
    fprintf(fp, "%d\n", value);
    fclose(fp);
}
int membership(int bill_amount, int visits)
{
    printf("\nDear Customer,\n");
    if(visits>100)
    {
        printf("You will come under PLATINUM membership");
        bill_amount-=bill_amount*(0.25);
    }
    else if(visits>40)
    {
        printf("You will come under GOLD membership");
        bill_amount-=bill_amount*(0.15);
    }
    else if(visits>20)
    {
        printf("You will come under SILVER membership");
        bill_amount-=bill_amount*(0.05);
    }
    else if(visits>10)
    {
        printf("You will come under BRONZE membership");
        bill_amount-=bill_amount*(0.025);
    }
    else
    {
        printf("You will not come under any membership scheme");
    }
    return bill_amount;
}
