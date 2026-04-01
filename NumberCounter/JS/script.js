

// Constant variables are declared and mapped to their HTML counterparts

const increaseButton = document.getElementById("increaseButton");
const decreaseButton = document.getElementById("decreaseButton");
const resetButton = document.getElementById("resetButton");
const countLabel = document.getElementById("myCounter");

// Count set to starting value of 0

// Interval controls the repeating action

// Timeout controls the delay before repeating starts

// Interval and timeout set to null since nothing is currently happening at that moment

let count = 0;
let interval = null;
let timeout = null;

// Function to start the timers
function startHold(value){
    count += value; // Updates count immediately as soon as the user presses the button
    countLabel.textContent = count; 
    timeout = setTimeout(() => {    // Timeout waits 400ms before starting rapid changes so that count does not update too quickly
        interval = setInterval(() => {  // Interval runs every 80ms and keeps increasing/decreasing as long as the button is still held
            count += value;
            countLabel.textContent = count;
        }, 80);
    }, 400);
}

function stopHold(){ 
    clearTimeout(timeout); // Clears timeout and makes sure repeating never starts if user lets go before 400ms
    clearInterval(interval); // Stops the repeating if already started
    timeout = null;  // Timeout and interval set back to idle state
    interval = null;
}

increaseButton.addEventListener("mousedown", () => startHold(1)); // Applies startHold functions to the increase and decrease buttons
decreaseButton.addEventListener("mousedown", () => startHold(-1)); // Starts when mouse button is pressed down

increaseButton.addEventListener("mouseup", stopHold); // Applies stopHold functions to both buttons as well
increaseButton.addEventListener("mouseleave", stopHold); // Stops when mouse button either comes up or leaves the pressed element 
decreaseButton.addEventListener("mouseup", stopHold);
decreaseButton.addEventListener("mouseleave", stopHold);

resetButton.onclick = function reset (){  // Resets count back to 0 and updates the display
    count = 0;
    countLabel.textContent = count;
}

