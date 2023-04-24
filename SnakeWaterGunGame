# Snake , Water Game
import random

print("       -Welcome-    \n")

if __name__ == '__main__':
    attempts = 1
    your_point = 0
    computer_point = 0

    while (attempts <= 10):

        lst=["Snake", "Water", "Gun"]
        randomchoice = random.choice(lst)

        inp =input('''******Game Started********
Enter Your Choice 
******************************
1)Snake
2)Water
3)Gun
******************************
You Have 10 Chances!
:
    ''')
        if inp==randomchoice:
            print("Tie")
            print(f"You chose {inp} and computer guess is {randomchoice}")
            print("No body gets point\n")

        elif inp=="Snake" and randomchoice == "Water":
            your_point=your_point+1
            print(f"You choosed {inp} and computer guess is {randomchoice}")
            print("The snake drank water\n")
            print("You won this round")
            print("You got 1 point\n")


        elif inp=="Water" and randomchoice=="Snake":
            computer_point = computer_point + 1
            print(f"You choosed {inp} and computer guess is {randomchoice}")
            print("The snake drank water\n")
            print("You lost this round")
            print("Computer gets 1 point\n")

        elif inp=="Water" and randomchoice=="Gun":
            print(f"You chose {inp} and computer guess is {randomchoice}")
            your_point = your_point + 1
            print("The gun sank in water\n")
            print("You won this round")
            print("You got 1 point\n")

        elif inp == "Gun" and randomchoice == "Water":
            print(f"you choosed {inp} and computer guess is {randomchoice}")
            computer_point = computer_point + 1
            print("The gun sank in water\n")
            print("You Lost this round")
            print("computer gets 1 point\n")


        elif inp == "Gun" and randomchoice == "Snake":
            print(f"You choosed {inp} and computer guess is {randomchoice}")
            your_point = your_point + 1
            print("The snake was shot and it died\n")
            print("You won this round")
            print("You get 1 point\n")


        elif inp == "Snake" and randomchoice == "Gun":
            print(f"you choosed {inp} and computer guess is {randomchoice}")
            computer_point=computer_point+1
            print("The snake was shoot and he died\n")
            print("You lost this round")
            print("computer gets 1 point\n")


        else:
            print("Something Went Wrong! Please Try Again\n")
            continue

        print("No. of guesses left: {}".format(10 - attempts))
        attempts = attempts + 1

        if attempts>10:
            print("Game over!")

        if computer_point > your_point:
            print("Computer Won The Game!")

        elif computer_point < your_point:
            print("You Won The Game!")

        else:

            print("It was a tie!")
            print("invalid")

              if attempts > 10:
            print("game over")

    if computer_point > your_point:
        print("********************************************************************")
        print("Computer wins and you loose")

    if computer_point < your_point:
        print("********************************************************************")
        print("you win and the computer looses")

    print(f"your point is {your_point} and computer point is {computer_point}")
    print("********************************************************************")
