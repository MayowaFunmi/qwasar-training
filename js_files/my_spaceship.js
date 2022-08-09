function my_spaceship(string) {
    let cur_pos = 'up'
    let x_coord = 0
    let y_coord = 0

    for (let i = 0; i < string.length; i++) {
        if (string[i] === 'R') {
            if (cur_pos === 'up') {
                cur_pos = 'right'
            } else if (cur_pos === 'left') {
                cur_pos = 'up'
            } else if (cur_pos === 'down') {
                cur_pos = 'left'
            } else {
                cur_pos = 'down'
            }
        } else if (string[i] === 'L') {
            if (cur_pos === 'up') {
                cur_pos = 'left'
            } else if (cur_pos === 'left') {
                cur_pos = 'down'
            } else if (cur_pos === 'down') {
                cur_pos = 'right'
            } else {
                cur_pos = 'up'
            }
        } else if (string[i] === 'A') {
            if (cur_pos === 'up') {
                y_coord--
            } else if (cur_pos === 'left') {
                x_coord--
            } else if (cur_pos === 'down') {
                y_coord++
            } else {
                x_coord++
            }
        }
    }
    return `{x: ${x_coord}, y: ${y_coord}, direction: '${cur_pos}'}`
}

console.log(my_spaceship('RAARA'))