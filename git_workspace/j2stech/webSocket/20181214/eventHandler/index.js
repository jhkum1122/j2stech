// event module 사용

var events = require('events');

//eventEmitter 객체 생성
var eventEmitter = new events.EventEmitter();

//eventHandler 함수 생성
var connectHandler = function connected() {
	console.log("Connection Success");	
	//data_recevied 이벤트를 발생시킴
	eventEmitter.emit("data_received");
}

//connection 이벤트와 connectHandler이벤트 핸들러 연동
eventEmitter.on('connection',connectHandler);

//data_received 이벤트와 익명 함수와 연동

//함수를 변수안에 담는 대신에 , .on()메소드의 인자로 직접 함수를 전달
eventEmitter.on('data_received',function(){ console.log("Data Received");});

//connection 이벤트 발생시키기
eventEmitter.emit('connection');

console.log("Program has ended");
