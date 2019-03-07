//
console.log('Hello world\n')

var myArray = [1,2,3];

function myCallback(element) {
	console.log(element);
}

$("#myButton").on("click", function(){
	console.log("clicked");
});

myArray.forEach(myCallback);


