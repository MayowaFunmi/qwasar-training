import sys
import random

#print(sys.argv[0])

words = ['rainbow', 'computer', 'science', 'programming', 'python', 'mathematics', 'player', 'condition','reverse', 'water', 'board', 'geeks']

word = random.choice(words)
print(word)

trials = 7
guesses = ''

while trials > 0:
    strike = 0

    for char in word:
        if char in guesses:
            print(char, end="")
        else:
            print("_", end="")
            strike += 1
    if strike == 0:
        print("word = ", word)
        break
    print()
    guess = input("guess a character: ")
    guesses += guess

    if not guess in word:
        trials -= 1
        print("wrong character")
        if trials == 0:
            print('you loose')