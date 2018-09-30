function foo(x) {
	function inner(y) {
		return (x + y);	
	};
	return inner;
};

var get_inner = foo(5);

console.log(get_inner(4));
console.dir(get_inner(3));

function outer() {
	var array = [];
	var i;
	for (i = 0; i < 4; ++i)
		array[i] = function() {
			return i;
		}
	return array;
}

var get_outer = outer();

console.log(get_outer[0]());