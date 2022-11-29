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
    gender = []
    for val in $val_arr do
        gender.append(val[0])
    end
    # r = [$val_arr.select{|val|}.append(val)]
    $data_dict["Gender"]["Male"] = gender.count("Male")
    $data_dict["Gender"]["Female"] = gender.count("Female")
    return $data_dict
end

def email_vals
    emails = []
    for val in $val_arr do
        emails.append(val[4])
    end
    $data_dict["Email"]["yahoo"] = emails.count("yahoo.com")
    $data_dict["Email"]["hotmail"] = emails.count("hotmail.com")
    return
end

def age_vals
    ages = []
    for val in $val_arr do
        ages.append(val[5])
    end
    $data_dict["Age"]["21->40"] = ages.count("21->40")
    $data_dict["Age"]["41->65"] = ages.count("41->65")
    $data_dict["Age"]["66->99"] = ages.count("66->99")
    return
end

def city_vals
    cities = []
    for val in $val_arr do
        cities.append(val[6])
    end
    $data_dict["City"]["Seattle"] = cities.count("Seattle")
    $data_dict["City"]["Detroit"] = cities.count("Detroit")
    $data_dict["City"]["Las Vegas"] = cities.count("Las Vegas")
    $data_dict["City"]["Chicago"] = cities.count("Chicago")
    return
end

def device_vals
    devices = []
    device_set = []
    for val in $val_arr do
        devices.append(val[7])
    end
    device_set = devices.uniq
    for i in device_set do
        $data_dict["Device"][i] = devices.count(i)
    end
end

def coffee_vals
    coffee = []
    coffee_set = []
    for val in $val_arr do
        coffee.append(val[8])
    end
    coffee_set = coffee.uniq
    for i in coffee_set do
        $data_dict["Coffee Quantity"][i] = coffee.count(i)
    end
end

def order_vals
    order = []
    order_set = []
    for val in $val_arr do
        order.append(val[9])
    end
    order_set = order.uniq
    for i in order_set do
        $data_dict["Order At"][i] = order.count(i)
    end
end

def my_data_process(data)
    gender_vals data
    email_vals
    age_vals
    city_vals
    device_vals
    coffee_vals
    order_vals
    return $data_dict
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