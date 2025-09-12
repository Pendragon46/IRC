/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trindran <trindran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:30:56 by trindran          #+#    #+#             */
/*   Updated: 2025/09/12 16:35:44 by trindran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
 #define CHANNEL_HPP
 #include <string>
 #include <vector>
 #include <unordered_set>
 #include <stdexcept>
 #include "Mode.hpp"
 class Channel
 {
	private:
		std::unordered_set<std::string> _members;
		std::unordered_set<std::string> _operators;
		std::unordered_set<std::string> _invited;
		struct Mode						_mode;

		Channel();
		Channel(const Channel &toCopy);
		Channel &operator=( const Channel &toCopy);
		
	public:
		std::string name;
		Channel( std::string channelName );
		virtual ~Channel();

		bool	isMemberOfChannel( std::string member );
		bool	isOperatorOfChannel( std::string member );
		void	addMember( std::string newMember );
		void	deleteMember( std::string member );
		void	addOperator( std::string member );
		void	deleteOperator( std::string member );

		void	modeFunction(std::string user, std::string mode, std::string arg);

		bool	inviteMember(std::string member);
 };

#endif