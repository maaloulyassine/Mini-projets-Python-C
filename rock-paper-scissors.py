import random

# Function to determine the winner
def determine_winner(user_choice, computer_choice):
    if user_choice == computer_choice:
        return "draw"
    elif (user_choice == "rock" and computer_choice == "scissors") or \
         (user_choice == "scissors" and computer_choice == "paper") or \
         (user_choice == "paper" and computer_choice == "rock"):
        return "user"
    else:
        return "computer"

# Main game logic
user_score = 0
computer_score = 0
score_limit = 5

print("Welcome to Rock-Paper-Scissors! First to 5 points wins.")
options = ["rock", "paper", "scissors"]

while user_score < score_limit and computer_score < score_limit:
    user_choice = input("Enter your choice (rock, paper, scissors): ").lower()
    if user_choice not in options:
        print("Invalid choice. Try again.")
        continue
    
    computer_choice = random.choice(options)
    print(f"Computer chose: {computer_choice}")
    
    winner = determine_winner(user_choice, computer_choice)
    if winner == "user":
        user_score += 1
        print("You win this round!")
    elif winner == "computer":
        computer_score += 1
        print("Computer wins this round!")
    else:
        print("It's a draw!")
    
    print(f"Score - You: {user_score}, Computer: {computer_score}")

if user_score == score_limit:
    print("Congratulations! You won the game!")
else:
    print("Computer wins the game! Better luck next time.")