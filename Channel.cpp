/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trindran <trindran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:30:54 by trindran          #+#    #+#             */
/*   Updated: 2025/09/12 16:39:54 by trindran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(){}
Channel::Channel(const Channel &toCopy){ static_cast<void>(toCopy);}
Channel &Channel::operator=(const Channel &toCopy){ static_cast<void>(toCopy); return *this;}
Channel::~Channel(){}

Channel::Channel( std::string channelName ) : name(channelName)
{
}

bool	Channel::isMemberOfChannel( std::string member )
{
	if ( _members.find(member) == _members.end() )
		return ( false );
	else
		return ( true );
}

bool	Channel::isOperatorOfChannel( std::string member )
{
	if ( _operators.find(member) == _operators.end() )
		return ( false );
	else
		return ( true );
}

void	Channel::addMember( std::string newMember )
{
	if ( isMemberOfChannel(newMember) )
		throw std::logic_error("User is already a member of this channel");
	if ( _mode.getLimits() == _members.size() )
		throw std::logic_error("Channel is full !");
	if ( !_mode.getInviteOnlyMode() )
		_members.insert(newMember);
	if (_mode.getInviteOnlyMode() && (_invited.find(newMember) != _invited.end()))
	{
		_members.insert(newMember);
		_invited.erase(newMember);
	}
	else
		throw std::logic_error("You need an invitation to join this channel !");
}

void	Channel::deleteMember( std::string member )
{
	if ( !isMemberOfChannel(member) )
		throw std::logic_error("User is not a member of this channel");
	else if ( isOperatorOfChannel(member) )
		_operators.erase(member);
	_members.erase(member);
}

void	Channel::addOperator( std::string member )
{
	if ( !isMemberOfChannel(member) )
		throw std::logic_error("User is not a member of this channel");
	if ( isOperatorOfChannel(member) )
		throw std::logic_error("User is already an operator of this channel");
	_operators.insert(member);
}

void	Channel::deleteOperator( std::string member )
{
	if ( !isMemberOfChannel(member) )
		throw std::logic_error("User is not a member of this channel");
	if ( !isOperatorOfChannel(member) )
		throw std::logic_error("User is not an operator of this channel");
	_operators.erase(member);
}

void	Channel::modeFunction(std::string user, std::string option, std::string arg)
{
	std::string array[]={"+i", "i", "-i", "+t", "t", "-t", "+k", "k", "-k", "+o", "o", "-o", "+l", "l", "-l", ""};
	int			i;

	if ( !isOperatorOfChannel(user) )
		throw std::logic_error("Only Operator can use mode !");
	for ( i=0; array[i] != "" && array[i] != option ; i++);
	switch (i)
	{
		case 0:	case 1:
			_mode.setInviteOnly();
			break;
		case 2:
			_mode.removeInviteOnly();
			_invited.clear();
			break;
		case 3:	case 4:
			_mode.setTopicSetable();
			break;
		case 5:
			_mode.removeTopic();
			break;
		case 6:	case 7:
			_mode.setPassword(arg);
			break;
		case 8:
			_mode.setPassword("");
		case 9:	case 10:
			addOperator(arg);
			break;
		case 11:
			deleteOperator(arg);
			break;
		case 12: case 13:
			_mode.setLimits(std::stoi(arg));
			break;
		case 14 :
			_mode.removeLimits();
			break;
		default:
			break;
	}
}

bool	Channel::inviteMember(std::string member)
{
	/* To check mode invited only */

	if (isMemberOfChannel(member))
		throw std::logic_error("User is already a member");
	if ( _invited.find(member) != _invited.end() )
		throw std::logic_error("Invitation already sent");
	_invited.insert(member);
}

