#include<iostream>
#include "CaesarCip.h"
#include "httplib.h"
using namespace std;

int main() {
	httplib::Server svr;

	//handler definition for OPTIONS requests
	svr.set_pre_routing_handler([](const httplib::Request& req, httplib::Response& res) {
		if (req.method == "OPTIONS") {
			res.set_header("Access-Control-Allow-Origin", "*");
			res.set_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
			res.set_header("Access-Control-Allow-Headers", "Content-Type");
			res.status = 200;
			return httplib::Server::HandlerResponse::Handled;
		}
		res.set_header("Access-Control-Allow-Origin", "*");
		return httplib::Server::HandlerResponse::Unhandled;
		});

	//path to caesarEncrypt API
	svr.Post("/encrypt", [](const httplib::Request& req, httplib::Response& res) {
		std::cout << "Rceived request: " << req.body << std::endl;
		std::string input_text = req.body; //getting the text from the user

		std::string encrypted_text = caesarEncrypt(input_text, 2);//tect encryption

		res.set_content(encrypted_text, "text/plain");//returning the encrypted text
		});

	svr.set_mount_point("/", "./public");
	
	std::cout << "Server started at http://localhost:3001" << std::endl;
	svr.listen("127.0.0.1", 3001);//turning on the server

	return 0;
}