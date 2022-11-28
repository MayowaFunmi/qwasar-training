from datetime import datetime

Output= ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]

global data_dict
global val_arr
global result
data_dict = {}
val_arr = []
result = []

def transform_age(age):
    if age < 21:
        return "1->20"
    elif age < 41:
        return "21->40"
    elif age < 66:
        return "41->65"
    else:
        return "66->90"

def transform_email(email):
    return email.split('@')[1]

def transform_time_range(time):
    datetime_object = datetime.strptime(time, "%Y-%m-%d %H:%M:%S")
    if datetime_object.hour < 12:
        return "morning"
    if datetime_object.hour < 18:
        return "afternoon"
    else:
        return 'evening'

def add_values_to_result(result, key, value):
    if not value in result[key]:
        result[key][value] = 1
    else:
        result[key][value] += 1

def gender_vals(data):
    for i in data[0].split(','):
        if i != 'FirstName' and i != 'LastName' and i != 'UserName':
            data_dict[i] = {}
    data_values = data[1:]
    #print('data_values = ', data_values)
    for values in data_values:
        val_arr.append(values.split(','))
    #print(val_arr)
    male_count = sum(x.count("Male") for x in val_arr)
    female_count = sum(x.count("Female") for x in val_arr)
    data_dict['Gender']['Male'] = male_count
    data_dict['Gender']['Female'] = female_count
    return
    
def email_vals():
    yahoo_count = sum(x.count("yahoo.com") for x in val_arr)
    hotmail_count = sum(x.count("hotmail.com") for x in val_arr)
    data_dict["Email"]["yahoo"] = yahoo_count
    data_dict["Email"]["hotmail"] = hotmail_count
    return
    """  
    for each in val_arr:
        mail_arr = each[4].split(".")
    """
    
def age_vals():
    age1_count = sum(x.count("21->40") for x in val_arr)
    age2_count = sum(x.count("41->65") for x in val_arr)
    age3_count = sum(x.count("66->90") for x in val_arr)
    data_dict["Age"]["21->40"] = age1_count
    data_dict["Age"]["41->65"] = age2_count
    data_dict["Age"]["66->90"] = age3_count
    return
    
def city_vals():
    city = []
    [city.append(val[6]) for val in val_arr]
    city_set = []
    [city_set.append(x) for x in city if x not in city_set]
    for i in city_set:
        data_dict["City"][i] = city.count(i)

def device_vals():
    device = []
    [device.append(val[7]) for val in val_arr]
    dev_set = []
    [dev_set.append(x) for x in device if x not in dev_set]
    for i in dev_set:
        data_dict["Device"][i] = device.count(i)
        
def coffee_vals():
    coffee = []
    [coffee.append(val[8]) for val in val_arr]
    coffee_set = []
    [coffee_set.append(x) for x in coffee if x not in coffee_set]
    for i in coffee_set:
        data_dict["Coffee Quantity"][i] = coffee.count(i)

def order_vals():
    order = []
    [order.append(val[9]) for val in val_arr]
    order_set = []
    [order_set.append(x) for x in order if x not in order_set]
    for i in order_set:
        data_dict["Order At"][i] = order.count(i)
   
def my_data_process(data):
    #data_dict = {}
    #val_arr = []
    gender_vals(data)
    email_vals()
    age_vals()
    city_vals()
    device_vals()
    coffee_vals()
    order_vals()
    return data_dict

def my_data_transform(csv_content):
    #result = []
    line_number = 0
    for line in csv_content.split("\n"):
        values = line.split(',')
        if len(values) > 1 and line_number > 0:
            values[4] = transform_email(values[4])
            values[5] = transform_age(int(values[5]))
            values[9] = transform_time_range(values[9])
        line_number += 1
        if len(values) > 1:
            result.append(','.join(values))
    print("result = ", result)
    return my_data_process(result)

def run():
    csv_content = "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
    print(my_data_transform(csv_content))

run()

"""
Input: "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
Output: ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]
"""