require 'date'

def transform_age(age)
    if age < 21
        return "1->20"
    elsif age < 41
        return "21->40"
    elsif age < 66
        return "41->65"
    else
        return "66->99"
    end
end

def transform_email(email)
    return email.split('@')[1]
end

def transform_time(time)
    #time = Time.now
    time_object = DateTime.parse(time, '%Y-%m-%d %H:%M:%S')
    if time_object.hour < 12
        return 'morning'
    elsif time_object.hour < 18
        return 'afternoon'
    else
        return 'evening'
    end    
end

def my_data_transform(csv_content)
    res = []
    line_number = 0
    for line in csv_content.split("\n") do
        content = line.split(",")
        if content.length > 1 && line_number > 0
            content[4] = transform_email content[4]
            content[5] = transform_age content[5].to_i
            content[9] = transform_time content[9]
        end
        line_number += 1
        if content.length > 1
            res.append(content.join(','))
        end
    end
    return res
end

def run
    csv_content = "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
    puts my_data_transform csv_content
end

run

#time = DateTime.parse('2020-03-05 15:19:48', '%Y-%m-%d %H:%M:%S')
#puts time.hour
#x = Time.now
#puts x