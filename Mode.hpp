/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trindran <trindran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:43:50 by trindran          #+#    #+#             */
/*   Updated: 2025/09/12 16:41:35 by trindran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_HPP
 #define MODE_HPP
 #include <string>
 #include <stdexpect>

 struct Mode
 {
	private:
		bool		_inviteOnly;
		bool		_topicSetable;
		std::string _topic;
		std::string _password;
		int			_limits;

	public:
		Mode();
		~Mode();
		void	setInviteOnly( void );
		void	removeInviteOnly( void );
		void	setTopicSetable( void );
		void	removeTopic( void );
		void	setTopic( std::string newTopic);
		void	setPassword( std::string password);
		void	setLimits( int limit);
		void	removeLimits( void );

		bool				getInviteOnlyMode( void );
		bool				getTopicSetable( void );
		const std::string	&getTopic( void );
		const std::string	&getPassword( void );
		const int			getLimits( void );

 };
 
#endif