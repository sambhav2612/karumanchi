(function () {
	'use strict';
}());

class set {
	constructor() {
		var collection = [];
		var index;

		this.has = function (element) {
			return (collection.indexOf(element) !== -1);
		};
		this.values = function () {
			return collection;
		};
		this.add = function (element) {
			if (!this.has(element)) {
				collection.push(element);
				return true; // pushed
			}
			return false; // not pushed
		};
		this.remove = function (element) {
			if (!this.has(element)) {
				index = collection.indexOf(element);
				// take out one element from index
				collection.splice(index, 1);
				return true; // removed
			}
			return false; // not removed
		};
		this.size = function () {
			return collection.length;
		};
		this.union = function (someSet) {
			var unionSet = new set();
			// get values to make union
			var firstSet = this.values();
			var secondSet = someSet.values();
			firstSet.forEach(function (e) {
				unionSet.add(e);
			});
			secondSet.forEach(function (e) {
				unionSet.add(e);
			});
			return unionSet;
		};
		this.intersection = function (someSet) {
			var intersectionSet = new set();
			// get values to make union
			var firstSet = this.values();
			firstSet.forEach(function (e) {
				if (someSet.has(e)) {
					intersectionSet.add(e);
				}
			});
			return intersectionSet;
		};
		this.difference = function (someSet) {
			var defferenceSet = new set();
			// get values to make union
			var firstSet = this.values();
			firstSet.forEach(function (e) {
				if (!someSet.has(e)) {
					differenceSet.add(e);
				}
			});
			return differenceSet;
		};
		this.subset = function (someSet) {
			// get values to make union
			var firstSet = this.values();
			return firstSet.every(function (e) {
				return someSet.has(e);
			});
		};
	}
}

var setA = new set();
var setB = new set();

setA.add('a');
setB.add('a');
setB.add('a');
setA.add('c');
setA.add('d');
setA.add('b');
setB.add('c');

console.log(setA.subset(setB)); // false
console.log(setB.subset(setA)); // true