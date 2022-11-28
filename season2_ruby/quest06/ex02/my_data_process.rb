$data_dict = {}
$val_arr = []

def gender_vals(data)
    for i in data[0].split(',') do
        if i != 'FirstName' && i != 'LastName' && i != 'UserName'
            $data_dict[i] = {}
        end
    end
    data_values = data.slice(1, data.length+1)
    for values in data_values do
        $val_arr.append(values.split(','))
    end
    return $val_arr[1]
end

def my_data_process(data)
    gender_vals data
end

def run
    output= ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]
    puts my_data_process output
end

run
#arr2D = Array.new(2){Array.new(3)}
a= Hash.new
a[[1,2]]= 23
a[[5,6]]= 42
puts a