const fs = require('fs');

const rotations = fs.readFileSync('input.txt', 'utf8').trim().split('\n');

// Password = num of times the dial is left pointing at 0 after any rotation
let position = 50;
let number_of_starts = 0;
for (const rotation of rotations) {
    const direction = rotation[0];
    const rotation_amount = parseInt(rotation.slice(1));

    if (direction === 'L') {
        position -= rotation_amount;
    }
    else {
        position += rotation_amount;
    }

    position = ((position % 100) + 100) % 100;

    if (position === 0) {
        number_of_starts++;
    }
}

console.log("Number of times 0 was seen: ", number_of_starts);