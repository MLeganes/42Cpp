/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:52:37 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 16:52:42 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook {
private:
  int _ncontacts;
  int _index;
  bool _full;
  Contact _contacts[8];

public:
  PhoneBook(void);
  ~PhoneBook(void);

  void add(void);
  void search(void);
  void setNContacts(int n);
//   void increaseNContacts(void);
//   int getNContacts(void);
  int printPreview(void);
  void printContact(int idx);
};

#endif