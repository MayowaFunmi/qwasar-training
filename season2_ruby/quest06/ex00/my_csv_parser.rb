def my_csv_parser(csv_content, separator)
    result = []
    for line in csv_content.split("\n")
        row = line.split(separator)
        if row.length > 1
            result.append(row)
        end
    end
    return result
end