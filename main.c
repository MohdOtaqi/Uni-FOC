'




































'#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void red();
void blue ();
void green ();
void purple();
void yellow();
void reset ();
void startGuessTheNumberGame();
void startHangmanGame();



int main()
{
    char username [20000];
    int gamenum=0;

    printf("Hi Please Enter Your Name : ");
    scanf("%[^\t\n]",username);
   
    printf("Hello");
    green();
    printf(" %s ",username);
    
    reset();
    printf ("Welcome to our games\n");
    printf("Choose numbers from 1-3 and see the options\n");
    
    printf("1. Guess the number.\n2. Hangman.\n3. Exit.\n");
    scanf("%d",&gamenum);
    
    if(gamenum==1||gamenum==2||gamenum==3)
    {
        
        while(gamenum!=1&&gamenum!=2&&gamenum!=3)
        {
            red ();
            printf("You Entered An Invalid Option Please Choose a Number from 1-3\n");
            
            
            reset();
            printf("1. Guess the number.\n2. Hangman.\n3. Exit.\n");
            scanf("%d",&gamenum);
        }
        switch(gamenum)
        {
            case 1:
            blue ();
            printf("Welcome To Guess the number game\n");
            
            reset();
            startGuessTheNumberGame();
            
            break;
            
            
            case 2:
            
            blue ();
            printf("Welcome To Hangman game\n");
            
            reset();
            startHangmanGame();
            
            break;
            
            
            case 3:
            
            blue ();
            printf("Thank you for coming have a great day\n");
            
            break;
            
        }
    }
    
    else
    {
        red ();
        printf("You Entered An Invalid Option Please Choose a Number from 1-3\n");
        reset ();
    }
    
}




void red()
{
    printf("\033[1;31m");
}


void blue()
{
    printf("\033[1;36m");
}


void green()
{
    printf("\033[1;32m");
}


void yellow()
{
    printf("\033[1;33m");
}


void purple()
{
    printf("\033[1;35m");
}


void reset () 
{
    printf("\033[0m");
}


void startGuessTheNumberGame()
{
    int mid;
    int low=1;
    int high=10000;
    mid=(low+high)/2;
    int usernum;
    int optionuser;
    int tries=1;
    
    printf("Enter a number between 1-10000 : ");
    scanf("%d",&usernum);
    
    if(usernum<=10000&&usernum>=1)
    {
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            blue();
            printf("Your secert number is");
            printf(" %d\n",usernum);
                
            yellow();
            printf("My guess is %d\n",mid);
            
            
            reset();
            printf("Please Choose from 1-3 For the Following options\n");
            
            printf("1. My Guess is right. Hurrah!!\n");
            printf("2. The secert number is bigger than %d\n",mid);
            printf("3. The secert number is smaller than %d\n",mid);      
            scanf("%d",&optionuser);
            
            if(optionuser==1)
            {
                green();
                printf("My Guess is right. Hurrah!!\n");
                
                purple();
                printf("Thank you for playing have a nice day\n");
                
                break;
            }
            else if(optionuser==2)
            {
                
                low=mid+1;
                
            }
            else if(optionuser==3)
            {
                
                high=mid-1;
                
            }
            tries++;
            
        }
        green();   
        printf("Your tries is %d\n",tries);
        
    }  
    
    else
    {
        red ();
        printf("You Entered An Invalid Option Please Choose a Number from 1-10000\n");
        reset();
    }
    
    
}


void startHangmanGame()
{
    
}





