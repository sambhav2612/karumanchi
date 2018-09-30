class queue {
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
			return this.items.shift();
		else {
			console.warn("Stack underflow!");
			return -1;
		}
	}
	peek() {
		if (!this.isEmpty())
			return this.items[0];
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

var newQueue = new queue();
console.log(newQueue.print());
console.log(newQueue.isEmpty());
newQueue.add(1);
newQueue.add(2);
console.log(newQueue.peek());
newQueue.add(3);
newQueue.add(4);
console.log(newQueue.peek());
newQueue.add(5);
console.log(newQueue.delete());
console.log(newQueue.print());
console.log(newQueue.peek());