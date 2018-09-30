function add(a, b, callback) {
	console.log(a + b);
	callback();
};

add(100000,
	100000,
	function disp() {
		console.log("Added!");
	});