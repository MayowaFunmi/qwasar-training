def add_values_to_result(result, key, value):
    if not value in result[key]:
        result[key][value] = 1
    else:
        result[key][value] += 1

def my_data_process():
    pass