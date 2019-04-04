/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:54:37 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/01 14:57:46 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(PresidentialPardonForm const& copy);
		virtual void		execute(Bureaucrat const& executor) const;

	private:
		PresidentialPardonForm();
		std::string		_target;
};

#endif
