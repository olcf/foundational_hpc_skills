# cake_solution.py

# Set up lists
real_cake = ['portal', 'the cake', 'is', 'not', 'a lie', '!', 'hl3']
fake_cake = ['the cake', 'is', 'a lie', '!']

# Manipulate real_cake to match fake_cake
test_cake = real_cake[1:3] + real_cake[4:6]

# Check to see if you are correct
print('real cake:', real_cake)
print('fake cake:', fake_cake)
print('test cake:', test_cake)

if test_cake == fake_cake:
    print('Success!')
else:
    print('Try again!')
    print('Fake cake should equal test cake')
