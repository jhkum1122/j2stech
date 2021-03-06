#include <cpprest/http_listener.h>
#include <cpprest/json.h>


//cpprest provides macros for all streams but std::clog in basic_types.h
//
#ifdef _UTF16_STRINGS
//on windows, all strings are wide
//
#define uclog std::wclog
#else
//on Posix platforms, all strings are narrow
//
#define uclog std::clog
#endif		//endif _UTF16_STRINGS

using namespace std;
using namespace web::http::experimental::listener;
using namespace web:http;
using namespace web;

void respond(const http_request& request, const status_code& status, const json::value& response) {
	json::value resp;
	resp[U("status")] = json::value::number(status);
	resp[U("response")] = response;

	//pack in the current time for debugging purpises
	time_t now = time(0);
	utility::stringstream_t ss;
	ss << put_time(localtime(&now), L"%Y-%M-%dT%H:%S:%MZ");
	resp[U("server_time")] = json::value::string(ss.str());

	request.reply(status, resp);
}

int main() {
	//synchronously bind the listener to all nics.
	uclog << U("Starting listener.") << endl;
	http_listener listener(U("http://*/json"));
	listener.open().wait();

	//Handle incoming requests
	uclog << U("Setting up JSON listener") << endl;
	listener.support(methods::GET, [](http_request req)) {
		auto http_get_vars = uri::split_query(req.request_uri().query());
		auto found_name = http_get_vars.find(U("request"));

		if(found_name == end(http_get_vars)) {
			auto err = U("Request reveived with get var \"request\" ommitted from query.");
			uclog << err << endl;
			respond(req, status_codes::BadRequest, json::value::string(err));

			return;
		}

		auto request_name = found_name->second;
		uclog << U("Received request: ") << request_name << endl;
		respond(req, status_codes::OK, json::value::string(U("Request received for:") + request_name));

	});


	//wait while  the listener does the heavy lifting.
	//TODO : Provide a way to safely terminate this loop.
	uclog << U("Waiting for incoming connection...") << endl;

	while (true) {
		this_thread::sleep_for(chrono::milliseconds(2000));
	}

	//Nothing left to do but commit suicide
	uclog << U("Terminating JSON listener.") << endl;

	listener.close();

	return 0;
}
