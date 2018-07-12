#pragma once

#include "logger.hpp"
#include <asio.hpp>
using asio::ip::tcp;

class BillingServer;

class ClientConnection: public std::enable_shared_from_this<ClientConnection>
{
public:
	ClientConnection(BillingServer* s, asio::io_service& io);
	~ClientConnection();
	tcp::socket& getSocket();
	void acceptHandler(const asio::error_code& error);
	void writeHandler(const asio::error_code& error, std::size_t size);

private:
	BillingServer * server;
	tcp::socket socket;
	void readFromClient();
	void processRequest(std::shared_ptr<string> request, std::size_t size);
};