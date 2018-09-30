class stack {
	constructor() {
		this.items = [];
		this.size = 0;
	}
	isEmpty() {
		return (this.size === 0);
	}
	add(element) {
		this.items.push(element);
		this.size++;
		console.log(element + " inserted!");
	}
	delete() {
		this.size--;
		if (!this.isEmpty())
			return this.items.pop();
		else {
			console.warn("Stack underflow!");
			return -1;
		}
	}
	peek() {
		if (!this.isEmpty())
			return this.items[this.size - 1];
		else {
			console.warn("Stack underflow!");
			return -1;
		}
	}
	print() {
		if (!this.isEmpty()) {
			var str = "";
			for (var x = 0; x < this.size; ++x)
				str += this.items[x] + " ";
			return str;
		}
		else {
			console.warn("Stack underflow!");
			return -1;
		}
	}
}

var newStack = new stack();
console.log(newStack.print());
console.log(newStack.isEmpty());
newStack.add(1);
newStack.add(2);
console.log(newStack.peek());
newStack.add(3);
newStack.add(4);
console.log(newStack.peek());
newStack.add(5);
console.log(newStack.delete());
console.log(newStack.print());
console.log(newStack.peek());