# func_var.py

def sum_var(x,y):
    '''This function will sum
       x and y into a variable
       z and return the variable z
       when the function exits'''

    z = x + y

    return z

# Example 8.1: execute the function without saving the result
sum_var(3,5)

# Example 8.2: execute the function while saving result to a variable
test = sum_var(3,5)
print(test)
