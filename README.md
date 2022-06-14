# CityU-Bridge_Game
The code used for the institution's the 3rd question of 3rd assignment, which is a library borrowing system
# Technique(s) used
1. Class
2. Class array
3. Class function that takes in other class's object(s)
4. Pointer 
# Function(s)
1. Rules of playing: The winner of the previous round goes first (human starts first at 1st round) -> 2nd player play cards (has same suit as the first player: must play a card of that suit/ does not have same suit: play any card)
2. Rules for winning: the one with a larger number wins (A being the largest) if 2nd player has the same suit: must play a card of that suit/ 2nd player loses no matter what if 2nd player does not have the same suit
3. Repeat until all cards are played without reusing them
4. CPU pattern: plays the card with he highest number in its card sequence if the CPU goes first/ plays the card that has the largest number if the CPU has the same suit/ plays the card that has the smallest number if the CPU does not have the same suit
# Reminder(s)
1. Skeleton code was provided
2. This is a single player game and the deck used by the CPU is fixed
3. In some particular situations, the program will not work as intended (9/10 test cases correct)
