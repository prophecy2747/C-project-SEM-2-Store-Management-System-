#include<stdio.h>
int main()
{
	char items[10]={'Apples','Chips','Pepsi','Chocolate','Boost','Nutella','Toothpaste','Surf Excel','Biscuits','Ketchup'};
	char whilemain='y';
	char cust_name[20];
	int cost[10]={'50','20','25','10','60','100','20','70','15','10',},stock[10]={'50','50','50','50','50','50','50','50','50','50',};
	
	while(whilemain=='y'||whilemain=='Y')
	    {
	    	printf("Enter your name");
	        gets(cust_name);
	        
	        int loop1=0;
	        
	        while(loop1==0)
	        {
	        	printf("Enter c/C for Customers\nEnter e/E for Employees");
	        	char choice;
				scanf(" %c", choice);
	        	
	        	if(choice=='c'||choice=='C')
	        	{
	        		
					loop1=1;
				}
				else if(choice=='e'||choice=='E')
				{
					
					loop1=1;
				}
				else
				printf("Invalid input, try again");
			}
			
			printf("Do you want to go back the main page? (y/n)");
			scanf(" %c", whilemain);
		}
		
	printf("Thank you for Shopping with us?");
	    
}
