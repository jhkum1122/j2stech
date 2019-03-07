//
console.log('Hello world\n')

var mysql = require('mysql');
var connection = mysql.createConnection({
	host : 'localhost',
	user : 'kum',
	password : '!@#qweasdzxc',
	port : '3306',
	database : 'test'
});

connection.connect();

connection.query('select * from ppp', function(err, rows, fields){
	if (!err)
		console.log('The solution is : ', rows);
	else
		console.log('Error while performing Query.', err);
});

connection.end();
