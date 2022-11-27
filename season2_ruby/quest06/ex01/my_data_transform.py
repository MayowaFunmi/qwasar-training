from datetime import datetime

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
Output= ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]
def my_data_process(data):
    data_dict = {}
    val_arr = []
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
    return data_dict

def my_data_transform(csv_content):
    result = []
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
    #return result
    return my_data_process(result)




def run():
    csv_content = "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
    print(my_data_transform(csv_content))

run()

"""
Input: "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
Output: ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]
"""