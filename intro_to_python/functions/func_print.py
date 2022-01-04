# func_print.py

# define the function
def sum_print(x,y):
    '''This function will sum
       x and y into a variable
       z and print z when the 
       function exits'''

    z = x + y        # the "body" that the function executes

    return print(z)  # what is done on function exit

# execute the function with x=3 and y=5
sum_print(x=3,y=5)
