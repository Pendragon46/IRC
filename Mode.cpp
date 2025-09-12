/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trindran <trindran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:43:47 by trindran          #+#    #+#             */
/*   Updated: 2025/09/12 16:43:59 by trindran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mode.hpp"

Mode::Mode() : _inviteOnly(false), _topicSetable(false), _limits(-1)
{
}

Mode::~Mode(){}

void	Mode::setInviteOnly( void )
{
	if ( _inviteOnly == false )
		_inviteOnly = true;
	// else
	// 	throw std::logic_error("Mode invited Only is already set !");
}
void	Mode::removeInviteOnly( void )
{
	if ( _inviteOnly == true )
		_inviteOnly = false;
	// else
	// 	throw std::logic_error("Mode invited Only is already removed !");
}

void	Mode::setTopicSetable( void )
{
	if ( _topicSetable == false )
		_topicSetable = true;
	// else
	// 	throw std::logic_error("Mode topic is already set !");	
}

void	Mode::removeTopic( void )
{
	if ( _topicSetable == true )
	{
		_topicSetable = false;
		_topic.clear();
	}
	// else
	// 	throw std::logic_error("Mode topic is already removed !");
}

void	Mode::setTopic( std::string newTopic)
{
	if ( _topicSetable )
		_topic = newTopic;
}

void	Mode::setPassword( std::string password )
{
	_password = password;
}

void	Mode::setLimits( int limit)
{
	_limits = limit;
}

void	Mode::removeLimits( void )
{
	_limits = -1;
}

bool	Mode::getInviteOnlyMode( void )
{
	return ( _inviteOnly );
}

bool	Mode::getTopicSetable( void )
{
	return ( _topicSetable );
}

const std::string	&Mode::getTopic( void )
{
	return ( _topic );
}

const std::string	&Mode::getPassword( void )
{
	return ( _password );
}

const int	Mode::getLimits( void )
{
	return ( _limits );
}
