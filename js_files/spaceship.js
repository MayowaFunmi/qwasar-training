function my_spaceship(flight_instruction) {
    const instructions = Array.from(flight_instruction);
    let x_coord = 0;
    let y_coord = 0;
    let orientation = 'up'
    instructions.forEach((element, index) => {
        switch (element) {
            case 'A':
                if (index) {
                    switch (orientation) {
                        case 'right':
                            x_coord++;
                            break;
                        case 'left':
                            x_coord--;
                            break;
                        case 'down':
                            y_coord++;
                            break;
                        case 'up':
                            y_coord--;
                            break
                        default:
                            break;
                    }
                } else {
                    y_coord--;
                }
                break;
            case 'R':
                switch (orientation) {
                    case 'right':
                        orientation = 'down';
                        break;
                    case 'left':
                        orientation = 'up';
                        break;
                    case 'down':
                        orientation = 'left';
                        break;
                    case 'up':
                        orientation = 'right';
                        break;
                    default:
                        break;
                }
                break;
            case 'L':
                switch (orientation) {
                    case 'right':
                        orientation = 'up';
                        break;
                    case 'left':
                        orientation = 'down';
                        break;
                    case 'down':
                        orientation = 'right';
                    case 'up':
                        orientation = 'left';
                        break;
                    default:
                        break;
                }
                break
            default:
                break;
        }
    });

    return `{x: ${x_coord}, y: ${y_coord}, direction: '${orientation}'}`
}

console.log(my_spaceship('RRALLA'))