def my_divmod(num, div):
    #res = divmod(num, div)
    quo = num // div
    rem = num % div
    res = (quo, rem)
    return res

def solve(num):
   res = ""
   table = [
      (1000, "M"),
      (900, "CM"),
      (500, "D"),
      (400, "CD"),
      (100, "C"),
      (90, "XC"),
      (50, "L"),
      (40, "XL"),
      (10, "X"),
      (9, "IX"),
      (5, "V"),
      (4, "IV"),
      (1, "I"),
   ]
   for fig, roman in table:
      #quo, rem = divmod(num, fig)
      quo, rem = my_divmod(num, fig)
      res += roman * quo
      num = rem

   return res

num = 500
print(solve(num))