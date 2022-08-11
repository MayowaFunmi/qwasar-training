function my_fibonacci(value) {

    if (value < 0) return -1;


    var i;
    var ini_array = [0, 1]; // Initialize array!
    var result;

    for (i = 2; i <= value; i++) {

        //update initial array at the current position to previous + one before previous
        ini_array[i] = ini_array[i - 2] + ini_array[i - 1];
        result = ini_array[i];

    }

    return result;


}