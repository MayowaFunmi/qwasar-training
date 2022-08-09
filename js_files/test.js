let string1 = 'jroke'
let string2 = 'trek'

function levenshteinDistance(string1, string2) {
    const row = Array(string2.length + 1).fill(null)
    const column = Array(string1.length + 1).fill(null)
    const matrix = row.map(() => column)
    console.log(matrix)

    for (let i = 0; i <= string1.length; i += 1) {
        matrix[0][i] = i
    }
    for (let j = 0; j <= string2.length; j += 1) {
        matrix[j][0] = j
    }
    //console.log(matrix)

    for (let j = 1; j < string2.length + 1; j++) {
        for (let i = 1; i < string1.length + 1; i++) {
            const check = string1[i - 1] === string2[j - 1] ? 0 : 1;
            matrix[j][i] = Math.min(
                matrix[j][i - 1] + 1, // delete
                matrix[j - 1][i] + 1, //insert
                matrix[j - 1][i - 1] + check, //replace
            )
        }
    }
    return matrix[string2.length][string1.length]
}

console.log(levenshteinDistance(string1, string2))