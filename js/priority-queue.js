/**
 * only difference is priority pushing onto queue by some parameter and depening on that the final sequence is determined
 */

(function () {
	'use strict';
}());

class pq {
	constructor() {
		var sequence = [];
		this.inqueue = function (value) {
			if (this.isEmpty()) {
				sequence.push(value);
			} else {
				var added = false;
				for (let i = 0; i < sequence.length; ++i) {
					// checking priority
					if (value[i] < sequence[i][1]) {
						// replace value in seqeunce starting from i and break from loop
						sequence.splice(i, 0, value);
						added = true;
						break;
					}
				}
				if (!added) {
					sequence.push(value);
				}
			}
			console.log("Pushed " + value + " to queue.");
		};
		this.dequeue = function () {
			var value = sequence.shift();
			return value[0];
		};
		this.len = function () {
			return sequence.length;
		};
		this.top = function () {
			return sequence[0];
		};
		this.isEmpty = function () {
			return (sequence.length === 0);
		};
		this.printer = function () {
			console.log("Traversing queue... \t first->" + sequence + "->last");
		};
	}
}

var obj = new pq();

// ["ITEM", PRIORITY]
obj.inqueue(["free", 1]);
obj.inqueue(["Code", 2]);
obj.inqueue(["Camp", 3]);
obj.inqueue(["Priority Queue Algo in JS", 1]);

console.log(obj.printer());

console.log("\n\"" + obj.dequeue() + "\" has been popped.");
console.log("Element at front is: " + obj.top());
console.log("Length of queue is:" + obj.len());
console.log(obj.printer());

console.log("\n\"" + obj.dequeue() + "\" has been popped.");
console.log("Element at front is: " + obj.top());
console.log("Length of queue is:" + obj.len());
console.log(obj.printer());

/*
do {
	console.log("MENU:");
	console.log("1. Push");
	console.log("2. Pop");
	console.log("3. Length");
	console.log("4. Peek");
	console.log("5. EXIT");
	console.log("Enter a choice: ");
	ch = prompt("")
} while( );*/