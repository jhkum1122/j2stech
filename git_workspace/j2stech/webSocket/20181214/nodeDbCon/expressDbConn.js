var mysql = require('mysql');

var conn = mysql.createConnection({
	host : 'localhost',
	user : 'kum',
	password : '!@#qweasdzxc',
	port : '3306',
	database : 'test'
});

conn.connect();

conn.query('select * from ppp', function(err, rows, fields){
	if(!err)
		console.log('Source : ' , rows);
	else
		console.log('Error : '. err);

});

conn.end();
