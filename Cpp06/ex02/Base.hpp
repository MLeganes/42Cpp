/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:20:24 by amorcill          #+#    #+#             */
/*   Updated: 2022/06/28 12:20:47 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	private:
		
	public:
		virtual	~Base(){}
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
