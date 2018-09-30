class person {
	constructor(name) {
		this.name = name;
	}
	getName() {
		return this.name;
	}
}

class child extends person {
	constructor(name, id) {
		super(name);
		this.id = id;
	}
	getDetails() {
		return super.getName() + " and " + this.id;
	}
}

var p1 = new child("Sambhav Jain", "16533");
console.log(p1.getDetails());