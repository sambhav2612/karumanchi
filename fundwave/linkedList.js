class node {
	constructor(element) {
		this.element = element;
		this.next = null;
	}
}

class list {
	constructor() {
		this.head = null;
		this.size = 0;
	}
	add(element) {
		var newNode = new node(element);
		var current;

		if (this.head == null)
			this.head = newNode;
		else {
			current = this.head;
			while (current.next)
				current = current.next;
			current.next = newNode;
		}
		this.size++;
		console.log(element + " inserted!");
	}
	addAt(element, pos) {
		var newNode = new node(element);
		var current, prev, k = 0;
		if (pos === 0) {	// empty and at one
			newNode.next = this.head;
			this.head = newNode;
		}
		else {
			current = this.head;
			while (k < pos) {
				k++;
				prev = current;
				current = current.next;
			}
			prev.next = newNode;
			newNode.next = current;
		}
		this.size++;
		console.log(element + " inserted at " + pos + "!");
	}
	deleteFrom(index) {
		var current = this.head, prev = current, k = 0;
		if (this.isEmpty()) {
			console.warn("List underflow!");
			return -1;
		} else {
			if (index === 0) {
				this.head = current.next;
			} else {	
				while (k < index) {
					k++;
					prev = current;
					current = current.next;
				}
				prev.next = current.next;
			}
			this.size--;
			return current.element;
		}
	}
	isEmpty() {
		return (this.size === 0);
	}
	printList() {
		if (!this.isEmpty()) {
			var current = this.head, str = "";
			while (current) {
				str += current.element + " ";
				current = current.next;
			}
			return str;
		} else {
			console.warn("List underflow!");
			return -1;
		}
	}
}

var newList = new list();
console.log(newList.isEmpty());
newList.add(1);
console.log(newList.printList());
newList.add(2);
console.log(newList.isEmpty());
newList.add(3);
console.log(newList.printList());
newList.add(4);
console.log(newList.isEmpty());
newList.add(5);
newList.addAt(10, 2);
console.log(newList.deleteFrom(2));
console.log(newList.printList());