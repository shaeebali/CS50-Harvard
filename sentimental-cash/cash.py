# TODO - import from cs50 library
from cs50 import get_float

# To declare needed variables
change = 0
count = 0

# Add some basic validation using while loop
while change <= 0:
    change = get_float('Change owed: ')

# Make value close to round number as possible
cents = round(change * 100)

# While loop to calculate change from greatest coin to least
while cents > 0:
    if cents >= 25:
        cents -= 25
        count += 1
    elif cents >= 10:
        cents -= 10
        count += 1
    elif cents >= 5:
        cents -= 5
        count += 1
    elif cents >= 1:
        cents -= 1
        count += 1

# Print the amount of change
print(count)
