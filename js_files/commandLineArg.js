args = process.argv.slice(2)

index = 0

while (index < args.length) {
    console.log(args[index])
    index++
}

function my_first_script_with_args() {
    args = process.argv.slice(2)
    for (let i = 0; i < args.length;) {
        console.log(args[i])
        i++;
    }
}
console.log(my_first_script_with_args())