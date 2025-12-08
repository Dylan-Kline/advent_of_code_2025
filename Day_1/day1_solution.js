const fs = require('fs');

const rotations = fs.readFileSync('input.txt', 'utf8').trim().split('\n');

// Password = num of times the dial passes 0 during and after rotations
let position = 50;
let number_of_zero = 0;
for (const rotation of rotations) {
    const direction = rotation[0];
    const rotation_amount = parseInt(rotation.slice(1));

    if (direction === 'L') {
        if (position === 0) {
            number_of_zero += Math.floor(rotation_amount / 100);
        } else if (rotation_amount >= position) {
            number_of_zero += Math.floor((rotation_amount - position) / 100) + 1;
        }
        position -= rotation_amount;
    }
    else {
        number_of_zero += Math.floor((position + rotation_amount) / 100);
        position += rotation_amount;
    }

    position = ((position % 100) + 100) % 100;

}

console.log("Number of times 0 was seen: ", number_of_zero);