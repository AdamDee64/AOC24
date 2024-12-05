const fs = require('fs')

fs.readFile('input.txt', 'utf8', (err, data) => {
    if(err) {
        console.log("file open error message D:")
    }

    let part1 = data.match(/mul\(\d+,\d+\)/g)
    let total1 = 0

    for (let i = 0; i < part1.length; i++){
        sort = part1[i].match(/\d+/g)
        x = sort[0] * 1
        y = sort[1] * 1

        total1 += x * y
    }

    let part2 = data.match(/mul\(\d+,\d+\)|do\(\)|don't\(\)/g)
    let total2 = 0
    let active = true

    for (let i = 0; i < part2.length; i++){
        if (part2[i] == 'do()') {
            active = true
        }
        if (part2[i] == 'don\'t()') {
            active = false
        }
        if (active == true) {
            sort = part2[i].match(/\d+/g)
                if (sort != null){
                    x = sort[0] * 1
                    y = sort[1] * 1
            
                    total2 += x * y
                }
        }
    }

    console.log(total1) //part 1 answer

    console.log(total2) //part 2 answer

})

