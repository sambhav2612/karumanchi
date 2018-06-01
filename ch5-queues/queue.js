'use strict';

var queue = function () {
	var sequence = [];

	this.inqueue = function (value) {
		sequence.push(value);

		console.log("Pushed " + value + " to queue.")
	}

	this.dequeue = function () {
		return sequence.shift();
	}

	this.len = function () {
		return sequence.length;
	}

	this.top = function () {
		return sequence[0];
	}

	this.isEmpty = function () {
		return (sequence.length === 0);
	}

	this.printer = function () {
		console.log("Traversing queue... \t first->" + sequence + "->last");
	}
}

var obj = new queue();

obj.inqueue(5);
obj.inqueue(4);
obj.inqueue("free");
obj.inqueue(3);
obj.inqueue(2);
obj.inqueue("Code");
obj.inqueue(1);
obj.inqueue(0);
obj.inqueue("Camp");

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