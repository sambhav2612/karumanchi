var school = {
	"name": "LFPS",
	"year": "1880",
	"loca": "home",
	"info": function () {
		return this.name + " " + this.year + " " + this.loca;
	}
}

console.log(school.info());
var boy = Object.create(school);
console.log(boy.info());

function person(name, add, id) {
	this.name = name;
	this.add = add;
	this.id = id;
	this.print = function () {
		return this.name + " " + this.add + " " + this.id;
	}
}

var obj = new person("Sambhav Jain", "Shahdara", "16533");
console.log(obj.print());
var obj2 = Object.create(new person("Varsha Aggarwal", "Ganga Vihar", "16543"));
console.log(obj2.print());
