#include <iostream>
#include <conio.h>
#include <windows.h>

/* This cpp program is supposed to run a simple tic-tac-toe game
which will keep scores, and allow you to choose from best 2
out of 3 or best 3 out of 5.  I ran this program on code::blocks
a month ago and it worked, but I made slight changes, and
havn't built the program since then.  If it doesn't work,
I would appreciate some help. It has only been roughly 2
months since I started learning cpp at my high school, and a month when I
finished this program, so there will be errors and bugs.
Anyways, thanks for checking my program out, and I'm working on more simple games like this one :D */




char square[10]={'0','1','2','3','4','5','6','7','8','9'};
void gameBoard();
int checkWinner();
int scoreA=0;
int scoreB=0;
int z;
bool overallwin(int, int, int);
int main() // main function
{
    int i;
    int j;
    int choice;
    for(j=48; j < 58; j++)  // creates values for the tic-tac-toe board
        {
                square[j-48]=j;
        }
    bool shutoff = false; // if the game will continue or not
std::cout<<"do you want best out of 3 or 5?:";
std::cin>>z;
int mark;
int player;
    while(shutoff == false)  // pretty much until player decides that s/he wants to quit
    {
        for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
        player=1,i,choice;
        system ("cls");
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(z==3)  // if player's choice was best out of 3
    {


        do
        {   gameBoard();
            player=(player%2)? 1:2;             /* the loop will allow this game to switch between player one and two */
            std::cout<<"Player"<<player<<", make your choice: ";
            std::cin>>choice;
            mark=(player==1)? 'X':'O';

            //////////////////////////////////////////////////////////////////////////////////////////
            /////////////// These next few lines will pretty much allow the     //////////////////////
            /////////////// corresponding square to be marked if it is not taken//////////////////////
            //////////////////////////////////////////////////////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////////

            if (choice==1 && square[1]=='1')
            {
                square [1]=mark;
            }
            else if(choice == 2 && square[2] == '2')
            {
                square[2]=mark;
            }
            else if(choice ==3 && square[3] == '3')
            {
                square [3] =mark;
            }
            else if(choice == 4 && square [4] == '4')
            {
                square [4]=mark;
            }
            else if (choice == 5 && square [5] == '5')
            {
                square[5]=mark;
            }

            else if(choice == 6 && square [6] == '6')
            {
                square[6]=mark;
            }
            else if (choice== 7 && square [7] == '7')
            {
                square[7]=mark;
            }
            else if (choice== 8 && square [8] == '8')
            {
                square[8]=mark;
            }
            else if(choice == 9 && square[9] == '9')
            {
                square[9]=mark;
            }
            else
            {
                std::cout<<"Dude, invalid move!!!";
                player--;
                getch();
            }
            player++;
             i=checkWinner();
        }

        //game condition

        while(i==0);
        {
          gameBoard();
        }

        if(i==1)
        {
            std::cout<<"Winner is, Player:1";
            scoreA++;
            getch();
            system("cls");
            for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
        gameBoard();

        }
        else if (i==2)
        {
            std::cout<<"Winner is, Player:2";
            scoreB++;
            getch();
            system("cls");
            for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
            gameBoard();


        }

        else
        {
        std::cout<<"It's a draw!";
        getch();
        system("cls");
        for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
        gameBoard();

        }
        shutoff = overallwin(scoreA, scoreB, z);

    }


    //same as the if (z==3), but only best out of 5

    else if(z==5)
    {
        do
        {   gameBoard();
            player=(player%2)? 1:2;
            std::cout<<"Player"<<player<<", make your choice: ";
            std::cin>>choice;
            mark=(player==1)? 'X':'O';
            if (choice==1 && square[1]=='1')
            {
                square [1]=mark;
            }
            else if(choice == 2 && square[2] == '2')
            {
                square[2]=mark;
            }
            else if(choice ==3 && square[3] == '3')
            {
                square [3] =mark;
            }
            else if(choice == 4 && square [4] == '4')
            {
                square [4]=mark;
            }
            else if (choice == 5 && square [5] == '5')
            {
                square[5]=mark;
            }
            else if(choice == 6 && square [6] == '6')
            {
                square[6]=mark;
            }
            else if (choice== 7 && square [7] == '7')
            {
                square[7]=mark;
            }
            else if (choice== 8 && square [8] == '8')
            {
                square[8]=mark;
            }
            else if(choice == 9 && square[9] == '9')
            {
                square[9]=mark;
            }
            else
            {
                std::cout<<"Dude, invalid move!!!";
                player--;
                getch();
            }
            player++;
             i=checkWinner();
        }

        while(i==0);
        {
          gameBoard();
        }

        if(i==1)
        {
            std::cout<<"Winner is, Player:1";
            scoreA++;
            getch();
            system("cls");
            for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
            gameBoard();
        }
        else if (i==2)
        {
            std::cout<<"Winner is, Player:2";
            scoreB++;
            getch();
            system("cls");
            for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
            gameBoard();
        }

        else
        {
        std::cout<<"It's a draw!";
        getch();
        system("cls");
        for(j=48; j < 58; j++)
        {
                square[j-48]=j;
        }
        gameBoard();
        }
        shutoff = overallwin(scoreA, scoreB, z);

    }

    // if player decides to enter a different number
    //There will be a bug if you enter a letter
    else if(z!=3,5)
    {
    std::cout<<"Enter a 3 or a 5"<<std::endl;
    std::cout<<"Press any key to go back";
    getch();
    system("cls");
    main();
    }


return 0;
}



bool overallwin(int scoreA, int scoreB, int z)  // function for the overall winner of the game
{
    if(z==3)
    {
        if (scoreB==2)
        {
            std::cout<<"overall winner is player2";
            getch();
            system ("cls");
            std::cout<<"Thanks For Playing!!!!";
            getch();
            return true;
        }
        else if (scoreA==2)
        {
            std::cout<<"overall winner is player1";
            getch();
            system ("cls");
            std::cout<<"Thanks For Playing!!!!";
            getch();
            return true;
        }
        return false;

    }

    //////////////////////////////////////////

    if(z==5)
    {
        if (scoreB==3)
        {
            std::cout<<"overall winner is player2";
            getch();
            system("cls");
            std::cout<<"Thanks for Playing!!!!";
            getch();
            return true;
        }
        else if (scoreA==3)
        {
            std::cout<<"overall winner is player1";
            getch();
            system("cls");
            std::cout<<"Thanks for Playing!!!!";
            getch();
            return true;
        }
        return false;

    }

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////                                              ////////////////////////////////////
///////////////////////////////below is the function to check the            ////////////////////////////////////
///////////////////////////////                 winner of the game           ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int checkWinner()
{

    if(square[1] == square[2] && square[2] == square[3] && square[1]=='X')
    {
        return 1;
    }
    else if(square[4] == square [5] && square [5] == square [6] && square[4]=='X')
    {
        return 1;
    }
    else if (square [7] == square [8] && square [8] == square[9] && square[7]=='X')
    {
        return 1;
    }
    else if(square [1] == square [4] && square [4] == square [7] && square [1]=='X')
    {
        return 1;
    }
    else if(square [2]== square[5] && square [5] == square [8] && square[2]=='X')
    {
        return 1;
    }
    else if(square [3] == square [6] && square [6] == square [9] && square[3]=='X')
    {
        return 1;
    }
    else if(square [1] == square [5] && square [5] == square [9] && square[1]=='X')
    {
        return 1;
    }
    else if(square[3] == square [5] && square [5] == square [7] && square[3]=='X')
    {
        return 1;
    }

     else if(square[1] == square[2] && square[2] == square[3] && square[1]=='O')
    {
        return 2;
    }
    else if(square[4] == square [5] && square [5] == square [6] && square[4]=='O')
    {
        return 2;
    }
    else if (square [7] == square [8] && square [8] == square[9] && square[7]=='O')
    {
        return 2;
    }
    else if(square [1] == square [4] && square [4] == square [7] && square[1]=='O')
    {
        return 2;
    }
    else if(square [2]== square[5] && square [5] == square [8] && square[2]=='O')
    {
        return 2;
    }
    else if(square [3] == square [6] && square [6] == square [9] && square[3]=='O')
    {
        return 2;
    }
    else if(square [1] == square [5] && square [5] == square [9] && square[1]=='O')
    {
        return 2;
    }
    else if(square[3] == square [5] && square [5] == square [7] && square[3]=='O')
    {
        return 2;
    }
    else if(square[1]!='1' && square [2]!= '2' && square [3]!= '3' && square[4]!= '4' && square[5]!= '5' && square[6]!= '6' && square[7]!= '7' && square[8]!= '8' && square[9]!= '9')
    {
        return 9000;
    }
    else
    {
        return 0;
    }

}

//This function draws the gameboard


void gameBoard()
{   system("cls");
    std::cout<<"Tic Tac Toe, Best out of "<< z <<std::endl;
    std::cout<<"Programmed by Shaka Kanenobu"<<std::endl;
    std::cout<<"Player 1-X: Player 2-O"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"score:"<<scoreA<<" : "<<scoreB<<std::endl;
    std::cout<<"    |    |    "<<std::endl;
    std::cout<<"  "<<square[1]<<"   "<<square[2]<<"    "<<square[3]<<"  "<<std::endl;
    std::cout<<"____|____|____"<<std::endl;
    std::cout<<"    |    |    "<<std::endl;
    std::cout<<"  "<<square[4]<<"   "<<square[5]<<"    "<<square[6]<<"  "<<std::endl;
    std::cout<<"____|____|____"<<std::endl;
    std::cout<<"    |    |    "<<std::endl;
    std::cout<<"  "<<square[7]<<"   "<<square[8]<<"    "<<square[9]<<"  "<<std::endl;
    std::cout<<"    |    |    "<<std::endl;
}
