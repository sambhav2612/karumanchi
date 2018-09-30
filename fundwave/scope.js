var x = "hello 1";

function func() {
	x = "hello 2";
	console.log(x);
}

func();
console.log(x);

var person = function () {
	var name = "Sambhav Jain";
	return {
		getName : function () {
			return name;
		},
		setName : function (newName) {
			name = newName;
		}
	};
}();

console.log(person.name);
console.log(person.getName());
console.log(person.setName("Varsha Aggarwal"));
console.log(person.getName());

// $ node scope.js
// hello 2
// hello 2