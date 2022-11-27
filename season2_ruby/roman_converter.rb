def my_divmod(num, div)
    #res = divmod(num, div)
    quo = num / div
    rem = num % div
    res = [quo, rem]
    return res
end

def my_roman_numerals_converter(num)
    res = ""
    rom_fig = {1000 => "M", 900 => "CM", 500 => "D", 400 => "CD", 100 => "C", 90 => "XC", 50 => "L", 40 => "XL", 10 => "x", 9 => "IX", 5 => "V", 4 => "IV", 1 => "I" }
    for fig, roman in rom_fig do
        get_mod = my_divmod num, fig
        quo = get_mod[0]
        rem = get_mod[1]
        res += roman * quo
        num = rem
    end
    return res
end

num = 901
puts my_roman_numerals_converter num