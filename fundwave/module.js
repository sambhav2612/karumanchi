function rectangle() {
	var length;
	var width;

	function create(x, y) {
		length = x;
		width = y;
	}
	function getArea() {
		return (length * width);
	}
	function getPerimeter() {
		return (2 * (length + width));
	}
	var publicAPI = {
		create: create,
		getArea: getArea,
		getPerimeter: getPerimeter
	};
	return publicAPI;
}

var rect = rectangle();
rect.create(10, 20);
console.log(rect.getArea(), rect.getPerimeter());