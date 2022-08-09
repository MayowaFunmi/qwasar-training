function getDistance(string1, string2) {
    const grid = [];
    for (let i = 0; i < string1.length + 1; i++) {
        const row = []
        for (let j = 0; j < string2.length + 1; j++) {
            row.push(j)
        }
        row[0] = i
        grid.push(row)
    }

    console.log(grid)
    for (let i = 1; i < string1.length; i++) {
        for (let j = 1; j < string2.length; j++) {
            // check if string1 value = string2 value at the current index
            if (string1[i - 1] === string2[j - 1]) {
                grid[i][j] = grid[i - 1][j - 1]
            } else {
                grid[i][j] = 1 + Math.min(grid[i - 1][j - 1], grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }
    console.log(grid)
    return grid[string1.length][string2.length]
}

console.log(getDistance('hitting', 'kitten'))