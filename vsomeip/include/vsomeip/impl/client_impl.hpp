//
// client_impl.hpp
//
// Date: 	Jan 14, 2014
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013 Bayerische Motoren Werke AG (BMW). 
// All rights reserved.
//

#ifndef VSOMEIP_IMPL_CLIENT_IMPL_HPP
#define VSOMEIP_IMPL_CLIENT_IMPL_HPP

#include <map>
#include <set>

#include <boost/asio.hpp>

#include <vsomeip/client.hpp>
#include <vsomeip/impl/connection_impl.hpp>

namespace vsomeip {

class client_impl: virtual public client {
public:
	client_impl();
	virtual ~client_impl();

	void send(const service &_service, const message &_message);
	void register_receiver(receiver *_receiver);
	void unregister_receiver(receiver *_receiver);

private:
	boost::asio::io_service io_;

	std::set<receiver *> receiver_;
	std::map<boost::asio::ip::tcp::endpoint, connection_impl> connections_;

private:
	connection_impl * create_connection(boost::asio::ip::tcp::endpoint);
	void send_tcp(const service &_service, const message &_message);
	void send_udp(const service &_service, const message &_message);
};

} // namespace vsomeip

#endif // VSOMEIP_IMPL_CLIENT_IMPL_HPP
