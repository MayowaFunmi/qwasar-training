def my_divmod(num, div):
    #res = divmod(num, div)
    quo = num // div
    rem = num % div
    res = (quo, rem)
    return res

num = int(input("Enter Number: "))
div = int(input("Enter Divisor: "))

print(my_divmod(num, div))

"""
print(5/2)  # 2.5
print(5//2) # 2 quotient
print(5%2)  # 1 remainder
"""