a = 11/2
#puts a
def my_divmod(num, div)
    #res = divmod(num, div)
    quo = num / div
    rem = num % div
    res = [quo, rem]
    return res
end

x = my_divmod 11, 2
puts (x[1])

months = {1 => "January", 2 => "February"}
puts months.values
for key, val in months do
    puts val
end

time = Time.now
puts time
puts time.hour