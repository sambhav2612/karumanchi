var person = {
	firstName : "Sumit",
	lastName : "Ghosh",
	getDetails : function() {
		return this.firstName + " " + this.lastName;
	}
};

console.log(person.getDetails());

class personn {
	constructor (first, last) {
		this.firstName = first;
		this.lastName = last;
	}
	getDetails() {
		return this.firstName + " " + this.lastName;
	}
}

var person1 = new personn("Varsha", "Aggarwal");
console.log(person1.getDetails());

function employee (name, number) {
	this.Ename = name;
	this.Enumber = number;
};

employee.prototype.getDetails = function () {
	return this.Ename + "\n" + this.Enumber;
}

var emp = new employee("Sambhav Jain", "16533 <3 16543");
console.log(emp.getDetails());