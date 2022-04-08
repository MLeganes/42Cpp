/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:49:01 by amorcill          #+#    #+#             */
/*   Updated: 2022/04/08 16:49:08 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.hpp"

bool isnumber(std::string number) {
  int i = 0;
  while (i < (int)number.length()) {
    if (std::isdigit(number[i]) == false) {

      return false;
    }

    i++;
  }
  return true;
}
