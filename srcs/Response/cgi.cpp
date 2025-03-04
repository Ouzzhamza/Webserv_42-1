/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:36:29 by ouzhamza          #+#    #+#             */
/*   Updated: 2023/03/31 16:21:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/response.hpp"

int Response::runcgi()
{
    fillClass();
    return(200);
}

void Response::fillClass()
{
    Cgi cgi;
    cgi.setCgiMethode(request.get_methode());
    cgi.setCgiPath(request.get_path());
    cgi.setCgiQuery(_query);
    cgi.setCgiroot(server.root);
    cgi.setCgiServerName(server.server_name[0]); //! NOT SUR OF THIS
    cgi.setCgiredirectStatus(_ret);
    cgi.setCgicontentLength(request.get_header("Content-Length"));
    cgi.setCgicontentType(request.get_header("Content-Type"));
    cgi.setCgiserverProtocol();
    cgi.setCgiPort(request.get_port());
    
    
    _Resbody += executeCgi("/Users/sahafid/Desktop/webserv_copy/srcs/Conf/php/file.php", cgi);
    std::cout << "exited" << std::endl;
    std::cout << _Resbody << std::endl;
    
    // std::cout << server.port[0] << std::endl; 
}

void Response::Cgi::setCgiMethode(std::string _methode)
{
    Methode = _methode;
}

void Response::Cgi::setCgiPath(std::string _path)
{
    Path = _path;
}

void Response::Cgi::setCgiQuery(std::string _query)
{
    Query = _query;
}

void Response::Cgi::setCgiroot(std::string _root)
{
    root = _root;
}

void Response::Cgi::setCgiredirectStatus(int _ret)
{
    std::stringstream ss;
    ss << _ret;
    this->redirectStatus = ss.str();
}

void Response::Cgi::setCgicontentLength(std::string _lenght)
{
    contentLength = _lenght;
}

void Response::Cgi::setCgicontentType (std::string _type)
{
    contentType = _type;
}

void Response::Cgi::setCgiServerName(std::string _serverName)
{
    serverName = _serverName;
}

void Response::Cgi::setCgiserverProtocol()
{
    serverProtocol = "TCP";
}

void Response::Cgi::setCgiPort(int port)
{
    std::stringstream ss;
    ss << port;
    this->port = ss.str();
}





std::string		Response::Cgi::getCgicontentType()
{
    return contentType;
}

std::string		Response::Cgi::getCgicontentLength()
{
    return contentLength;
}

std::string		Response::Cgi::getCgiPath()
{
    return Path;
}

std::string		Response::Cgi::getCgiQuery()
{
    return Query;
}

std::string		Response::Cgi::getCgiredirectStatus()
{
    return redirectStatus;
}

std::string		Response::Cgi::getCgiroot()
{
    return root;
}

std::string		Response::Cgi::getCgiServerName()
{
    return serverName;
}

std::string		Response::Cgi::getCgiMethode()
{
    return Methode;
}

std::string		Response::Cgi::getCgiserverProtocol()
{
    return serverProtocol;
}

std::string		Response::Cgi::getCgiPort()
{
    return port;
}