(function () {
	'use strict';
}());

class stack {
	constructor() {
		this.count = 0;
		this.sequence = {};
		this.push = function (value) {
			this.sequence[this.count] = value;
			this.count++;
			console.log("Pushed " + value + " to stack.");
		};
		this.pop = function () {
			if (this.count == 0) {
				return undefined;
			}
			this.count--;
			var res = this.sequence[this.count];
			delete this.sequence[this.count];
			return res;
		};
		this.len = function () {
			return this.count;
		};
		this.top = function () {
			return this.sequence[this.count - 1];
		};
		this.counter = function () {
			return this.count;
		};
		this.printer = function () {
			console.log("Traversing queue... \t" + this.sequence);
		};
	}
}

var obj = new stack();

obj.push(5);
obj.push(4);
obj.push("free");
obj.push(3);
obj.push(2);
obj.push("Code");
obj.push(1);
obj.push(0);
obj.push("Camp");

console.log("\nCount value is: " + obj.counter());
console.log("\"" + obj.pop() + "\" has been popped.");
console.log("Element at top is: " + obj.top());
console.log("Length of stack is:" + obj.len());
console.log(obj.printer());

console.log("\nCount value is: " + obj.counter());
console.log(obj.pop() + " has been popped.");
console.log("Element at top is: " + obj.top());
console.log("Length of stack is:" + obj.len());
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