/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:52:23 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 16:52:25 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef CONTACT_H
#define CONTACT_H

class Contact {
private:
  std::string _first_name;
  std::string _last_name;
  std::string _phone;
  std::string _nick;
  std::string _darkest_secret;

public:
  Contact(void);
  ~Contact(void);
  Contact(std::string first_name, std::string last_name, std::string nick,
          std::string phone);

  std::string getFirstName();
  std::string getLastName();
  std::string getNick();
  std::string getPhone();
  std::string getSecret();

  void setFirstName(std::string first_name);
  void setLastName(std::string last_name);
  void setNick(std::string nick);
  void setPhone(std::string phone);
  void setSecret(std::string secret);
  void printContact();
};

#endif