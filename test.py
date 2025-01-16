import random
import os

good = []
bad = []

def tester(min, max):
    numbers = []
    while len(numbers) < max:  # Ensure we generate the correct number of elements
        i = random.randint(min, max)  # Adjusted range for numbers
        if i not in numbers:  # Ensure uniqueness of the numbers
            numbers.append(i)

    # Join numbers to a string for passing them to push_swap and checker_mac
    p = ' '.join(map(str, numbers))

    # Run push_swap and checker_mac to check if sorting is correct
    result = os.popen(f"./push_swap {p} | ./checker_mac {p}").read().strip()
    
    if result != "OK":
        print("--------------- Danger! The code failed ---------------")
        return  # Stop the test if failure occurs
    
    # Count the number of operations
    out = int(os.popen(f"./push_swap {p} | wc -l").read().strip())
    
    # Add the result to either good or bad list based on the number of operations
    if out < 5501:
        good.append(out)
    else:
        bad.append(out)
    
    # Print the current number of operations and success/failure rate
    success_rate = (len(good) / (len(good) + len(bad))) * 100 if (len(good) + len(bad)) > 0 else 0
    print(f"Operations: {out}, Success Rate: {success_rate:.2f}%", result)

# Run the tests in a loop (with a limited number of iterations for safety)
max_tests = 100  # Example limit for 100 tests
for _ in range(max_tests):
    tester(0, 500)  # You can adjust the range of numbers to test



# $>./checker 3 2 1 0
# rra
# pb
# sa
# rra
# pa
# OK
# $>./checker 3 2 1 0
# sa
# rra
# pb
# KO
# $>./checker 3 2 one 0
# Error
# $>./checker "" 1
# Erro