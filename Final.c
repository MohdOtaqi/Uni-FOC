//preprocessor directives
#include <stdio.h>  //standard input output header file
#include <stdlib.h> //standard input output library 
#include <time.h> 
#include <math.h>
#include <string.h>

#include "foc_fa22.h" //I have to include this file so when we compile we can see the image 


void red();

void blue ();

void green ();

void purple();  //these functions are for coloring

void yellow();

void reset ();

// I chose void in these two functions because we wnat him to go and play and nothing we wnat to be returned

void startGuessTheNumberGame();     // this function will call guessing the number game

void startHangmanGame();    //this function will call the Hangman game



int main()// the excuting will start from here 
{
    char username [50] ;     //I declared a charecter array so we can have a string
    
    int gamenum=0;      //this integer is for the number of chosen game

    printf("Hi Please Enter Your Name : ");     //introductory sentence
    
    scanf("%s",username);   //here reading his(only first name will be shown and stored) 
   
    printf("Hello");
    
    green();
    
    printf(" %s ",username);    //i made the variable here with himself so it will be colored green 
    
    
    reset();    //resetting color
    
    
    while(1)
    {
    
        printf ("Welcome to our games\n");
        
        printf("Choose numbers from 1-3 and see the options\n");
        
        
        printf("1. Guess the number.\n2. Hangman.\n3. Exit.\n");
        
        scanf("%d",&gamenum);
        
        if(gamenum==1||gamenum==2||gamenum==3)      //here i am checking if the user entered a correct game number 
        
        
        {       //if he does we will enter and start the games or it is going to be an exit
            
            
            
            if(gamenum==1)     //here is the switch so if he chose 1 we will go to Hangman and like that 
            {

                
                reset();
                
                startGuessTheNumberGame();  //here i am calling the funtion that i made so user can play gess the number game 
                
            }    
                
                
            else if (gamenum==2)
            {
               
                reset();
                
                startHangmanGame();    //here i am calling the funtion that i made so user can play Hangman
                
            }    
                
            else if (gamenum==3)
            {    
                blue ();
                printf("Thank you for coming have a great day\n");//here is ending the program 
                
                break;
                
                
            }
            
            
            
        }
        
        
        
        else        //this else is for the else in line 41
                    //here we ending the program if he entered any wrong input    
        {
            red ();
            printf("You Entered An Invalid Option Please Choose a Number from 1-3\n");
            reset ();
        }
    
        
    }
    

return 0;
   
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
    
    int usernum;//the number that is read from the user 
    
    int optionuser;// variable that read 
    
    int tries=1;//the tries number and is start from 1 because the computer will strat the guessing
    
    int count1=0;//counter for the image (rows)
    
    int count2=0;//counter for the image (columns)
    
    int imagerr[150][150];// here are the image pixel
    
    int x=1;
    
    
	blue ();
	printf("Guess the Number has started\n");    //introductory sentence
    	reset(); 
        
    
    printf("Enter a number between 1-10000 : ");
    
    scanf("%d",&usernum);   //here i read a number from the user
    
    if(usernum<=10000&&usernum>=1)  //if the number is bigger than 10000 or smaller than 1 the game wont be played
    {
        while(1)//the loop will keep running until the user enter 1 and if he enter a wrong number it will tell him to enter between 1-3
        {
        
            while(low<=high)    //this while is for the guessing it will be run until user enter 1 or low is bigger than high
            {
                mid=(low+high)/2; //here the divison will give us the 5000 through the binary search
                
                
                blue();
                
                printf("Your secert number is");//here it will keep showing your number so you wont forget it
                
                printf(" %d\n",usernum);
                    
                
                yellow();
                
                printf("My guess is %d\n",mid); //showing him his number and my guess so he wouldnt forget it
                
                
                
                reset();
                
                printf("Please Choose from 1-3 For the Following options\n");
                
                
                printf("1. My Guess is right. Hurrah!!\n");
                
                printf("2. The secert number is bigger than %d\n",mid);
                
                printf("3. The secert number is smaller than %d\n",mid);      
                
                scanf("%d",&optionuser);// here the user will chooseone of the options
                
                
                if(optionuser==1)
                {
                    
                    green();
                    
                    printf("My Guess is right. Hurrah!!\n");
                    
                    purple();
                    
                    printf("Thank you for playing have a nice day\n");
                    
                    break;//here it will break beacuse the number is found
                
                    
                }
                
                
                else if(optionuser==2)
                {
                    
                    low=mid+1;    //here using the binary search            
                
                    
                }
                
                
                else if(optionuser==3)
                {
                    
                    high=mid-1; //also here using the binary search 
                    
                }
                
                
                else // here it will end the program because he didnt enter a valid number for the options
                {
    		        
    		        red ();
            	    
            	    printf("You Entered An Invalid Option Please Choose a Number from 1-3\n");
            	    
            	    reset();
            	    //this else will be shown if the user didnt enter a number between 1-3
            	   
                
                    
                }
                
                tries++; //here is tries counter it will keep increasing until the user enter 1 so it will break and it will help in drawing the image(the rows number)
                
            
                
            }
            
            
            
           if(optionuser==1)
           {
        
        	break;
        
           }
        
        }
        

        
        green();   
        
        printf("Your tries is %d\n",tries);// here it will show the user the tries number
        
        
    }  
    
    
    else // here it will end the program because he didnt enter a valid number for the guessing
    {
        
        red ();
        
        printf("You Entered An Invalid Option Please Choose a Number from 1-10000\n");
        
        reset();
    
        
    }
    
    
    
    int try=tries*10; // this is the block and every block is 10*tries

    
    for(count1=0; count1<150; count1++)     //this loop is for draing the bordar
    {
    
        
        for(count2=0; count2<150; count2++)  //here it will enter and draw the bordars around the the image 
        {
            
            
            imagerr[count1][count2]=225;
            
            if(count1==1 || count1==150)
		    {
		        
		        imagerr[count1][count2]=0;
		        
		    }
		    
		    else if(count1<150 && count1>1)
		    {
		        
		        imagerr[count1][149]=0;
		        imagerr[count1][1]=0;
		        
		        
		    }
            
        }
    
    
    } 
    
    
    

    for(count1=0 ; count1<150 ; count1++)   //this loop is for the blcoks and the white background 
        
    {
        
        for (count2=0; count2<150 ; count2++)   //here drawingt he white background
        
        {
        
            imagerr[count1][count2]=255;
            
            if (count1>150-try && count2 >=65 && count2 <= 85)    // here drawing the block in the dimension between 65 and 85 and we start from 150-try because it start drwaing from up to down 
            
            {
                
                imagerr[count1][count2]=0;
                
            }     
            
            
            
            
        }
            
            
    }
       
        
   
    
    
        showArray(150,150,imagerr); //here the image will be shown
	
	
	reset();

}


void startHangmanGame()
{



    FILE *fileop; //here making a pointer that referance to the file address
    
    int catchoice = 0;// this is for the category choice and reading it from the user
    
    srand (time (NULL));//here the null time will change the seed for the randomizer using the time 
    
    int randomizer = rand () % 15;//here generating random number from 0-14
    
    char wordfile[50];// an array that store a random word from the file 
    
    int count1 = 0;//counter for loops
    
    int count2 = 0;// counter for the loops

    int wordlength = 0;//here is the wordlengthand will be change with the strlen when  it is read
    
    char underscore[100]="\0";// an array that will print the - of the word
    int attempts = 5;// tries number 
    char userletter = '\0';//a variable that read the letters from the user

    
    int x = 1;//this will keep the loop running
    
	
	blue ();
	printf("Hangman has started\n");    //introductory sentence
    	reset();       

    
    while (x = 1)
    {
        printf("Choose a category : \n1.Food.\n2.Objects.\n3.Names.\n4.Colors\nPlease choose between 1-4\n");
        //introductory sentence for the user to show which category the user want
        
        scanf ("%d", &catchoice);
    
        //this if will open a file depending on the what user choose
        
        if (catchoice == 1)
        {
        
        fileop = fopen ("food.txt", "r");
        
        break;
        
        }
        
        else if (catchoice == 2)
        {
        
        fileop = fopen ("objects.txt", "r");
        
        break;
        
        }
        
        
        else if (catchoice == 3)
        {
        
        fileop = fopen ("names.txt", "r");
        
        break;
        
        
        }
        
        else if (catchoice == 4)
        {
        
        fileop = fopen ("colors.txt", "r");
        
        break;
        
        }
        
        
        else    //here it will tell the user that he entered a wrong variable
        {
        
        red ();
        
        printf("You Entered An Invalid Option Please Choose a Number from 1-4\n");
        
        reset();
        
        }
    
    
    
    }
    
    int k = 0;
    
    int verify = 0;

    while (k!=randomizer)//this while will read the words in the file 
    {
        
        fscanf(fileop,"%s",wordfile);
        
        k++;
        
    }
    
    fclose (fileop);//here the file that is opened will be closed
    
    
    wordlength = strlen (wordfile);//here the lenght of the word will be calculated and converted into a number 
    
    
    printf ("The word has %d letters\n", wordlength);// the user will see how many letter is the word
    
    attempts=5;// here is the attempts that user have  
    
    
    for (count1 = 0; count1 < wordlength; count1++)// this loop to assing the undersocer in a loop (it is an array)
    {
    
        underscore[count1] = '-';
    
    }
    



    while(1)//the loop will run until the user find the word or he exceeded the attempts limit
    {
    
    
        for (count1 = 0; count1 < wordlength; count1++)//this loop print the - and the letter that the user found
        {
        
        
            printf ("%c", underscore[count1]);
        
        }
        
            printf ("\n");//making new line
        
        


        
        
        
        
        
        if(attempts==0)//this if will check the attempt	and if the user exceededthe limit if he exceeded the loop will break
        {
            yellow();  		
            printf("you didn't get the word try agian.\n");	
              		
	        break;
            
            reset();  		

        
            
        }    

        	
        
    
        printf("You have %d attempts remaining\n",attempts);// here will show the user how many attempts he have remaining
        

        
        scanf (" %c", &userletter);//here we will read the letter from the user  
        

        
        
        

        
        
        for (count2 = 0; count2 < wordlength; count2++) //this loop is to check if the letter that the user enteredis correct or not
        {
        
            if (userletter == wordfile[count2])
            {
        
            
            underscore[count2] = userletter;
            catchoice=0;//this is for the yes corrector no keep going test
                
            }
            
        }
        
        
        if(catchoice==0)// this if shows you if the letter that the user input is correct in sentences
        {
            green();
            printf("yes this is right\n");// here the letter that user entered is correct
            reset();
        }
        
        
        else
        {
            red();
            printf("not quite try again\n");
            reset();
	        attempts--;//here because the letter isnt correct the attempts will decrease by one every time the letter isnt correct
        }
        
        catchoice=1;// here we are re zeroing this tester so nothing wrong will happen
        
        
        if (strcmp(underscore,wordfile)==0)//this if will check if the word is correct if yes it print congrats and break the loop
        {
	    
	    green();	
            printf("\nCongratulations you have found the word\n");
            printf("%s\n",wordfile);

            
            reset();
            
            break;
            	
        	
        }
        
          
        
        
    }
    
    
    

    

reset();
    
        
}


















